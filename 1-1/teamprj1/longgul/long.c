#include <stdio.h>
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
	double nowspeed = 0.0, bestspeed = 0.0; //현재타수와 최고타수
	time_t begint, nowt; //현재타수 계산을 위한 시작시간과 끝시간
	double payt, accuracy = 0; //현재타수의 걸린시간, 정확도

	char alpha; //getch()로 받아내는 값을 저장
	int pointing = 0; //글자를 가리키는 변수(이하 포인터)

	char typing[N]; //입력하는 문자를 저장하는 문자열
	char moongoo[5][10][N] = 
	{
		{
			"11The slefish Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
			"enenenen Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
		}
		,
		{
			"222222222fish Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
			"enenenen Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
		}
		,
		{
			"33The slefish Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
			"enenenen Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
		}
		,
		{
			"4444e slefish Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
			"enenenen Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
		}
		,
		{
			"555he slefish Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
			"enenenen Giant",
			"abcdefg asdfasdfqwerzxcv adsf, asdfas",
			"asdfasdfas dfasdfsafdasdfddd",
			"abcdefg hijklmnop qrs tuv w x yz",
			"hallo hallo hallo hallo, hallo",
		}
	}

	srand(time(NULL)); //문구의 랜덤 출력을 위함.


		r = rand() % 5; //난수로 랜덤하게 문장을 정합니다.
		// 긴글을 놓는다. moongoo[r][10][N]
		pointing = 0;  //포인터를 초기화합니다.
		pvs = 0;      //시간 측정 변수를 초기화합니다.
		okletter = 0;  //현재 문장의 맞은 타수를 초기화합니다.

		//표시하는 부분//
		system("clear");
		printf("[option] ESC : 메뉴로 복귀하기\n");
		printf("< < < 영문 타자 연습 :: 짧은 글 연습 > > >\n");
		printf("현재타수: %-5.0f  정확도: %4.0f%%\n", nowspeed, accuracy);
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

		i++;
	}

	//통계//
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
