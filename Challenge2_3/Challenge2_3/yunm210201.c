#include <stdio.h>

int strangesum(char * str)
{
	int i = 0;
	int sum = 0;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			sum += str[i] - '0';
		++i;
	}
	return sum;
}

int yunm210201() 
{
	char a[100] = { 0, };
	printf("ÀÔ·Â : ");
	scanf("%s", a);
	printf("sum : %d", strangesum(a));
	return 0;
}