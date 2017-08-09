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



	srand(time(NULL));       //랜드함수


	for (i = 0; i < 5; i++)				//5개만 놓는다.
	{
		r = rand() % 30;    //랜덤하게 놓는다.
		system("clear");
		printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
		printf("진행도 : %-5d 현재타수 : %-5.0f 최고타수 : %-5.0f 정확도 : %-5.0f\n", ongoing, nowspeed, bestspeed, accuracy);
		printf("%s\n", moongoo[r]);  //문구를 놓는다.

		letter = 0;

		while (1)
		{
			alpha = getch();
			printf("%c, %d", alpha, alpha);
			if (alpha == 13 && letter != 0)
				break;  //Enter 누르면 문장입력 종료
			if (alpha == 27)
				return 0; //ESC 누르면 함수종료
			if (alpha == 8 || alpha == 127) // 백스페이스 누르면
			{
				if (letter != 0)
				{
					// printf("\b"); // 화면에 한글자 지우기


					/*
					   time(&nowtime);
					   payingtime = difftime(nowtime, begintime);
					   if (payingtime == 0)
					   nowspeed = 1000.0;
					   else
					   nowspeed = (60*letter)/payingtime;
					   현타수 표시하기;
					 */

					letter--;
					system("clear");
						printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
					printf("진행도 : %-5d 현재타수 : %-5.0f 최고타수 : %-5.0f 정확도 : %-5.0f\n", ongoing, nowspeed, bestspeed, accuracy);
					printf("%s\n", moongoo[r]);  //문구를 놓는다.
					a = 0;
					while (a < letter)
						printf("%c", typing[a++]); //다시놓는다.
				}
			}
			else if (alpha != 13) // 백스페이스도 아니고 Enter도 아니면
			{
				if (letter == 0)
					time(&begintime); //처음이면 시간 측정

				typing[letter++] = alpha;
			/****/	
				   time(&nowtime);
				   payingtime = difftime(nowtime, begintime);
				   if (payingtime == 0)
				   nowspeed = 1000.0;
				   else
				   nowspeed = (60*letter)/payingtime;
				 


				system("clear");
					printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
				printf("진행도 : %-5d 현재타수 : %-5.0f 최고타수 : %-5.0f 정확도 : %-5.0f\n", ongoing, nowspeed, bestspeed, accuracy);
				printf("%s\n", moongoo[r]);  //문구를 놓는다.
				a = 0;
				while (a < letter)
					printf("%c", typing[a++]); //다시놓는다.

				// printf("%c", alpha);

			}
		}
		ongoing += 20;	//진행도 증가
		//최고타수검사
		if (nowspeed > bestspeed)
			bestspeed = nowspeed;
		//최고타수 표시하기;
		system("clear");

	}







	/*
	   for (j = 0; j < (int)strlen(moongoo[r]); j++)
	   {
	   if (input[j])	//내가 입력한 문장의 하나하나 문자를 검사한다.
	   {
	   if (input[j] != moongoo[r][j]) //내가 입력한 문자와 문구의 문자가 갖지 않으면
	   wrong_count++;		//오타를 늘린다.
	   }
	   else //문자가 없다면
	   {
	   wrong_count += (strlen(moongoo[r]) - j); //사실상 0을 더한다.
	   break;
	   }
	   }
	 */
	//time(&tEnd);

	/***********************************************
	  accuracy = (float)(total - wrong_count) / (float)total * 100.0f;
	  elapsed_time = difftime(tEnd, tStart);
	  printf("\n경과시간 %0.0lf초\n 확률 %3.2f%%\n", elapsed_time, accuracy);
	  printf("\n틀린 문자 수 : %d\n", wrong_count);
	 */
	return 0;

}
