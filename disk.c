#include "oslabs.h"
#include <stdlib.h>



static inline void enqueue(struct RCB q[QUEUEMAX], int *cnt, struct RCB r) {
    if (*cnt < QUEUEMAX) q[(*cnt)++] = r;
}
static inline struct RCB remove_at(struct RCB q[QUEUEMAX], int *cnt, int idx) {
    struct RCB r = q[idx];
    for (int i=idx; i+1<*cnt; ++i) q[i] = q[i+1];
    (*cnt)--;
    return r;
}

//FCFS
struct RCB handle_request_arrival_fcfs(struct RCB request_queue[QUEUEMAX],
                                       int *queue_cnt,
                                       struct RCB current_req,
                                       struct RCB new_req,
                                       int timestamp) {
    (void)timestamp;                 // not used by FCFS arrival
    if (is_null(current_req))        // disk free
        return new_req;              // start it now
    enqueue(req_queue, queue_cnt, new_req);
    return current_req;              // keep servicing current
}
