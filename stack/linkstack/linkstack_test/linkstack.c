//
// Created by k on 23-10-4.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

/*
 * 1.创建栈
 */
linkstack stack_create() {
    // 1.申请栈空间
    linkstack s = (linkstack) malloc(sizeof(listnode));  // 申请头节点空间
    if (s == NULL) {
        printf("栈创建失败\n");
        return NULL;
    }
    // 2.初始化栈
    s->data = 0;
    s->next = NULL;
    return s;
}

/*
 * 2.入栈
 */
int stack_push(linkstack s, data_t value) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    // 1.申请节点空间，将value赋值给节点的数据域
    linkstack newnode = (linkstack) malloc(sizeof(listnode));
    if (newnode == NULL) {
        printf("节点申请失败\n");
        return -1;
    }
    newnode->data = value;
    // 3.入栈
    newnode->next = s->next;  // 将新节点插入到头节点后面
    s->next = newnode;        // 头节点的next指向新节点
    return 0;
}

/*
 * 3.出栈
 */
data_t stack_pop(linkstack s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    linkstack newnode = s->next;    // 头节点的下一个节点（栈顶）
    data_t value = newnode->data;   // 栈顶节点的数据域
    // 2.出栈
    s->next = newnode->next;        // 头节点的next指向新节点的下一个节点
    free(newnode);              // 释放头节点的下一个节点（栈顶）
    newnode = NULL;
    return value;
}

/*
 * 4.取栈顶元素
 */
data_t stack_top(linkstack s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    data_t value = s->next->data;   // 栈顶节点的数据域
    return value;
}

/*
 * 5.判断栈是否为空
 */
int stack_empty(linkstack s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    return (s->next == NULL ? 1 : 0);
}

/*
 * 6.释放栈
 */
linkstack stack_free(linkstack s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return NULL;
    }
    linkstack p = s;
    while (p->next != NULL) {
        linkstack q = p->next;  // 保存栈顶节点
        printf("free:%d\n", q->data);
        free(p);            // 释放栈顶节点
        p = q;                  // 栈顶指针指向栈顶节点
    }
    free(p);
    return NULL;
}