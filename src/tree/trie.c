#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDS 26

typedef struct node_s node_t;
typedef node_t *node;

struct node_s {
    char ch;
    int weight;
    int max_weight;
    node childs[MAX_CHILDS];
};

void create_node(node *np, char c)
{
    node newp = malloc(sizeof(struct node_s));
    memset(newp, 0, sizeof(struct node_s));
    newp->ch = c;
    newp->weight = 0;
    *np = newp;
}

inline int max ( int a, int b ) { return a > b ? a : b; }

inline void set_weight(node np, int weight)
{
    np->weight = weight;
}

node attach_node(node root, char c)
{
    int index = c - 'a';
    int i;

    if (root->childs[index]) {
        return root->childs[index];
    }

    create_node(&root->childs[index], c);
    return root->childs[index];
}

void attach_string(node root, char str[], int weight)
{
    int i = 0;
    node new = root;

    for (i = 0; str[i] != '\0'; i++) {
        new = attach_node(new, str[i]);
    }

    set_weight(new, weight);
}

int find_maxweight(node root)
{
    int max_weight = -1, weight = 0;
    int i = 0;

    if (root == NULL)
        return max_weight;

    if (root->max_weight != 0)
        return root->max_weight;

    max_weight = root->weight;

    for (i = 0; i < MAX_CHILDS; i++) {
        weight = find_maxweight(root->childs[i]);
        max_weight = max(max_weight, weight);
    }
 
    root->max_weight = max_weight;   
    return max_weight;
}

int find_match(node root, char str[])
{
    int i = 0, index = 0;
    node search = root;

    for (i = 0; str[i] != '\0'; i++) {
        index = str[i] - 'a';
        if (!search) {
            return -1;
        }
        search = search->childs[index];
    }

    if (!search) {
        return -1;
    }

    return find_maxweight(search);
}

int main()
{
    int nodes_num, search_num, weight;
    node root;
    char input_str[1000000];
    int i, max_weight;

    create_node(&root, 0);

    scanf("%d", &nodes_num);
    scanf("%d", &search_num);

    for (i = 0; i < nodes_num; i++) {
        scanf("%s", input_str);
        scanf("%d", &weight);
        attach_string(root, input_str, weight);
    }

    for (i = 0; i < search_num; i++) {
        scanf("%s", input_str);
        max_weight = find_match(root, input_str);
        printf("%d\n", max_weight);
    }

    return 0;
}
