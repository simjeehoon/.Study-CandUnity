#include <stdio.h>

int main(void)
{
	int n;
	int sum0, sum1;
	int i = 1;

	scanf("%d", &n);

	while(i<=n)
	{
		if(i%2 == 0)
			sum0 += i;
		else
			sum1 += i;
		i++;
	}
	printf("짝합:%d 홀합:%d", sum0, sum1);
	return 0;
}

