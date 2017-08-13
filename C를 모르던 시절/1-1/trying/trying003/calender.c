#include <stdio.h>

int main(void)
{
	int date, day = 1;

	printf("Su Mo Tu We Th Fr Sa\n");

	for(date = -1; date <= 30; date++) //date:
	{
			if(date<1)
				printf("   ");
			else
				printf("%2d ", date);
			day++;
			if(day==8)
			{
				printf("\n");
				day = 1;
			}
	}
	return 0;
}



