#define NUMBER_OF_QUESTION 5  //문제수 (수정가능)
#define QUESTION(X,Y) strcpy( munje[X-1], Y )

#include <stdio.h>
#include <conio.h> // getch
#include <string.h>  //string
#include "windows.h"

int main()
{
	char ch;
	int munjesoo = 0, munje_pointer = 0, ch_pointer = 0;
	char munje[NUMBER_OF_QUESTION][256], answer[256];
	double typing_msec, typing_sec, typing_per_sec;
	int start;

	//문제내용 (갯수와 내용 언제든지 수정 가능)

	QUESTION(1, "miro");
	QUESTION(2, "awmiao");
	QUESTION(3, "bola");
	QUESTION(4, "alala");
	QUESTION(5, "dda");

	srand(GetTickCount());  // 랜덤 시드(씨앗) 생성

	while(1) 
	{
		munje_pointer = rand() % NUMBER_OF_QUESTION;  //문제 랜덤하게 선택
		printf( "%s\n", munje[munje_pointer] ); //문제 출력
		ch_pointer = 0;
		

		while(1)
		{
			ch = getch();
			if ( ch == 13 && ch_pointer != 0 ) break; //Enter 누르면 문장입력 종료
			if ( ch == 27 ) { printf("\n프로그램을 종료합니다\n"); return 0; } //ESC 누르면 종료
			if ( ch == 8 ) // 백스페이스 누르면
			{
				if ( ch_pointer != 0 )
				{
					printf("\b \b"); // 화면에 한글자 지우기
					ch_pointer--;
				}
			}
			else if ( ch != 13 ) // 백스페이스도 아니고 Enter도 아니면
			{
				if ( ch_pointer == 1 ) start = GetTickCount(); //처음이면 시간 측정
				printf("%c",ch);
				answer[ch_pointer++] = ch;     
			}
		}




		typing_msec = GetTickCount() - start; //종료시간 측정

		printf("\n");
		answer[ch_pointer] = '\0';
		if ( strcmp(answer,munje[munje_pointer]) ) printf("문장이 틀렸습니다.\n");

		typing_sec = typing_msec / 1000; // 걸린시간을 밀리초에서 초로 변경
		typing_per_sec = strlen(munje[munje_pointer]) / typing_sec; // 초당타수 계산

		printf("걸린 시간: %.3lf초\n", typing_sec); // 걸린시간 출력
		printf("분당 %d타를 치셨습니다.\n\n", (int)(typing_per_sec*60)); //분당타수 계산&출력



	} 

	return 0;
}

