#include <stdio.h>
#include "tree.h"

int main() {
    link_tree root = tree_create();
    if (root == NULL) {
        printf("tree_create error\n");
        return -1;
    }
    tree_preorder(root);
    printf("\n");
    tree_inorder(root);
    printf("\n");
    tree_postorder(root);
    printf("\n");
    tree_levelorder(root);
    printf("\n");
    return 0;
}
