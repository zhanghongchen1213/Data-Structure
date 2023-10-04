#include <stdio.h>
#include "sequeue.h"

int main() {
    sequeue *sq = queue_create();
    if (sq == NULL) {
        printf("队列创建失败\n");
        return -1;
    }
    queue_push(sq, 10);
    queue_push(sq, 20);
    queue_push(sq, 30);
    queue_push(sq, 40);

    while (!queue_empty(sq)) {
        printf("queue_pop: %d\n", queue_pop(sq));
    }
    queue_free(sq);
    return 0;
}
