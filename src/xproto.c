/*
 * XCB X protocol C-language Binding: xproto.c
 * version libxcb 1.14
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbxcb.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* xcb_screen_t */
static HB_GARBAGE_FUNC( hb_screen_Destructor )
{
   xcb_screen_t ** ppScreen = ( xcb_screen_t ** ) Cargo;

   if( * ppScreen )
   {
      * ppScreen = NULL;
   }
}

static const HB_GC_FUNCS s_gcScreenFuncs =
{
   hb_screen_Destructor,
   hb_gcDummyMark
};

xcb_screen_t * hb_screen_Param( int iParam )
{
   xcb_screen_t ** ppScreen = ( xcb_screen_t ** ) hb_parptrGC( &s_gcScreenFuncs, iParam );

   if( ppScreen && * ppScreen )
   {
      return * ppScreen;
   }

   HB_ERR_ARGS();
   return NULL;
}

xcb_screen_t * hb_screen_ParamGet( int iParam )
{
   xcb_screen_t ** ppScreen = ( xcb_screen_t ** ) hb_parptrGC( &s_gcScreenFuncs, iParam );

   return ppScreen ? *ppScreen : NULL;
}

xcb_screen_t * hb_screen_ItemGet( PHB_ITEM pItem )
{
   xcb_screen_t ** ppScreen = ( xcb_screen_t ** ) hb_itemGetPtrGC( pItem, &s_gcScreenFuncs );

   return ppScreen ? *ppScreen : NULL;
}

PHB_ITEM hb_screen_ItemPut( PHB_ITEM pItem, xcb_screen_t * pScreen )
{
   xcb_screen_t ** ppScreen = ( xcb_screen_t ** ) hb_gcAllocate( sizeof( xcb_screen_t * ), &s_gcScreenFuncs );
   * ppScreen = pScreen;
   return hb_itemPutPtrGC( pItem, ppScreen );
}

void hb_screen_ItemClear( PHB_ITEM pItem )
{
   xcb_screen_t ** ppScreen = ( xcb_screen_t ** ) hb_itemGetPtrGC( pItem, &s_gcScreenFuncs );

   if( ppScreen )
   {
      * ppScreen = NULL;
   }
}

