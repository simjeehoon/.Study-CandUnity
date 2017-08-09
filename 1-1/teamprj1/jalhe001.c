#include <stdio.h>
#include <termio.h>
#include <time.h>

int getch(void)
{
	int res;
	struct termios buf, storage;
	tcgetattr(0,&storage);
	buf = storage;
	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	res = getchar();
	tcsetattr(0, TCSAFLUSH, &storage);
	return res;
}

int main(void)
{
	int i, total = 0, wrong_count = 0, j, r;
	int a=0;
	int ongoing = 0, letter = 0; //진행도, 현재타수, 최고타수   (, 글자 위치
	double nowspeed = 0, bestspeed = 0;
	//////////int shutdown = getch();

	time_t begintime, nowtime;
	double payingtime, accuracy; //정확도

	char alpha; //단일문자검사
	char typing[100]; //타이핑한것 저장
	char moongoo[30][100] =
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

printf("28번째문자열의 길이 : 16 = (%d)\n", strlen(moongoo[27]));
return 0;
}
