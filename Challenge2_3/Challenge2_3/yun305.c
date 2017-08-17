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
		printf("바위는 1, 가위는 2, 보는 3: ");
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
	if (myhand == 1)//바위
	{
		if (com == 1)
			return 0;//바위 : 비김
		if (com == 2)
			return 1;//가위 : 이김
		if (com == 3)
			return -1;//보 : 짐
	}
	if (myhand == 2)//가위
	{
		if (com == 1)
			return -1;//바위 : 짐
		if (com == 2)
			return 0;//가위 : 비김
		if (com == 3)
			return 1;//보 : 이김
	}
	if (myhand == 3)// 보
	{
		if (com == 1)
			return 1;//바위 : 이김
		if (com == 2)
			return -1;//가위 : 짐
		if (com == 3)
			return 0;//보 : 비김
	}
}

int result_process(int result, int myhand, int com, int * win, int * draw)
{
	int progress;
	char * card_name[3] = { "바위", "가위", "보" };
	switch (result) {
	case 1 :
		printf("당신은 %s 선택, 컴퓨터는 %s 선택, 당신이 이겼습니다!\n", card_name[myhand - 1], card_name[com - 1]);
		++(*win);
		progress = 1;
		break;
	case 0 :
		printf("당신은 %s 선택, 컴퓨터는 %s 선택, 비겼습니다!\n", card_name[myhand - 1], card_name[com - 1]);
		progress = 1;
		++(*draw);
		break;
	case -1 :
		printf("당신은 %s 선택, 컴퓨터는 %s 선택, 당신이 졌습니다!\n", card_name[myhand - 1], card_name[com - 1]);
		progress = 0;
		break;
	}
	if (!progress)
		printf("\n게임의 결과 : %d승 %d무\n", *win, *draw);
	return progress;
}