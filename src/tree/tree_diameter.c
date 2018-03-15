#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_LEFT 'L'
#define NODE_RIGHT 'R'
#define MAX_NODES 21

struct node_s {
    int data;
    struct node_s *left;
    struct node_s *right;
};

typedef struct node_s *node;

inline int max ( int a, int b ) { return a > b ? a : b; }

void create_node(node *root, int data)
{
    node p = malloc(sizeof(node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    *root = p;
}

node append_node(node root, int data, char flag)
{
    if (root == NULL)
        return NULL;

    node p = malloc(sizeof(node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    if (flag == NODE_LEFT) {
        root->left = p;
    } else {
        root->right = p;
    }

    return p;
}

node find_append_pos(node root, char node_path[], char *flag)
{
    int j = 0;
    node append_root = root;

    for (j = 0; j < MAX_NODES; j++) {
        if (node_path[j] == '\0')
            return append_root;

        if (node_path[j] == NODE_LEFT) {
            if (append_root->left == NULL) {
                append_root = append_node(append_root, 0, node_path[j]);
            } else {
                append_root = append_root->left;
            }
        } else {
            if (append_root->right == NULL) {
                append_root = append_node(append_root, 0, node_path[j]);
            } else {
                append_root = append_root->right;
            }
        }
    }   

    return NULL;
}

int cal_diameter(node root, int *height)
{
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;

    if (root == NULL) {
        *height = 0;
        return 0;
    }

    ldiameter = cal_diameter(root->left, &lh);
    rdiameter = cal_diameter(root->right, &rh);
    
    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int main()
{
    int nodes_num, data;
    node root;
    char node_path[MAX_NODES];
    int i = 0, j = 0, diameter = 0, height = 0;

    scanf("%d", &nodes_num);
    scanf("%d", &data);
    create_node(&root, data);

    for (i = 0; i < nodes_num - 1; i++) {
        scanf("%s", node_path);
        scanf("%d", &data);
        char flag;
        node append_root = find_append_pos(root, node_path, &flag);
        append_root->data = data;
    }

    diameter = cal_diameter(root, &height);
    printf("%d\n", diameter);
    return 0;
}
