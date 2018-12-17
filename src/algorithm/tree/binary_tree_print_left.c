#include <stdio.h>
struct TreeNode {
    struct TreeNode * left;
    struct TreeNode * right;
    int data;
};

void print_left_node(struct TreeNode* root) {
    struct TreeNode * curNode = root;
    while (curNode!= NULL) {
        printf("%d \n", curNode->data);
        if (curNode->left != NULL) {
            curNode = curNode->left;
        } else if (curNode->right != NULL) {
            curNode = curNode->right;
        } else {
            curNode = NULL;
        }
    }
}

int main() {
    struct TreeNode leftRightLeft = {
        .data = 7
    };
    struct TreeNode leftRight= {
        .left = &leftRightLeft,
        .data =4
    };
    struct TreeNode left = {
        .right = &leftRight,
        .data = 3
    };
    struct TreeNode right = {
        .data = 2
    };
    struct TreeNode root = {
        .left = &left,
        .right = &right,
        .data = 1
    };
    print_left_node(&root);
    return 0;
}
