#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIMIT 100

int hash_key(char s)
{
    return s - ' ';
}

void append(int occurs[], char c)
{
    int key = hash_key(c);
    occurs[key] = occurs[key] + 1;
}

void print_max(int occurs[])
{
    int max_ocur = 0;
    int pos, i = 0;
    char c = ' ';

    for (i = 0; i < MAX_LIMIT; i++) {
        if (occurs[i] > max_ocur) {
            max_ocur = occurs[i];
            pos = i;
        }
    }

    c = c + pos;

    printf("%c %d\n", c, max_ocur);
}

int main()
{
    char input[1001];
    int occurs[MAX_LIMIT];
    int iput_len, i= 0;

    memset(occurs, 0, MAX_LIMIT*sizeof(int));

    fgets (input, sizeof(input), stdin);
    iput_len = strlen(input);

    if ((iput_len > 0) && (input[iput_len - 1] == '\n'))
        iput_len = iput_len - 1;

    for (i = 0; i < iput_len; i++) {
        append(occurs, input[i]);
    }

    print_max(occurs);
    return 0;
}
