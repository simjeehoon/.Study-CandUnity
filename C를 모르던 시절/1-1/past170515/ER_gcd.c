#include <stdio.h>

int main(void)
{
	int x, y, tmp;

	scanf("%d%d", &x, &y);

	while((x%y)!=0)
	{
		tmp = x;
		x = y;
		y = x%y;
	}
	printf("%d",y);

	return 0;

}

