//
// Created by k on 23-9-25.
//
typedef int data_t;

typedef struct node {
    data_t data;
    struct node *next;  //指向下一个节点的指针,节点类型是struct node
} listnode, *linklist;  //listnode是节点类型名,linklist是节点指针类型名

linklist list_create();  //创建一个空的线性表,返回线性表的地址
int list_tail_insert(linklist H, data_t value); //尾插法创建链表,返回1表示成功,返回0表示失败
int list_show(linklist H); //遍历链表,打印链表中的每个元素
linklist list_get(linklist H, int pos); //获取链表中指定位置的元素地址
int list_insert(linklist H, data_t value, int pos); //在链表中指定位置插入元素
int list_delete(linklist H, int pos); //删除链表中指定位置的元素
int list_free(linklist H); //释放链表的内存空间
int list_reverse(linklist H); //反转链表
linklist list_adjmax(linklist H, data_t *value); //返回链表中最大值的前一个节点的指针
linklist list_merge(linklist H1, linklist H2); //合并两个链表
int list_sort(linklist H); //对链表进行排序
int list_isempty(linklist H); //判断链表是否为空
linklist list_find(linklist H, data_t value); //查找链表中是否存在指定元素,返回该元素的前驱节点的指针
int list_delete_value(linklist H, data_t value); //删除链表中指定值的元素

#ifndef LINKLIST_TEST_LINKLIST_H
#define LINKLIST_TEST_LINKLIST_H

#endif //LINKLIST_TEST_LINKLIST_H
