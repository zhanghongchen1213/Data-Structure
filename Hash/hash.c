//
// Created by k on 23-10-7.
//

#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 1.创建哈希表
 */
linkhash hash_create() {
    linkhash HT = (linkhash) malloc(sizeof(hash));
    if (HT == NULL) {
        printf("创建哈希表失败\n");
        return NULL;
    }
    memset(HT, 0, sizeof(hash));
    return HT;
}

/**
 * 2.向哈希表中插入
 */
int hash_insert(linkhash HT, datatype key) {
    if (HT == NULL) {
        printf("哈希表不存在\n");
        return -1;
    }
    //1.计算哈希地址
    linklist p = (linklist) malloc(sizeof(listnode));
    if (p == NULL) {
        printf("申请空间失败\n");
        return -1;
    }
    p->key = key;
    p->value = key % N;
    p->next = NULL;
    //2.插入到哈希表中
    linklist q = &(HT->data[key % N]);
    while (q->next != NULL && q->next->key < p->key) {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    return 0;
}

/**
 * 3.在哈希表中查找
 */
linklist hash_search(linkhash HT, datatype key) {
    if (HT == NULL) {
        printf("哈希表不存在\n");
        return NULL;
    }
    linklist p = &(HT->data[key % N]);
    while (p->next != NULL && p->next->key != key) {
        p = p->next;
    }
    if (p->next == NULL) {
        return NULL;
    } else {
        printf("查找成功\n");
        return p->next;
    }
}