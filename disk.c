#include "oslabs.h"
#include <stdlib.h>



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
