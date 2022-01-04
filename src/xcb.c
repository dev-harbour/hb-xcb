/*
 * XCB X protocol C-language Binding: xcb.c
 * version libxcb 1.14
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbxcb.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* xcb_connection_t */
static HB_GARBAGE_FUNC( hb_connection_Destructor )
{
   xcb_connection_t ** ppConnection = ( xcb_connection_t ** ) Cargo;

   if( * ppConnection )
   {
      xcb_connection_t * pConnection = * ppConnection;
      * ppConnection = NULL;
      xcb_disconnect( pConnection );
   }
}

static const HB_GC_FUNCS s_gcConnectionFuncs =
{
   hb_connection_Destructor,
   hb_gcDummyMark
};

xcb_connection_t * hb_connection_Param( int iParam )
{
   xcb_connection_t ** ppConnection = ( xcb_connection_t ** ) hb_parptrGC( &s_gcConnectionFuncs, iParam );

   if( ppConnection && * ppConnection )
   {
      return * ppConnection;
   }

   HB_ERR_ARGS();
   return NULL;
}

xcb_connection_t * hb_connection_ParamGet( int iParam )
{
   xcb_connection_t ** ppConnection = ( xcb_connection_t ** ) hb_parptrGC( &s_gcConnectionFuncs, iParam );

   return ppConnection ? *ppConnection : NULL;
}

xcb_connection_t * hb_connection_ItemGet( PHB_ITEM pItem )
{
   xcb_connection_t ** ppConnection = ( xcb_connection_t ** ) hb_itemGetPtrGC( pItem, &s_gcConnectionFuncs );

   return ppConnection ? *ppConnection : NULL;
}

PHB_ITEM hb_connection_ItemPut( PHB_ITEM pItem, xcb_connection_t * pConnection )
{
   xcb_connection_t ** ppConnection = ( xcb_connection_t ** ) hb_gcAllocate( sizeof( xcb_connection_t * ), &s_gcConnectionFuncs );
   * ppConnection = pConnection;
   return hb_itemPutPtrGC( pItem, ppConnection );
}

void hb_connection_ItemClear( PHB_ITEM pItem )
{
   xcb_connection_t ** ppConnection = ( xcb_connection_t ** ) hb_itemGetPtrGC( pItem, &s_gcConnectionFuncs );

   if( ppConnection )
   {
      * ppConnection = NULL;
   }
}

