#include <stdio.h>
#include <termio.h>
#include <time.h>
#include <string.h>

#define N 100

int getch(void)
{
	int res;
	struct termios buf, storage;
	tcgetattr(0, &storage);
	buf = storage;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	res = getchar();
	tcsetattr(0, TCSAFLUSH, &storage);
	return res;
}

int main(void)
{
	int okletter = 0, totalletter = 0; //맞은 문자수, 전체 문자수 : 정확도 및 현재타수 검사에 사용
	int i = 0, a, r, b;
	int ongoing = 0; //진행도
	double nowspeed = 0.0, bestspeed = 0.0; //현재타수와 최고타수
	time_t begint, nowt; //현재타수 계산을 위한 시작시간과 끝시간
	double payt, accuracy = 0; //현재타수의 걸린시간, 정확도

	char alpha; //getch()로 받아내는 값을 저장
	int pointing = 0; //글자를 가리키는 변수(이하 포인터)

	char lentest[N];
	char typing[N]; //입력하는 문자를 저장하는 문자열
	char moongoo[30][N] = 
	{
		"Soongsil university is nice.",   //1
		"I love Soongsil.",
		"Stars can't shine without darkness.",
		"Try your best rather than be the best.",
		"Poetry is the mother tongue of mankind.",  //5
		"This project helps me become good at C language.",
		"It is very hard to fill 30 sentences.",
		"You can do it!",
		"I am fine thank you, and you?",
		"I want to go home now.",  //10
		"Happy birth day to you.",
		"So I say a little prayer, hope my dreams will take me there.",
		"I'm all alone, the rooms are getting smaller.",
		"The angel in her eyes became the devil in me.",
		"Yet I thought it would settle there but never would leave.",  //15
		"I have a pen, and I have an apple.",
		"This game makes me angry.",
		"Where is the post office?",
		"Do your best, and you will get what you want.",
		"All web pages are automatically displayed in your language.",  //20
		"Translator is a really good thing.",
		"The weather is really hot.",
		"Use the distribution to obtain the probability that the sample variance is more than 30.",
		"How do you add 1 to 100?",
		"I want to learn java language.",  //25
		"I want to get at least B plus.",
		"I never wanna hear you say.",
		"I am from Korea.",
		"She likes talking with me.",
		"Life ain't the math, but the philosophy.",  //30
	}; //저장된 30개의 문자열

	srand(time(NULL)); //문구의 랜덤 출력을 위함.

	
	while(i<5)
	{
		r = rand() % 30;
		pointing = 0;

		//표시하는 부분//
		system("clear");
		printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
		printf("진행도: %-5d  현재타수: %-5.0f  최고타수: %-5.0f  정확도: %-5.0f%%\n", ongoing, nowspeed, bestspeed, accuracy);
		printf("%s\n", moongoo[r]);
		printf("이 문자열의 길이 : %d\n", strlen(moongoo[r]));
		sleep(4);
		i++;
	}
	//결과
return 0;

}
