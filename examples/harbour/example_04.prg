/*
 *
 */

#include "hbxcb.ch"

PROCEDURE Main()

   LOCAL pConnect
   LOCAL aIterator
   LOCAL aScreen
   LOCAL nWindow
   LOCAL nMask
   LOCAL aValues[ 2 ]
   LOCAL aWindowCookie, aMapCookie
   LOCAL pEvent := NIL
   LOCAL aKeyRelease
   LOCAL lQuit := .F.

   pConnect := xcb_connect( NIL, NIL )
   IF( xcb_connection_has_error( pConnect ) < 0 )
      OutStd( e"Error opening display.\n" )
      RETURN
   ENDIF

   aIterator := xcb_setup_roots_iterator( xcb_get_setup( pConnect ) )
   aScreen   := aIterator[ DATA ]

   nWindow      := xcb_generate_id( pConnect )
   nMask        := hb_BitOr( XCB_CW_BACK_PIXEL, XCB_CW_EVENT_MASK )
   aValues[ 1 ] := aScreen[ WHITE_PIXEL ]
   aValues[ 2 ] := hb_BitOr( XCB_EVENT_MASK_KEY_RELEASE, XCB_EVENT_MASK_BUTTON_PRESS, XCB_EVENT_MASK_EXPOSURE, XCB_EVENT_MASK_POINTER_MOTION )

   aWindowCookie := xcb_create_window_checked( pConnect, aScreen[ ROOT_DEPTH ], nWindow, aScreen[ ROOT ], ;
      20, 200, 300, 100, ;
      0, ;
      XCB_WINDOW_CLASS_INPUT_OUTPUT, aScreen[ ROOT_VISUAL ], ;
      nMask, aValues )

   testCookie( aWindowCookie, pConnect, "can't create nWindow" )

   aMapCookie := xcb_map_window_checked( pConnect, nWindow )

   testCookie( aMapCookie, pConnect, "can't map nWindow" )

   xcb_flush( pConnect )

   DO WHILE( ! lQuit )

      IF( ( pEvent := xcb_poll_for_event( pConnect ) ) != NIL )

         SWITCH( hb_BitAnd( generic_event( pEvent, RESPONSE_TYPE ), hb_BitNot( 0x80 ) ) )

            CASE XCB_EXPOSE

               drawText( pConnect, aScreen, nWindow, 10, 100 - 10, "Press ESC key to exit..." )
               EXIT

            CASE XCB_KEY_RELEASE

               aKeyRelease := key_release( pEvent )

               SWITCH aKeyRelease[ EVT_DETAIL ]
                  /* ESC */
                  CASE 9
                     lQuit := .T.
                  EXIT
               ENDSWITCH

         ENDSWITCH

      ENDIF

   ENDDO

   xcb_disconnect( pConnect )

   RETURN

STATIC PROCEDURE testCookie( aCookie, pConnect, errMessage )

   LOCAL pError

   pError := xcb_request_check( pConnect, aCookie )

   IF( pError != NIL )
      OutStd( "ERROR: ", errMessage, generic_error( pError, ERROR_ERROR_CODE  ) )
      xcb_disconnect( pConnect )
      __Quit()
   ENDIF

   RETURN

STATIC PROCEDURE drawText( pConnect, aScreen, nWindow, x1, y1, cLabel )

   LOCAL nGC
   LOCAL aTextCookie, aGcCookie

   /* Use the command `xlsfonts` in a terminal to know which are the fonts available on your computer. */
   nGC := getFontGC( pConnect, aScreen, nWindow, "fixed" )

   aTextCookie := xcb_image_text_8_checked( pConnect, strlen( cLabel ), nWindow, nGC, x1, y1, cLabel )

   testCookie( aTextCookie, pConnect, "can't paste text" )

   aGcCookie := xcb_free_gc_checked( pConnect, nGC )

   testCookie( aGcCookie, pConnect, "can't free graphics context" )

   RETURN

STATIC FUNCTION getFontGC( pConnect, aScreen, nWindow, cFont_name )

   LOCAL nFont
   LOCAL aFontCookie, aGcCookie
   LOCAL nGC
   LOCAL nMask
   LOCAL aValues[ 3 ]

   nFont := xcb_generate_id( pConnect )

   aFontCookie := xcb_open_font_checked( pConnect, nFont, strlen( cFont_name ), cFont_name )

   testCookie( aFontCookie, pConnect, "can't open font" )

   /* create graphics context */
   nGC          := xcb_generate_id( pConnect )
   nMask        := hb_BitOr( XCB_GC_FOREGROUND, XCB_GC_BACKGROUND, XCB_GC_FONT )
   aValues[ 1 ] := aScreen[ BLACK_PIXEL ]
   aValues[ 2 ] := aScreen[ WHITE_PIXEL ]
   aValues[ 3 ] := nFont

   aGcCookie := xcb_create_gc_checked( pConnect, nGC, nWindow, nMask, aValues )

   testCookie( aGcCookie, pConnect, "can't create graphics context" )

   aFontCookie := xcb_close_font_checked( pConnect, nFont )

   testCookie( aFontCookie, pConnect, "can't close font" )

   RETURN nGC


