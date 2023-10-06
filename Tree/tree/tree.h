//
// Created by k on 23-10-6.
//
#ifndef TREE_TREE_H
#define TREE_TREE_H

typedef char data_t;
typedef struct node {
    data_t data;
    struct node *left;
    struct node *right;
} bitree, *link_tree;

link_tree tree_create();  // 创建二叉树
void tree_preorder(link_tree root);  // 先序遍历
void tree_inorder(link_tree root);  // 中序遍历
void tree_postorder(link_tree root);  // 后序遍历

void tree_levelorder(link_tree root);  //层次遍历

#endif //TREE_TREE_H