void hb_screen_Return( xcb_screen_t * pScreen )
{
   if( pScreen )
   {
      hb_screen_ItemPut( hb_param( -1, HB_IT_ANY ), pScreen );
   }
   else
   {
      hb_ret();
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* xcb_setup_t */
static HB_GARBAGE_FUNC( hb_setup_Destructor )
{
   xcb_setup_t ** ppSetup = ( xcb_setup_t ** ) Cargo;

   if( * ppSetup )
   {
      * ppSetup = NULL;
   }
}

static const HB_GC_FUNCS s_gcSetupFuncs =
{
   hb_setup_Destructor,
   hb_gcDummyMark
};

xcb_setup_t * hb_setup_Param( int iParam )
{
   xcb_setup_t ** ppSetup = ( xcb_setup_t ** ) hb_parptrGC( &s_gcSetupFuncs, iParam );

   if( ppSetup && * ppSetup )
   {
      return * ppSetup;
   }

   HB_ERR_ARGS();
   return NULL;
}

xcb_setup_t * hb_setup_ParamGet( int iParam )
{
   xcb_setup_t ** ppSetup = ( xcb_setup_t ** ) hb_parptrGC( &s_gcSetupFuncs, iParam );

   return ppSetup ? *ppSetup : NULL;
}

xcb_setup_t * hb_setup_ItemGet( PHB_ITEM pItem )
{
   xcb_setup_t ** ppSetup = ( xcb_setup_t ** ) hb_itemGetPtrGC( pItem, &s_gcSetupFuncs );

   return ppSetup ? *ppSetup : NULL;
}

PHB_ITEM hb_setup_ItemPut( PHB_ITEM pItem, xcb_setup_t * pSetup )
{
   xcb_setup_t ** ppSetup = ( xcb_setup_t ** ) hb_gcAllocate( sizeof( xcb_setup_t * ), &s_gcSetupFuncs );
   * ppSetup = pSetup;
   return hb_itemPutPtrGC( pItem, ppSetup );
}

void hb_setup_ItemClear( PHB_ITEM pItem )
{
   xcb_setup_t ** ppSetup = ( xcb_setup_t ** ) hb_itemGetPtrGC( pItem, &s_gcSetupFuncs );

   if( ppSetup )
   {
      * ppSetup = NULL;
   }
}

void hb_setup_Return( xcb_setup_t * pSetup )
{
   if( pSetup )
   {
      hb_setup_ItemPut( hb_param( -1, HB_IT_ANY ), pSetup );
   }
   else
   {
      hb_ret();
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

// void xcb_char2b_next (xcb_char2b_iterator_t *i);

// xcb_generic_iterator_t xcb_char2b_end (xcb_char2b_iterator_t i);

// void xcb_window_next (xcb_window_iterator_t *i);

// xcb_generic_iterator_t xcb_window_end (xcb_window_iterator_t i);

// void xcb_pixmap_next (xcb_pixmap_iterator_t *i);

// xcb_generic_iterator_t xcb_pixmap_end (xcb_pixmap_iterator_t i);

// void xcb_cursor_next (xcb_cursor_iterator_t *i);

// xcb_generic_iterator_t xcb_cursor_end (xcb_cursor_iterator_t i);

// void xcb_font_next (xcb_font_iterator_t *i);

// xcb_generic_iterator_t xcb_font_end (xcb_font_iterator_t i);

// void xcb_gcontext_next (xcb_gcontext_iterator_t *i);

// xcb_generic_iterator_t xcb_gcontext_end (xcb_gcontext_iterator_t i);

// void xcb_colormap_next (xcb_colormap_iterator_t *i);

// xcb_generic_iterator_t xcb_colormap_end (xcb_colormap_iterator_t i);

// void xcb_atom_next (xcb_atom_iterator_t *i);

// xcb_generic_iterator_t xcb_atom_end (xcb_atom_iterator_t i);

// void xcb_drawable_next (xcb_drawable_iterator_t *i);

// xcb_generic_iterator_t xcb_drawable_end (xcb_drawable_iterator_t i);

// void xcb_fontable_next (xcb_fontable_iterator_t *i);

// xcb_generic_iterator_t xcb_fontable_end (xcb_fontable_iterator_t i);

// void xcb_bool32_next (xcb_bool32_iterator_t *i);

// xcb_generic_iterator_t xcb_bool32_end (xcb_bool32_iterator_t i);

// void xcb_visualid_next (xcb_visualid_iterator_t *i);

// xcb_generic_iterator_t xcb_visualid_end (xcb_visualid_iterator_t i);

// void xcb_timestamp_next (xcb_timestamp_iterator_t *i);

// xcb_generic_iterator_t xcb_timestamp_end (xcb_timestamp_iterator_t i);

// void xcb_keysym_next (xcb_keysym_iterator_t *i);

// xcb_generic_iterator_t xcb_keysym_end (xcb_keysym_iterator_t i);

// void xcb_keycode_next (xcb_keycode_iterator_t *i);

// xcb_generic_iterator_t xcb_keycode_end (xcb_keycode_iterator_t i);

// void xcb_keycode32_next (xcb_keycode32_iterator_t *i);

// xcb_generic_iterator_t xcb_keycode32_end (xcb_keycode32_iterator_t i);

// void xcb_button_next (xcb_button_iterator_t *i);

// xcb_generic_iterator_t xcb_button_end (xcb_button_iterator_t i);

// void xcb_point_next (xcb_point_iterator_t *i);

// xcb_generic_iterator_t xcb_point_end (xcb_point_iterator_t i);

// void xcb_rectangle_next (xcb_rectangle_iterator_t *i);

// xcb_generic_iterator_t xcb_rectangle_end (xcb_rectangle_iterator_t i);

// void xcb_arc_next (xcb_arc_iterator_t *i);

// xcb_generic_iterator_t xcb_arc_end (xcb_arc_iterator_t i);

// void xcb_format_next (xcb_format_iterator_t *i);

// xcb_generic_iterator_t xcb_format_end (xcb_format_iterator_t i);

// void xcb_visualtype_next (xcb_visualtype_iterator_t *i);

// xcb_generic_iterator_t xcb_visualtype_end (xcb_visualtype_iterator_t i);

// int xcb_depth_sizeof (const void *_buffer);

// xcb_visualtype_t *xcb_depth_visuals (const xcb_depth_t *R);

// int xcb_depth_visuals_length (const xcb_depth_t *R);

// xcb_visualtype_iterator_t xcb_depth_visuals_iterator (const xcb_depth_t *R);

// void xcb_depth_next (xcb_depth_iterator_t *i);

// xcb_generic_iterator_t xcb_depth_end (xcb_depth_iterator_t i);

// int xcb_screen_sizeof (const void *_buffer);

// intxcb_screen_allowed_depths_length (const xcb_screen_t *R);

// xcb_depth_iterator_t xcb_screen_allowed_depths_iterator (const xcb_screen_t *R);

// void xcb_screen_next (xcb_screen_iterator_t *i);

// xcb_generic_iterator_t xcb_screen_end (xcb_screen_iterator_t i);

// intxcb_setup_request_sizeof (const void *_buffer);

// char *xcb_setup_request_authorization_protocol_name (const xcb_setup_request_t *R);

// intxcb_setup_request_authorization_protocol_name_length (const xcb_setup_request_t *R);

// xcb_generic_iterator_t xcb_setup_request_authorization_protocol_name_end (const xcb_setup_request_t *R);

// char *xcb_setup_request_authorization_protocol_data (const xcb_setup_request_t *R);

// intxcb_setup_request_authorization_protocol_data_length (const xcb_setup_request_t *R);

// xcb_generic_iterator_t xcb_setup_request_authorization_protocol_data_end (const xcb_setup_request_t *R);

// void xcb_setup_request_next (xcb_setup_request_iterator_t *i);

// xcb_generic_iterator_t xcb_setup_request_end (xcb_setup_request_iterator_t i);

// intxcb_setup_failed_sizeof (const void *_buffer);

// char *xcb_setup_failed_reason (const xcb_setup_failed_t *R);

// intxcb_setup_failed_reason_length (const xcb_setup_failed_t *R);

// xcb_generic_iterator_t xcb_setup_failed_reason_end (const xcb_setup_failed_t *R);

// void xcb_setup_failed_next (xcb_setup_failed_iterator_t *i);

// xcb_generic_iterator_t xcb_setup_failed_end (xcb_setup_failed_iterator_t i);

// intxcb_setup_authenticate_sizeof (const void *_buffer);

// char *xcb_setup_authenticate_reason (const xcb_setup_authenticate_t *R);

// intxcb_setup_authenticate_reason_length (const xcb_setup_authenticate_t *R);

// xcb_generic_iterator_t xcb_setup_authenticate_reason_end (const xcb_setup_authenticate_t *R);

// void xcb_setup_authenticate_next (xcb_setup_authenticate_iterator_t *i);

// xcb_generic_iterator_t xcb_setup_authenticate_end (xcb_setup_authenticate_iterator_t i);

// intxcb_setup_sizeof (const void *_buffer);

// char *xcb_setup_vendor (const xcb_setup_t *R);

// intxcb_setup_vendor_length (const xcb_setup_t *R);

// xcb_generic_iterator_t xcb_setup_vendor_end (const xcb_setup_t *R);

// xcb_format_t *xcb_setup_pixmap_formats (const xcb_setup_t *R);

// intxcb_setup_pixmap_formats_length (const xcb_setup_t *R);

// xcb_format_iterator_t xcb_setup_pixmap_formats_iterator (const xcb_setup_t *R);

// intxcb_setup_roots_length (const xcb_setup_t *R);

// xcb_screen_iterator_t xcb_setup_roots_iterator (const xcb_setup_t *R);
HB_FUNC( XCB_SETUP_ROOTS_ITERATOR )
{
   const xcb_setup_t * R = hb_setup_Param( 1 );

   if( R  )
   {
      xcb_screen_iterator_t iterator = xcb_setup_roots_iterator( R );

      PHB_ITEM pScreen_iteratorArray = hb_itemArrayNew( 3 );

         // xcb_screen_t *data
         PHB_ITEM pSubarrayScreen = hb_arrayGetItemPtr( pScreen_iteratorArray, 1 );

         hb_arrayNew( pSubarrayScreen, 16 );
         hb_arraySetNI( pSubarrayScreen, 1,  ( xcb_window_t   ) iterator.data->root                  );
         hb_arraySetNI( pSubarrayScreen, 2,  ( xcb_colormap_t ) iterator.data->default_colormap      );
         hb_arraySetNI( pSubarrayScreen, 3,  ( uint32_t       ) iterator.data->white_pixel           );
         hb_arraySetNI( pSubarrayScreen, 4,  ( uint32_t       ) iterator.data->black_pixel           );
         hb_arraySetNI( pSubarrayScreen, 5,  ( uint32_t       ) iterator.data->current_input_masks   );
         hb_arraySetNI( pSubarrayScreen, 6,  ( uint16_t       ) iterator.data->width_in_pixels       );
         hb_arraySetNI( pSubarrayScreen, 7,  ( uint16_t       ) iterator.data->height_in_pixels      );
         hb_arraySetNI( pSubarrayScreen, 8,  ( uint16_t       ) iterator.data->width_in_millimeters  );
         hb_arraySetNI( pSubarrayScreen, 9,  ( uint16_t       ) iterator.data->height_in_millimeters );
         hb_arraySetNI( pSubarrayScreen, 10, ( uint16_t       ) iterator.data->min_installed_maps    );
         hb_arraySetNI( pSubarrayScreen, 11, ( uint16_t       ) iterator.data->max_installed_maps    );
         hb_arraySetNI( pSubarrayScreen, 12, ( xcb_visualid_t ) iterator.data->root_visual           );
         hb_arraySetNI( pSubarrayScreen, 13, ( uint8_t        ) iterator.data->backing_stores        );
         hb_arraySetNI( pSubarrayScreen, 14, ( uint8_t        ) iterator.data->save_unders           );
         hb_arraySetNI( pSubarrayScreen, 15, ( uint8_t        ) iterator.data->root_depth            );
         hb_arraySetNI( pSubarrayScreen, 16, ( uint8_t        ) iterator.data->allowed_depths_len    );

      hb_arraySetNI( pScreen_iteratorArray,  2, iterator.rem   );
      hb_arraySetNI( pScreen_iteratorArray,  3, iterator.index );

      hb_itemReturnRelease( pScreen_iteratorArray );
   }
}

// void xcb_setup_next (xcb_setup_iterator_t *i);

// xcb_generic_iterator_t xcb_setup_end (xcb_setup_iterator_t i);

// void xcb_client_message_data_next (xcb_client_message_data_iterator_t *i);

// xcb_generic_iterator_t xcb_client_message_data_end (xcb_client_message_data_iterator_t i);

// int xcb_create_window_value_list_serialize (void **_buffer, uint32_t value_mask, const xcb_create_window_value_list_t *_aux);

// int xcb_create_window_value_list_unpack (const void *_buffer, uint32_t value_mask, xcb_create_window_value_list_t *_aux);

// intxcb_create_window_value_list_sizeof (const void *_buffer, uint32_t value_mask);

// int xcb_create_window_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_create_window_checked (xcb_connection_t *c, uint8_t depth, xcb_window_t wid, xcb_window_t parent, int16_t x, int16_t y, uint16_t width, uint16_t height, uint16_t border_width, uint16_t _class, xcb_visualid_t visual, uint32_t value_mask, const void *value_list);
HB_FUNC( XCB_CREATE_WINDOW_CHECKED )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_INTEGER ) != NULL &&
      hb_param( 8, HB_IT_INTEGER ) != NULL &&
      hb_param( 9, HB_IT_INTEGER ) != NULL &&
      hb_param( 10, HB_IT_INTEGER ) != NULL &&
      hb_param( 11, HB_IT_INTEGER ) != NULL &&
      hb_param( 12, HB_IT_INTEGER ) != NULL && ( pItem = hb_param( 13, HB_IT_ARRAY ) ) != NULL )
   {
      HB_SIZE nLength = hb_arrayLen( pItem );

      uint32_t values[ nLength ];

      for ( size_t i = 0; i < nLength; i++ )
      {
         values[ i ] = hb_arrayGetNI( pItem, i + 1 );
      }

      xcb_void_cookie_t cookie = xcb_create_window_checked( connection,
         ( uint8_t ) hb_parni( 2 ), ( xcb_window_t ) hb_parni( 3 ), ( xcb_window_t ) hb_parni( 4 ),
         ( int16_t ) hb_parni( 5 ), ( int16_t ) hb_parni( 6 ), ( int16_t ) hb_parni( 7 ), ( int16_t ) hb_parni( 8 ),
         ( int16_t ) hb_parni( 9 ), ( int16_t ) hb_parni( 10 ), ( xcb_visualid_t ) hb_parni( 11 ),
         ( uint32_t ) hb_parni( 12 ), values );

      PHB_ITEM pItem = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_create_window (xcb_connection_t *conn, uint8_t depth, xcb_window_t wid, xcb_window_t parent, int16_t x, int16_t y, uint16_t width, uint16_t height, uint16_t border_width, uint16_t _class, xcb_visualid_t visual, uint32_t value_mask, const uint32_t *value_list);
HB_FUNC( XCB_CREATE_WINDOW )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_INTEGER ) != NULL &&
      hb_param( 8, HB_IT_INTEGER ) != NULL &&
      hb_param( 9, HB_IT_INTEGER ) != NULL &&
      hb_param( 10, HB_IT_INTEGER ) != NULL &&
      hb_param( 11, HB_IT_INTEGER ) != NULL &&
      hb_param( 12, HB_IT_INTEGER ) != NULL && ( pItem = hb_param( 13, HB_IT_ARRAY ) ) != NULL )
   {
      HB_SIZE nLength = hb_arrayLen( pItem );

      uint32_t values[ nLength ];

      for ( size_t i = 0; i < nLength; i++ )
      {
         values[ i ] = hb_arrayGetNI( pItem, i + 1 );
      }

      xcb_create_window( connection,
         ( uint8_t ) hb_parni( 2 ), ( xcb_window_t ) hb_parni( 3 ), ( xcb_window_t ) hb_parni( 4 ),
         ( int16_t ) hb_parni( 5 ), ( int16_t ) hb_parni( 6 ), ( int16_t ) hb_parni( 7 ), ( int16_t ) hb_parni( 8 ),
         ( int16_t ) hb_parni( 9 ), ( int16_t ) hb_parni( 10 ), ( xcb_visualid_t ) hb_parni( 11 ),
         ( uint32_t ) hb_parni( 12 ), values );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_create_window_aux_checked (xcb_connection_t *c, uint8_t depth, xcb_window_t wid, xcb_window_t parent, int16_t x, int16_t y, uint16_t width, uint16_t height, uint16_t border_width, uint16_t _class, xcb_visualid_t visual, uint32_t value_mask, const xcb_create_window_value_list_t *value_list);

// xcb_void_cookie_t xcb_create_window_aux (xcb_connection_t *c, uint8_t depth, xcb_window_t wid, xcb_window_t parent, int16_t x, int16_t y, uint16_t width, uint16_t height, uint16_t border_width, uint16_t _class, xcb_visualid_t visual, uint32_t value_mask, const xcb_create_window_value_list_t *value_list);

// void *xcb_create_window_value_list (const xcb_create_window_request_t *R);

// int xcb_change_window_attributes_value_list_serialize (void **_buffer, uint32_t value_mask, const xcb_change_window_attributes_value_list_t *_aux);

// int xcb_change_window_attributes_value_list_unpack (const void *_buffer, uint32_t value_mask, xcb_change_window_attributes_value_list_t *_aux);

// int xcb_change_window_attributes_value_list_sizeof (const void *_buffer, uint32_t value_mask);

// int xcb_change_window_attributes_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_change_window_attributes_checked (xcb_connection_t *c, xcb_window_t window, uint32_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_change_window_attributes (xcb_connection_t *c, xcb_window_t window, uint32_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_change_window_attributes_aux_checked (xcb_connection_t *c, xcb_window_t window, uint32_t value_mask, const xcb_change_window_attributes_value_list_t *value_list);

// xcb_void_cookie_t xcb_change_window_attributes_aux (xcb_connection_t *c, xcb_window_t window, uint32_t value_mask, const xcb_change_window_attributes_value_list_t *value_list);

// void *xcb_change_window_attributes_value_list (const xcb_change_window_attributes_request_t *R);

// xcb_get_window_attributes_cookie_t xcb_get_window_attributes (xcb_connection_t *c, xcb_window_t window);

// xcb_get_window_attributes_cookie_t xcb_get_window_attributes_unchecked (xcb_connection_t *c, xcb_window_t window);

// xcb_get_window_attributes_reply_t *xcb_get_window_attributes_reply (xcb_connection_t *c, xcb_get_window_attributes_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_destroy_window_checked (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_destroy_window (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_destroy_subwindows_checked (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_destroy_subwindows (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_change_save_set_checked (xcb_connection_t *c, uint8_t mode, xcb_window_t window);

// xcb_void_cookie_t xcb_change_save_set (xcb_connection_t *c, uint8_t mode, xcb_window_t window);

// xcb_void_cookie_t xcb_reparent_window_checked (xcb_connection_t *c, xcb_window_t window, xcb_window_t parent, int16_t x, int16_t y);

// xcb_void_cookie_t xcb_reparent_window (xcb_connection_t *c, xcb_window_t window, xcb_window_t parent, int16_t x, int16_t y);

// xcb_void_cookie_t xcb_map_window_checked (xcb_connection_t *c, xcb_window_t window);
HB_FUNC( XCB_MAP_WINDOW_CHECKED )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      xcb_void_cookie_t cookie = xcb_map_window_checked( connection, ( xcb_window_t ) hb_parni( 2 ) );

      PHB_ITEM pItem = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}


// xcb_void_cookie_t xcb_map_window (xcb_connection_t *c, xcb_window_t window);
HB_FUNC( XCB_MAP_WINDOW )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection )
   {
      xcb_map_window( connection, ( xcb_window_t ) hb_parni( 2 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_map_subwindows_checked (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_map_subwindows (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_unmap_window_checked (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_unmap_window (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_unmap_subwindows_checked (xcb_connection_t *c, xcb_window_t window);

// xcb_void_cookie_t xcb_unmap_subwindows (xcb_connection_t *c, xcb_window_t window);

// int xcb_configure_window_value_list_serialize (void **_buffer, uint16_t value_mask, const xcb_configure_window_value_list_t *_aux);

// int xcb_configure_window_value_list_unpack (const void *_buffer, uint16_t value_mask, xcb_configure_window_value_list_t *_aux);

// int xcb_configure_window_value_list_sizeof (const void *_buffer, uint16_t  value_mask);

// int xcb_configure_window_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_configure_window_checked (xcb_connection_t *c, xcb_window_t window, uint16_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_configure_window (xcb_connection_t *c, xcb_window_t window, uint16_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_configure_window_aux_checked (xcb_connection_t *c, xcb_window_t window, uint16_t value_mask, const xcb_configure_window_value_list_t *value_list);

// xcb_void_cookie_t xcb_configure_window_aux (xcb_connection_t *c, xcb_window_t window, uint16_t value_mask, const xcb_configure_window_value_list_t *value_list);

// void *xcb_configure_window_value_list (const xcb_configure_window_request_t *R);

// xcb_void_cookie_t xcb_circulate_window_checked (xcb_connection_t *c, uint8_t direction, xcb_window_t window);

// xcb_void_cookie_t xcb_circulate_window (xcb_connection_t *c, uint8_t direction, xcb_window_t window);

// xcb_get_geometry_cookie_t xcb_get_geometry (xcb_connection_t *c, xcb_drawable_t drawable);

// xcb_get_geometry_cookie_t xcb_get_geometry_unchecked (xcb_connection_t *c, xcb_drawable_t drawable);

// xcb_get_geometry_reply_t *xcb_get_geometry_reply (xcb_connection_t *c, xcb_get_geometry_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_query_tree_sizeof (const void *_buffer);

// xcb_query_tree_cookie_t xcb_query_tree (xcb_connection_t *c, xcb_window_t window);

// xcb_query_tree_cookie_t xcb_query_tree_unchecked (xcb_connection_t *c, xcb_window_t window);

// xcb_window_t *xcb_query_tree_children (const xcb_query_tree_reply_t *R);

// int xcb_query_tree_children_length (const xcb_query_tree_reply_t *R);

// xcb_generic_iterator_t xcb_query_tree_children_end (const xcb_query_tree_reply_t *R);

// xcb_query_tree_reply_t *xcb_query_tree_reply (xcb_connection_t *c, xcb_query_tree_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_intern_atom_sizeof (const void *_buffer);

// xcb_intern_atom_cookie_t xcb_intern_atom (xcb_connection_t *c, uint8_t only_if_exists, uint16_t name_len, const char *name);

// xcb_intern_atom_cookie_t xcb_intern_atom_unchecked (xcb_connection_t *c, uint8_t only_if_exists, uint16_t name_len, const char *name);

// xcb_intern_atom_reply_t *xcb_intern_atom_reply (xcb_connection_t *c, xcb_intern_atom_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_get_atom_name_sizeof (const void *_buffer);

// xcb_get_atom_name_cookie_t xcb_get_atom_name (xcb_connection_t *c, xcb_atom_t atom);

// xcb_get_atom_name_cookie_t xcb_get_atom_name_unchecked (xcb_connection_t *c, xcb_atom_t atom);

// char *xcb_get_atom_name_name (const xcb_get_atom_name_reply_t *R);

// int xcb_get_atom_name_name_length (const xcb_get_atom_name_reply_t *R);

// xcb_generic_iterator_t xcb_get_atom_name_name_end (const xcb_get_atom_name_reply_t *R);

// xcb_get_atom_name_reply_t *xcb_get_atom_name_reply (xcb_connection_t *c, xcb_get_atom_name_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_change_property_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_change_property_checked (xcb_connection_t *c, uint8_t mode, xcb_window_t window, xcb_atom_t property, xcb_atom_t type, uint8_t format, uint32_t data_len, const void *data);

// xcb_void_cookie_t xcb_change_property (xcb_connection_t *c, uint8_t mode, xcb_window_t window, xcb_atom_t property, xcb_atom_t type, uint8_t format, uint32_t data_len, const void *data);
HB_FUNC( XCB_CHANGE_PROPERTY )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_INTEGER ) != NULL &&
      hb_param( 8, HB_IT_STRING ) != NULL )
   {
      xcb_change_property( connection, ( uint8_t ) hb_parni( 2 ), ( xcb_window_t ) hb_parni( 3 ), ( xcb_atom_t ) hb_parni( 4 ),
         ( xcb_atom_t ) hb_parni( 5 ), ( uint8_t ) hb_parni( 6 ), ( uint32_t ) hb_parni( 7 ), hb_parc( 8 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void *xcb_change_property_data (const xcb_change_property_request_t *R);

// int xcb_change_property_data_length (const xcb_change_property_request_t *R);

// xcb_generic_iterator_t xcb_change_property_data_end (const xcb_change_property_request_t *R);

// xcb_void_cookie_t xcb_delete_property_checked (xcb_connection_t *c, xcb_window_t window, xcb_atom_t property);

// xcb_void_cookie_t xcb_delete_property (xcb_connection_t *c, xcb_window_t window, xcb_atom_t property);

// int xcb_get_property_sizeof (const void *_buffer);

// xcb_get_property_cookie_t xcb_get_property (xcb_connection_t *c, uint8_t _delete, xcb_window_t window, xcb_atom_t property, xcb_atom_t type, uint32_t long_offset, uint32_t long_length);

// xcb_get_property_cookie_t xcb_get_property_unchecked (xcb_connection_t *c,  uint8_t _delete, xcb_window_t window, xcb_atom_t property, xcb_atom_t type, uint32_t long_offset, uint32_t long_length);

// void *xcb_get_property_value (const xcb_get_property_reply_t *R);

// int xcb_get_property_value_length (const xcb_get_property_reply_t *R);

// xcb_generic_iterator_t xcb_get_property_value_end (const xcb_get_property_reply_t *R);

// xcb_get_property_reply_t *xcb_get_property_reply (xcb_connection_t *c, xcb_get_property_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_list_properties_sizeof (const void *_buffer);

// xcb_list_properties_cookie_t xcb_list_properties (xcb_connection_t *c, xcb_window_t window);

// xcb_list_properties_cookie_t xcb_list_properties_unchecked (xcb_connection_t *c, xcb_window_t window);

// xcb_atom_t *xcb_list_properties_atoms (const xcb_list_properties_reply_t *R);

// int xcb_list_properties_atoms_length (const xcb_list_properties_reply_t *R);

// xcb_generic_iterator_t xcb_list_properties_atoms_end (const xcb_list_properties_reply_t *R);

// xcb_list_properties_reply_t *xcb_list_properties_reply (xcb_connection_t *c, xcb_list_properties_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_set_selection_owner_checked (xcb_connection_t *c, xcb_window_t owner, xcb_atom_t selection, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_set_selection_owner (xcb_connection_t *c, xcb_window_t owner, xcb_atom_t selection, xcb_timestamp_t   time);

// xcb_get_selection_owner_cookie_t xcb_get_selection_owner (xcb_connection_t *c, xcb_atom_t selection);

// xcb_get_selection_owner_cookie_t xcb_get_selection_owner_unchecked (xcb_connection_t *c, xcb_atom_t selection);

// xcb_get_selection_owner_reply_t *xcb_get_selection_owner_reply (xcb_connection_t *c, xcb_get_selection_owner_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_convert_selection_checked (xcb_connection_t *c, xcb_window_t requestor, xcb_atom_t selection, xcb_atom_t target, xcb_atom_t property, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_convert_selection (xcb_connection_t *c, xcb_window_t requestor, xcb_atom_t selection, xcb_atom_t target, xcb_atom_t property, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_send_event_checked (xcb_connection_t *c, uint8_t propagate, xcb_window_t destination, uint32_t event_mask, const char *event);

// xcb_void_cookie_t xcb_send_event (xcb_connection_t *c, uint8_t propagate, xcb_window_t destination, uint32_t event_mask, const char *event);

// xcb_grab_pointer_cookie_t xcb_grab_pointer (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, uint16_t event_mask, uint8_t pointer_mode, uint8_t keyboard_mode, xcb_window_t confine_to, xcb_cursor_t cursor, xcb_timestamp_t time);

// xcb_grab_pointer_cookie_t xcb_grab_pointer_unchecked (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, uint16_t event_mask, uint8_t pointer_mode, uint8_t keyboard_mode, xcb_window_t confine_to, xcb_cursor_t cursor, xcb_timestamp_t time);

// xcb_grab_pointer_reply_t *xcb_grab_pointer_reply (xcb_connection_t *c, xcb_grab_pointer_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_ungrab_pointer_checked (xcb_connection_t *c, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_ungrab_pointer (xcb_connection_t *c, xcb_timestamp_t   time);

// xcb_void_cookie_t xcb_grab_button_checked (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, uint16_t event_mask, uint8_t pointer_mode, uint8_t keyboard_mode, xcb_window_t confine_to, xcb_cursor_t cursor, uint8_t button, uint16_t modifiers);

// xcb_void_cookie_t xcb_grab_button (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, uint16_t event_mask, uint8_t pointer_mode, uint8_t keyboard_mode, xcb_window_t confine_to, xcb_cursor_t cursor, uint8_t button, uint16_t modifiers);

// xcb_void_cookie_t xcb_ungrab_button_checked (xcb_connection_t *c, uint8_t button, xcb_window_t grab_window, uint16_t modifiers);

// xcb_void_cookie_t xcb_ungrab_button (xcb_connection_t *c, uint8_t button, xcb_window_t grab_window, uint16_t modifiers);

// xcb_void_cookie_t xcb_change_active_pointer_grab_checked (xcb_connection_t *c, xcb_cursor_t cursor, xcb_timestamp_t time, uint16_t event_mask);

// xcb_void_cookie_t xcb_change_active_pointer_grab (xcb_connection_t *c, xcb_cursor_t cursor, xcb_timestamp_t time, uint16_t event_mask);

// xcb_grab_keyboard_cookie_t xcb_grab_keyboard (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, xcb_timestamp_t time, uint8_t pointer_mode, uint8_t keyboard_mode);

// xcb_grab_keyboard_cookie_t xcb_grab_keyboard_unchecked (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, xcb_timestamp_t time, uint8_t pointer_mode, uint8_t keyboard_mode);

// xcb_grab_keyboard_reply_t *xcb_grab_keyboard_reply (xcb_connection_t *c, xcb_grab_keyboard_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_ungrab_keyboard_checked (xcb_connection_t *c, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_ungrab_keyboard (xcb_connection_t *c, xcb_timestamp_t   time);

// xcb_void_cookie_t xcb_grab_key_checked (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, uint16_t modifiers, xcb_keycode_t key, uint8_t pointer_mode, uint8_t keyboard_mode);

// xcb_void_cookie_t xcb_grab_key (xcb_connection_t *c, uint8_t owner_events, xcb_window_t grab_window, uint16_t modifiers, xcb_keycode_t key, uint8_t pointer_mode, uint8_t keyboard_mode);

// xcb_void_cookie_t xcb_ungrab_key_checked (xcb_connection_t *c, xcb_keycode_t key, xcb_window_t grab_window, uint16_t modifiers);

// xcb_void_cookie_t xcb_ungrab_key (xcb_connection_t *c, xcb_keycode_t key, xcb_window_t grab_window, uint16_t modifiers);

// xcb_void_cookie_t xcb_allow_events_checked (xcb_connection_t *c, uint8_t mode, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_allow_events (xcb_connection_t *c, uint8_t mode, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_grab_server_checked (xcb_connection_t *c);

// xcb_void_cookie_t xcb_grab_server (xcb_connection_t *c);

// xcb_void_cookie_t xcb_ungrab_server_checked (xcb_connection_t *c);

// xcb_void_cookie_t xcb_ungrab_server (xcb_connection_t *c);

// xcb_query_pointer_cookie_t xcb_query_pointer (xcb_connection_t *c, xcb_window_t window);

// xcb_query_pointer_cookie_t xcb_query_pointer_unchecked (xcb_connection_t *c, xcb_window_t window);

// xcb_query_pointer_reply_t *xcb_query_pointer_reply (xcb_connection_t *c, xcb_query_pointer_cookie_t cookie /**< */, xcb_generic_error_t **e);

// void xcb_timecoord_next (xcb_timecoord_iterator_t *i);

// xcb_generic_iterator_t xcb_timecoord_end (xcb_timecoord_iterator_t i);

// int xcb_get_motion_events_sizeof (const void *_buffer);

// xcb_get_motion_events_cookie_t xcb_get_motion_events (xcb_connection_t *c, xcb_window_t window, xcb_timestamp_t start, xcb_timestamp_t stop);

// xcb_get_motion_events_cookie_t xcb_get_motion_events_unchecked (xcb_connection_t *c, xcb_window_t window, xcb_timestamp_t start, xcb_timestamp_t stop);

// xcb_timecoord_t *xcb_get_motion_events_events (const xcb_get_motion_events_reply_t *R);

// int xcb_get_motion_events_events_length (const xcb_get_motion_events_reply_t *R);

// xcb_timecoord_iterator_t xcb_get_motion_events_events_iterator (const xcb_get_motion_events_reply_t *R);

// xcb_get_motion_events_reply_t *xcb_get_motion_events_reply (xcb_connection_t *c, xcb_get_motion_events_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_translate_coordinates_cookie_t xcb_translate_coordinates (xcb_connection_t *c, xcb_window_t src_window, xcb_window_t dst_window, int16_t src_x, int16_t src_y);

// xcb_translate_coordinates_cookie_t xcb_translate_coordinates_unchecked (xcb_connection_t *c, xcb_window_t src_window, xcb_window_t dst_window, int16_t src_x, int16_t src_y);

// xcb_translate_coordinates_reply_t *xcb_translate_coordinates_reply (xcb_connection_t *c, xcb_translate_coordinates_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_warp_pointer_checked (xcb_connection_t *c, xcb_window_t src_window, xcb_window_t dst_window, int16_t src_x, int16_t src_y, uint16_t src_width, uint16_t src_height, int16_t dst_x, int16_t dst_y);

// xcb_void_cookie_t xcb_warp_pointer (xcb_connection_t *c, xcb_window_t src_window, xcb_window_t dst_window, int16_t src_x, int16_t src_y, uint16_t src_width, uint16_t src_height, int16_t dst_x, int16_t dst_y);

// xcb_void_cookie_t xcb_set_input_focus_checked (xcb_connection_t *c, uint8_t revert_to, xcb_window_t focus, xcb_timestamp_t time);

// xcb_void_cookie_t xcb_set_input_focus (xcb_connection_t *c, uint8_t revert_to, xcb_window_t focus, xcb_timestamp_t time);

// xcb_get_input_focus_cookie_t xcb_get_input_focus (xcb_connection_t *c);

// xcb_get_input_focus_cookie_t xcb_get_input_focus_unchecked (xcb_connection_t *c);

// xcb_get_input_focus_reply_t *xcb_get_input_focus_reply (xcb_connection_t *c, xcb_get_input_focus_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_query_keymap_cookie_t xcb_query_keymap (xcb_connection_t *c);

// xcb_query_keymap_cookie_t xcb_query_keymap_unchecked (xcb_connection_t *c);

// xcb_query_keymap_reply_t *xcb_query_keymap_reply (xcb_connection_t *c, xcb_query_keymap_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_open_font_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_open_font_checked (xcb_connection_t *c, xcb_font_t fid, uint16_t name_len, const char *name);
HB_FUNC( XCB_OPEN_FONT_CHECKED )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_STRING ) != NULL )
   {
      xcb_void_cookie_t cookie = xcb_open_font_checked( connection, ( xcb_font_t ) hb_parni( 2 ), ( uint16_t ) hb_parni( 3 ), hb_parc( 4 ) );

      PHB_ITEM pItem = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_open_font (xcb_connection_t *c, xcb_font_t fid, uint16_t name_len, const char *name);
HB_FUNC( XCB_OPEN_FONT )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_STRING ) != NULL )
   {
      xcb_open_font( connection, ( xcb_font_t ) hb_parni( 2 ), ( uint16_t ) hb_parni( 3 ), hb_parc( 4 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// char *xcb_open_font_name (const xcb_open_font_request_t *R);

// int xcb_open_font_name_length (const xcb_open_font_request_t *R);

// xcb_generic_iterator_t xcb_open_font_name_end (const xcb_open_font_request_t *R);

// xcb_void_cookie_t xcb_close_font_checked (xcb_connection_t *c, xcb_font_t font);
HB_FUNC( XCB_CLOSE_FONT_CHECKED )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      xcb_void_cookie_t cookie = xcb_close_font_checked( connection, ( xcb_font_t ) hb_parni( 2 ) );

      PHB_ITEM pItem = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_close_font (xcb_connection_t *c, xcb_font_t font);
HB_FUNC( XCB_CLOSE_FONT )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      xcb_close_font( connection, ( xcb_font_t ) hb_parni( 2 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void xcb_fontprop_next (xcb_fontprop_iterator_t *i);

// xcb_generic_iterator_t xcb_fontprop_end (xcb_fontprop_iterator_t i);

// void xcb_charinfo_next (xcb_charinfo_iterator_t *i);

// xcb_generic_iterator_t xcb_charinfo_end (xcb_charinfo_iterator_t i);

// int xcb_query_font_sizeof (const void *_buffer);

// xcb_query_font_cookie_t xcb_query_font (xcb_connection_t *c, xcb_fontable_t font);

// xcb_query_font_cookie_t xcb_query_font_unchecked (xcb_connection_t *c, xcb_fontable_t font);

// xcb_fontprop_t *xcb_query_font_properties (const xcb_query_font_reply_t *R);

// int xcb_query_font_properties_length (const xcb_query_font_reply_t *R);

// xcb_fontprop_iterator_t xcb_query_font_properties_iterator (const xcb_query_font_reply_t *R);

// xcb_charinfo_t *xcb_query_font_char_infos (const xcb_query_font_reply_t *R);

// int xcb_query_font_char_infos_length (const xcb_query_font_reply_t *R);

// xcb_charinfo_iterator_t xcb_query_font_char_infos_iterator (const xcb_query_font_reply_t *R);

// xcb_query_font_reply_t *xcb_query_font_reply (xcb_connection_t *c, xcb_query_font_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_query_text_extents_sizeof (const void *_buffer, uint32_t string_len);

// xcb_query_text_extents_cookie_t xcb_query_text_extents (xcb_connection_t *c, xcb_fontable_t font, uint32_t string_len, const xcb_char2b_t *string);
HB_FUNC( XCB_QUERY_TEXT_EXTENTS )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection && hb_param( 2, HB_IT_INTEGER ) != NULL &&
                     hb_param( 3, HB_IT_INTEGER ) != NULL &&
           ( pItem = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      xcb_char2b_t char2b;

      char2b.byte1 = ( uint8_t ) hb_arrayGetNI( pItem, 1 );
      char2b.byte2 = ( uint8_t ) hb_arrayGetNI( pItem, 2 );

      xcb_query_text_extents_cookie_t cookie = xcb_query_text_extents( connection, ( xcb_fontable_t ) hb_parni( 2 ), ( uint32_t ) hb_parni( 3 ), &char2b );

      PHB_ITEM pItem1 = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem1, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem1 );
   }
   else
   {
      HB_ERR_ARGS();
   }
}


// xcb_query_text_extents_cookie_t xcb_query_text_extents_unchecked (xcb_connection_t *c, xcb_fontable_t font, uint32_t string_len, const xcb_char2b_t *string);

// xcb_query_text_extents_reply_t *xcb_query_text_extents_reply (xcb_connection_t *c, xcb_query_text_extents_cookie_t cookie /**< */, xcb_generic_error_t **e);
HB_FUNC( XCB_QUERY_TEXT_EXTENTS_REPLY )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection && ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 1 )
   {
      xcb_query_text_extents_cookie_t cookie;

      cookie.sequence = ( unsigned int ) hb_arrayGetNI( pItem, 1 );

      xcb_query_text_extents_reply( connection, cookie, NULL );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int xcb_str_sizeof (const void *_buffer);

// char *xcb_str_name (const xcb_str_t *R);

// int xcb_str_name_length (const xcb_str_t *R);

// xcb_generic_iterator_t xcb_str_name_end (const xcb_str_t *R);

// void xcb_str_next (xcb_str_iterator_t *i);

// xcb_generic_iterator_t xcb_str_end (xcb_str_iterator_t i);

// int xcb_list_fonts_sizeof (const void *_buffer);

// xcb_list_fonts_cookie_t xcb_list_fonts (xcb_connection_t *c, uint16_t max_names, uint16_t pattern_len, const char *pattern);

// xcb_list_fonts_cookie_t xcb_list_fonts_unchecked (xcb_connection_t *c, uint16_t max_names, uint16_t pattern_len, const char *pattern);

// int xcb_list_fonts_names_length (const xcb_list_fonts_reply_t *R);

// xcb_str_iterator_t xcb_list_fonts_names_iterator (const xcb_list_fonts_reply_t *R);

// xcb_list_fonts_reply_t *xcb_list_fonts_reply (xcb_connection_t *c, xcb_list_fonts_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_list_fonts_with_info_sizeof (const void *_buffer);

// xcb_list_fonts_with_info_cookie_t xcb_list_fonts_with_info (xcb_connection_t *c, uint16_t max_names, uint16_t pattern_len, const char *pattern);

// xcb_list_fonts_with_info_cookie_t xcb_list_fonts_with_info_unchecked (xcb_connection_t *c, uint16_t max_names, uint16_t pattern_len, const char *pattern);

// xcb_fontprop_t *xcb_list_fonts_with_info_properties (const xcb_list_fonts_with_info_reply_t *R);

// int xcb_list_fonts_with_info_properties_length (const xcb_list_fonts_with_info_reply_t *R);

// xcb_fontprop_iterator_t xcb_list_fonts_with_info_properties_iterator (const xcb_list_fonts_with_info_reply_t *R);

// char *xcb_list_fonts_with_info_name (const xcb_list_fonts_with_info_reply_t *R);

// int xcb_list_fonts_with_info_name_length (const xcb_list_fonts_with_info_reply_t *R);

// xcb_generic_iterator_t xcb_list_fonts_with_info_name_end (const xcb_list_fonts_with_info_reply_t *R);

// xcb_list_fonts_with_info_reply_t *xcb_list_fonts_with_info_reply (xcb_connection_t *c, xcb_list_fonts_with_info_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_set_font_path_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_set_font_path_checked (xcb_connection_t *c, uint16_t font_qty, const xcb_str_t *font);

// xcb_void_cookie_t xcb_set_font_path (xcb_connection_t *c, uint16_t font_qty, const xcb_str_t *font);

// int xcb_set_font_path_font_length (const xcb_set_font_path_request_t *R);

// xcb_str_iterator_t xcb_set_font_path_font_iterator (const xcb_set_font_path_request_t *R);

// int xcb_get_font_path_sizeof (const void *_buffer);

// xcb_get_font_path_cookie_t xcb_get_font_path (xcb_connection_t *c);

// xcb_get_font_path_cookie_t xcb_get_font_path_unchecked (xcb_connection_t *c);

// int xcb_get_font_path_path_length (const xcb_get_font_path_reply_t *R);

// xcb_str_iterator_t xcb_get_font_path_path_iterator (const xcb_get_font_path_reply_t *R);

// xcb_get_font_path_reply_t *xcb_get_font_path_reply (xcb_connection_t *c, xcb_get_font_path_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_create_pixmap_checked (xcb_connection_t *c, uint8_t depth, xcb_pixmap_t pid, xcb_drawable_t drawable, uint16_t width, uint16_t height);

// xcb_void_cookie_t xcb_create_pixmap (xcb_connection_t *c, uint8_t depth, xcb_pixmap_t pid, xcb_drawable_t drawable, uint16_t width, uint16_t height);

// xcb_void_cookie_t xcb_free_pixmap_checked (xcb_connection_t *c, xcb_pixmap_t pixmap);

// xcb_void_cookie_t xcb_free_pixmap (xcb_connection_t *c, xcb_pixmap_t pixmap);

// int xcb_create_gc_value_list_serialize (void **_buffer, uint32_t value_mask, const xcb_create_gc_value_list_t *_aux);

// int xcb_create_gc_value_list_unpack (const void *_buffer, uint32_t value_mask, xcb_create_gc_value_list_t *_aux);

// int xcb_create_gc_value_list_sizeof (const void *_buffer, uint32_t value_mask);

// int xcb_create_gc_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_create_gc_checked (xcb_connection_t *c, xcb_gcontext_t cid, xcb_drawable_t drawable, uint32_t value_mask, const void *value_list);
HB_FUNC( XCB_CREATE_GC_CHECKED )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL && ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL )
   {
      HB_SIZE nLength = hb_arrayLen( pItem );

      uint32_t values[ nLength ];

      for ( size_t i = 0; i < nLength; i++ )
      {
         values[ i ] = hb_arrayGetNI( pItem, i + 1 );
      }

      xcb_void_cookie_t cookie = xcb_create_gc_checked( connection, ( xcb_gcontext_t ) hb_parni( 2 ), ( xcb_drawable_t ) hb_parni( 3 ), ( uint32_t ) hb_parni( 4 ), values );

      PHB_ITEM pItem = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_create_gc (xcb_connection_t *c, xcb_gcontext_t cid, xcb_drawable_t drawable, uint32_t value_mask, const void *value_list);
HB_FUNC( XCB_CREATE_GC )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL && ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL )
   {
      HB_SIZE nLength = hb_arrayLen( pItem );

      uint32_t values[ nLength ];

      for ( size_t i = 0; i < nLength; i++ )
      {
         values[ i ] = hb_arrayGetNI( pItem, i + 1 );
      }

      xcb_create_gc( connection, ( xcb_gcontext_t ) hb_parni( 2 ), ( xcb_drawable_t ) hb_parni( 3 ), ( uint32_t ) hb_parni( 4 ), values );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_create_gc_aux_checked (xcb_connection_t *c, xcb_gcontext_t cid, xcb_drawable_t drawable, uint32_t value_mask, const xcb_create_gc_value_list_t *value_list);

// xcb_void_cookie_t xcb_create_gc_aux (xcb_connection_t *c, xcb_gcontext_t cid, xcb_drawable_t drawable, uint32_t value_mask, const xcb_create_gc_value_list_t *value_list);

// void *xcb_create_gc_value_list (const xcb_create_gc_request_t *R);

// int xcb_change_gc_value_list_serialize (void **_buffer, uint32_t value_mask, const xcb_change_gc_value_list_t *_aux);

// int xcb_change_gc_value_list_unpack (const void *_buffer, uint32_t value_mask, xcb_change_gc_value_list_t *_aux);

// int xcb_change_gc_value_list_sizeof (const void *_buffer, uint32_t value_mask);

// int xcb_change_gc_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_change_gc_checked (xcb_connection_t *c, xcb_gcontext_t gc, uint32_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_change_gc (xcb_connection_t *c, xcb_gcontext_t gc, uint32_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_change_gc_aux_checked (xcb_connection_t *c, xcb_gcontext_t gc, uint32_t value_mask, const xcb_change_gc_value_list_t *value_list);

// xcb_void_cookie_t xcb_change_gc_aux (xcb_connection_t *c, xcb_gcontext_t gc, uint32_t value_mask, const xcb_change_gc_value_list_t *value_list);

// void *xcb_change_gc_value_list (const xcb_change_gc_request_t *R);

// xcb_void_cookie_t xcb_copy_gc_checked (xcb_connection_t *c, xcb_gcontext_t src_gc, xcb_gcontext_t dst_gc, uint32_t value_mask);

// xcb_void_cookie_t xcb_copy_gc (xcb_connection_t *c, xcb_gcontext_t src_gc, xcb_gcontext_t dst_gc, uint32_t value_mask);

// int xcb_set_dashes_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_set_dashes_checked (xcb_connection_t *c, xcb_gcontext_t gc, uint16_t dash_offset, uint16_t dashes_len, const uint8_t *dashes);

// xcb_void_cookie_t xcb_set_dashes (xcb_connection_t *c, xcb_gcontext_t gc, uint16_t dash_offset, uint16_t dashes_len, const uint8_t *dashes);

// uint8_t *xcb_set_dashes_dashes (const xcb_set_dashes_request_t *R);

// int xcb_set_dashes_dashes_length (const xcb_set_dashes_request_t *R);

// xcb_generic_iterator_t xcb_set_dashes_dashes_end (const xcb_set_dashes_request_t *R);

// int xcb_set_clip_rectangles_sizeof (const void *_buffer, uint32_t rectangles_len);

// xcb_void_cookie_t xcb_set_clip_rectangles_checked (xcb_connection_t *c, uint8_t ordering, xcb_gcontext_t gc, int16_t clip_x_origin, int16_t clip_y_origin, uint32_t rectangles_len, const xcb_rectangle_t *rectangles);

// xcb_void_cookie_t xcb_set_clip_rectangles (xcb_connection_t *c, uint8_t ordering, xcb_gcontext_t gc, int16_t clip_x_origin, int16_t clip_y_origin, uint32_t rectangles_len, const xcb_rectangle_t *rectangles);

// xcb_rectangle_t *xcb_set_clip_rectangles_rectangles (const xcb_set_clip_rectangles_request_t *R);

// int xcb_set_clip_rectangles_rectangles_length (const xcb_set_clip_rectangles_request_t *R);

// xcb_rectangle_iterator_t xcb_set_clip_rectangles_rectangles_iterator (const xcb_set_clip_rectangles_request_t *R);

// xcb_void_cookie_t xcb_free_gc_checked (xcb_connection_t *c, xcb_gcontext_t gc);
HB_FUNC( XCB_FREE_GC_CHECKED )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      xcb_void_cookie_t cookie = xcb_free_gc_checked( connection, ( xcb_gcontext_t ) hb_parni( 2 ) );

      PHB_ITEM pItem = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_free_gc (xcb_connection_t *c, xcb_gcontext_t gc);
HB_FUNC( XCB_FREE_GC )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      xcb_free_gc( connection, ( xcb_gcontext_t ) hb_parni( 2 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_clear_area_checked (xcb_connection_t *c, uint8_t exposures, xcb_window_t window, int16_t x, int16_t y, uint16_t width, uint16_t height);

// xcb_void_cookie_t xcb_clear_area (xcb_connection_t *c, uint8_t exposures, xcb_window_t window, int16_t x, int16_t y, uint16_t width, uint16_t height);

// xcb_void_cookie_t xcb_copy_area_checked (xcb_connection_t *c, xcb_drawable_t src_drawable, xcb_drawable_t dst_drawable, xcb_gcontext_t gc, int16_t src_x, int16_t src_y, int16_t dst_x, int16_t dst_y, uint16_t width, uint16_t height);

// xcb_void_cookie_t xcb_copy_area (xcb_connection_t *c, xcb_drawable_t src_drawable, xcb_drawable_t dst_drawable, xcb_gcontext_t gc, int16_t src_x, int16_t src_y, int16_t dst_x, int16_t dst_y, uint16_t width, uint16_t height);

// xcb_void_cookie_t xcb_copy_plane_checked (xcb_connection_t *c, xcb_drawable_t src_drawable, xcb_drawable_t dst_drawable, xcb_gcontext_t gc, int16_t src_x, int16_t src_y, int16_t dst_x, int16_t dst_y, uint16_t width, uint16_t height, uint32_t bit_plane);

// xcb_void_cookie_t xcb_copy_plane (xcb_connection_t *c, xcb_drawable_t src_drawable, xcb_drawable_t dst_drawable, xcb_gcontext_t gc, int16_t src_x, int16_t src_y, int16_t dst_x, int16_t dst_y, uint16_t width, uint16_t height, uint32_t bit_plane);

// int xcb_poly_point_sizeof (const void *_buffer, uint32_t points_len);

// xcb_void_cookie_t xcb_poly_point_checked (xcb_connection_t *c, uint8_t coordinate_mode, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t points_len, const xcb_point_t *points);

// xcb_void_cookie_t xcb_poly_point (xcb_connection_t *c, uint8_t coordinate_mode, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t points_len, const xcb_point_t *points);

// xcb_point_t *xcb_poly_point_points (const xcb_poly_point_request_t *R);

// int xcb_poly_point_points_length (const xcb_poly_point_request_t *R);

// xcb_point_iterator_t xcb_poly_point_points_iterator (const xcb_poly_point_request_t *R);

// int xcb_poly_line_sizeof (const void *_buffer, uint32_t points_len);

// xcb_void_cookie_t xcb_poly_line_checked (xcb_connection_t *c, uint8_t coordinate_mode, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t points_len, const xcb_point_t *points);

// xcb_void_cookie_t xcb_poly_line (xcb_connection_t *c, uint8_t coordinate_mode, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t points_len, const xcb_point_t *points);

// xcb_point_t *xcb_poly_line_points (const xcb_poly_line_request_t *R);

// int xcb_poly_line_points_length (const xcb_poly_line_request_t *R);

// xcb_point_iterator_t xcb_poly_line_points_iterator (const xcb_poly_line_request_t *R);

// void xcb_segment_next (xcb_segment_iterator_t *i);

// xcb_generic_iterator_t xcb_segment_end (xcb_segment_iterator_t i);

// int xcb_poly_segment_sizeof (const void *_buffer, uint32_t segments_len);

// xcb_void_cookie_t xcb_poly_segment_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t segments_len, const xcb_segment_t *segments);

// xcb_void_cookie_t xcb_poly_segment (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t segments_len, const xcb_segment_t *segments);

// xcb_segment_t *xcb_poly_segment_segments (const xcb_poly_segment_request_t *R);

// int xcb_poly_segment_segments_length (const xcb_poly_segment_request_t *R);

// xcb_segment_iterator_t xcb_poly_segment_segments_iterator (const xcb_poly_segment_request_t *R);

// int xcb_poly_rectangle_sizeof (const void *_buffer, uint32_t rectangles_len);

// xcb_void_cookie_t xcb_poly_rectangle_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t rectangles_len, const xcb_rectangle_t *rectangles);

// xcb_void_cookie_t xcb_poly_rectangle (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t rectangles_len, const xcb_rectangle_t *rectangles);
HB_FUNC( XCB_POLY_RECTANGLE )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      xcb_rectangle_t rectangles;
      memset( &rectangles, 0, sizeof( rectangles ) );

      rectangles.x      = ( int16_t )  hb_arrayGetNI( pItem, 1 );
      rectangles.y      = ( int16_t )  hb_arrayGetNI( pItem, 2 );
      rectangles.width  = ( uint16_t ) hb_arrayGetNI( pItem, 3 );
      rectangles.height = ( uint16_t ) hb_arrayGetNI( pItem, 4 );

      xcb_poly_rectangle( connection, ( xcb_drawable_t ) hb_parni( 2 ), ( xcb_gcontext_t ) hb_parni( 3 ), ( uint32_t ) hb_parni( 4 ), &rectangles );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_rectangle_t *xcb_poly_rectangle_rectangles (const xcb_poly_rectangle_request_t *R);

// int xcb_poly_rectangle_rectangles_length (const xcb_poly_rectangle_request_t *R);

// xcb_rectangle_iterator_t xcb_poly_rectangle_rectangles_iterator (const xcb_poly_rectangle_request_t *R);

// int xcb_poly_arc_sizeof (const void *_buffer, uint32_t arcs_len);

// xcb_void_cookie_t xcb_poly_arc_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t arcs_len, const xcb_arc_t *arcs);

// xcb_void_cookie_t xcb_poly_arc (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t arcs_len, const xcb_arc_t *arcs);

// xcb_arc_t *xcb_poly_arc_arcs (const xcb_poly_arc_request_t *R);

// int xcb_poly_arc_arcs_length (const xcb_poly_arc_request_t *R);

// xcb_arc_iterator_t xcb_poly_arc_arcs_iterator (const xcb_poly_arc_request_t *R);

// int xcb_fill_poly_sizeof (const void *_buffer, uint32_t points_len);

// xcb_void_cookie_t xcb_fill_poly_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint8_t shape, uint8_t coordinate_mode, uint32_t points_len, const xcb_point_t *points);

// xcb_void_cookie_t xcb_fill_poly (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint8_t shape, uint8_t coordinate_mode, uint32_t points_len, const xcb_point_t *points);

// xcb_point_t *xcb_fill_poly_points (const xcb_fill_poly_request_t *R);

// int xcb_fill_poly_points_length (const xcb_fill_poly_request_t *R);

// xcb_point_iterator_t xcb_fill_poly_points_iterator (const xcb_fill_poly_request_t *R);

// int xcb_poly_fill_rectangle_sizeof (const void *_buffer, uint32_t rectangles_len);

// xcb_void_cookie_t xcb_poly_fill_rectangle_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t rectangles_len, const xcb_rectangle_t *rectangles);

// xcb_void_cookie_t xcb_poly_fill_rectangle (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t rectangles_len, const xcb_rectangle_t *rectangles);
HB_FUNC( XCB_POLY_FILL_RECTANGLE )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );
   PHB_ITEM pItem;

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      xcb_rectangle_t rectangles;
      memset( &rectangles, 0, sizeof( rectangles ) );

      rectangles.x      = ( int16_t )  hb_arrayGetNI( pItem, 1 );
      rectangles.y      = ( int16_t )  hb_arrayGetNI( pItem, 2 );
      rectangles.width  = ( uint16_t ) hb_arrayGetNI( pItem, 3 );
      rectangles.height = ( uint16_t ) hb_arrayGetNI( pItem, 4 );

      xcb_poly_fill_rectangle( connection, ( xcb_drawable_t ) hb_parni( 2 ), ( xcb_gcontext_t ) hb_parni( 3 ), ( uint32_t ) hb_parni( 4 ), &rectangles );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_rectangle_t *xcb_poly_fill_rectangle_rectangles (const xcb_poly_fill_rectangle_request_t *R);

// int xcb_poly_fill_rectangle_rectangles_length (const xcb_poly_fill_rectangle_request_t *R);

// xcb_rectangle_iterator_t xcb_poly_fill_rectangle_rectangles_iterator (const xcb_poly_fill_rectangle_request_t *R);

// int xcb_poly_fill_arc_sizeof (const void *_buffer, uint32_t arcs_len);

// xcb_void_cookie_t xcb_poly_fill_arc_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t arcs_len, const xcb_arc_t *arcs);

// xcb_void_cookie_t xcb_poly_fill_arc (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, uint32_t arcs_len, const xcb_arc_t *arcs);

// xcb_arc_t *xcb_poly_fill_arc_arcs (const xcb_poly_fill_arc_request_t *R);

// int xcb_poly_fill_arc_arcs_length (const xcb_poly_fill_arc_request_t *R);

// xcb_arc_iterator_t xcb_poly_fill_arc_arcs_iterator (const xcb_poly_fill_arc_request_t *R);

// int xcb_put_image_sizeof (const void *_buffer, uint32_t data_len);

// xcb_void_cookie_t xcb_put_image_checked (xcb_connection_t *c, uint8_t format, xcb_drawable_t drawable, xcb_gcontext_t gc, uint16_t width, uint16_t height, int16_t dst_x, int16_t dst_y, uint8_t left_pad, uint8_t depth, uint32_t data_len, const uint8_t *data);

// xcb_void_cookie_t xcb_put_image (xcb_connection_t *c, uint8_t format, xcb_drawable_t drawable, xcb_gcontext_t gc, uint16_t width, uint16_t height, int16_t dst_x, int16_t dst_y, uint8_t left_pad, uint8_t depth, uint32_t data_len, const uint8_t *data);

// uint8_t *xcb_put_image_data (const xcb_put_image_request_t *R);

// int xcb_put_image_data_length (const xcb_put_image_request_t *R);

// xcb_generic_iterator_t xcb_put_image_data_end (const xcb_put_image_request_t *R);

// int xcb_get_image_sizeof (const void *_buffer);

// xcb_get_image_cookie_t xcb_get_image (xcb_connection_t *c, uint8_t format, xcb_drawable_t drawable, int16_t x, int16_t y, uint16_t width, uint16_t height, uint32_t plane_mask);

// xcb_get_image_cookie_t xcb_get_image_unchecked (xcb_connection_t *c,  uint8_t format, xcb_drawable_t drawable, int16_t x, int16_t y, uint16_t width, uint16_t height, uint32_t plane_mask);

// uint8_t *xcb_get_image_data (const xcb_get_image_reply_t *R);

// int xcb_get_image_data_length (const xcb_get_image_reply_t *R);

// xcb_generic_iterator_t xcb_get_image_data_end (const xcb_get_image_reply_t *R);

// xcb_get_image_reply_t *xcb_get_image_reply (xcb_connection_t *c, xcb_get_image_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_poly_text_8_sizeof (const void *_buffer, uint32_t items_len);

// xcb_void_cookie_t xcb_poly_text_8_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, uint32_t items_len, const uint8_t *items);

// xcb_void_cookie_t xcb_poly_text_8 (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, uint32_t items_len, const uint8_t *items);

// uint8_t *xcb_poly_text_8_items (const xcb_poly_text_8_request_t *R);

// int xcb_poly_text_8_items_length (const xcb_poly_text_8_request_t *R);

// xcb_generic_iterator_t xcb_poly_text_8_items_end (const xcb_poly_text_8_request_t *R);

// int xcb_poly_text_16_sizeof (const void *_buffer, uint32_t items_len);

// xcb_void_cookie_t xcb_poly_text_16_checked (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, uint32_t items_len, const uint8_t *items);

// xcb_void_cookie_t xcb_poly_text_16 (xcb_connection_t *c, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, uint32_t items_len, const uint8_t *items);

// uint8_t *xcb_poly_text_16_items (const xcb_poly_text_16_request_t *R);

// int xcb_poly_text_16_items_length (const xcb_poly_text_16_request_t *R);

// xcb_generic_iterator_t xcb_poly_text_16_items_end (const xcb_poly_text_16_request_t *R);

// int xcb_image_text_8_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_image_text_8_checked (xcb_connection_t *c, uint8_t string_len, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, const char *string);
HB_FUNC( XCB_IMAGE_TEXT_8_CHECKED )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_STRING ) != NULL )
   {
      xcb_void_cookie_t cookie = xcb_image_text_8_checked( connection, ( uint8_t ) hb_parni( 2 ), ( xcb_drawable_t ) hb_parni( 3 ), ( xcb_gcontext_t ) hb_parni( 4 ),
         ( int16_t ) hb_parni( 5 ), ( int16_t ) hb_parni( 6 ), hb_parc( 7 ) );

      PHB_ITEM pItem = hb_itemArrayNew( 1 );
      hb_arraySetNI( pItem, 1, ( unsigned int ) cookie.sequence );
      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// xcb_void_cookie_t xcb_image_text_8 (xcb_connection_t *c, uint8_t string_len, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, const char *string);
HB_FUNC( XCB_IMAGE_TEXT_8 )
{
   xcb_connection_t * connection = hb_connection_Param( 1 );

   if( connection &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_STRING ) != NULL )
   {
      xcb_image_text_8( connection, ( uint8_t ) hb_parni( 2 ), ( xcb_drawable_t ) hb_parni( 3 ), ( xcb_gcontext_t ) hb_parni( 4 ),
         ( int16_t ) hb_parni( 5 ), ( int16_t ) hb_parni( 6 ), hb_parc( 7 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// char *xcb_image_text_8_string (const xcb_image_text_8_request_t *R);

// int xcb_image_text_8_string_length (const xcb_image_text_8_request_t *R);

// xcb_generic_iterator_t xcb_image_text_8_string_end (const xcb_image_text_8_request_t *R);

// int xcb_image_text_16_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_image_text_16_checked (xcb_connection_t *c, uint8_t string_len, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, const xcb_char2b_t *string);

// xcb_void_cookie_t xcb_image_text_16 (xcb_connection_t *c, uint8_t string_len, xcb_drawable_t drawable, xcb_gcontext_t gc, int16_t x, int16_t y, const xcb_char2b_t *string);


// xcb_char2b_t *xcb_image_text_16_string (const xcb_image_text_16_request_t *R);

// int xcb_image_text_16_string_length (const xcb_image_text_16_request_t *R);

// xcb_char2b_iterator_t xcb_image_text_16_string_iterator (const xcb_image_text_16_request_t *R);

// xcb_void_cookie_t xcb_create_colormap_checked (xcb_connection_t *c, uint8_t alloc, xcb_colormap_t mid, xcb_window_t window, xcb_visualid_t visual);

// xcb_void_cookie_t xcb_create_colormap (xcb_connection_t *c, uint8_t alloc, xcb_colormap_t mid, xcb_window_t window, xcb_visualid_t visual);

// xcb_void_cookie_t xcb_free_colormap_checked (xcb_connection_t *c, xcb_colormap_t cmap);

// xcb_void_cookie_t xcb_free_colormap (xcb_connection_t *c, xcb_colormap_t cmap);

// xcb_void_cookie_t xcb_copy_colormap_and_free_checked (xcb_connection_t *c, xcb_colormap_t mid, xcb_colormap_t src_cmap);

// xcb_void_cookie_t xcb_copy_colormap_and_free (xcb_connection_t *c, xcb_colormap_t mid, xcb_colormap_t src_cmap);

// xcb_void_cookie_t xcb_install_colormap_checked (xcb_connection_t *c, xcb_colormap_t cmap);

// xcb_void_cookie_t xcb_install_colormap (xcb_connection_t *c, xcb_colormap_t cmap);

// xcb_void_cookie_t xcb_uninstall_colormap_checked (xcb_connection_t *c, xcb_colormap_t cmap);

// xcb_void_cookie_t xcb_uninstall_colormap (xcb_connection_t *c, xcb_colormap_t cmap);

// int xcb_list_installed_colormaps_sizeof (const void *_buffer);

// xcb_list_installed_colormaps_cookie_t xcb_list_installed_colormaps (xcb_connection_t *c, xcb_window_t window);

// xcb_list_installed_colormaps_cookie_t xcb_list_installed_colormaps_unchecked (xcb_connection_t *c, xcb_window_t window);

// xcb_colormap_t *xcb_list_installed_colormaps_cmaps (const xcb_list_installed_colormaps_reply_t *R);

// int xcb_list_installed_colormaps_cmaps_length (const xcb_list_installed_colormaps_reply_t *R);

// xcb_generic_iterator_t xcb_list_installed_colormaps_cmaps_end (const xcb_list_installed_colormaps_reply_t *R);

// xcb_list_installed_colormaps_reply_t *xcb_list_installed_colormaps_reply (xcb_connection_t *c, xcb_list_installed_colormaps_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_alloc_color_cookie_t xcb_alloc_color (xcb_connection_t *c, xcb_colormap_t cmap, uint16_t red, uint16_t green, uint16_t blue);

// xcb_alloc_color_cookie_t xcb_alloc_color_unchecked (xcb_connection_t *c, xcb_colormap_t cmap, uint16_t red, uint16_t green, uint16_t blue);

// xcb_alloc_color_reply_t *xcb_alloc_color_reply (xcb_connection_t *c, xcb_alloc_color_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_alloc_named_color_sizeof (const void *_buffer);

// xcb_alloc_named_color_cookie_t xcb_alloc_named_color (xcb_connection_t *c, xcb_colormap_t cmap, uint16_t name_len, const char *name);

// xcb_alloc_named_color_cookie_t xcb_alloc_named_color_unchecked (xcb_connection_t *c, xcb_colormap_t cmap, uint16_t name_len, const char *name);

// xcb_alloc_named_color_reply_t *xcb_alloc_named_color_reply (xcb_connection_t *c, xcb_alloc_named_color_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_alloc_color_cells_sizeof (const void *_buffer);

// xcb_alloc_color_cells_cookie_t xcb_alloc_color_cells (xcb_connection_t *c, uint8_t contiguous, xcb_colormap_t cmap, uint16_t colors, uint16_t planes);

// xcb_alloc_color_cells_cookie_t xcb_alloc_color_cells_unchecked (xcb_connection_t *c, uint8_t contiguous, xcb_colormap_t cmap, uint16_t colors, uint16_t planes);

// uint32_t *xcb_alloc_color_cells_pixels (const xcb_alloc_color_cells_reply_t *R);

// int xcb_alloc_color_cells_pixels_length (const xcb_alloc_color_cells_reply_t *R);

// xcb_generic_iterator_t xcb_alloc_color_cells_pixels_end (const xcb_alloc_color_cells_reply_t *R);

// uint32_t *xcb_alloc_color_cells_masks (const xcb_alloc_color_cells_reply_t *R);

// int xcb_alloc_color_cells_masks_length (const xcb_alloc_color_cells_reply_t *R);

// xcb_generic_iterator_t xcb_alloc_color_cells_masks_end (const xcb_alloc_color_cells_reply_t *R);

// xcb_alloc_color_cells_reply_t *xcb_alloc_color_cells_reply (xcb_connection_t *c, xcb_alloc_color_cells_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_alloc_color_planes_sizeof (const void *_buffer);

// xcb_alloc_color_planes_cookie_t xcb_alloc_color_planes (xcb_connection_t *c, uint8_t contiguous, xcb_colormap_t cmap, uint16_t colors, uint16_t reds, uint16_t greens, uint16_t blues);

// xcb_alloc_color_planes_cookie_t xcb_alloc_color_planes_unchecked (xcb_connection_t *c, uint8_t contiguous, xcb_colormap_t cmap, uint16_t colors, uint16_t reds, uint16_t greens, uint16_t blues);

// uint32_t *xcb_alloc_color_planes_pixels (const xcb_alloc_color_planes_reply_t *R);

// int xcb_alloc_color_planes_pixels_length (const xcb_alloc_color_planes_reply_t *R);

// xcb_generic_iterator_t xcb_alloc_color_planes_pixels_end (const xcb_alloc_color_planes_reply_t *R);

// xcb_alloc_color_planes_reply_t *xcb_alloc_color_planes_reply (xcb_connection_t *c, xcb_alloc_color_planes_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_free_colors_sizeof (const void *_buffer, uint32_t pixels_len);

// xcb_void_cookie_t xcb_free_colors_checked (xcb_connection_t *c, xcb_colormap_t cmap, uint32_t plane_mask, uint32_t pixels_len, const uint32_t *pixels);

// xcb_void_cookie_t xcb_free_colors (xcb_connection_t *c, xcb_colormap_t cmap, uint32_t plane_mask, uint32_t pixels_len, const uint32_t *pixels);

// uint32_t *xcb_free_colors_pixels (const xcb_free_colors_request_t *R);

// int xcb_free_colors_pixels_length (const xcb_free_colors_request_t *R);

// xcb_generic_iterator_t xcb_free_colors_pixels_end (const xcb_free_colors_request_t *R);

// void xcb_coloritem_next (xcb_coloritem_iterator_t *i);

// xcb_generic_iterator_t xcb_coloritem_end (xcb_coloritem_iterator_t i);

// int xcb_store_colors_sizeof (const void *_buffer, uint32_t items_len);

// xcb_void_cookie_t xcb_store_colors_checked (xcb_connection_t *c, xcb_colormap_t cmap, uint32_t items_len, const xcb_coloritem_t *items);

// xcb_void_cookie_t xcb_store_colors (xcb_connection_t *c, xcb_colormap_t cmap, uint32_t items_len, const xcb_coloritem_t *items);

// xcb_coloritem_t *xcb_store_colors_items (const xcb_store_colors_request_t *R);

// int xcb_store_colors_items_length (const xcb_store_colors_request_t *R);

// xcb_coloritem_iterator_t xcb_store_colors_items_iterator (const xcb_store_colors_request_t *R);

// int xcb_store_named_color_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_store_named_color_checked (xcb_connection_t *c, uint8_t flags, xcb_colormap_t cmap, uint32_t pixel, uint16_t name_len, const char *name);

// xcb_void_cookie_t xcb_store_named_color (xcb_connection_t *c, uint8_t flags,xcb_colormap_t cmap, uint32_t pixel, uint16_t name_len, const char *name);

// char *xcb_store_named_color_name (const xcb_store_named_color_request_t *R);

// int xcb_store_named_color_name_length (const xcb_store_named_color_request_t *R);

// xcb_generic_iterator_t xcb_store_named_color_name_end (const xcb_store_named_color_request_t *R);

// void xcb_rgb_next (xcb_rgb_iterator_t *i);

// xcb_generic_iterator_t xcb_rgb_end (xcb_rgb_iterator_t i);

// int xcb_query_colors_sizeof (const void *_buffer, uint32_t pixels_len);

// xcb_query_colors_cookie_t xcb_query_colors (xcb_connection_t *c, xcb_colormap_t cmap, uint32_t pixels_len, const uint32_t *pixels);

// xcb_query_colors_cookie_t xcb_query_colors_unchecked (xcb_connection_t *c, xcb_colormap_t cmap, uint32_t pixels_len, const uint32_t *pixels);

// xcb_rgb_t *xcb_query_colors_colors (const xcb_query_colors_reply_t *R);

// int xcb_query_colors_colors_length (const xcb_query_colors_reply_t *R);

// xcb_rgb_iterator_t xcb_query_colors_colors_iterator (const xcb_query_colors_reply_t *R);

// xcb_query_colors_reply_t *xcb_query_colors_reply (xcb_connection_t *c, xcb_query_colors_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_lookup_color_sizeof (const void *_buffer);

// xcb_lookup_color_cookie_t xcb_lookup_color (xcb_connection_t *c, xcb_colormap_t cmap, uint16_t name_len, const char *name);

// xcb_lookup_color_cookie_t xcb_lookup_color_unchecked (xcb_connection_t *c, xcb_colormap_t cmap, uint16_t name_len, const char *name);

// xcb_lookup_color_reply_t *xcb_lookup_color_reply (xcb_connection_t *c, xcb_lookup_color_cookie_t cookie  /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_create_cursor_checked (xcb_connection_t *c, xcb_cursor_t cid, xcb_pixmap_t source, xcb_pixmap_t mask, uint16_t fore_red, uint16_t fore_green, uint16_t fore_blue, uint16_t back_red, uint16_t back_green, uint16_t back_blue, uint16_t x, uint16_t y);

// xcb_void_cookie_t xcb_create_cursor (xcb_connection_t *c, xcb_cursor_t cid, xcb_pixmap_t source, xcb_pixmap_t mask, uint16_t fore_red, uint16_t fore_green, uint16_t fore_blue, uint16_t back_red, uint16_t back_green, uint16_t back_blue, uint16_t x, uint16_t y);

// xcb_void_cookie_t xcb_create_glyph_cursor_checked (xcb_connection_t *c, xcb_cursor_t cid, xcb_font_t source_font, xcb_font_t mask_font, uint16_t source_char, uint16_t mask_char, uint16_t fore_red, uint16_t fore_green, uint16_t fore_blue, uint16_t back_red, uint16_t back_green, uint16_t back_blue);

// xcb_void_cookie_t xcb_create_glyph_cursor (xcb_connection_t *c, xcb_cursor_t cid, xcb_font_t source_font, xcb_font_t mask_font, uint16_t source_char, uint16_t mask_char, uint16_t fore_red, uint16_t fore_green, uint16_t fore_blue, uint16_t back_red, uint16_t back_green, uint16_t back_blue);

// xcb_void_cookie_t xcb_free_cursor_checked (xcb_connection_t *c, xcb_cursor_t cursor);

// xcb_void_cookie_t xcb_free_cursor (xcb_connection_t *c, xcb_cursor_t cursor);

// xcb_void_cookie_t xcb_recolor_cursor_checked (xcb_connection_t *c, xcb_cursor_t cursor, uint16_t fore_red, uint16_t fore_green, uint16_t fore_blue, uint16_t back_red, uint16_t back_green, uint16_t back_blue);

// xcb_void_cookie_t xcb_recolor_cursor (xcb_connection_t *c, xcb_cursor_t cursor, uint16_t fore_red, uint16_t fore_green, uint16_t fore_blue, uint16_t back_red, uint16_t back_green, uint16_t back_blue);

// xcb_query_best_size_cookie_t xcb_query_best_size (xcb_connection_t *c, uint8_t _class, xcb_drawable_t drawable, uint16_t width, uint16_t height);

// xcb_query_best_size_cookie_t xcb_query_best_size_unchecked (xcb_connection_t *c, uint8_t _class, xcb_drawable_t drawable, uint16_t width, uint16_t height);

// xcb_query_best_size_reply_t *xcb_query_best_size_reply (xcb_connection_t *c, xcb_query_best_size_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_query_extension_sizeof (const void *_buffer);

// xcb_query_extension_cookie_t xcb_query_extension (xcb_connection_t *c, uint16_t name_len, const char *name);

// xcb_query_extension_cookie_t xcb_query_extension_unchecked (xcb_connection_t *c, uint16_t name_len, const char *name);

// xcb_query_extension_reply_t *xcb_query_extension_reply (xcb_connection_t *c, xcb_query_extension_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_list_extensions_sizeof (const void *_buffer);

// xcb_list_extensions_cookie_t xcb_list_extensions (xcb_connection_t *c);

// xcb_list_extensions_cookie_t xcb_list_extensions_unchecked (xcb_connection_t *c);

// int xcb_list_extensions_names_length (const xcb_list_extensions_reply_t *R);

// xcb_str_iterator_t xcb_list_extensions_names_iterator (const xcb_list_extensions_reply_t *R);

// xcb_list_extensions_reply_t *xcb_list_extensions_reply (xcb_connection_t *c, xcb_list_extensions_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_change_keyboard_mapping_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_change_keyboard_mapping_checked (xcb_connection_t *c, uint8_t keycode_count, xcb_keycode_t first_keycode, uint8_t keysyms_per_keycode, const xcb_keysym_t *keysyms);

// xcb_void_cookie_t xcb_change_keyboard_mapping (xcb_connection_t *c, uint8_t keycode_count, xcb_keycode_t first_keycode, uint8_t keysyms_per_keycode, const xcb_keysym_t *keysyms);

// xcb_keysym_t *xcb_change_keyboard_mapping_keysyms (const xcb_change_keyboard_mapping_request_t *R);

// int xcb_change_keyboard_mapping_keysyms_length (const xcb_change_keyboard_mapping_request_t *R);

// xcb_generic_iterator_t xcb_change_keyboard_mapping_keysyms_end (const xcb_change_keyboard_mapping_request_t *R);

// int xcb_get_keyboard_mapping_sizeof (const void *_buffer);

// xcb_get_keyboard_mapping_cookie_t xcb_get_keyboard_mapping (xcb_connection_t *c, xcb_keycode_t first_keycode, uint8_t count);

// xcb_get_keyboard_mapping_cookie_t xcb_get_keyboard_mapping_unchecked (xcb_connection_t *c, xcb_keycode_t first_keycode, uint8_t count);

// xcb_keysym_t *xcb_get_keyboard_mapping_keysyms (const xcb_get_keyboard_mapping_reply_t *R);

// int xcb_get_keyboard_mapping_keysyms_length (const xcb_get_keyboard_mapping_reply_t *R);

// xcb_generic_iterator_t xcb_get_keyboard_mapping_keysyms_end (const xcb_get_keyboard_mapping_reply_t *R);

// xcb_get_keyboard_mapping_reply_t *xcb_get_keyboard_mapping_reply (xcb_connection_t *c, xcb_get_keyboard_mapping_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_change_keyboard_control_value_list_serialize (void **_buffer, uint32_t value_mask, const xcb_change_keyboard_control_value_list_t *_aux);

// int xcb_change_keyboard_control_value_list_unpack (const void *_buffer, uint32_t value_mask, xcb_change_keyboard_control_value_list_t *_aux);

// int xcb_change_keyboard_control_value_list_sizeof (const void *_buffer, uint32_t value_mask);

// int xcb_change_keyboard_control_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_change_keyboard_control_checked (xcb_connection_t *c, uint32_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_change_keyboard_control (xcb_connection_t *c, uint32_t value_mask, const void *value_list);

// xcb_void_cookie_t xcb_change_keyboard_control_aux_checked (xcb_connection_t *c, uint32_t value_mask, const xcb_change_keyboard_control_value_list_t *value_list);

// xcb_void_cookie_t xcb_change_keyboard_control_aux (xcb_connection_t *c, uint32_t value_mask, const xcb_change_keyboard_control_value_list_t *value_list);

// void *xcb_change_keyboard_control_value_list (const xcb_change_keyboard_control_request_t *R);

// xcb_get_keyboard_control_cookie_t xcb_get_keyboard_control (xcb_connection_t *c);

// xcb_get_keyboard_control_cookie_t xcb_get_keyboard_control_unchecked (xcb_connection_t *c);

// xcb_get_keyboard_control_reply_t *xcb_get_keyboard_control_reply (xcb_connection_t *c, xcb_get_keyboard_control_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_bell_checked (xcb_connection_t *c, int8_t percent);

// xcb_void_cookie_t xcb_bell (xcb_connection_t *c, int8_t percent);

// xcb_void_cookie_t xcb_change_pointer_control_checked (xcb_connection_t *c, int16_t acceleration_numerator, int16_t acceleration_denominator, int16_t threshold, uint8_t do_acceleration, uint8_t do_threshold);

// xcb_void_cookie_t xcb_change_pointer_control (xcb_connection_t *c, int16_t acceleration_numerator, int16_t acceleration_denominator, int16_t threshold, uint8_t do_acceleration, uint8_t do_threshold);

// xcb_get_pointer_control_cookie_t xcb_get_pointer_control (xcb_connection_t *c);

// xcb_get_pointer_control_cookie_t xcb_get_pointer_control_unchecked (xcb_connection_t *c);

// xcb_get_pointer_control_reply_t *xcb_get_pointer_control_reply (xcb_connection_t *c, xcb_get_pointer_control_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_set_screen_saver_checked (xcb_connection_t *c, int16_t timeout, int16_t interval, uint8_t prefer_blanking, uint8_t allow_exposures);

// xcb_void_cookie_t xcb_set_screen_saver (xcb_connection_t *c, int16_t timeout, int16_t interval, uint8_t prefer_blanking, uint8_t allow_exposures);

// xcb_get_screen_saver_cookie_t xcb_get_screen_saver (xcb_connection_t *c);

// xcb_get_screen_saver_cookie_t xcb_get_screen_saver_unchecked (xcb_connection_t *c);

// xcb_get_screen_saver_reply_t *xcb_get_screen_saver_reply (xcb_connection_t *c, xcb_get_screen_saver_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_change_hosts_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_change_hosts_checked (xcb_connection_t *c, uint8_t mode, uint8_t family, uint16_t address_len, const uint8_t *address);

// xcb_void_cookie_t xcb_change_hosts (xcb_connection_t *c, uint8_t mode, uint8_t family, uint16_t address_len, const uint8_t *address);

// uint8_t *xcb_change_hosts_address (const xcb_change_hosts_request_t *R);

// int xcb_change_hosts_address_length (const xcb_change_hosts_request_t *R);

// xcb_generic_iterator_t xcb_change_hosts_address_end (const xcb_change_hosts_request_t *R);

// int xcb_host_sizeof (const void *_buffer);

// uint8_t *xcb_host_address (const xcb_host_t *R);

// int xcb_host_address_length (const xcb_host_t *R);

// xcb_generic_iterator_t xcb_host_address_end (const xcb_host_t *R);

// void xcb_host_next (xcb_host_iterator_t *i);

// xcb_generic_iterator_t xcb_host_end (xcb_host_iterator_t i);

// int xcb_list_hosts_sizeof (const void *_buffer);

// xcb_list_hosts_cookie_t xcb_list_hosts (xcb_connection_t *c);

// xcb_list_hosts_cookie_t xcb_list_hosts_unchecked (xcb_connection_t *c);

// int xcb_list_hosts_hosts_length (const xcb_list_hosts_reply_t *R);

// xcb_host_iterator_t xcb_list_hosts_hosts_iterator (const xcb_list_hosts_reply_t *R);

// xcb_list_hosts_reply_t *xcb_list_hosts_reply (xcb_connection_t *c, xcb_list_hosts_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_set_access_control_checked (xcb_connection_t *c, uint8_t mode);

// xcb_void_cookie_t xcb_set_access_control (xcb_connection_t *c, uint8_t mode);

// xcb_void_cookie_t xcb_set_close_down_mode_checked (xcb_connection_t *c, uint8_t mode);

// xcb_void_cookie_t xcb_set_close_down_mode (xcb_connection_t *c, uint8_t mode);

// xcb_void_cookie_t xcb_kill_client_checked (xcb_connection_t *c, uint32_t resource);

// xcb_void_cookie_t xcb_kill_client (xcb_connection_t *c, uint32_t resource);

// int xcb_rotate_properties_sizeof (const void *_buffer);

// xcb_void_cookie_t xcb_rotate_properties_checked (xcb_connection_t *c, xcb_window_t window, uint16_t atoms_len, int16_t delta, const xcb_atom_t *atoms);

// xcb_void_cookie_t xcb_rotate_properties (xcb_connection_t *c, xcb_window_t window, uint16_t atoms_len, int16_t delta, const xcb_atom_t *atoms);

// xcb_atom_t *xcb_rotate_properties_atoms (const xcb_rotate_properties_request_t *R);

// int xcb_rotate_properties_atoms_length (const xcb_rotate_properties_request_t *R);

// xcb_generic_iterator_t xcb_rotate_properties_atoms_end (const xcb_rotate_properties_request_t *R);

// xcb_void_cookie_t xcb_force_screen_saver_checked (xcb_connection_t *c, uint8_t mode);

// xcb_void_cookie_t xcb_force_screen_saver (xcb_connection_t *c, uint8_t mode);

// int xcb_set_pointer_mapping_sizeof (const void *_buffer);

// xcb_set_pointer_mapping_cookie_t xcb_set_pointer_mapping (xcb_connection_t *c, uint8_t map_len, const uint8_t *map);

// xcb_set_pointer_mapping_cookie_t xcb_set_pointer_mapping_unchecked (xcb_connection_t *c, uint8_t map_len, const uint8_t *map);

// xcb_set_pointer_mapping_reply_t *xcb_set_pointer_mapping_reply (xcb_connection_t *c, xcb_set_pointer_mapping_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_get_pointer_mapping_sizeof (const void *_buffer);

// xcb_get_pointer_mapping_cookie_t xcb_get_pointer_mapping (xcb_connection_t *c);

// xcb_get_pointer_mapping_cookie_t xcb_get_pointer_mapping_unchecked (xcb_connection_t *c);

// uint8_t *xcb_get_pointer_mapping_map (const xcb_get_pointer_mapping_reply_t *R);

// int xcb_get_pointer_mapping_map_length (const xcb_get_pointer_mapping_reply_t *R);

// xcb_generic_iterator_t xcb_get_pointer_mapping_map_end (const xcb_get_pointer_mapping_reply_t *R);

// xcb_get_pointer_mapping_reply_t *xcb_get_pointer_mapping_reply (xcb_connection_t *c, xcb_get_pointer_mapping_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_set_modifier_mapping_sizeof (const void *_buffer);

// xcb_set_modifier_mapping_cookie_t xcb_set_modifier_mapping (xcb_connection_t *c, uint8_t keycodes_per_modifier, const xcb_keycode_t *keycodes);

// xcb_set_modifier_mapping_cookie_t xcb_set_modifier_mapping_unchecked (xcb_connection_t *c, uint8_t keycodes_per_modifier, const xcb_keycode_t *keycodes);

// xcb_set_modifier_mapping_reply_t *xcb_set_modifier_mapping_reply (xcb_connection_t *c, xcb_set_modifier_mapping_cookie_t cookie /**< */, xcb_generic_error_t **e);

// int xcb_get_modifier_mapping_sizeof (const void *_buffer);

// xcb_get_modifier_mapping_cookie_t xcb_get_modifier_mapping (xcb_connection_t *c);

// xcb_get_modifier_mapping_cookie_t xcb_get_modifier_mapping_unchecked (xcb_connection_t *c);

// xcb_keycode_t *xcb_get_modifier_mapping_keycodes (const xcb_get_modifier_mapping_reply_t *R);

// int xcb_get_modifier_mapping_keycodes_length (const xcb_get_modifier_mapping_reply_t *R);

// xcb_generic_iterator_t xcb_get_modifier_mapping_keycodes_end (const xcb_get_modifier_mapping_reply_t *R);

// xcb_get_modifier_mapping_reply_t *xcb_get_modifier_mapping_reply (xcb_connection_t *c, xcb_get_modifier_mapping_cookie_t cookie /**< */, xcb_generic_error_t **e);

// xcb_void_cookie_t xcb_no_operation_checked (xcb_connection_t *c);

// xcb_void_cookie_t xcb_no_operation (xcb_connection_t *c);

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* xcb_key_press_event_t */
/* aKeyPress key_press( pEvent ) */
HB_FUNC( KEY_PRESS )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_key_press_event_t * key_press = ( xcb_key_press_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 14 );

      hb_arraySetNI( pItem, 1,  ( uint8_t )  key_press->response_type );
      hb_arraySetNI( pItem, 2,  ( uint8_t )  key_press->detail );
      hb_arraySetNI( pItem, 3,  ( uint16_t ) key_press->sequence );
      hb_arraySetNI( pItem, 4,  ( uint32_t ) key_press->time );
      hb_arraySetNI( pItem, 5,  ( uint32_t ) key_press->root );
      hb_arraySetNI( pItem, 6,  ( uint32_t ) key_press->event );
      hb_arraySetNI( pItem, 7,  ( uint32_t ) key_press->child );
      hb_arraySetNI( pItem, 8,  ( int16_t )  key_press->root_x );
      hb_arraySetNI( pItem, 9,  ( int16_t )  key_press->root_y );
      hb_arraySetNI( pItem, 10, ( int16_t )  key_press->event_x );
      hb_arraySetNI( pItem, 11, ( int16_t )  key_press->event_y );
      hb_arraySetNI( pItem, 12, ( uint16_t ) key_press->state );
      hb_arraySetNI( pItem, 13, ( uint8_t )  key_press->same_screen );
      hb_arraySetNI( pItem, 14, ( uint8_t )  key_press->pad0 );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* xcb_key_release_event_t */
/* aKeyRelease key_release( pEvent ) */
HB_FUNC( KEY_RELEASE )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_key_release_event_t * key_release = ( xcb_key_release_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 14 );

      hb_arraySetNI( pItem, 1,  ( uint8_t )  key_release->response_type );
      hb_arraySetNI( pItem, 2,  ( uint8_t )  key_release->detail );
      hb_arraySetNI( pItem, 3,  ( uint16_t ) key_release->sequence );
      hb_arraySetNI( pItem, 4,  ( uint32_t ) key_release->time );
      hb_arraySetNI( pItem, 5,  ( uint32_t ) key_release->root );
      hb_arraySetNI( pItem, 6,  ( uint32_t ) key_release->event );
      hb_arraySetNI( pItem, 7,  ( uint32_t ) key_release->child );
      hb_arraySetNI( pItem, 8,  ( int16_t )  key_release->root_x );
      hb_arraySetNI( pItem, 9,  ( int16_t )  key_release->root_y );
      hb_arraySetNI( pItem, 10, ( int16_t )  key_release->event_x );
      hb_arraySetNI( pItem, 11, ( int16_t )  key_release->event_y );
      hb_arraySetNI( pItem, 12, ( uint16_t ) key_release->state );
      hb_arraySetNI( pItem, 13, ( uint8_t )  key_release->same_screen );
      hb_arraySetNI( pItem, 14, ( uint8_t )  key_release->pad0 );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}


/* xcb_button_press_event_t */
/* aButtonPress button_press( pEvent ) */
HB_FUNC( BUTTON_PRESS )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_button_press_event_t * button_press = ( xcb_button_press_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 14 );

      hb_arraySetNI( pItem, 1,  ( uint8_t )  button_press->response_type );
      hb_arraySetNI( pItem, 2,  ( uint8_t )  button_press->detail );
      hb_arraySetNI( pItem, 3,  ( uint16_t ) button_press->sequence );
      hb_arraySetNI( pItem, 4,  ( uint32_t ) button_press->time );
      hb_arraySetNI( pItem, 5,  ( uint32_t ) button_press->root );
      hb_arraySetNI( pItem, 6,  ( uint32_t ) button_press->event );
      hb_arraySetNI( pItem, 7,  ( uint32_t ) button_press->child );
      hb_arraySetNI( pItem, 8,  ( int16_t )  button_press->root_x );
      hb_arraySetNI( pItem, 9,  ( int16_t )  button_press->root_y );
      hb_arraySetNI( pItem, 10, ( int16_t )  button_press->event_x );
      hb_arraySetNI( pItem, 11, ( int16_t )  button_press->event_y );
      hb_arraySetNI( pItem, 12, ( uint16_t ) button_press->state );
      hb_arraySetNI( pItem, 13, ( uint8_t )  button_press->same_screen );
      hb_arraySetNI( pItem, 14, ( uint8_t )  button_press->pad0 );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* xcb_button_release_event_t */
/* aButtonRelease button_release( pEvent ) */
HB_FUNC( BUTTON_RELEASE )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_button_release_event_t * button_release = ( xcb_button_release_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 14 );

      hb_arraySetNI( pItem, 1,  ( uint8_t )  button_release->response_type );
      hb_arraySetNI( pItem, 2,  ( uint8_t )  button_release->detail );
      hb_arraySetNI( pItem, 3,  ( uint16_t ) button_release->sequence );
      hb_arraySetNI( pItem, 4,  ( uint32_t ) button_release->time );
      hb_arraySetNI( pItem, 5,  ( uint32_t ) button_release->root );
      hb_arraySetNI( pItem, 6,  ( uint32_t ) button_release->event );
      hb_arraySetNI( pItem, 7,  ( uint32_t ) button_release->child );
      hb_arraySetNI( pItem, 8,  ( int16_t )  button_release->root_x );
      hb_arraySetNI( pItem, 9,  ( int16_t )  button_release->root_y );
      hb_arraySetNI( pItem, 10, ( int16_t )  button_release->event_x );
      hb_arraySetNI( pItem, 11, ( int16_t )  button_release->event_y );
      hb_arraySetNI( pItem, 12, ( uint16_t ) button_release->state );
      hb_arraySetNI( pItem, 13, ( uint8_t )  button_release->same_screen );
      hb_arraySetNI( pItem, 14, ( uint8_t )  button_release->pad0 );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* xcb_motion_notify_event_t */
/* aMotionNotify motion_notify( pEvent ) */
HB_FUNC( MOTION_NOTIFY )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_motion_notify_event_t * motion_notify = ( xcb_motion_notify_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 14 );

      hb_arraySetNI( pItem, 1,  ( uint8_t )  motion_notify->response_type );
      hb_arraySetNI( pItem, 2,  ( uint8_t )  motion_notify->detail );
      hb_arraySetNI( pItem, 3,  ( uint16_t ) motion_notify->sequence );
      hb_arraySetNI( pItem, 4,  ( uint32_t ) motion_notify->time );
      hb_arraySetNI( pItem, 5,  ( uint32_t ) motion_notify->root );
      hb_arraySetNI( pItem, 6,  ( uint32_t ) motion_notify->event );
      hb_arraySetNI( pItem, 7,  ( uint32_t ) motion_notify->child );
      hb_arraySetNI( pItem, 8,  ( int16_t )  motion_notify->root_x );
      hb_arraySetNI( pItem, 9,  ( int16_t )  motion_notify->root_y );
      hb_arraySetNI( pItem, 10, ( int16_t )  motion_notify->event_x );
      hb_arraySetNI( pItem, 11, ( int16_t )  motion_notify->event_y );
      hb_arraySetNI( pItem, 12, ( uint16_t ) motion_notify->state );
      hb_arraySetNI( pItem, 13, ( uint8_t )  motion_notify->same_screen );
      hb_arraySetNI( pItem, 14, ( uint8_t )  motion_notify->pad0 );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* xcb_enter_notify_event_t */
/* aEnterNotify enter_notify( pEvent ) */
HB_FUNC( ENTER_NOTIFY )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_enter_notify_event_t * enter_notify = ( xcb_enter_notify_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 14 );

      hb_arraySetNI( pItem, 1,  ( uint8_t )  enter_notify->response_type );
      hb_arraySetNI( pItem, 2,  ( uint8_t )  enter_notify->detail );
      hb_arraySetNI( pItem, 3,  ( uint16_t ) enter_notify->sequence );
      hb_arraySetNI( pItem, 4,  ( uint32_t ) enter_notify->time );
      hb_arraySetNI( pItem, 5,  ( uint32_t ) enter_notify->root );
      hb_arraySetNI( pItem, 6,  ( uint32_t ) enter_notify->event );
      hb_arraySetNI( pItem, 7,  ( uint32_t ) enter_notify->child );
      hb_arraySetNI( pItem, 8,  ( int16_t )  enter_notify->root_x );
      hb_arraySetNI( pItem, 9,  ( int16_t )  enter_notify->root_y );
      hb_arraySetNI( pItem, 10, ( int16_t )  enter_notify->event_x );
      hb_arraySetNI( pItem, 11, ( int16_t )  enter_notify->event_y );
      hb_arraySetNI( pItem, 12, ( uint16_t ) enter_notify->state );
      hb_arraySetNI( pItem, 13, ( uint8_t )  enter_notify->mode );
      hb_arraySetNI( pItem, 14, ( uint8_t )  enter_notify->same_screen_focus );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* xcb_leave_notify_event_t */
/* aLeaveNotify leave_notify( pEvent ) */
HB_FUNC( LEAVE_NOTIFY )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_leave_notify_event_t * leave_notify = ( xcb_leave_notify_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 14 );

      hb_arraySetNI( pItem, 1,  ( uint8_t )  leave_notify->response_type );
      hb_arraySetNI( pItem, 2,  ( uint8_t )  leave_notify->detail );
      hb_arraySetNI( pItem, 3,  ( uint16_t ) leave_notify->sequence );
      hb_arraySetNI( pItem, 4,  ( uint32_t ) leave_notify->time );
      hb_arraySetNI( pItem, 5,  ( uint32_t ) leave_notify->root );
      hb_arraySetNI( pItem, 6,  ( uint32_t ) leave_notify->event );
      hb_arraySetNI( pItem, 7,  ( uint32_t ) leave_notify->child );
      hb_arraySetNI( pItem, 8,  ( int16_t )  leave_notify->root_x );
      hb_arraySetNI( pItem, 9,  ( int16_t )  leave_notify->root_y );
      hb_arraySetNI( pItem, 10, ( int16_t )  leave_notify->event_x );
      hb_arraySetNI( pItem, 11, ( int16_t )  leave_notify->event_y );
      hb_arraySetNI( pItem, 12, ( uint16_t ) leave_notify->state );
      hb_arraySetNI( pItem, 13, ( uint8_t )  leave_notify->mode );
      hb_arraySetNI( pItem, 14, ( uint8_t )  leave_notify->same_screen_focus );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* xcb_expose_event_t */
/* aExpose expose( pEvent ) */
HB_FUNC( EXPOSE )
{
   xcb_generic_event_t * event = hb_event_Param( 1 );

   xcb_expose_event_t * expose = ( xcb_expose_event_t * ) event;

   if( event )
   {
      PHB_ITEM pItem = hb_itemArrayNew( 10 );

      hb_arraySetNI( pItem, 1, ( uint8_t )  expose->response_type );
      hb_arraySetNI( pItem, 2, ( uint8_t )  expose->pad0 );
      hb_arraySetNI( pItem, 3, ( uint16_t ) expose->sequence );
      hb_arraySetNI( pItem, 4, ( uint32_t ) expose->window );
      hb_arraySetNI( pItem, 5, ( uint16_t ) expose->x );
      hb_arraySetNI( pItem, 6, ( uint16_t ) expose->y );
      hb_arraySetNI( pItem, 7, ( uint16_t ) expose->width );
      hb_arraySetNI( pItem, 8, ( uint16_t ) expose->height );
      hb_arraySetNI( pItem, 9, ( uint16_t ) expose->count );

         PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 10 );

         hb_arrayNew( pSubarray, 2 );
         hb_arraySetNI( pSubarray, 1, ( uint8_t ) expose->pad1[ 0 ] );
         hb_arraySetNI( pSubarray, 2, ( uint8_t ) expose->pad1[ 1 ] );

      hb_itemReturnRelease( pItem );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
