/*
 * XCB X protocol C-language Binding: xcbext.c
 * version libxcb 1.14
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbxcb.h"

// unsigned int xcb_send_request(xcb_connection_t *c, int flags, struct iovec *vector, const xcb_protocol_request_t *request);

// unsigned int xcb_send_request_with_fds(xcb_connection_t *c, int flags, struct iovec *vector, const xcb_protocol_request_t *request, unsigned int num_fds, int *fds);

// uint64_t xcb_send_request64(xcb_connection_t *c, int flags, struct iovec *vector, const xcb_protocol_request_t *request);

// uint64_t xcb_send_request_with_fds64(xcb_connection_t *c, int flags, struct iovec *vector, const xcb_protocol_request_t *request, unsigned int num_fds, int *fds);

// void xcb_send_fd(xcb_connection_t *c, int fd);

// int xcb_take_socket(xcb_connection_t *c, void (*return_socket)(void *closure), void *closure, int flags, uint64_t *sent);

// int xcb_writev(xcb_connection_t *c, struct iovec *vector, int count, uint64_t requests);

// void *xcb_wait_for_reply(xcb_connection_t *c, unsigned int request, xcb_generic_error_t **e);

// void *xcb_wait_for_reply64(xcb_connection_t *c, uint64_t request, xcb_generic_error_t **e);

// int xcb_poll_for_reply(xcb_connection_t *c, unsigned int request, void **reply, xcb_generic_error_t **error);

// int xcb_poll_for_reply64(xcb_connection_t *c, uint64_t request, void **reply, xcb_generic_error_t **error);

// int *xcb_get_reply_fds(xcb_connection_t *c, void *reply, size_t replylen);

// int xcb_popcount(uint32_t mask);

// int xcb_sumof(uint8_t *list, int len);
