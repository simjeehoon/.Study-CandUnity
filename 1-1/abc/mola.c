#include <stdio.h>

int main(void)
{
	int a, b, c;
	long double x, y, z, res;
	printf("1/a^2 = 1/b^2 + 1/c^2 순서쌍 (a,b,c) 찾기\n");
	for(a=1;a<10;a++)
	{	
		for(b=1;b<10;b++)
		{
			for(c=1;c<10;c++)
			{
				x = 1/(a*a);
				y = 1/(b*b);
				z = 1/(c*c);
				res = x-(y+z);
				if (!res)
				{
					printf("(%d,%d,%d)\n", a, b, c);
				}
			}
		}
	}
	return 0;
}

