/*
 *
 */

#include "hbxcb.ch"

PROCEDURE Main()

   LOCAL pConnect
   LOCAL pSetup
   LOCAL aIterator
   LOCAL aScreen
   LOCAL nForeground
   LOCAL nMask
   LOCAL aValues[ 2 ]
   LOCAL nWindow
   LOCAL lQuit := .F.
   LOCAL pEvent := NIL
   LOCAL aRectangles := { 20, 20, 60, 60 }

   pConnect := xcb_connect( NIL, NIL )
   IF( xcb_connection_has_error( pConnect ) < 0 )
      OutStd( e"Error opening display.\n" )
      RETURN
   ENDIF

   pSetup    := xcb_get_setup( pConnect )
   aIterator := xcb_setup_roots_iterator( pSetup )
   aScreen   := aIterator[ DATA ]

   nForeground  := xcb_generate_id( pConnect )
   nMask        := hb_bitOr( XCB_GC_FOREGROUND, XCB_GC_GRAPHICS_EXPOSURES )
   aValues[ 1 ] := aScreen[ BLACK_PIXEL ]
   aValues[ 2 ] := 0
   xcb_create_gc( pConnect, nForeground, aScreen[ ROOT ], nMask, aValues )

   nWindow      := xcb_generate_id( pConnect )
   nMask        := hb_bitOr( XCB_CW_BACK_PIXEL, XCB_CW_EVENT_MASK )
   aValues[ 1 ] := aScreen[ WHITE_PIXEL ]
   aValues[ 2 ] := hb_bitOr( XCB_EVENT_MASK_EXPOSURE, XCB_EVENT_MASK_KEY_PRESS )
   xcb_create_window( pConnect, aScreen[ ROOT_DEPTH ], nWindow, aScreen[ ROOT ], ;
      10, 10, 200, 200, ;
      1, ;
      XCB_WINDOW_CLASS_INPUT_OUTPUT, aScreen[ ROOT_VISUAL ], ;
      nMask, aValues )

   xcb_map_window( pConnect, nWindow )

   xcb_flush( pConnect )

   DO WHILE( ! lQuit .AND. ( pEvent := xcb_wait_for_event( pConnect ) ) != NIL )

      SWITCH( generic_event( pEvent, RESPONSE_TYPE ) )

         CASE XCB_EXPOSE
            xcb_poly_fill_rectangle( pConnect, nWindow, nForeground, 1, aRectangles )
            xcb_flush( pConnect )
            EXIT

         CASE XCB_KEY_PRESS
            lQuit := .T.
            EXIT

      ENDSWITCH

   ENDDO

   xcb_disconnect( pConnect )

   RETURN
