#include <stdio.h>
#include "hash.h"

int main() {
    int key;
    linklist r;
    int data[] = {23, 34, 14, 38, 46, 16, 68, 15, 01, 31, 26};
    linkhash HT = hash_create();
    if (HT == NULL) {
        printf("创建哈希表失败\n");
        return -1;
    }
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        hash_insert(HT, data[i]);
    }
    printf("请输入要查找的关键字：");
    scanf("%d", &key);
    r = hash_search(HT, key);
    if (r == NULL) {
        printf("查找失败\n");
    } else {
        printf("查找成功，关键字为%d/%d的值为%d\n", key, r->key, r->value);
    }
    return 0;
}
