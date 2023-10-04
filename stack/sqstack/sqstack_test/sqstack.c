//
// Created by k on 23-10-4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqstack.h"

/*
 * 1.创建栈
 */
sqstack *stack_create(int len) {
    // 1.申请栈空间
    sqstack *s = (sqstack *) malloc(sizeof(sqstack));
    if (s == NULL) {
        printf("栈创建失败\n");
        return NULL;
    }
    // 2.申请数据空间
    s->data = (sqstack *) malloc(sizeof(data_t) * len);
    if (s->data == NULL) {
        printf("数据空间申请失败\n");
        return NULL;
    }
    // 3.初始化栈
    memset(s->data, 0, sizeof(data_t) * len);  // 初始化数据空间,数组元素全部置0
    s->maxlen = len;  // 栈的最大长度
    s->top = -1;  // 栈顶指针置-1,表示栈为空
    return s;
}

/*
 * 2.入栈
 */
int stack_push(sqstack *s, data_t value) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    // 1.判断栈是否为满
    if (s->top == s->maxlen - 1) {
        printf("栈已满,入栈失败\n");
        return -1;
    }
    // 2.入栈
    s->top++;             // 栈顶指针加1
    s->data[s->top] = value;  // 将x入栈
    return 0;
}

/*
 * 3.出栈
 */
data_t stack_pop(sqstack *s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    // 1.判断栈是否为空
    if (s->top == -1) {
        printf("栈为空,出栈失败\n");
        return -1;
    }
    // 2.出栈
    data_t value = s->data[s->top];  // 栈顶元素
    s->top--;                    // 栈顶指针减1
    return value;
}

/*
 * 4.取栈顶元素
 */
data_t stack_top(sqstack *s) {
    data_t value = s->data[s->top];
    return value;
}

/*
 * 5.判断栈是否为空
 */
int stack_empty(sqstack *s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    return (s->top == -1 ? 1 : 0);
}

/*
 * 6.判断栈是否为满
 */
int stack_full(sqstack *s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    return (s->top == s->maxlen - 1 ? 1 : 0);
}

/*
 * 7.清空栈
 */
int stack_clear(sqstack *s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    s->top = -1;
    return 0;
}

/*
 * 8.释放栈
 */
int stack_free(sqstack *s) {
    if (s == NULL) {
        printf("栈不存在\n");
        return -1;
    }
    free(s->data);  // 释放数据空间
    free(s);        // 释放栈空间
    return 0;
}