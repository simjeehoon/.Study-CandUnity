#include <stdio.h>

int main(void)
{
	int x, y, t, u;
	t=0;
	x=-5;
	while(t == 0 && x <= 6)
	{
		u=0;
		y=-5;

		while(u == 0 && y <= 5)
		{
			if(x + y == 0)
				u=1;
			y++;
		}
	if (u==0)
		t==1;
	else
		x++;

	}
	printf(" 진리값 : %d", t);
	return 0;
}






			
