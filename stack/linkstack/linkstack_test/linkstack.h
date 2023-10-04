//
// Created by k on 23-10-4.
//
typedef int data_t;
typedef struct node {
    data_t data;       // 数据域
    struct node *next; // 指针域
} listnode, *linkstack;

linkstack stack_create();  // 创建栈
int stack_push(linkstack s, data_t value);  // 入栈
data_t stack_pop(linkstack s);  // 出栈
data_t stack_top(linkstack s); // 取栈顶元素
int stack_empty(linkstack s);  // 判断栈是否为空
linkstack stack_free(linkstack s); // 释放栈

#ifndef LINKSTACK_TEST_LINKSTACK_H
#define LINKSTACK_TEST_LINKSTACK_H

#endif //LINKSTACK_TEST_LINKSTACK_H
