#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

typedef struct node {
    int val;
    struct node *left;
    struct node *right;

} node_t;

void search(int val, node_t *root) {
    if (root == NULL) {
        printf("2分探索木に%dは存在しません。\n", val);
    } else if (root->val == val) {
        printf("2分探索木に%dは存在します。\n", val);
    } else if (root->val > val) {
        search(val, root->left);
    } else {
        search(val, root->right);
    }
}

node_t *talloc(void) {
    return ((node_t *) malloc(sizeof(node_t)));
}

node_t *insert(int val, node_t *root) {
    if (root == NULL) {
        root = talloc();
        root->val = val;
        root->right = NULL;
        root->left = NULL;
    } else if (root->val == val) {
        printf("整数%dは既に2分探索木に挿入されています。\n", val);
    } else if (root->val > val) {
        root->left = insert(val, root->left);
    } else {
        root->right = insert(val, root->right);
    }

    return (root);
}

char children_type(node_t *ptr) {
    if (ptr->left == NULL) {
        if (ptr->right == NULL) {
            return 'n';
        } else {
            return 'r';
        }
    } else if (ptr->right == NULL) {
        return 'l';
    } else {
        return 'b';
    }
}

node_t *delete_node(node_t *ptr) {
    char c;
    node_t *p, *parent_of_p;
    c = children_type(ptr);

    if (c == 'n') {
        ptr = NULL;
    } else if (c == 'l') {
        ptr = ptr->left;
    } else if (c == 'r') {
        ptr = ptr->right;
    } else {
        p = ptr->right;
        if ((children_type(p) == 'r') || (children_type(p) == 'n')) {
            p->left = ptr->left;
            ptr = p;
        } else {
            while (p->left != NULL) {
                parent_of_p = p;
                p = p->left;
            }
            parent_of_p->left = p->right;
            p->left = ptr->left;
            p->right = ptr->right;
            ptr = p;
        }
    }
    return ptr;
}

node_t *delete_item(int val, node_t *root) {
    if (root == NULL) {
        printf("データ%dは2分探索木に存在しません。\n", val);
    } else if (root->val == val) {
        root = delete_node(root);
    } else if (root->val > val) {
        root->left = delete_item(val, root->left);
    } else {
        root->right = delete_item(val, root->right);
    }
    return root;
}

void print_inorder(node_t *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d\n", root->val);
        print_inorder(root->right);
    }
}

int main() {
    char c;
    node_t *root = NULL;
    int val;

    while(TRUE){
        printf(">>>");
        scanf("%1s", &c);
        switch (c){
            case 's':
                printf("検索する整数を入力してください。: ");
                scanf("%d", &val);
                search(val, root);
                break;
            case 'i':
                printf("挿入する整数を入力してください。: ");
                scanf("%d", &val);
                root = insert(val, root);
                break;
            case 'd':
                printf("挿入する整数を入力してください。: ");
                scanf("%d", &val);
                root = delete_item(val, root);
                break;
            case 'p':
                print_inorder(root);
                break;
            case 'q':
                exit(0);
            default:
                printf("s, i, d, p, qのいずれかを入力してください。\n");
        }
    }
}