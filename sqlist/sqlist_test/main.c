#include <stdio.h>
#include "sqlist.h"

void test_insert(void);

void test_delete(void);

void test_merge(void);

void test_purge(void);

int main() {
    test_purge();
}

void test_insert(void) {
    sqlist *L = list_create();
    if (L == NULL) {
        printf("线性表不存在\n");
    }
    list_insert(L, 10, 0);
    list_insert(L, 20, 1);
    list_insert(L, 30, 2);
    list_insert(L, 100, 3);
    list_insert(L, 100, list_length(L));
    printf("线性表的长度为:%d\n", list_length(L));
    list_show(L);
    list_free(L); //清空线性表
    printf("线性表的长度为:%d\n", list_length(L));
}

void test_delete(void) {
    sqlist *L = list_create();
    if (L == NULL) {
        printf("线性表不存在\n");
    }
    list_insert(L, 10, 0);
    list_insert(L, 20, 1);
    list_insert(L, 30, 2);
    list_insert(L, 100, 3);
    list_insert(L, 128, list_length(L));
    list_show(L);
    list_delete_pos(L, 4);
    list_delete_pos(L, 1);
    list_show(L);

    list_free(L); //释放内存空间
}

void test_merge(void) {
    sqlist *L1 = list_create();
    sqlist *L2 = list_create();
    if (L1 == NULL) {
        printf("线性表不存在\n");
    }
    list_insert(L1, 50, 0);
    list_insert(L1, 10, 1);
    list_insert(L1, 5, 2);
    list_insert(L2, 10, 0);
    list_insert(L2, 128, list_length(L2));
    list_show(L1);
    list_show(L2);
    printf("***************\n");
    list_merge(L1, L2);
    list_show(L1);
    list_show(L2);
    list_free(L1); //释放内存空间
    list_free(L2); //释放内存空间
}

void test_purge(void) {
    sqlist *L1 = list_create();
    if (L1 == NULL) {
        printf("线性表不存在\n");
    }
    list_insert(L1, 10, 0);
    list_insert(L1, 10, 1);
    list_insert(L1, 5, 2);
    list_insert(L1, 5, 3);
    list_insert(L1, 1, 4);
    list_show(L1);
    printf("***************\n");
    list_purge(L1);
    list_show(L1);
    list_free(L1); //释放内存空间
}