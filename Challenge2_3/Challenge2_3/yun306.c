#include "main.h"
void number_determine(int nums[]);
static void input(int mynum[]);
static int compare(int mynum[], int nums[]);

int yun306() {
	int num[3];
	int mynum[3];
	int end = 0;
	printf("Start Game!\n");
	number_determine(num);
	while (!end) {
		input(mynum);
		end = compare(mynum, num);
	}
	printf("\nGame over!\n");

	return 0;
}

void number_determine(int nums[])
{
	int i;
	srand((unsigned)time(NULL));
	nums[0] = rand() % 10;
	for (i = 1; i < 3; i++)
	{
		do {
			nums[i] = rand() % 10;
		} while (nums[i - 1] == nums[i]);
	}
}

static void input(int mynum[])
{
	int i;
	printf("3개의 숫자 선택: ");
	for (i = 0; i < 3; i++)
		scanf("%d", &mynum[i]);
}

static int compare(int mynum[], int nums[]) {
	int i, j;
	static int count = 0;
	int strike=0, ball=0;
	for (i = 0; i < 3; i++) {
		if (mynum[i] == nums[i])
			strike++;
		else
		{
			for (j = 0; j < 3; j++) {
				if (i == j) continue;
				else if (mynum[i] == nums[j])
					ball++;
			}
		}
	}
	count++;
	printf("%d번째 도전 결과 : %dStrike, %dball!!\n", count, strike, ball);
	if (strike == 3) {
		count = 0;
		return 1;
	}
	else return 0;
}