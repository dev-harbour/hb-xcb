/*
 *
 */

#include "hbxcb.ch"

PROCEDURE Main()

   LOCAL pConnect
   LOCAL pSetup
   LOCAL aIterator
   LOCAL aScreen
   LOCAL nWindow
   LOCAL nMask
   LOCAL aValues[ 2 ]

   pConnect := xcb_connect( NIL, NIL )
   IF( xcb_connection_has_error( pConnect ) < 0 )
      OutStd( e"Error opening display.\n" )
      RETURN
   ENDIF

   pSetup    := xcb_get_setup( pConnect )
   aIterator := xcb_setup_roots_iterator( pSetup )
   aScreen   := aIterator[ DATA ]

   nWindow      := xcb_generate_id( pConnect )
   nMask        := hb_bitOr( XCB_CW_BACK_PIXEL, XCB_CW_EVENT_MASK )
   aValues[ 1 ] := aScreen[ WHITE_PIXEL ]
   aValues[ 2 ] := hb_bitOr( XCB_EVENT_MASK_EXPOSURE, XCB_EVENT_MASK_KEY_PRESS )

   xcb_create_window( pConnect, XCB_COPY_FROM_PARENT, nWindow, aScreen[ ROOT ], ;
      0, 0, 720, 450, ;
      0, ;
      XCB_WINDOW_CLASS_INPUT_OUTPUT, ;
      aScreen[ ROOT_VISUAL ], ;
      nMask, aValues )

   xcb_map_window( pConnect, nWindow )

   xcb_flush( pConnect )

      hb_idleSleep( 5 )

   xcb_disconnect( pConnect )

   RETURN
