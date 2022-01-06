/*
 * Defined in header <string.h>: string.c
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbxcb.h"

// size_t strlen( const char *str );
HB_FUNC( STRLEN )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
     hb_retns( strlen( hb_parc( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
