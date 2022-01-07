/*
 * XCB X protocol C-language Binding: xcb.c
 * version libxcb 1.14
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbxcb.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
HB_FUNC( BUILD_CHARS )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      const char * str = hb_parc( 1 );
      size_t length = hb_parni( 2 );

      xcb_char2b_t * char2b = malloc( length * sizeof( xcb_char2b_t ) );

      for( size_t i = 0; i < length; i++ )
      {
         char2b[ i ].byte1 = 0;
         char2b[ i ].byte2 = str[ i ];
      }

      PHB_ITEM pChar2bArray = hb_itemArrayNew( 2 );

      hb_arraySetNI( pChar2bArray, 1, char2b->byte1 );
      hb_arraySetNI( pChar2bArray, 2, char2b->byte2 );

      hb_itemReturnRelease( pChar2bArray );

      free( char2b );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
