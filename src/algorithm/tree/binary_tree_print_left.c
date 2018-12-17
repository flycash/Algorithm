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
    struct TreeNode root = {
        .data=1
    };

    return 0;
}
