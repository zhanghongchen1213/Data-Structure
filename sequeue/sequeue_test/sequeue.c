//
// Created by k on 23-10-4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequeue.h"

/*
 * 1.创建队列
 */
sequeue *queue_create() {
    // 1.申请队列空间
    sequeue *sq = (sequeue *) malloc(sizeof(sequeue));
    if (sq == NULL) {
        printf("队列创建失败\n");
        return NULL;
    }
    // 2.初始化队列
    memset(sq->data, 0, sizeof(data_t) * N);  // 初始化数据空间,数组元素全部置0
    sq->front = 0;  // 队头指针置0
    sq->rear = 0;  // 队尾指针置0
    return sq;
}

/*
 * 2.入队
 */
int queue_push(sequeue *sq, data_t value) {
    if (sq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    // 1.判断队列是否为满
    if ((sq->rear + 1) % N == sq->front) {  // 队尾指针+1取余队列长度等于队头指针,则队列循环赋值且满
        printf("队列已满,入队失败\n");
        return -1;
    }
    // 2.入队
    sq->data[sq->rear] = value;  // 将x入队
    sq->rear = (sq->rear + 1) % N;  // 队尾指针+1取余队列长度
    return 0;
}

/*
 * 3.出队
 */
data_t queue_pop(sequeue *sq) {
    if (sq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    // 1.判断队列是否为空
    if (sq->front == sq->rear) {  // 队头指针等于队尾指针,则队列为空
        printf("队列为空,出队失败\n");
        return -1;
    }
    // 2.出队
    data_t value = sq->data[sq->front];  // 将队头元素赋值给value
    sq->front = (sq->front + 1) % N;  // 队头指针+1取余队列长度
    return value;
}

/*
 * 4.判断队列是否为空
 */
int queue_empty(sequeue *sq) {
    if (sq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    return (sq->front == sq->rear ? 1 : 0);  // 队头指针等于队尾指针,则队列为空
}

/*
 * 5.判断队列是否为满
 */
int queue_full(sequeue *sq) {
    if (sq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    return ((sq->rear + 1) % N == sq->front ? 1 : 0);  // 队尾指针+1取余队列长度等于队头指针,则队列循环赋值且满
}

/*
 * 6.清空队列
 */
int queue_clear(sequeue *sq) {
    if (sq == NULL) {
        printf("队列不存在\n");
        return -1;
    }
    sq->front = 0;  // 队头指针置0
    sq->rear = 0;  // 队尾指针置0
    return 0;
}

/*
 * 7.释放队列
 */
sequeue *queue_free(sequeue *sq) {
    if (sq == NULL) {
        printf("队列不存在\n");
        return NULL;
    }
    free(sq);  // 释放队列空间
    sq = NULL;  // 队列指针置空
    return NULL;
}