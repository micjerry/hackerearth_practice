#include <stdio.h>
#include <string.h>

int main()
{
	char test_input[100];
	int test_output[10] = {0,0,0,0,0,0,0,0,0,0};
	int input_len,i,index = 0;
	
	
	scanf("%s", test_input);
	
	input_len = strlen(test_input);
        printf("%d\n", input_len);
	for (i = 0; i < input_len; i++) {
		if ((test_input[i] >= '0') && (test_input[i] <= '9')) {
			index = test_input[i] - '0';
			test_output[index]++;
		}
	}
	
        
	for (i = 0; i < 10; i++) {
		printf("%d %d\n", i, test_output[i]);
	}

        return 0;
}
