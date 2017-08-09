#include <stdio.h>

int main(void)
{
	long long a=1,b=1,c=1, res=1;

	while(a<=1000)
	{
		while(b<=1000)
		{
			while(c<=1000)
			{
				res = a*a*(b*b+c*c)-b*b*c*c;
				if(!res)
					printf("(%lld, %lld, %lld)\n",a,b,c);
				c++;
			}
			b++;
			c=1;
		}

		a++;
		b=1;

	}
	return 0;
}

