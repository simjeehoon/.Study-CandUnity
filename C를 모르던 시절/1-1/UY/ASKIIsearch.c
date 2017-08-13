#include <stdio.h>

int main(void)
{
	char i;

	while ( i != '\n')
	{	
		printf("What is char? : \n");
		i = getchar();
		printf("askicode %c : %d\n", i, i);
		getchar();
	}
	return 0;
}

