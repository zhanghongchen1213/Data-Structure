#include <stdio.h>
#include <stdlib.h>

// 链式队列的结点定义
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// 链式队列的定义
typedef struct {
    QueueNode *front; // 队头指针
    QueueNode *rear;  // 队尾指针
} LinkQueue;

// 初始化链式队列
void initQueue(LinkQueue *q) {
    q->front = q->rear = (QueueNode *) malloc(sizeof(QueueNode));
    q->front->next = NULL;
}

// 入队操作
void enQueue(LinkQueue *q, int data) {
    QueueNode *newNode = (QueueNode *) malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    q->rear->next = newNode;
    q->rear = newNode;
}

// 出队操作
int deQueue(LinkQueue *q, int *data) {
    if (q->front == q->rear) return -1; // 队列为空
    QueueNode *temp = q->front->next;
    *data = temp->data;
    q->front->next = temp->next;
    if (q->rear == temp) q->rear = q->front; // 如果出队的是最后一个结点，更新rear指针
    free(temp);
    return 0;
}

int main() {
    LinkQueue q;
    initQueue(&q);
    char command;
    int data;
    while (1) {
        scanf("%c", &command);
        if (command >= '0' && command <= '9') {
            enQueue(&q, command - '0');
        } else {
            if (deQueue(&q, &data) == 0) {
                printf("出队元素：%d\n", data);
            } else {
                printf("队列为空！\n");
            }
        }
        getchar(); // 消耗掉回车字符
    }
    return 0;
}
