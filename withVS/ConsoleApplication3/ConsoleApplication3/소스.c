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
		printf("���� 369 ���� �غ���! (Y/N)\n");
		answer = getchar();
		getchar();
		if (answer == 'y' || answer == 'Y')
			game();
		else
			return 0;
		fflush(stdin);
		printf("���ҷ�? (Y/N) \n");
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
		return -1; //¦
}

int turncheck(int nowturn)
{
	if (nowturn)
		return 0; //��ǻ������
	else
		return 1; //������
}

void computer_game(int num)
{
	if (num % 3)
		printf("%d ! \n", num);
	else
		printf("¦ ! \n");
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
			printf("��!\n");
			return 0; //��
		}
	}
	else
	{
		if (mynum)
		{
			printf("��!\n");
			return 0; //��
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
	
	printf("�� �����Ѵ�!\n");
	if (!turn)
		printf("�ʺ��� ��!\n");

	while (going)
	{
		turn = turncheck(turn);
		if (turn)
			going = my_game(num);
		else
			computer_game(num);
		num++;
	}
	
	printf("�Ʊ���.. �Ф�\n", --num);
	return;

}
