#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100000
#define MAX_COLS 11

int cal_depth(int **tree, int node)
{
    int depth = 1;
    int node_pos = node;

    if (node_pos == 0)
        return 0;

    while (tree[node_pos][0] != 0) {
        node_pos = tree[node_pos][0];
        depth++;
    }

    return depth;
}

int upto_parent(int **tree, int node, int steps)
{
    int parent = node, i = 0;

    if (steps == 0)
        return node;

    for (i = 0; i < steps; i++) {
        parent = tree[parent][0];
    }

    return parent;
}

void upto_samelevel(int **tree, int childs[], int childs_depth[], int len, int min_depth, int *finded, int *node)
{
    int i = 0, unique = 1;

    if (min_depth == 0) {
        *finded = 1;
        *node = 0;
        return;
    }

    for (i = 0; i < len; i++) {
        childs[i] = upto_parent(tree, childs[i], childs_depth[i] - min_depth);
        if (unique && (i > 0) && (childs[i] != childs[i - 1]))
            unique = 0;
    }

    if (unique) {
        *finded = 1;
        *node = childs[0];
    }
}

void find_lca(int **tree, int childs[], int len)
{
    int i, child = 0;
    int unique = 1;

    for (i = 0; i < len; i++) {
        child = childs[i];
        childs[i] = tree[child][0];
        if (unique && (i > 0) && (childs[i] != childs[i - 1]))
            unique = 0;
    }


    if (unique) {
        printf("%d\n", childs[0]);
        return;
    } 

    return find_lca(tree, childs, len);
}


int main()
{
    int nodes_num = 0, index = 0, last_index = 0, min_depth = MAX_ROWS;
    int **tree;
    int *child_sets;
    int *child_depths;
    int i = 0, j = 1;
    int result_node = 0, founded = 0;

    //malloc memory
    tree = malloc(MAX_ROWS * sizeof(*tree));
    for (i = 0; i < MAX_ROWS; i++) {
        tree[i] = malloc(MAX_COLS * sizeof(*tree[i]));
    }

    child_sets = malloc(MAX_ROWS * sizeof(int));
    child_depths = malloc(MAX_ROWS * sizeof(int));

    //read test data
    scanf("%d", &nodes_num);

    for (i = 1; i < nodes_num; i++) {
        scanf("%d", &index);
        if (last_index != index) 
            j = 1;

        tree[index][j++] = i;
        tree[i][0] = index;
        last_index = index;
    }

    scanf("%d", &nodes_num);
    for (i = 0; i < nodes_num; i++) {
        scanf("%d", &child_sets[i]);
        child_depths[i] = cal_depth(tree, child_sets[i]);
        if (child_depths[i] < min_depth)
            min_depth = child_depths[i];
    }

    //find lca
    upto_samelevel(tree, child_sets, child_depths, nodes_num, min_depth, &founded, &result_node);
    if (founded) {
        printf("%d\n", result_node);
        return 0;
    }

    find_lca(tree, child_sets, nodes_num);

    return 0;
}
