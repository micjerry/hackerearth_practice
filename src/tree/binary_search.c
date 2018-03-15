#include <stdio.h>
#include <stdlib.h>

struct node_s {
    int data;
    struct node_s *left;
    struct node_s *right;
};

typedef struct node_s *node;


void create_node(node *root, int data)
{
    node node_root = *root;
    if (node_root == NULL) {
        node p = malloc(sizeof(node));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
        *root = p;
        return;
    }

    if (node_root->data < data) {
        return create_node(&node_root->right, data);
    } else {
        return create_node(&node_root->left, data);
    }
}

node search(node root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
        return root;

    if (root->data > data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }

    return NULL;
}

void pre_order(node root)
{
    if (root == NULL)
        return;

    printf("%d\n", root->data);
    pre_order(root->left);
    pre_order(root->right);
}


int main()
{
    int nodes_num = 0, data = 0, cond = 0;
    node root = NULL;
    int i = 0;

    scanf("%d", &nodes_num);

    for (i = 0; i < nodes_num; i++) {
        scanf("%d", &data);
        create_node(&root, data);
    }

    scanf("%d", &cond);
    node search_result = search(root, cond);
    pre_order(search_result);

    return 0;
}
