#include <stdio.h>
#include <string.h>

void sort(char *a, int left, int right)
{
    if (left > right)
        return;

    int i = left;
    int j = right;
    char key = a[left];

    while (i < j)
    {
        while (i < j && key >= a[j])
            j--;

        a[i] = a[j];

        while (i < j && key <= a[i])
            i++;

        a[j] = a[i];
    }

    a[i] = key;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}

void order_string()
{
    char input[10000];
    int start_pos, end_pos, input_len = 0;
    int i, j = 0;
    char temp;

    scanf("%s", input);
    scanf("%d", &start_pos);
    scanf("%d", &end_pos);

    input_len = strlen(input);
    if (end_pos >= input_len || start_pos > end_pos) {
        return;
    }

    if (start_pos < end_pos) {
        sort(input, start_pos, end_pos);
    }

    printf("%s\n", input);
}


int main()
{
        int test_numbers,i = 0;
        scanf("%d", &test_numbers);
        if (test_numbers < 1 || test_numbers > 1000)
            return 0;

        for (i = 0; i < test_numbers; i++)
            order_string();

        return 0;
}
