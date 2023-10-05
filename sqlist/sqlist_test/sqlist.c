//
// Created by k on 23-9-19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlist.h"

/*
 * 1.创建一个空的线性表,返回线性表的地址
 * */
sqlink list_create() {
    //首先需要分配内存空间
    sqlink L;
    L = (sqlink) malloc(sizeof(sqlist));
    //分配内存空间,sizeof(sqlist)是结构体的大小
    //(sqlink)是强制类型转换,因为malloc返回的是void *类型
    if (L == NULL) {
        printf("分配内存失败\n");
        return NULL;
    }
    memset(L, 0, sizeof(sqlist));
    L->last = -1; //代表最后一个元素的下标,初始值为-1,代表没有元素，是个空表
    //将L指向的内存空间清零
    //menset(void *s, int c, size_t n)代表将s指向的内存空间的前n个字节清零，c代表要清零的内容
    return L;
}

/*
 * 2.判断线性表是否为空,返回-1表示为空，返回0表示不为空，函数执行成功
 */
int list_clear(sqlink L) {//清空线性表,返回1表示成功,返回0表示失败
    if (L == NULL) {
        printf("线性表不存在\n");
        return -1;
    }
    L->last = -1;
    return 0;
}

/*
 * 3.判断线性表是否为空,返回1表示为空,返回0表示不为空
 */
int list_empty(sqlink L) {//判断线性表是否为空,返回1表示为空,返回0表示不为空
    if (L->last == -1)
        return 1;
    else
        return 0;
}

/*
 * 4.求线性表的长度,返回线性表的长度
 */
int list_length(sqlink L) {
    if (L == NULL) {
        printf("线性表不存在\n");
        return -1;
    }
    return L->last + 1;
}

/*
 * 5.向线性表中插入一个元素,在pos位置插入元素value,返回1表示成功,返回0表示失败
 */
int list_insert(sqlink L, data_t x, int pos) {
    //1.判定线性表是否已满,或者判定L->last是否等于N-1
    if (list_length(L) == N) {
        printf("线性表已满\n");
        return -1;
    }
    //2.pos的取值范围是0~list_length(L),或者判定pos > L->last+1
    if (pos < 0 || pos > list_length(L)) {
        printf("pos取值范围应在0~%d之间\n", list_length(L));
        return -1;
    }
    //3.从最后一个元素开始,将元素向后移动一个位置
    for (int i = L->last; i >= pos; i--)
        L->data[i + 1] = L->data[i];
    //4.将x插入到pos位置
    L->data[pos] = x;  //将x插入到pos位置
    L->last++;         //最后一个元素的下标加1
    return 0;
}

/*
 * 6.遍历线性表,打印线性表中的每个元素
 */
int list_show(sqlink L) {
    if (L == NULL) {
        printf("线性表不存在\n");
        return -1;
    }
    if (L->last == -1) { //判断线性表是否为空
        printf("线性表为空\n");
        return -1;
    }
    for (int i = 0; i <= L->last; i++) //遍历线性表,i代表下标,从0开始,到L->last结束
        printf("%d ", L->data[i]);
    printf("\n");
    return 0;
}

/*
 * 7.释放内存空间
 */
int list_free(sqlink L) {
    if (L == NULL)
        return -1;
    free(L); //释放L指向的内存空间
    L = NULL;
    return 0;
}

/*
 * 8.删除线性表pos位置的元素
 */
int list_delete_pos(sqlink L, int pos) {
    //删除pos位置的元素
    //1.判定线性表是否为空
    if (L->last == -1) {
        printf("线性表为空\n");
        return -1;
    }
    //2.判定pos的取值范围
    if (pos < 0 || pos > L->last) {
        printf("pos取值范围应在0~%d之间\n", L->last);
        return -1;
    }
    //3.从pos位置开始,将元素向前移动一个位置
    for (int i = pos; i < L->last; i++)
        L->data[i] = L->data[i + 1];
    //4.将最后一个元素的下标减1
    L->last--;
    return 0;
}

/*
 * 9.合并两个有序表
 */
int list_merge(sqlink L1, sqlink L2) {
    int i = 0;
    int result;
    while (i <= L2->last) {
        result = list_locate(L1, L2->data[i]);
        //查找L2->data[i]是否在L1中,如果存在则跳过下面if语句继续读取下个线性表元素
        //如果不存在,则将L2->data[i]插入到L1中
        if (result == -1) {
            if (list_insert(L1, L2->data[i], L1->last + 1) == -1)
                //将L2->data[i]插入到L1中,如果插入失败,返回-1
                return -1;
        }
        i++;    //插入成功后,将i加1
    }
    return 0;
}

/*
 * 10.删除重复元素
 */
int list_purge(sqlink L) {
    //删除重复元素
    //1.判定线性表是否为空
    if (L == NULL) {
        printf("线性表不存在\n");
        return -1;
    }
    //2.遍历线性表,查找重复元素
    for (int i = 0; i <= L->last; i++) {
        for (int j = i + 1; j <= L->last; j++) {
            if (L->data[i] == L->data[j]) {
                //如果找到重复元素,则将重复元素后面的元素循环向前移动一个位置
                for (int k = j; k < L->last; k++)
                    L->data[k] = L->data[k + 1];
                L->last--; //将最后一个元素的下标减1
                j--; //将j的值减1,因为j位置的元素已经被删除了,所以需要重新判断j位置的元素
            }
        }
    }
    return 0;
}

/*
 * 11.查找元素是否在线性表中,返回元素在线性表中的位置，如果不存在返回-1
 */
int list_locate(sqlink L, data_t value) {
    //查找元素是否在线性表中
    //1.判定线性表是否为空
    if (L == NULL) {
        printf("线性表不存在\n");
        return -1;
    }
    //2.遍历线性表,查找元素是否在线性表中
    for (int i = 0; i <= L->last; i++) {
        if (L->data[i] == value)
            return i;
    }
    return -1;
}