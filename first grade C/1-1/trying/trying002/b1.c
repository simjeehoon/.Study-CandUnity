#include <stdio.h>
int main(void)
{
	int i = 1;
	int res =1;
	while (i<=5)
	{
		res *= i;
		i++;
	}

	printf("%d",res);
	return
	   	0;
}
		
