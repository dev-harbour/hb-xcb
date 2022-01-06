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
   LOCAL aValues2[ 2 ]

   LOCAL lQuit := .F.
   LOCAL pEvent := NIL
   LOCAL aKeyPress

   pConnect := xcb_connect( NIL, NIL )
   IF( xcb_connection_has_error( pConnect ) < 0 )
      OutStd( e"Error opening display.\n" )
      RETURN
   ENDIF

   pSetup    := xcb_get_setup( pConnect )
   aIterator := xcb_setup_roots_iterator( pSetup )
   aScreen   := aIterator[ DATA ]

   nWindow       := xcb_generate_id( pConnect )
   nMask         := hb_BitOr( XCB_CW_BACK_PIXEL, XCB_CW_EVENT_MASK )
   aValues2[ 1 ] := aScreen[ WHITE_PIXEL ]
   aValues2[ 2 ] := hb_BitOr( XCB_EVENT_MASK_EXPOSURE, XCB_EVENT_MASK_KEY_PRESS )

   xcb_create_window( pConnect, XCB_COPY_FROM_PARENT, nWindow, aScreen[ ROOT ], ;
		0, 0, 720, 450, ;
		0, ;
		XCB_WINDOW_CLASS_INPUT_OUTPUT, aScreen[ ROOT_VISUAL ], ;
		nMask, aValues2 )

   xcb_map_window( pConnect, nWindow )
   xcb_flush( pConnect )

   DO WHILE( ! lQuit .AND. ( pEvent := xcb_wait_for_event( pConnect ) ) != NIL )

      SWITCH( hb_BitAnd( generic_event( pEvent, RESPONSE_TYPE ), hb_BitNot( 0x80 ) ) )

         CASE XCB_EXPOSE

            drawText( pConnect, aScreen, nWindow, 0, 14, "Hello world!...", 0xff0000 )
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

PROCEDURE drawText( pConnect, aScreen, nWindow, x, y, string, nColor )

   LOCAL nFont
   LOCAL nGC
   LOCAL nMask
   LOCAL aValues4[ 4 ]

   nFont := xcb_generate_id( pConnect )
   xcb_open_font( pConnect, nFont, strlen( FONT_9x18 ), FONT_9x18 )

   nGC           := xcb_generate_id( pConnect )
   nMask         := hb_BitOr( XCB_GC_FOREGROUND, XCB_GC_BACKGROUND, XCB_GC_FONT, XCB_GC_GRAPHICS_EXPOSURES )
   aValues4[ 1 ] := nColor
   aValues4[ 2 ] := aScreen[ WHITE_PIXEL ]
   aValues4[ 3 ] := nFont
   aValues4[ 4 ] := 1
   xcb_create_gc( pConnect, nGC, nWindow, nMask, aValues4 )

   xcb_image_text_8( pConnect, strlen( string ), nWindow, nGC, x, y, string )

   RETURN
