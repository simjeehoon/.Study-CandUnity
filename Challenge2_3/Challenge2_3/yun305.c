#include "main.h"

static int input();
int computer_determine();
static int compare(int myhand, int com);
int result_process(int result, int myhand, int com, int * win, int * draw);

int yun305() {
	int my_card, com_card;
	int win = 0, draw = 0;
	int result;
	do {
		my_card = input();
		com_card = computer_determine();
		result = compare(my_card, com_card);
	} while (result_process(result, my_card, com_card, &win, &draw));
	return 0;
}

static int input() {
	int my_card;
	do {
		printf("������ 1, ������ 2, ���� 3: ");
		scanf("%d", &my_card);
	} while (!(1 <= my_card&&my_card <= 3));
	return my_card;
}

int computer_determine() {
	int computer_card;
	srand((unsigned)time(NULL));
	computer_card = rand() % 3 + 1;
	return computer_card;
}

static int compare(int myhand, int com) {
	if (myhand == 1)//����
	{
		if (com == 1)
			return 0;//���� : ���
		if (com == 2)
			return 1;//���� : �̱�
		if (com == 3)
			return -1;//�� : ��
	}
	if (myhand == 2)//����
	{
		if (com == 1)
			return -1;//���� : ��
		if (com == 2)
			return 0;//���� : ���
		if (com == 3)
			return 1;//�� : �̱�
	}
	if (myhand == 3)// ��
	{
		if (com == 1)
			return 1;//���� : �̱�
		if (com == 2)
			return -1;//���� : ��
		if (com == 3)
			return 0;//�� : ���
	}
}

int result_process(int result, int myhand, int com, int * win, int * draw)
{
	int progress;
	char * card_name[3] = { "����", "����", "��" };
	switch (result) {
	case 1 :
		printf("����� %s ����, ��ǻ�ʹ� %s ����, ����� �̰���ϴ�!\n", card_name[myhand - 1], card_name[com - 1]);
		++(*win);
		progress = 1;
		break;
	case 0 :
		printf("����� %s ����, ��ǻ�ʹ� %s ����, �����ϴ�!\n", card_name[myhand - 1], card_name[com - 1]);
		progress = 1;
		++(*draw);
		break;
	case -1 :
		printf("����� %s ����, ��ǻ�ʹ� %s ����, ����� �����ϴ�!\n", card_name[myhand - 1], card_name[com - 1]);
		progress = 0;
		break;
	}
	if (!progress)
		printf("\n������ ��� : %d�� %d��\n", *win, *draw);
	return progress;
}