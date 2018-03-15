#include <stdio.h>
#include <stdlib.h>


void push_stack(int stack[], int num, int *top)
{
    int top_pos = *top + 1;
    stack[top_pos] = num;
    *top = top_pos;
}

void pop_stack(int stack[], int *top) {
    int num;
    int top_pos = *top;

    if (top_pos == -1) {
        printf("No Food\n");
        return;
    }

    num = stack[top_pos];
    *top = top_pos - 1;

    printf("%d\n", num);
}


int main()
{
    int test_numbers, cmd_type, food = 0;
    int * stack_food = malloc(100000*sizeof(int));
    int top = -1;
    int i = 0;
    scanf("%d", &test_numbers);

    for (i = 0; i < test_numbers; i++) {
        scanf("%d", &cmd_type);
        if (cmd_type == 1) {
            pop_stack(stack_food, &top);
        } else if (cmd_type == 2) {
            scanf("%d", &food);
            push_stack(stack_food, food, &top);
        } else {
            return 0;
        }
    }

    return 0;
}
