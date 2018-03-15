#include <stdio.h>
#include <stdlib.h>


void bubbleup(int queue[], int top_pos)
{
    int pos = top_pos;
    while ((pos > 0 && (pos/2 > 0)) && (queue[pos/2] < queue[pos])) {
        int y = queue[pos/2];
        queue[pos/2] = queue[pos];
        queue[pos] = y;
        pos = pos / 2;
    }
}

/*print_queue(int queue[], int top)
{
    int i = 0;
    for (i = 1; i <= top; i++) {
        printf("%d ", queue[i]);
        printf("\n");
    }
}*/

void add_element(int queue[], int num, int *top)
{
    int top_pos = *top + 1;
    queue[top_pos] = num;
    *top = top_pos;
    if (top_pos > 1)
        bubbleup(queue, top_pos);
}


void printmax(int queue[], int top_pos) 
{
    if (top_pos > 0)
        printf("%d\n", queue[1]);
}

int main()
{
    int initial_num, initial_value = 0;
    int opt_num, opt_type, opt_value = 0;
    int * stack_food = malloc(110001*sizeof(int));
    int top = 0;
    int i = 0;

    scanf("%d", &initial_num);

    for (i = 0; i < initial_num; i++) {
        scanf("%d", &initial_value);
        add_element(stack_food, initial_value, &top);
    }

    scanf("%d", &opt_num);
    for (i = 0; i < opt_num; i++) {
        scanf("%d", &opt_type);
        if (opt_type == 1) {
            scanf("%d", &opt_value);
            add_element(stack_food, opt_value, &top);
        } else if (opt_type == 2) {
            printmax(stack_food, top);
        }
    }

    return 0;
}
