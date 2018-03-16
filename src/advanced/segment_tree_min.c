#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 100005
#define MAX_TREES 2000005

void build(int tree[], int datas[], int node, int start, int end)
{
    if (start == end) {
        tree[node] = datas[start];
    } else {
        int mid = (start + end) / 2;
        build(tree, datas, 2*node, start, mid);
        build(tree, datas, 2*node+1, mid+1, end);
        if (tree[2*node] < tree[2*node+1]) {
            tree[node] = tree[2*node];
        } else {
            tree[node] = tree[2*node+1];
        }
    }
}

void update(int tree[], int datas[], int node, int start, int end, int idx, int val)
{
    if (start == end) {
        datas[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(tree, datas, 2*node, start, mid, idx, val);
        } else {
            update(tree, datas, 2*node+1, mid+1, end, idx, val);
        }
        
        if (tree[2*node] < tree[2*node+1]) {
            tree[node] = tree[2*node];
        } else {
            tree[node] = tree[2*node+1];
        }
    }
}

int query(int tree[], int node, int start, int end, int l, int r)
{
    if ((r < start) || (end < l)) {
        return MAX_LIMIT;
    }
    
    if ((l <= start) && (end <= r)) {
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    int p1 = query(tree, 2*node, start, mid, l, r);
    int p2 = query(tree, 2*node+1, mid+1, end, l, r);
    
    if (p1 < p2) {
        return p1;
    } else {
        return p2;
    }
}

int main()
{
    int input_numbers, test_numbers = 0;
    int *datas;
    int *trees;
    int i = 0;
    char cmd;
    int index, val = 0;
    int left, right, result = 0;
	
    datas = malloc(MAX_LIMIT * sizeof(int));
    memset(datas, 0, sizeof(int) * MAX_LIMIT);
    
    trees = malloc(MAX_TREES * sizeof(int));
    memset(trees, 0, sizeof(int) * MAX_TREES);
    
    scanf("%d", &input_numbers);
    scanf("%d", &test_numbers);
	
	for (i = 1; i <= input_numbers; i++) {
        scanf("%d", &datas[i]);	    
	}
    
    build(trees, datas, 1, 1, input_numbers);
    
    for (i = 0; i < test_numbers; i++) {
        scanf(" %c", &cmd);
        if (cmd == 'u') {
            scanf("%d", &index);
            scanf("%d", &val);
            if (index > input_numbers )
                continue;
            update(trees, datas, 1, 1, input_numbers, index, val);
        } else {
            scanf("%d", &left);
            scanf("%d", &right);
            result = query(trees, 1, 1, input_numbers, left, right);
            printf("%d\n", result);
        }
    }

    free(datas);
    free(trees);
	
    return 0;
}
