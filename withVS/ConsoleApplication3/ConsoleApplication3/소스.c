#include <stdio.h>
#include <stdlib.h>


int thisischak(int num);
int turncheck(int nowturn);
void computer_game(int num);
int my_game(int num);
void game();


int main(void)
{
	char answer;

	fflush(stdin);
	srand((unsigned)time(NULL));

	while (1)
	{
		printf("³ª¶û 369 °ÔÀÓ ÇØº¸ÀÚ! (Y/N)\n");
		answer = getchar();
		getchar();
		if (answer == 'y' || answer == 'Y')
			game();
		else
			return 0;
		fflush(stdin);
		printf("¶ÇÇÒ·¡? (Y/N) \n");
			answer = getchar();
		getchar();
		if (answer == 'y' || answer == 'Y')
			continue;
		return 0;
	}
}

int thisischak(int num)
{
	if (num % 3)
		return num;
	else
		return -1; //Â¦
}

int turncheck(int nowturn)
{
	if (nowturn)
		return 0; //ÄÄÇ»ÅÍÂ÷·Ê
	else
		return 1; //³»Â÷·Ê
}

void computer_game(int num)
{
	if (num % 3)
		printf("%d ! \n", num);
	else
		printf("Â¦ ! \n");
	return;
}

int my_game(int num)
{
	char typing[30];
	int mynum;

	scanf("%s", typing);
	mynum = atoi(typing);

	if (thisischak(num) != -1)
	{
		if (num == mynum)
		{
			return 1;
		}
		else
		{
			printf("¶¯!\n");
			return 0; //³¡
		}
	}
	else
	{
		if (mynum)
		{
			printf("¶¯!\n");
			return 0; //³¡
		}
		else
		{
			return 1;
		}
	}
}

void game()
{
	int going = 1;
	int num = 1;
	int turn = rand() % 2;
	
	printf("ÀÚ ½ÃÀÛÇÑ´Ù!\n");
	if (!turn)
		printf("³ÊºÎÅÍ ÇØ!\n");

	while (going)
	{
		turn = turncheck(turn);
		if (turn)
			going = my_game(num);
		else
			computer_game(num);
		num++;
	}
	
	printf("¾Æ±õ´Ù.. ¤Ğ¤Ğ\n", --num);
	return;

}
