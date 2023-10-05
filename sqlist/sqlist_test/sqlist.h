//
// Created by k on 23-9-19.
//

typedef int data_t;
#define N 128
typedef struct {
    data_t data[N];
    int last; //代表最后一个元素的下标
} sqlist, *sqlink; //sqlist是结构体类型名,sqlink是结构体指针名，是一个指针指向结构体
//在定义结构体的同时进行重命名,即typedef struct sqlist_t sqlist; typedef struct sqlist_t *sqllink;
//这样就可以直接使用sqlist和sqlink来代替struct sqlist_t和struct sqlist_t *了

sqlink list_create();  //创建一个空的线性表,返回线性表的地址
int list_clear(sqlink L);  //清空线性表,返回1表示成功,返回0表示失败
int list_empty(sqlink L);  //判断线性表是否为空,返回1表示为空,返回0表示不为空
int list_length(sqlink L);  //求线性表的长度,返回线性表的长度
int list_locate(sqlink L, data_t value);  //按值查找,返回值在表中的位置,返回-1表示失败
int list_insert(sqlink L, data_t value, int pos);  //在pos位置插入元素value,返回1表示成功,返回0表示失败
int list_show(sqlink L);  //遍历线性表,打印线性表中的每个元素
int list_free(sqlink L); //释放线性表内存空间
int list_delete_pos(sqlink L, int pos); //删除pos位置的元素
int list_merge(sqlink La, sqlink Lb); //合并两个有序表
int list_purge(sqlink L); //删除重复元素


#ifndef SQLIST_TEST_SQLIST_H
#define SQLIST_TEST_SQLIST_H

#endif //SQLIST_TEST_SQLIST_H
