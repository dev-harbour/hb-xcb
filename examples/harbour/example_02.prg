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
   LOCAL nBackground
   LOCAL nMask
   LOCAL aValues[ 2 ]
   LOCAL nWindow
   LOCAL lQuit := .F.
   LOCAL pEvent := NIL
   LOCAL aRectangles := { 20, 24, 316, 3 }
   LOCAL cString := "hb-xcb - Harbour module implementing bindings to XCB."
   LOCAL aKeyPress

   pConnect := xcb_connect( NIL, NIL )
   IF( xcb_connection_has_error( pConnect ) < 0 )
      OutStd( e"Error opening display.\n" )
      RETURN
   ENDIF

   pSetup    := xcb_get_setup( pConnect )
   aIterator := xcb_setup_roots_iterator( pSetup )
   aScreen   := aIterator[ DATA ]

   nForeground  := xcb_generate_id( pConnect )
   nMask        := hb_BitOr( XCB_GC_FOREGROUND, XCB_GC_GRAPHICS_EXPOSURES )
   aValues[ 1 ] := aScreen[ BLACK_PIXEL ]
   aValues[ 2 ] := 0
   xcb_create_gc( pConnect, nForeground, aScreen[ ROOT ], nMask, aValues )

   nBackground  := xcb_generate_id( pConnect )
   nMask        := hb_BitOr( XCB_GC_BACKGROUND, XCB_GC_GRAPHICS_EXPOSURES )
   aValues[ 1 ] := aScreen[ WHITE_PIXEL ]
   aValues[ 2 ] := 0
   xcb_create_gc( pConnect, nBackground, aScreen[ ROOT ], nMask, aValues )

   nWindow := xcb_generate_id( pConnect )
   nMask := hb_BitOr( XCB_CW_BACK_PIXEL, XCB_CW_EVENT_MASK )
   aValues[ 1 ] := aScreen[ WHITE_PIXEL ]
   aValues[ 2 ] := hb_BitOr( XCB_EVENT_MASK_EXPOSURE, XCB_EVENT_MASK_KEY_PRESS )
   xcb_create_window( pConnect, aScreen[ ROOT_DEPTH ], nWindow, aScreen[ ROOT ], ;
      0, 0, 720, 450, ;
      0, ;
      XCB_WINDOW_CLASS_INPUT_OUTPUT, aScreen[ ROOT_VISUAL ], ;
      nMask, aValues )

   xcb_change_property( pConnect, XCB_PROP_MODE_REPLACE, nWindow, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8, strlen( cString ), cString )

   xcb_map_window( pConnect, nWindow )

   xcb_flush( pConnect )

   DO WHILE( ! lQuit .AND. ( pEvent := xcb_wait_for_event( pConnect ) ) != NIL )

      SWITCH( hb_BitAnd( generic_event( pEvent, RESPONSE_TYPE ), hb_BitNot( 0x80 ) ) )

         CASE XCB_EXPOSE
            xcb_poly_rectangle( pConnect, nWindow, nForeground, 1, aRectangles )
            xcb_image_text_8( pConnect, strlen( cString ), nWindow, nBackground, 20, 20, cString )
            xcb_flush( pConnect )
            EXIT

         CASE XCB_KEY_PRESS

            aKeyPress := key_press( pEvent )

            SWITCH aKeyPress[ EVT_DETAIL ]
               /* ESC */
               CASE 9
                  lQuit := .T.
               EXIT
            ENDSWITCH

     ENDSWITCH

   ENDDO

   xcb_disconnect( pConnect )

   RETURN
