#include <stdio.h>
#include <string.h>

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
    int processes[100];
    int ideals[100];
	int step = 0;
    int start_pos = 0;
	
	scanf("%d", &test_number);

    for (i = 0; i < test_number; i++)
        scanf("%d", &processes[i]);

    for (i = 0; i < test_number; i++)
        scanf("%d", &ideals[i]);
	
	for (i = 0; i < test_number; i++) {
        int need_processed = ideals[i];

        for (j = start_pos; j < test_number; j = (j + 1) % test_number) {
            if (processes[j] == 0)
                continue;

            if (processes[j] != need_processed) {
                step++;
            } else {
                processes[j] = 0;
                step++;
                start_pos = (j + 1) % test_number;
                printf("%d\n", step);
                print_array(processes, test_number);
                break;
            }
        }
    }

    printf("%d\n", step);

    return 0;
}
