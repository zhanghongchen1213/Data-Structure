//
// Created by k on 23-9-25.
//
#include  <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/*
 * 1.创建一个空的线性表,返回线性表的地址
*/
linklist list_create() {
    //1.首先需要分配链表的内存空间
    linklist H = (linklist) malloc(sizeof(listnode));
    //分配内存空间,sizeof(struct list_node)是结构体的大小,(linklist)是强制类型转换,因为malloc返回的是void *类型
    list_isempty(H);
    //2.将H指向的内存空间清零,因为malloc返回的内存空间是随机的
    H->data = 0;
    H->next = NULL;
    return H;
}

/*
 * 2.判断线性表是否为空,返回-1表示为空，返回0表示不为空，函数执行成功
 */
int list_tail_insert(linklist H, data_t value) {
    //1.需要创建一个新节点
    linklist p = (linklist) malloc(sizeof(listnode));
    list_isempty(p);
    p->data = value;
    p->next = NULL;
    //2.定位到链表的最后一个节点
    linklist q;
    q = H;
    while (q->next != NULL) {  //找到链表最后节点的位置，此时q指向链表最后一个节点
        q = q->next;
    }
    //3.将p节点插入到链表的最后一个节点的后面
    q->next = p;
    return 0;
}

/*
 * 3.遍历链表,打印链表中的每个元素
 */
int list_show(linklist H) {
    list_isempty(H);
    //1.定位到链表的第一个节点
    linklist p;
    p = H->next;
    //2.遍历链表,打印链表中的每个元素
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

/*
 * 4.获取链表中指定位置的元素
 */
linklist list_get(linklist H, int pos) {
    list_isempty(H);
    linklist p;
    int i;
    if (pos <= -1) { //如果pos为-1,则返回最后一个节点的地址
        return H;
    }
    //1.定位到链表的第一个节点
    p = H->next;
    //2.遍历链表,打印链表中的每个元素
    for (i = 0; i < pos; i++) {
        if (p == NULL) {
            printf("链表不存在\n");
            return NULL;
        }
        p = p->next;
    }
    //3.返回指定位置的元素
    return p;
}

/*
 * 5.在链表中指定位置插入元素,成功返回0,失败返回-1
 */
int list_insert(linklist H, data_t value, int pos) {
    //1.p指向要插入节点的前一个节点位置
    list_isempty(H);
    linklist p = list_get(H, pos - 1);
    list_isempty(p);
    //2.分配内存空间,创建一个新的节点q
    linklist q = (linklist) malloc(sizeof(listnode));
    list_isempty(q);
    q->data = value;
    q->next = NULL;
    //3.将q指向的节点插入到链表的pos位置,p指向该节点的后面
    q->next = p->next;
    p->next = q;
    return 0;
}

/*
 * 6.在链表中删除指定位置的元素
 */
int list_delete(linklist H, int pos) {
    linklist p, q;
    //1.首先需要分配内存空间,p指向要插入节点的前一个节点位置
    list_isempty(H);
    p = list_get(H, pos - 1);
    if (p == NULL || p->next == NULL) {
        printf("删除位置不存在\n");
        return -1;
    }
    //2.删除pos位置的节点,更正链表
    q = p->next;       //q指向要删除的节点，相当于中间变量的作用
    p->next = q->next; //p指向要删除的节点的后一个节点,即p指向q的下一个节点，将q从链表中删除
    //3.释放q指向的节点的内存空间
    printf("删除的元素是:%d\n", q->data);
    free(q);  //释放q指向的节点的内存空间
    q = NULL;
    return 0;
}

/*
 * 7.删除链表中所有元素
 */
int list_free(linklist H) {
    linklist p;
    list_isempty(H);
    p = H;
    printf("free:");
    while (p != NULL) {  //退出循环条件为p=NULL
        H = p->next;  //H指向p的下一个节点
        printf("%d ", p->data);
        free(p);
        p = H;        //p指向H，即p指向p的下一个节点
    }
    printf("\n");
    return 0;
}

/*
 * 8.反转链表
 */
int list_reverse(linklist H) {
    linklist p, q;
    list_isempty(H);
    if (H->next == NULL || H->next->next == NULL) {
        //链表只有一个或者两个节点
        return 0;
    }
    p = H->next->next; //p 是一个临时指针，用于遍历原始链表。初始化时，p 指向链表的第二个节点（H->next->next）
    H->next->next = NULL;//将第一个节点的 next 指针设置为 NULL，这实际上将链表从第一个节点断开，创建了两个子链表。一个子链表只包含第一个节点，另一个子链表包含其余的节点。
    while (p != NULL) {
        q = p;
        p = p->next;  //p指向下一个节点
        //将q插入到链表H头结点后面，第一个节点的前面
        q->next = H->next; //将q指向的节点插入到链表H的第一个节点的前面,即头结点后面
        H->next = q; //将q指向的节点插入到链表H的第一个节点的前面,即头结点后面
    }
    return 0;
}

/*
 * 9.返回链表中最大值的前一个节点的指针
 */
linklist list_adjmax(linklist H, data_t *value) {
    linklist p, q, r;
    data_t max, sum;
    list_isempty(H);
    if (H->next == NULL || H->next->next == NULL || H->next->next->next == NULL) {
        //链表为空或者链表只有三个节点
        return H;
    }
    //1.找到链表中前两个节点,并计算他们的和为最大值
    q = H->next;
    p = H->next->next;
    r = q;
    max = p->data + q->data;
    //2.遍历链表,找到最大值，r指向最大值之和的第一个节点
    while (p->next != NULL) {
        p = p->next;
        q = q->next;
        sum = p->data + q->data;
        if (sum > max) {
            max = sum;
            r = q;
        }
    }
    *value = max;
    return r;
}

/*
 * 10.合并两个链表
 */
linklist list_merge(linklist H1, linklist H2) {
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    // 使用一个新的头节点，这样我们就不需要单独处理第一个节点
    linklist head = (linklist) malloc(sizeof(listnode));
    linklist r = head; // r 是新链表的当前节点
    // 不需要修改 list1 和 list2 的 next 指针
    linklist p = H1;
    linklist q = H2;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
        } else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    if (p == NULL)
        r->next = q;
    if (q == NULL)
        r->next = p;
    linklist result = head->next; // 跳过我们添加的新头节点
    free(head); // 释放我们添加的新头节点
    return result;
}

