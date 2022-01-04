#ifndef XCB_CH_
#define XCB_CH_

#define X_PROTOCOL                       11
#define X_PROTOCOL_REVISION              0
#define X_TCP_PORT                       6000
#define XCB_CONN_ERROR                   1
#define XCB_CONN_CLOSED_EXT_NOTSUPPORTED 2
#define XCB_CONN_CLOSED_MEM_INSUFFICIENT 3
#define XCB_CONN_CLOSED_REQ_LEN_EXCEED   4
#define XCB_CONN_CLOSED_PARSE_ERR        5
#define XCB_CONN_CLOSED_INVALID_SCREEN   6
#define XCB_CONN_CLOSED_FDPASSING_FAILED 7
//#define XCB_TYPE_PAD(T,I) (-(I) & (sizeof(T) > 4 ? 3 : sizeof(T) - 1))
#define XCB_NONE                         0x00000000
#define XCB_COPY_FROM_PARENT             0x00000000
#define XCB_CURRENT_TIME                 0x00000000
#define XCB_NO_SYMBOL                    0x00000000

/* xcb_generic_event_t */
#define RESPONSE_TYPE                    1   /**< Type of the response */
#define PAD0                             2   /**< Padding */
#define SEQUENCE                         3   /**< Sequence number */
#define PAD                              4   /**< Padding */
#define FULL_SEQUENCE                    5   /**< full sequence */

/* xcb_generic_error_t */
#define ERROR_RESPONSE_TYPE              1   /**< Type of the response */
#define ERROR_ERROR_CODE                 2   /**< Error code */
#define ERROR_SEQUENCE                   3   /**< Sequence number */
#define ERROR_RESOURCE_ID                4   /**< Resource ID for requests with side effects only */
#define ERROR_MINOR_CODE                 5   /**< Minor opcode of the failed request */
#define ERROR_MAJOR_CODE                 6   /**< Major opcode of the failed request */
#define ERROR_PAD0                       7
#define ERROR_PAD                        8   /**< Padding */
#define ERROR_FULL_SEQUENCE              9   /**< full sequence */

#endif /* XCB_CH_ */
