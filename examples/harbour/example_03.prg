/*
 *
 */

#include "hbxcb.ch"

PROCEDURE Main()

   LOCAL pConnect
   LOCAL pSetup
   LOCAL aIterator
   LOCAL aScreen
   LOCAL nMask
   LOCAL aValues[ 2 ]
   LOCAL nWindow
   LOCAL cString := "X events: a complete example"
   LOCAL pEvent := NIL
   LOCAL aExpose
   LOCAL aButtonPress, aButtonRelease, aMotionNotify, aEnterNotify, aLeaveNotify, aKeyPress, aKeyRelease

   pConnect := xcb_connect( NIL, NIL )
   IF( xcb_connection_has_error( pConnect ) < 0 )
      OutStd( e"Error opening display.\n" )
      RETURN
   ENDIF

   pSetup    := xcb_get_setup( pConnect )
   aIterator := xcb_setup_roots_iterator( pSetup )
   aScreen   := aIterator[ DATA ]

   nWindow := xcb_generate_id( pConnect )
   nMask := hb_BitOr( XCB_CW_BACK_PIXEL, XCB_CW_EVENT_MASK )
   aValues[ 1 ] := aScreen[ WHITE_PIXEL ]
   aValues[ 2 ] := hb_BitOr( XCB_EVENT_MASK_EXPOSURE, XCB_EVENT_MASK_BUTTON_PRESS, XCB_EVENT_MASK_BUTTON_RELEASE, XCB_EVENT_MASK_POINTER_MOTION, ;
                             XCB_EVENT_MASK_ENTER_WINDOW, XCB_EVENT_MASK_LEAVE_WINDOW, XCB_EVENT_MASK_KEY_PRESS, XCB_EVENT_MASK_KEY_RELEASE )
   xcb_create_window( pConnect, aScreen[ ROOT_DEPTH ], nWindow, aScreen[ ROOT ], ;
      0, 0, 720, 450, ;
      0, ;
      XCB_WINDOW_CLASS_INPUT_OUTPUT, aScreen[ ROOT_VISUAL ], ;
      nMask, aValues )

   xcb_change_property( pConnect, XCB_PROP_MODE_REPLACE, nWindow, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8, Len( cString ), cString )

   xcb_map_window( pConnect, nWindow )

   xcb_flush( pConnect )

   DO WHILE( ( pEvent := xcb_wait_for_event( pConnect ) ) != NIL )

      SWITCH( hb_BitAnd( generic_event( pEvent, RESPONSE_TYPE ), hb_BitNot( 0x80 ) ) )

         CASE XCB_EXPOSE

            aExpose := expose( pEvent )

            OutStd( e"\nWindow exposed" )
            OutStd( e"\nWindow -", aExpose[ EXPOSE_WINDOW ] )
            OutStd( e"\nx      -", aExpose[ EXPOSE_X ] )
            OutStd( e"\ny      -", aExpose[ EXPOSE_Y ] )
            OutStd( e"\nwidth  -", aExpose[ EXPOSE_WIDTH ] )
            OutStd( e"\nheight -", aExpose[ EXPOSE_HEIGHT ] )
            EXIT

         CASE XCB_BUTTON_PRESS

            aButtonPress := button_press( pEvent )

            SWITCH aButtonPress[ EVT_DETAIL ]

               CASE 4
                  OutStd( e"\nWheel Button up in window" )
                  OutStd( e"\nevent   -", aButtonPress[ EVT_EVENT ] )
                  OutStd( e"\nevent_x -", aButtonPress[ EVT_EVENT_X ] )
                  OutStd( e"\nevent_y -", aButtonPress[ EVT_EVENT_Y ] )
                  EXIT
               CASE 5
                  OutStd( e"\nWheel Button down in window" )
                  OutStd( e"\nevent   -", aButtonPress[ EVT_EVENT ] )
                  OutStd( e"\nevent_x -", aButtonPress[ EVT_EVENT_X ] )
                  OutStd( e"\nevent_y -", aButtonPress[ EVT_EVENT_Y ] )
                  EXIT

               OTHERWISE
                  OutStd( e"\nButton pressed in window" )
                  OutStd( e"\nevent   -", aButtonPress[ EVT_DETAIL ] )
                  OutStd( e"\nevent   -", aButtonPress[ EVT_EVENT ] )
                  OutStd( e"\nevent_x -", aButtonPress[ EVT_EVENT_X ] )
                  OutStd( e"\nevent_y -", aButtonPress[ EVT_EVENT_Y ] )

            ENDSWITCH

            EXIT

         CASE XCB_BUTTON_RELEASE

            aButtonRelease := button_release( pEvent )

            OutStd( e"\nButton released in window" )
            OutStd( e"\nevent   -", aButtonRelease[ EVT_DETAIL ] )
            OutStd( e"\nevent   -", aButtonRelease[ EVT_EVENT ] )
            OutStd( e"\nevent_x -", aButtonRelease[ EVT_EVENT_X ] )
            OutStd( e"\nevent_y -", aButtonRelease[ EVT_EVENT_Y ] )
            EXIT

         CASE XCB_MOTION_NOTIFY

            aMotionNotify := motion_notify( pEvent )

            OutStd( e"\nMouse moved in window" )
            OutStd( e"\nevent   -", aMotionNotify[ EVT_EVENT ] )
            OutStd( e"\nevent_x -", aMotionNotify[ EVT_EVENT_X ] )
            OutStd( e"\nevent_y -", aMotionNotify[ EVT_EVENT_Y ] )
            EXIT

         CASE XCB_ENTER_NOTIFY

            aEnterNotify := enter_notify( pEvent )

            OutStd( e"\nMouse entered window" )
            OutStd( e"\nevent   -", aEnterNotify[ EVT_EVENT ] )
            OutStd( e"\nevent_x -", aEnterNotify[ EVT_EVENT_X ] )
            OutStd( e"\nevent_y -", aEnterNotify[ EVT_EVENT_Y ] )
            EXIT

         CASE XCB_LEAVE_NOTIFY

            aLeaveNotify := leave_notify( pEvent )

            OutStd( e"\nMouse left window" )
            OutStd( e"\nevent   -", aLeaveNotify[ EVT_EVENT ] )
            OutStd( e"\nevent_x -", aLeaveNotify[ EVT_EVENT_X ] )
            OutStd( e"\nevent_y -", aLeaveNotify[ EVT_EVENT_Y ] )
            EXIT

         CASE XCB_KEY_PRESS

            aKeyPress := key_press( pEvent )

            OutStd( e"\nKey pressed in window" )
            OutStd( e"\nevent   -", aKeyPress[ EVT_STATE ] )
            EXIT

         CASE XCB_KEY_RELEASE

            aKeyRelease := key_release( pEvent )

            OutStd( e"\nKey pressed in window" )
            OutStd( e"\nevent   -", aKeyRelease[ EVT_STATE ] )
            EXIT

         OTHERWISE
            /* Unknown event type, ignore it */
            OutStd( e"\nUnknown event:", generic_event( pEvent, RESPONSE_TYPE ) )

      ENDSWITCH

   ENDDO

   xcb_disconnect( pConnect )

   RETURN
