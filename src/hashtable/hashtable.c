#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s node_t;

struct node_s {
    node_t *next;
    unsigned int key;
    int len;
    char *value;
};


#define MAX_LIMIT 131072

int hash_key1(unsigned int org)
{
    return org % MAX_LIMIT;
}

int hash_key2(unsigned int org)
{
    return ((org % 27) | 1);
}

static char *ngx_copy(char *dst, char *src, int len)
{
    if (len < 17) {
        while (len) {
            *dst++ = *src++;
            len--;   
        }
    } else {
        memcpy(dst, src, (size_t)len);
    }
} 

void set_node(node_t *node, int key, char *str)
{
    node->key = key;
    node->len = strlen(str);
    node->value = malloc(node->len + 1); 
    memset(node->value, 0, node->len + 1);
    ngx_copy(node->value, str, node->len);
    node->next = NULL;
}

void append_value(node_t **node, int key, char *str)
{
    if (*node == NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        set_node(new_node, key, str);
        *node = new_node;
    } else {
        node_t *dst_node = *node;
        while (dst_node) {
            if (dst_node->next == NULL) {
                dst_node->next = malloc(sizeof(node_t));
                set_node(dst_node->next, key, str);
                break;
            } else {
                dst_node = dst_node->next;
            }
        }
    }
}

int print_key(node_t *node, unsigned int coo_number)
{
    node_t *dst_node = node;
    while (dst_node) {
        if (dst_node->key == coo_number) {
            printf("%s\n", dst_node->value);
            return 1;
        }

        dst_node = dst_node->next;
    }

    return 0;
}

void insert_hash(node_t **hash_array, unsigned int coo_number, char *name)
{
    int key = hash_key1(coo_number);
    int step = hash_key2(coo_number);

    //printf("key = %d, step = %d\n", key, step);
    hash_array = hash_array + key;
    while (*hash_array != NULL) {
        hash_array = hash_array + step;
    }

    append_value(hash_array, coo_number, name);
}

void search_hash(node_t **hash_array, unsigned int coo_number)
{
    int key = hash_key1(coo_number);
    int step = hash_key2(coo_number);
    hash_array = hash_array + key;
    while (!(*hash_array) || !print_key(*hash_array, coo_number)) {
        hash_array = hash_array + step;
    }
}

int main()
{
    int initial_num, query_num;
    unsigned int roll_number = 0;
    char name[26];
    int i = 0;
    node_t **hash_arry = malloc(MAX_LIMIT*sizeof(node_t *));
    memset(hash_arry, 0, MAX_LIMIT*sizeof(node_t *));

    scanf("%d", &initial_num);
    //printf("%d read\n", initial_num);

    for (i = 0; i < initial_num; i++) {
        scanf("%u", &roll_number);
        scanf("%s", name);
        //printf("%d read\n", i);
        insert_hash(hash_arry, roll_number, name);
    }

    scanf("%d", &query_num);
    for (i = 0; i < query_num; i++) {
        scanf("%u", &roll_number);
        search_hash(hash_arry, roll_number);
    }

    return 0;
}
