#include <stdio.h>
#include "linklist.h"

linklist test_listinsert(void);

int test_merge(void);

int test_find(void);

int main() {
    test_find();
}

linklist test_listinsert(void) {
    linklist H = list_create();
    linklist p;
    data_t value, sum;
    if (H == NULL) {
        return NULL;
    }
    printf("请输入要插入的元素的值,输入-1表示结束:");
    while (scanf("%d", &value) == 1 && value != -1) {
        list_tail_insert(H, value);
        printf("请输入要插入的元素的值,输入-1表示结束:");
    }
    list_show(H);
    list_insert(H, 100, 0);
    list_show(H);
    list_delete(H, -5);
    list_show(H);
    p = list_adjmax(H, &sum);
    if (p != NULL && p != H) {
        printf("最大值的前一个节点的值是:%d num=%d\n", p->data, sum);
    }
    list_show(H);
    list_reverse(H);
    list_show(H);
    list_free(H);
    return H;
}

int test_merge(void) {
    linklist H1, H2;
    int a[] = {1, 4, 6, 8, 10};
    int b[] = {2, 45, 4, 21, 9};
    H1 = list_create();
    if (H1 == NULL)
        return -1;
    H2 = list_create();
    if (H2 == NULL)
        return -1;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        list_tail_insert(H1, a[i]);
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
        list_tail_insert(H2, b[i]);
    list_show(H1);
    list_show(H2);
    list_sort(H2);
    list_show(H1);
    list_show(H2);
    list_free(H1);
    list_free(H2);
}

int test_find(void) {
    linklist H = list_create();
    data_t value;
    printf("请输入要插入的元素的值,输入-1表示结束:");
    while (scanf("%d", &value) == 1 && value != -1) {
        list_tail_insert(H, value);
        printf("请输入要插入的元素的值,输入-1表示结束:");
    }
    list_show(H);
    list_delete_value(H, 5);
    list_show(H);
    list_free(H);
}

