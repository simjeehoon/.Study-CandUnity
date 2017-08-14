#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <time.h>
#include <string.h>

#define N 100

int getch(void)  //리눅스 시스템에서 getch를 사용하기 위함.
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
	int okletter = 0; //현재문장의 맞은 문자수 
	int i = 0, a, r, pvs; //pvs는 현재타수 계산 시작을 알리는 변수입니다.
	int ongoing = 0; //진행도
	double nowspeed = 0.0, bestspeed = 0.0; //현재타수와 최고타수
	time_t begint, nowt; //현재타수 계산을 위한 시작시간과 끝시간
	double payt, accuracy = 0; //현재타수의 걸린시간, 정확도

	char alpha; //getch()로 받아내는 값을 저장
	int pointing = 0; //글자를 가리키는 변수(이하 포인터)

	char typing[N]; //입력하는 문자를 저장하는 문자열
	char moongoo[30][N] = 
	{
		"Soongsil university is nice.",   //1
		"I love Soongsil.",
		"Stars can not shine without darkness.",
		"Try your best rather than be the best.",
		"Poetry is the mother tongue of mankind.",  //5
		"This project helps me become good at C language.",
		"It is very hard to fill 30 sentences.",
		"You can do it!",
		"I am fine thank you, and you?",
		"I want to go home now.",  //10
		"Happy birthday to you.",
		"So I say a little prayer, hope my dreams will take me there.",
		"I am all alone, the rooms are getting smaller.",
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
		"Let me introduce myself.",
		"I never wanna hear you say.",
		"I am from Korea.",
		"She likes talking with me.",
		"Wow, I made it.",  //30
	}; //저장된 30개의 문자열

	srand(time(NULL)); //문구의 랜덤 출력을 위함.

	while(i < 5)  //5번 출력합니다.
	{
		r = rand() % 30; //난수로 랜덤하게 문장을 정합니다.
		pointing = 0;  //포인터를 초기화합니다.
		pvs = 0;      //시간 측정 변수를 초기화합니다.
		okletter = 0;  //현재 문장의 맞은 타수를 초기화합니다.

		//표시하는 부분//
		system("clear");
//디버거		  printf("[%4d]  ", alpha);
//꼭 삭제하시오	  printf(" OK : %d  ||  TOTAL : %d  ||  Pointing : %d || speedletter : %d || this 길이 : %d\n", okletter, totalletter, pointing, speedletter, strlen(moongoo[r]));  
		printf("[option] ESC : 메뉴로 복귀하기\n");
		printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
		printf("진행도: %4d%%  현재타수: %-5.0f  최고타수: %-5.0f  정확도: %4.0f%%\n", ongoing, nowspeed, bestspeed, accuracy);
		printf("\n");
		printf("%s\n", moongoo[r]);
		////////////////

		while (1)
		{
			alpha = getch();

			if (alpha == 27)
				return 0;//esc를 누르면 함수를 종료합니다.
			if (alpha == 10)
			{
				if (pointing != 0)
					break; //enter를 누르면 문장을 처리합니다.
			}
			else if (alpha == 8 || alpha == 127) // 백스페이스
			{
				if (pointing != 0)
				{
					if (typing[pointing - 1] == moongoo[r][pointing - 1])
					{	
						okletter--;  //현재문장의 맞은타수 감수
					}
					pointing--;  //포인터감소

					//정확도처리//
					if (pointing == 0)
						accuracy = 0.0;
					else
						accuracy = ((double)okletter / pointing) * 100;
					/////////////

					//현재타수처리//
					time(&nowt);
					payt = difftime(nowt, begint);
					if (payt == 0)
						nowspeed = 1000.0; // 입력 초기에는 분모가 0이므로 1000으로 설정했습니다.
					else
						nowspeed = (60 * okletter) / payt; // 분당 타수를 저장합니다.
					///////////////

					//표시하는 부분//
					system("clear");
//디버거		  printf("[%4d]  ", alpha);
//꼭 삭제하시오	  printf(" OK : %d  ||  TOTAL : %d  ||  Pointing : %d || speedletter : %d || this 길이 : %d\n", okletter, totalletter, pointing, speedletter, strlen(moongoo[r]));  
					printf("[option] ESC : 메뉴로 복귀하기\n");
					printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
					printf("진행도: %4d%%  현재타수: %-5.0f  최고타수: %-5.0f  정확도: %4.0f%%\n", ongoing, nowspeed, bestspeed, accuracy);
					printf("\n");
					printf("%s\n", moongoo[r]);
					////////////////
					//사용자 입력 표시부//
					a = 0;
					while(a < pointing)
						printf("%c", typing[a++]);
					//////////////////////

				}
			}
			else // 타자 입력(엔터가 아닐 때)
			{
				if (pointing < N) //글자수 초과 방지.
				{
					if (pvs == 0)
					{
						time(&begint);  //처음이면 시작시간을 설정.
						pvs = 1; //시작한 순간은 한번만 측정되야되므로 pvs를 1로 설정하였습니다.
					}
	
					typing[pointing] = alpha;
					if (typing[pointing] == moongoo[r][pointing])
					{
						okletter++;   //현재문장의 맞은타수 증가
					}
					pointing++;     //포인터증가
	
					//정확도처리//
					if (pointing == 0)
						accuracy = 0.0;
					else
						accuracy = ((double)okletter / pointing) * 100;
					/////////////
	
					//현재타수처리//
					time(&nowt);
					payt = difftime(nowt, begint);
					if (payt == 0)
						nowspeed = 1000.0; //입력 초기에는 분모가 0이므로 1000으로 설정하였습니다. 
					else
						nowspeed = (60 * okletter) / payt;
					///////////////

					//표시하는 부분//
					system("clear");
//디버거		  printf("[%4d]  ", alpha);
//꼭 삭dd제하시오	  printf(" OK : %d  ||  TOTAL : %d  ||  Pointing : %d || speedletter : %d || this 길이 : %d\n", okletter, totalletter, pointing, speedletter, strlen(moongoo[r]));  
					printf("[option] ESC : 메뉴로 복귀하기\n");
					printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
					printf("진행도: %4d%%  현재타수: %-5.0f  최고타수: %-5.0f  정확도: %4.0f%%\n", ongoing, nowspeed, bestspeed, accuracy);
					printf("\n");
					printf("%s\n", moongoo[r]);
					////////////////
					//사용자 입력 표시부//
					a = 0;
					while(a < pointing)
						printf("%c", typing[a++]);
					//////////////////////
				}
			}

		}


		ongoing += 20; //진행도 증가
		if (nowspeed > bestspeed) //최고타수를 검사합니다.
			bestspeed = nowspeed;
		i++;
	}

	//표시하는 부분//
	system("clear");
	printf("******************통계*******************\n");
	printf("                                         \n");
	printf("      영문 타자 연습 :: 짧은 글 연습     \n");
	printf("    진행도: %-4d%%                       \n", ongoing);
	printf("    최고타수: %-6.0f                     \n", bestspeed);
	printf("    ESC키를 누르면 메뉴로 복귀합니다.    \n");
	printf("                                         \n");
	printf("*****************************************\n");
	////////////////
	while(1)
	{
		alpha = getch();
		if (alpha == 27) //ESC를 입력받으면 함수를 종료합니다. 
		{
			system("clear");
			return 0;
		}
	}

}
