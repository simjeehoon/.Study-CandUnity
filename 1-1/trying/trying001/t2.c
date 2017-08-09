#include <stdio.h>

int main(void)
{
	int x,y;
	_Bool t,u;

	t = 0;
	x = 0;

	while(t == 0 && x <=6)
	{
		u=0;
		y=0;
		while(u ==0 && y<=5)
		{
			if(x+y==5)
				u=1;
			y++;
		}
		if (u==0)
		   t = 1;
		x++;
	}

	if (t==1)
		printf("it is false");
	else
		printf("it is true");

	return 0;
}

