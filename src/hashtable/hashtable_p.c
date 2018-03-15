#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node_s {
    struct node_s *next;
    unsigned int key;
    int len;
    char *value;
};

typedef struct node_s *node_p;


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

void set_node(node_p node, int key, char *str)
{
    node->key = key;
    node->len = strlen(str);
    node->value = malloc(node->len + 1); 
    memset(node->value, 0, node->len + 1);
    ngx_copy(node->value, str, node->len);
    node->next = NULL;
}

void create_node(node_p *node, int key, char *str)
{
    node_p temp;
    temp  = malloc(sizeof(node_p));
    set_node(temp, key, str);
    *node = temp;
}

int print_key(node_p node, unsigned int coo_number)
{
    if (node->key == coo_number) {
        printf("%s\n", node->value);
        return 1;
    }

    return 0;
}

void insert_hash(node_p hash_array[], unsigned int coo_number, char *name)
{
    int pos = 0;
    int key = hash_key1(coo_number);
    int step = hash_key2(coo_number);

    pos = key;
    while (hash_array[pos] != NULL) {
        pos = (pos + step) % MAX_LIMIT;
    }

    create_node(&hash_array[pos], coo_number, name);
}

void search_hash(node_p hash_array[], unsigned int coo_number)
{
    int pos = 0;
    int key = hash_key1(coo_number);
    int step = hash_key2(coo_number);

    pos = key;
    while ((hash_array[pos] == NULL) || !print_key(hash_array[pos], coo_number)) {
        pos = (pos + step) % MAX_LIMIT;
    }
}

int main()
{
    int initial_num, query_num;
    unsigned int roll_number = 0;
    char name[26];
    int i = 0;
    node_p *hash_arry = malloc(MAX_LIMIT*sizeof(node_p *));
    memset(hash_arry, 0, MAX_LIMIT*sizeof(node_p *));

    scanf("%d", &initial_num);

    for (i = 0; i < initial_num; i++) {
        scanf("%u", &roll_number);
        scanf("%s", name);
        insert_hash(hash_arry, roll_number, name);
    }

    scanf("%d", &query_num);
    for (i = 0; i < query_num; i++) {
        scanf("%u", &roll_number);
        search_hash(hash_arry, roll_number);
    }

    return 0;
}
