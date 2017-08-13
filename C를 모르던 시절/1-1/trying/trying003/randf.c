#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i = 1;
	
	srand(time(NULL));

	while (i<=10)
	{
		printf("%d\n", rand());
		i++;
	}


	return 0;
}