/*
 * 11.链表排序
 */
int list_sort(linklist H) {
    list_isempty(H);
    if (H->next == NULL) {
        printf("链表只有一个节点\n");
        return -1;
    }
    linklist sorted = NULL; // 创建一个新的链表来存储排序后的节点
    linklist current = H->next; // 从头节点的下一个节点开始
    while (current != NULL) {
        linklist next = current->next; // 保存当前节点的下一个节点
        if (sorted == NULL || sorted->data >= current->data) {
            // 如果新链表为空或当前节点的数据小于新链表的第一个节点的数据
            current->next = sorted;
            sorted = current;
        } else {
            // 否则，找到新链表中适合插入当前节点的位置
            linklist temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next; // 移动到下一个节点
    }
    H->next = sorted; // 更新头节点的next指针
    return 0;
}

/*
 * 12.判断是否为空链表
 */
int list_isempty(linklist H) {
    if (H == NULL) {
        printf("链表不存在\n");
        return -1;
    }
    return 0;
}

/*
 * 13.查找链表中是否存在指定元素,返回该元素的前驱节点的指针
 */
linklist list_find(linklist H, data_t value) {
    linklist p;
    p = H;
    while (p->next != NULL && p->next->data != value)
        p = p->next;
    return p;
}

/*
 * 14.//删除链表中指定值的元素
 */
int list_delete_value(linklist H, data_t value) {
    linklist p, q;
    p = list_find(H, value);
    if (p == NULL || p->next == NULL) {
        printf("删除元素不存在\n");
        return -1;
    }
    q = p->next;
    p->next = q->next;
    printf("删除的元素是:%d\n", q->data);
    free(q);  //释放q指向的节点的内存空间
    q = NULL;
    return 0;
}