void hb_connection_Return( xcb_connection_t * pConnection )
{
   if( pConnection )
   {
      hb_connection_ItemPut( hb_param( -1, HB_IT_ANY ), pConnection );
   }
   else
   {
      hb_ret();
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* xcb_generic_event_t */
static HB_GARBAGE_FUNC( hb_event_Destructor )
{
   xcb_generic_event_t ** ppEvent = ( xcb_generic_event_t ** ) Cargo;

   if( * ppEvent )
   {
      xcb_generic_event_t * pEvent = * ppEvent;
      * ppEvent = NULL;
      free( pEvent );
   }
}

static const HB_GC_FUNCS s_gcEventFuncs =
{
   hb_event_Destructor,
   hb_gcDummyMark
};

xcb_generic_event_t * hb_event_Param( int iParam )
{
   xcb_generic_event_t ** ppEvent = ( xcb_generic_event_t ** ) hb_parptrGC( &s_gcEventFuncs, iParam );

   if( ppEvent && * ppEvent )
   {
      return * ppEvent;
   }

   HB_ERR_ARGS();
   return NULL;
}

xcb_generic_event_t * hb_event_ParamGet( int iParam )
{
   xcb_generic_event_t ** ppEvent = ( xcb_generic_event_t ** ) hb_parptrGC( &s_gcEventFuncs, iParam );

   return ppEvent ? *ppEvent : NULL;
}

xcb_generic_event_t * hb_event_ItemGet( PHB_ITEM pItem )
{
   xcb_generic_event_t ** ppEvent = ( xcb_generic_event_t ** ) hb_itemGetPtrGC( pItem, &s_gcEventFuncs );

   return ppEvent ? *ppEvent : NULL;
}

PHB_ITEM hb_event_ItemPut( PHB_ITEM pItem, xcb_generic_event_t * pEvent )
{
   xcb_generic_event_t ** ppEvent = ( xcb_generic_event_t ** ) hb_gcAllocate( sizeof( xcb_generic_event_t * ), &s_gcEventFuncs );
   * ppEvent = pEvent;
   return hb_itemPutPtrGC( pItem, ppEvent );
}

void hb_event_ItemClear( PHB_ITEM pItem )
{
   xcb_generic_event_t ** ppEvent = ( xcb_generic_event_t ** ) hb_itemGetPtrGC( pItem, &s_gcEventFuncs );

   if( ppEvent )
   {
      * ppEvent = NULL;
   }
}

void hb_event_Return( xcb_generic_event_t * pEvent )
{
   if( pEvent )
   {
      hb_event_ItemPut( hb_param( -1, HB_IT_ANY ), pEvent );
   }
   else
   {
      hb_ret();
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* xcb_generic_error_t */
static HB_GARBAGE_FUNC( hb_error_Destructor )
{
   xcb_generic_error_t ** ppError = ( xcb_generic_error_t ** ) Cargo;

   if( * ppError )
   {
      * ppError = NULL;
   }
}

static const HB_GC_FUNCS s_gcErrorFuncs =
{
   hb_error_Destructor,
   hb_gcDummyMark
};

xcb_generic_error_t * hb_error_Param( int iParam )
{
   xcb_generic_error_t ** ppError = ( xcb_generic_error_t ** ) hb_parptrGC( &s_gcErrorFuncs, iParam );

   if( ppError && * ppError )
   {
      return * ppError;
   }

   hb_errRT_BASE_SubstR( EG_ARG, 2021, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   return NULL;
}

xcb_generic_error_t * hb_error_ParamGet( int iParam )
{
   xcb_generic_error_t ** ppError = ( xcb_generic_error_t ** ) hb_parptrGC( &s_gcErrorFuncs, iParam );

   return ppError ? *ppError : NULL;
}

xcb_generic_error_t * hb_error_ItemGet( PHB_ITEM pItem )
{
   xcb_generic_error_t ** ppError = ( xcb_generic_error_t ** ) hb_itemGetPtrGC( pItem, &s_gcErrorFuncs );

   return ppError ? *ppError : NULL;
}

PHB_ITEM hb_error_ItemPut( PHB_ITEM pItem, xcb_generic_error_t * pError )
{
   xcb_generic_error_t ** ppError = ( xcb_generic_error_t ** ) hb_gcAllocate( sizeof( xcb_generic_error_t * ), &s_gcErrorFuncs );
   * ppError = pError;
   return hb_itemPutPtrGC( pItem, ppError );
}

void hb_error_ItemClear( PHB_ITEM pItem )
{
   xcb_generic_error_t ** ppError = ( xcb_generic_error_t ** ) hb_itemGetPtrGC( pItem, &s_gcErrorFuncs );

   if( ppError )
   {
      * ppError = NULL;
   }
}

void hb_error_Return( xcb_generic_error_t * pError )
{
   if( pError )
   {
      hb_error_ItemPut( hb_param( -1, HB_IT_ANY ), pError );
   }
   else
   {
      hb_ret();
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

// int xcb_flush(xcb_connection_t *c);
HB_FUNC( XCB_FLUSH )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection )
   {
      hb_retni( xcb_flush( connection ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// uint32_t xcb_get_maximum_request_length(xcb_connection_t *c);

// void xcb_prefetch_maximum_request_length(xcb_connection_t *c);
HB_FUNC( XCB_PREFETCH_MAXIMUM_REQUEST_LENGTH )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection )
   {
      xcb_prefetch_maximum_request_length( connection );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_generic_event_t *xcb_wait_for_event(xcb_connection_t *c);
HB_FUNC( XCB_WAIT_FOR_EVENT )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection )
   {
      hb_event_Return( xcb_wait_for_event( connection ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_generic_event_t *xcb_poll_for_event(xcb_connection_t *c);
HB_FUNC( XCB_POLL_FOR_EVENT )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection )
   {
      hb_event_Return( xcb_poll_for_event( connection ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_generic_event_t *xcb_poll_for_queued_event(xcb_connection_t *c);
// xcb_generic_event_t *xcb_poll_for_special_event(xcb_connection_t *c, xcb_special_event_t *se);
// xcb_generic_event_t *xcb_wait_for_special_event(xcb_connection_t *c, xcb_special_event_t *se);
// xcb_special_event_t *xcb_register_for_special_xge(xcb_connection_t *c, xcb_extension_t *ext, uint32_t eid, uint32_t *stamp);
// void xcb_unregister_for_special_event(xcb_connection_t *c, xcb_special_event_t *se);

// xcb_generic_error_t *xcb_request_check(xcb_connection_t *c, xcb_void_cookie_t cookie);
HB_FUNC( XCB_REQUEST_CHECK )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 1 )
   {
      xcb_void_cookie_t cookie;
      cookie.sequence = ( unsigned int ) hb_arrayGetNI( pItem, 1 );

      hb_error_Return( xcb_request_check( connection, cookie ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void xcb_discard_reply(xcb_connection_t *c, unsigned int sequence);
// void xcb_discard_reply64(xcb_connection_t *c, uint64_t sequence);
// const struct xcb_query_extension_reply_t *xcb_get_extension_data(xcb_connection_t *c, xcb_extension_t *ext);
// void xcb_prefetch_extension_data(xcb_connection_t *c, xcb_extension_t *ext);

// const struct xcb_setup_t *xcb_get_setup(xcb_connection_t *c);
HB_FUNC( XCB_GET_SETUP )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection )
   {
      hb_setup_Return( ( struct xcb_setup_t * ) xcb_get_setup( connection ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int xcb_get_file_descriptor(xcb_connection_t *c);
HB_FUNC( XCB_GET_FILE_DESCRIPTOR )
{
   xcb_connection_t *connection = hb_connection_Param( 1 );

   if( connection )
   {
      hb_retni( xcb_get_file_descriptor( connection ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int xcb_connection_has_error(xcb_connection_t *c);
HB_FUNC( XCB_CONNECTION_HAS_ERROR )
{
   xcb_connection_t *connection = hb_connection_Param( 1 );

   if( connection )
   {
      hb_retni( xcb_connection_has_error( connection ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_connection_t *xcb_connect_to_fd(int fd, xcb_auth_info_t *auth_info);

// void xcb_disconnect(xcb_connection_t *c);
HB_FUNC( XCB_DISCONNECT )
{
   xcb_connection_t ** ppConnection = ( xcb_connection_t ** ) hb_parptrGC( &s_gcConnectionFuncs, 1 );

   if( ppConnection && *ppConnection  )
   {
      xcb_disconnect( *ppConnection );
      *ppConnection = NULL;
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int xcb_parse_display(const char *name, char **host, int *display, int *screen);

// xcb_connection_t *xcb_connect(const char *displayname, int *screenp);
HB_FUNC( XCB_CONNECT )
{
   hb_connection_Return( xcb_connect( NULL, NULL ) );
}

// xcb_connection_t *xcb_connect_to_display_with_auth_info(const char *display, xcb_auth_info_t *auth, int *screen);

// uint32_t xcb_generate_id(xcb_connection_t *c);
HB_FUNC( XCB_GENERATE_ID )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection )
   {
      hb_retni( ( uint32_t ) xcb_generate_id( connection ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// uint64_t xcb_total_read(xcb_connection_t *c);
// uint64_t xcb_total_written(xcb_connection_t *c);

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* xcb_generic_event_t */
/* nType generic_event( pEvent, nType ) */
HB_FUNC( GENERIC_EVENT )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   if( event && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      switch( hb_parni( 2 ) )
      {
      case 1:
         hb_retni( ( uint8_t ) event->response_type );
         break;
      case 2:
         hb_retni( ( uint8_t ) event->pad0 );
         break;
      case 3:
         hb_retni( ( uint16_t ) event->sequence );
         break;
      case 4:
         {
            PHB_ITEM pItem = hb_itemArrayNew( 7 );

            hb_arraySetNI( pItem, 1, ( uint32_t ) event->pad[ 0 ] );
            hb_arraySetNI( pItem, 2, ( uint32_t ) event->pad[ 1 ] );
            hb_arraySetNI( pItem, 3, ( uint32_t ) event->pad[ 2 ] );
            hb_arraySetNI( pItem, 4, ( uint32_t ) event->pad[ 3 ] );
            hb_arraySetNI( pItem, 5, ( uint32_t ) event->pad[ 4 ] );
            hb_arraySetNI( pItem, 6, ( uint32_t ) event->pad[ 5 ] );
            hb_arraySetNI( pItem, 7, ( uint32_t ) event->pad[ 6 ] );

            hb_itemReturnRelease( pItem );
            break;
         }
      case 5:
         hb_retni( ( uint32_t ) event->full_sequence );
         break;

      default:
         hb_ret();
         break;
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* xcb_generic_error_t */
/* nType generic_error( pError, nType ) */
HB_FUNC( GENERIC_ERROR )
{
   xcb_generic_error_t * error = hb_error_Param( 1 );

   if( error && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      switch( hb_parni( 2 ) )
      {
      case 1:
         hb_retni( ( uint8_t ) error->response_type );
         break;
      case 2:
         hb_retni( ( uint8_t ) error->error_code  );
         break;
      case 3:
         hb_retni( ( uint16_t ) error->sequence );
         break;
      case 4:
         hb_retni( ( uint32_t ) error->resource_id );
         break;
      case 5:
         hb_retni( ( uint16_t ) error->minor_code );
         break;
      case 6:
         hb_retni( ( uint8_t ) error->major_code );
         break;
      case 7:
         hb_retni( ( uint8_t  ) error->pad0 );
         break;
      case 8:
         {
            PHB_ITEM pItem = hb_itemArrayNew( 5 );

            hb_arraySetNI( pItem, 1, ( uint32_t ) error->pad[ 0 ] );
            hb_arraySetNI( pItem, 2, ( uint32_t ) error->pad[ 1 ] );
            hb_arraySetNI( pItem, 3, ( uint32_t ) error->pad[ 2 ] );
            hb_arraySetNI( pItem, 4, ( uint32_t ) error->pad[ 3 ] );
            hb_arraySetNI( pItem, 5, ( uint32_t ) error->pad[ 4 ] );

            hb_itemReturnRelease( pItem );
            break;
         }
      case 9:
         hb_retni( ( uint32_t ) error->full_sequence );
         break;

      default:
         hb_ret();
         break;
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}
