#include "linkqueue.h"
#include <stdio.h>

int main() {
    linkqueue *lq = create_linkqueue();
    if (lq == NULL) {
        printf("队列创建失败\n");
        return -1;
    }
    queue_push(lq, 10);
    queue_push(lq, 20);
    queue_push(lq, 30);
    queue_push(lq, 40);
#if 1
    while (!queue_empty(lq)) {
        printf("queue_pop: %d\n", queue_pop(lq));
    }
#endif
    lq = queue_free(lq);
    return 0;
}
