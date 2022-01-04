#ifndef HBXCB_H_
#define HBXCB_H_

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"
#include "hbstack.h"

#include <xcb/xcb.h>

HB_EXTERN_BEGIN

/* xcb_connection_t */
extern HB_EXPORT xcb_connection_t * hb_connection_Param( int iParam );
extern HB_EXPORT xcb_connection_t * hb_connection_ParamGet( int iParam );
extern HB_EXPORT xcb_connection_t * hb_connection_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM           hb_connection_ItemPut( PHB_ITEM pItem, xcb_connection_t * pConnection );
extern HB_EXPORT void               hb_connection_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void               hb_connection_Return( xcb_connection_t * pConnection );

/* xcb_setup_t */
extern HB_EXPORT xcb_setup_t * hb_setup_Param( int iParam );
extern HB_EXPORT xcb_setup_t * hb_setup_ParamGet( int iParam );
extern HB_EXPORT xcb_setup_t * hb_setup_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM      hb_setup_ItemPut( PHB_ITEM pItem, xcb_setup_t * pSetup );
extern HB_EXPORT void          hb_setup_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void          hb_setup_Return( xcb_setup_t * pSetup );

/* xcb_screen_t */
extern HB_EXPORT xcb_screen_t * hb_screen_Param( int iParam );
extern HB_EXPORT xcb_screen_t * hb_screen_ParamGet( int iParam );
extern HB_EXPORT xcb_screen_t * hb_screen_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM       hb_screen_ItemPut( PHB_ITEM pItem, xcb_screen_t * pScreen );
extern HB_EXPORT void           hb_screen_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void           hb_screen_Return( xcb_screen_t * pScreen );

/* xcb_generic_event_t */
extern HB_EXPORT xcb_generic_event_t * hb_event_Param( int iParam );
extern HB_EXPORT xcb_generic_event_t * hb_event_ParamGet( int iParam );
extern HB_EXPORT xcb_generic_event_t * hb_event_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM              hb_event_ItemPut( PHB_ITEM pItem, xcb_generic_event_t * pEvent );
extern HB_EXPORT void                  hb_event_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void                  hb_event_Return( xcb_generic_event_t * pEvent );

extern HB_EXPORT xcb_generic_error_t * hb_error_Param( int iParam );
extern HB_EXPORT xcb_generic_error_t * hb_error_ParamGet( int iParam );
extern HB_EXPORT xcb_generic_error_t * hb_error_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM              hb_error_ItemPut( PHB_ITEM pItem, xcb_generic_error_t * pError );
extern HB_EXPORT void                  hb_error_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void                  hb_error_Return( xcb_generic_error_t * pError );

HB_EXTERN_END

#define UNUSED( x ) ( ( void ) ( x ) )
#define HB_ERR_ARGS() ( hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS ) )

#endif /* HBXCB_H_ */
