#include <stdio.h>
#include <string.h>

int main()
{
        int arr_rows, arr_columns = 0;
        int i,j = 0;
        scanf("%d", &arr_rows);
        scanf("%d", &arr_columns);

        int twod_arrs[arr_rows][arr_columns];

        for (i = 0; i < arr_rows; i++) {
            for (j = 0; j < arr_columns; j++) {
                scanf("%d", &twod_arrs[i][j]);
            }
        }

        for ( i = 0; i < arr_columns; i++) {
           for ( j = 0; j < arr_rows; j++) {
               printf("%d ", twod_arrs[j][i]);
           }
           printf("\n");
        }

        return 0;
}
