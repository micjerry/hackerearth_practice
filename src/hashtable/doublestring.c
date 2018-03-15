#include <stdio.h>
#include <string.h>

unsigned int hash_key(char s)
{
    return s - 'a';
}

int exist(unsigned int *hash, char s)
{
    unsigned int hash_value = *hash;
    unsigned int key = hash_key(s);
    unsigned int pos = 1 << key;

    if (hash_value & pos)
        return 1;

    *hash = hash_value | pos;
    return 0;
}

void check_double(char input[])
{
    int input_len = strlen(input);
    int i = 0;
    unsigned int hash = 0;


    for (i = 0; i < input_len; i++) {
        if (exist(&hash, input[i])) {
            printf("Yes\n");
            return;
        }
    }

    printf("No\n");
}

int main()
{
    char input[101];
    int test_number= 0;
    int i= 0;

    scanf("%d", &test_number);
    for (i = 0; i < test_number; i++) {
        scanf("%s", input);
        check_double(input);
    }

   return 0;
}
