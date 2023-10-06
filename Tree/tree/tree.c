//
// Created by k on 23-10-6.
//

#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *1.初始化树
 */
link_tree tree_create() {
    //1.创建根节点
    data_t data;
    scanf("%c", &data);
    if (data == '#')
        return NULL;
    link_tree root = (link_tree) malloc(sizeof(bitree));
    if (root == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    //2.初始化根节点
    root->data = data;
    root->left = tree_create();
    root->right = tree_create();
    return root;
}

/*
 *2.先序遍历
 */
void tree_preorder(link_tree root) {
    if (root == NULL)
        return;
    printf("%c ", root->data);
    tree_preorder(root->left);
    tree_preorder(root->right);
}

/*
 *3.中序遍历
 */
void tree_inorder(link_tree root) {
    if (root == NULL)
        return;
    tree_inorder(root->left);
    printf("%c ", root->data);
    tree_inorder(root->right);
}

/*
 *4.后序遍历
 */
void tree_postorder(link_tree root) {
    if (root == NULL)
        return;
    tree_postorder(root->left);
    tree_postorder(root->right);
    printf("%c ", root->data);
}

/*
 *5.层次遍历
 */
void tree_levelorder(link_tree root) {
    //1.创建队列
    linkqueue *lq = create_linkqueue();
    if (lq == NULL) {
        printf("create_linkqueue error\n");
        return;
    }
    if (root == NULL) {
        printf("tree is empty\n");
        return;
    }
    //2.根节点入队
    printf("%c ", root->data);
    queue_push(lq, root);
    //3.循环入队
    while (!queue_empty(lq)) {
        root = queue_pop(lq);
        if (root->left != NULL) {   //如果左子树不为空,则入队
            printf("%c ", root->left->data);
            queue_push(lq, root->left);
        }
        if (root->right != NULL) {  //如果右子树不为空,则入队
            printf("%c ", root->right->data);
            queue_push(lq, root->right);
        }
    }
    puts("");
}