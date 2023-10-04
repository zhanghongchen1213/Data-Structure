//
// Created by k on 23-10-4.
//
typedef int data_t;
#define N 128

typedef struct{
    data_t data[N];
    int front;
    int rear;
}sequeue;

sequeue *queue_create();//创建队列
int queue_push(sequeue *sq,data_t value);//入队
data_t queue_pop(sequeue *sq);//出队
int queue_empty(sequeue *sq);//判断队列是否为空
int queue_full(sequeue *sq);//判断队列是否为满
int queue_clear(sequeue *sq);//清空队列
sequeue *queue_free(sequeue *sq);//释放队列



#ifndef SEQUEUE_TEST_SEQUEUE_H
#define SEQUEUE_TEST_SEQUEUE_H

#endif //SEQUEUE_TEST_SEQUEUE_H
