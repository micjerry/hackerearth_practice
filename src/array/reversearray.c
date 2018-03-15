#include <stdio.h>

int main()
{
	int input_numbers, input_data = 0;
	int datas[100];
	int i = 0;
	
	scanf("%d", &input_numbers);
	
	for (i = 0; i < input_numbers; i++) {
            scanf("%d", &datas[i]);
	    //scanf("%d", &input_data);
            //datas[i] = input_data;
	}
	
	for (i = input_numbers; i > 0; i--)
	{
          printf("%d\n", datas[i - 1]);
	}
	
    return 0;
}
