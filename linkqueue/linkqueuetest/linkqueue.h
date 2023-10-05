//
// Created by k on 23-10-5.
//
typedef int data_t;

typedef struct node {
    data_t data;
    struct node *next;
} listnode, *linklist;

typedef struct {
    linklist front;
    linklist rear;
} linkqueue;

linkqueue *create_linkqueue();//创建队列
int queue_push(linkqueue *lq, data_t value);//入队
data_t queue_pop(linkqueue *lq);//出队
int queue_empty(linkqueue *lq);//判断队列是否为空
int queue_clear(linkqueue *lq);//清空队列
linkqueue *queue_free(linkqueue *lq);//释放队列




#ifndef LINKQUEUETEST_LINKQUEUE_H
#define LINKQUEUETEST_LINKQUEUE_H

#endif //LINKQUEUETEST_LINKQUEUE_H
