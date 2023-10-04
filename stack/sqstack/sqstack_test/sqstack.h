//
// Created by k on 23-10-4.
//
//
// Created by k on 23-10-4.
//
typedef int data_t;
typedef struct {
    data_t *data; // 数据域
    int maxlen;   // 栈的最大长度
    int top;      // 栈顶指针,代表数组下标
} sqstack;

sqstack *stack_create(int len);  // 创建栈
int stack_push(sqstack *s, data_t value);  // 入栈
data_t stack_pop(sqstack *s);  // 出栈
data_t stack_top(sqstack *s); // 取栈顶元素
int stack_empty(sqstack *s);  // 判断栈是否为空
int stack_full(sqstack *s);  // 判断栈是否为满
int stack_clear(sqstack *s);  // 清空栈
int stack_free(sqstack *s); // 释放栈

#ifndef SQSTACK_TEST_SQSTACK_H
#define SQSTACK_TEST_SQSTACK_H

#endif //SQSTACK_TEST_SQSTACK_H
