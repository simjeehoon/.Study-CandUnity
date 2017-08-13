#include <stdio.h>

int main(void)
{
	int array[2][3] = {{1, 2, 3}, {4, 5}};
	int i,j;
	for(i=0; i<2; i++)
		for(j=0; j<3; j++)
			printf("array[%d][%d] = %d\n", i, j, array[i][j]);

	return 0;
}
