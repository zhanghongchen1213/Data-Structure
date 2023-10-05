//
// Created by k on 23-10-5.
//
#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * 1.创建队列
 */
linkqueue *create_linkqueue() {
    // 1.申请队列空间
    linkqueue *lq = (linkqueue *) malloc(sizeof(linkqueue));
    if (lq == NULL) {
        printf("队列创建失败\n");
        return NULL;
    }
    lq->front = lq->rear = (linklist) malloc(sizeof(listnode));
    if (lq->front == NULL) {
        printf("队列创建失败\n");
        return NULL;
    }
    // 2.初始化队列内节点内容
    lq->front->data = 0;
    lq->front->next = NULL;
    return lq;
}

/*
 * 2.入队
 */
int queue_push(linkqueue *lq, data_t value) {
    if (lq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    //1.申请新节点
    linklist newnode = (linklist) malloc(sizeof(listnode));
    if (newnode == NULL) {
        printf("队列创建失败\n");
        return -1;
    }
    newnode->data = value;
    newnode->next = NULL;
    //2.入队
    lq->rear->next = newnode;
    lq->rear = newnode;
    return 0;
}

/*
 * 3.出队
 */
data_t queue_pop(linkqueue *lq) {
    if (lq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    //1.判断队列是否为空
    if (lq->front == lq->rear) {
        printf("队列为空,出队失败\n");
        return -1;
    }
    //2.出队
    linklist p = lq->front->next;   // 保存队头元素
    data_t value = p->data;         // 保存队头元素值
    lq->front->next = p->next;      // 队头指针指向下一个元素
    if (p == lq->rear) {            // 如果出队元素是队尾元素
        lq->rear = lq->front;       // 队尾指针指向队头元素
    }
    //3.释放出队元素空间
    free(p);
    p = NULL;
    return value;
}
/*
 * 4.判断队列是否为空
 */
int queue_empty(linkqueue *lq){
    if (lq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    return (lq->front == lq->rear ? 1 : 0);  // 队头指针等于队尾指针,则队列为空
}

/*
 * 5.清空队列
 */
int queue_clear(linkqueue *lq){
    if (lq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    //1.释放队列内节点空间
    linklist p = lq->front->next;  // 保存队头元素
    while (p != NULL) {
        lq->front->next = p->next;  // 队头指针指向下一个元素
        free(p);
        p = lq->front->next;
    }
    //2.初始化队列内节点内容
    lq->front->data = 0;
    lq->front->next = NULL;
    lq->rear = lq->front;
    return 0;
}
/*
 * 6.释放队列
 */
linkqueue *queue_free(linkqueue *lq){
    if (lq == NULL) {
        printf("队列不存在\n");
        return NULL;
    }
    //1.释放队列内节点空间
    linklist p = lq->front->next;  // 保存队头元素
    while (p != NULL) {
        lq->front->next = p->next;  // 队头指针指向下一个元素
        printf("free: %d\n", p->data);
        free(p);
        p = lq->front->next;
    }
    //2.释放队列空间
    free(lq);
    lq = NULL;
    return NULL;
}