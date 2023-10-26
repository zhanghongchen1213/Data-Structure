//
// Created by k on 23-10-7.
//
#ifndef HASH_HASH_H
#define HASH_HASH_H

#define N 15

typedef int datatype;

typedef struct node {
    datatype key;
    datatype value;
    struct node *next;
} listnode, *linklist;

typedef struct {
    listnode data[N];
} hash, *linkhash;

linkhash hash_create();//创建哈希表
int hash_insert(linkhash HT, datatype key);//向哈希表中插入
linklist hash_search(linkhash HT, datatype key);//在哈希表中查找



#endif //HASH_HASH_H
