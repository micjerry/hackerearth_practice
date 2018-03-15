#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");
}

int main()
{
	int test_number, i, j;
    int *test_input = malloc(1000000*sizeof(int));
	int max_unique = -1;
	
	scanf("%d", &test_number);

    for (i = 0; i < test_number; i++)
        scanf("%d", &test_input[i]);

	
	for (i = 0; i < test_number; i++) {
        if (test_input[i] == -1)
            continue;

        int find_repeat = 0;
        for (j = i + 1; j < test_number; j++) {
            if (test_input[j] == test_input[i]) {
                test_input[j] = -1;
                find_repeat = 1;
            }

        }

        if (!find_repeat && (test_input[i] > max_unique))
            max_unique = test_input[i];
    }

    printf("%d\n", max_unique);

    return 0;
}
