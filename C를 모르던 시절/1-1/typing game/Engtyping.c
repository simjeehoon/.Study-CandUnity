#include <stdio.h>
#include <termio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int getch(void);
void jari(void);
void natmal(void);
void jjalven(void);
void gin(void);

int main(void)
{
	int op = '0';
	while(1)
	{
		system("clear");
		printf(">> 영문 타자 연습 프로그램 <<\n1. 자리 연습        2. 낱말 연습\n3. 짧은 글 연습     4. 긴 글 연습\n5. 프로그램 종료\n");
		if (op==-1) printf("* 다시 입력해주세요.\n\n번호 입력 : ");
		else printf("\n\n번호 입력 : ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			jari();
			break;
		case 2:
			natmal();
			break;
		case 3:
			jjalven();
			break;
		case 4:
			gin();
			break;
		case 5:
			system("clear"); //화면을 클리어합니다.
			system("clear");
			break;
		default :
			op = -1;
			break;
		}
	}
	return 0;
}

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

void jari(void)
{
	int ongoing = 0; //진행도
	int okletter = 0, totalletter = 0; //맞은 타수, 입력한 총 타수
	double accuracy = 0.0; //정확도
	int i = 0, r; // 반복 변수, 랜덤 변수
	char moonja[52]; //주어지는 문자
	char alpha; //사용자 입력 변수

	srand(time(NULL)); //랜덤 출력을 위함

	for (i = 0; i < 26; i++)
		moonja[i] = 'A' + i; //대문자 배정
	for (i = 0; i < 26; i++)
		moonja[i + 26] = 'a' + i; //소문자 배정

	for (i = 0; i < 20; i++)
	{
		r = rand() % 52; //총 알파벳 52개중 랜덤 선택

		/// 표시부 ///
		system("clear");
		printf("[opton] : ESC를 누르면 메뉴로 복귀 \n");
		printf("< < < 영문 타자 연습 :: 자리 연습 > > >\n");
		printf("진행도: %3d%%  오타수: %d  정확도: %3.0f%%\n\n", ongoing, totalletter - okletter, accuracy);
		printf("%c\n", moonja[r]);
		//////////////

		while (1)
		{
			alpha = getch();//사용자 입력을 알파에 저장한다.

			if (alpha == 27)
				return ;//ESC로 함수 종료
			else if (alpha == moonja[r])
			{
				okletter++; //맞은 타수 증가
				totalletter++; //총 타수 증가

				accuracy = ((double)okletter / totalletter) * 100; //정확도 계산
				break; // 다음 문제로 간다.
			}
			else
			{
				totalletter++; //총 타수 증가
				accuracy = ((double)okletter / totalletter) * 100; //정확도 계산
				/// 표시부 ///
				system("clear");
				printf("[opton] : ESC를 누르면 메뉴로 복귀 \n");
				printf("< < < 영문 타자 연습 :: 자리 연습 > > >\n");
				printf("진행도: %3d%%  오타수: %d  정확도: %3.0f%%\n\n", ongoing, totalletter - okletter, accuracy);
				printf("%c\n", moonja[r]);
				//////////////
			}
		}

		ongoing += 5; //진행도 5퍼센트 증가
	}

	system("clear");
	printf("******************통계*******************\n");
	printf("                                         \n");
	printf("      영문 타자 연습 :: 자리 연습     \n");
	printf("      진행도 : %4d%%                       \n", ongoing);
	printf("      정확도 : %4.0f%% 	          \n", accuracy);
	printf("      오타수 : %4d 	          \n", totalletter - okletter);
	printf("    엔터키를 누르면 메뉴로 복귀합니다.    \n");
	printf("                                         \n");
	printf("*****************************************\n");

	while (1)
	{
		alpha = getch();
		if (alpha == 10) //엔터를 누르면 함수를 종료합니다.
		{
			system("clear");
			return ;
		}
	}

}

void natmal(void)
{

	char word[100][30] = { 
		"remind" , "pheonmeon" , "tune" , "meanwhile" , "decorate" , //5
	   	"sculpture" , "import" , "take" , "stream" , "merge" ,   //10
	   	"current" , "interaction" , "likewise" , "herdsman" , "graze" ,  //15
	   	"cattle" , "crop" , "logger" , "manufacture" , "timber" ,   //20
		"dump" , "toxic" , "get" , "independently" , "maximize" ,  //25
	   	"ultimately" , "renewable" , "yield" , "diminish" , "vanish" ,  //30
	   	"trap" , "mediebal" , "stable" , "urban" , "era" ,   //35
		"expel" , "altigether" , "barn" , "english" , "despise" ,  //40
	   	"encyclopedia" , "adopt" , "volume" , "physical" , "content" ,  //45
	   	"access" , "subscription" , "fee" , "extend" , "thus" ,  //50
		"transition" , "prime" , "aware" , "ingredient" , "gaze" , //55
		"shifr" , "signle" , "fraction" , "momentary" , "regular" , //60
		"leak" , "minimize" , "revolve" , "airtight" , "spin" , //65
		"state" , "anaze" , "transpormation" , "blossom" , "stem" , //70
	   	"jar" , "shade" , "container" , "once" , "bouquet" , //75
		"arrange" , "board" , "reason" , "aircraft" , "reduce" ,  //80
	   	"fuel" , "initially" , "intend" , "last" , "expand" , //85
		"positive" , "carbon", "emission" , "measure" , "output" ,  //90
	   	"official" , "mainly" , "date" , "conference" , "transport" ,  //95
	   	"vehicle" , "specialist" , "visible" , "combination", "eradicate"  //100
   	};

	///단어 목록///

	char input[30]; //입력받는 값
	char alpha; //마지막 종료시 getch로 입력값을 저장합니다.

	int w_count = 0, percentige_of_complete = 0, i, j = 0; //틀린 문자수, 진행도, 랜덤변수, 여태까지 출제된 문제수
	float c_percentige = 0; //정확도
	int c_count = 0; //맞은 문자수(정확도 계산시 필요)
	char exit[8] = "###"; //탈출 조건

	system("clear"); //화면을 지운다

	srand(time(NULL));//수를 랜덤으로 생성하기위해 srand사용

	while (percentige_of_complete < 100)
	{
		j++; //출제된 문제수 증가
		i = rand() % 100; //0부터99까지 랜덤으로 생성

		//표시되는 부분//
		printf("[opton] : ###엔터를 누르면 메뉴로 복귀 \n");
		printf("< < < 영문 타자 연습 :: 낱말 연습 > > >\n");
		printf("진행도 : %d%%  오타수 : %d  정확도 : %0.1f%% \n", percentige_of_complete, w_count, c_percentige);
		printf("\n");
		printf("%s\n", word[i]);
		///////////////

		scanf("%s", input);
		getchar();

		if (strcmp(input, word[i]) == 0)
			c_count += 1; //맞은 문자수 증가
		else
		{
			if (strcmp(input, exit) == 0) //###입력 후 엔터를 누르면
				return ; //함수를 종료한다.
			w_count += 1; //틀린 문자수 증가
		}

		system("clear");  
		c_percentige = ((float)c_count / j) * 100;  //정확도 계산
		percentige_of_complete += 5; //진행도 증가

	}

	system("clear");
	printf("******************통계*******************\n");
	printf("                                         \n");
	printf("      영문 타자 연습 :: 낱말 연습     \n");
	printf("      진행도 : %4d%%                       \n", percentige_of_complete);
	printf("      정확도 : %4.0f%% 	          \n", c_percentige);
	printf("      오타수 : %4d 	          \n", w_count);
	printf("    엔터키를 누르면 메뉴로 복귀합니다.    \n");
	printf("                                         \n");
	printf("*****************************************\n");

	while(1)
	{
		alpha = getch();
		if (alpha == 10) // 엔터를 누르면 함수를 종료합니다.
		{
			system("clear");
			return ;
		}
	}
}	


void jjalven(void)
{
	int okletter = 0; //현재문장의 맞은 문자수 
	int i = 0, a, r, pvs; //pvs는 현재타수 계산 시작을 알리는 변수입니다.
	int ongoing = 0; //진행도
	double nowspeed = 0.0, bestspeed = 0.0; //현재타수와 최고타수
	time_t begint, nowt; //현재타수 계산을 위한 시작시간과 끝시간
	double payt, accuracy = 0; //현재타수의 걸린시간, 정확도

	char alpha; //getch()로 받아내는 값을 저장
	int pointing = 0; //글자를 가리키는 변수(이하 포인터)

	char typing[100]; //입력하는 문자를 저장하는 문자열
	char moongoo[30][100] =
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

	while (i < 5)  //5번 출력합니다.
	{
		r = rand() % 30; //난수로 랜덤하게 문장을 정합니다.
		pointing = 0;  //포인터를 초기화합니다.
		pvs = 0;      //시간 측정 변수를 초기화합니다.
		okletter = 0;  //현재 문장의 맞은 타수를 초기화합니다.

		//표시하는 부분//
		system("clear");
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
				return ;//esc를 누르면 함수를 종료합니다.
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
					{
						if (okletter)
							nowspeed = 1000.0; //입력 초기에는 분모가 0이므로 1000으로 설정하였습니다. 
						else
							nowspeed = 0.0;
					}
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
					while (a < pointing)
						printf("%c", typing[a++]);
					//////////////////////

				}
			}
			else // 타자 입력(엔터가 아닐 때)
			{
				if (pointing < 100) //글자수 초과 방지.
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
					{
						if (okletter)
							nowspeed = 1000.0; //입력 초기에는 분모가 0이므로 1000으로 설정하였습니다. 
						else
							nowspeed = 0.0;
					}
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
					while (a < pointing)
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
	while (1)
	{
		alpha = getch();
		if (alpha == 27) //ESC를 입력받으면 함수를 종료합니다. 
		{
			system("clear");
			return ;
		}
	}

}

void gin(void)
{
	int okletter = 0; //여태까지 총 맞은 문자수 
	int r, ns;  //랜덤 출력 변수, 다음페이지 및 타자연습 완료를 위한 반복문 변수 
	int line = 0, nowjul = 0; //문구 프린트 반복문 변수, 현재줄 위치
	int prnujeock = 0, prjul = 0, a, b; // 첫페이지 총 문자수, 프린트 표시 인자 
	int allletters = 0;  // 총 문자수, 이것은 타자연습을 종료하는데 필요하다.

	int pvs = 0, nextpage = 0;  //현재타수 계산 시작 변수, 다음페이지 변수
	double nowspeed = 0.0; //현재타수
	time_t begint, nowt; //현재타수 계산을 위한 시작시간과 끝시간
	double payt, accuracy = 0; //현재타수의 걸린시간, 정확도

	char alpha; //getch()로 받아내는 값을 저장
	int pointing = 0; //글자를 가리키는 변수(이하 포인터)이자, 토탈문자수
	int thislinept = 0;  //현재줄에서만의 포인터

	char typing[1000]; //입력하는 문자를 저장하는 문자열
	char moongoo[4][10][100] =
	{
		{
			"So many types of a person",
			"Someone do hard and make one's thing great. It is best. ",
			"Another do and try hard but sometime there are several ",
			"mistakes but in many times he do not know it, or ",
			"he neglacts that with so bad arrogance that I reserve ",
			"to be clapped with my effort and I am happy, so I do not ",
			"need to do this. Surprisingly, it is not end. ",
			"There is a person who don't do anything, It is worst person. And ",
			"he want to get payment like other people. ",
			"I am sad for this."
		}
		,
			{
				"Strange world",
				"If I complain this for him, It is awesome. It becomes wrong ",
				"between me and him. I don't like myself thinking like this.",
				"I give up thingking seriously. Everything is okay, and ",
				"I won't do this mistakes again." ,
				"Sometimes I respect the very easy life, no effort life",
				"But I also know thoes endding is empty.",
				"He is living worng life, and I will live better. In this way, I do ",
				"regard it like this. Anything is not changed.",
				"What a strange world it is."
			}
		,
			{
				"Let me introduce myself",
				"My name is Tom. I like eating apple. I used to go to PC rooms. I have",
				"two brothers, and six sisters.",
				"My house has a large lovely garden, with soft green grass. Here and there ",
				"over the grass stook beautiful flowers like stars, and there are",
				"and apple. I like it so much.",
				"I am middle school student. I am from Korea. My father is taxi driver.",
				"I love my mother. She is beautiful.",
				"It is hard to fill 4 texts in array. Actually, I must fill 40 sentenses",
				"I want to get good grade about it"
			}
		,
			{
				"The importance of taking hard",
				"When most people face hard thing, they complain about this at first.",
				"Believe that it needs to go your way.",
				"It might be expensive thing at future. Think like this. it is good for ",
				"you. Someone want to do your work. Even it is chore, Do it. It makes ",
				"you great. It is a stair to your goal.",
				"I want you become what you wanted. It is possible for you, only you.",
				"Shout your dream. Do your dream. Cry out. And run and run. if you get ",
				"there, you will know that I really have helped you.",
				"Hey, come on. I made all of these! I finished to fill out!"
			}
	};

	srand(time(NULL)); //문구의 랜덤 출력을 위함.

	// 사전 설정 //
	r = rand() % 4; //난수로 랜덤하게 문장을 정합니다.
	for (ns = 0; ns < 5; ns++) //nextpage 출력시 필요
		prnujeock += strlen(moongoo[r][ns]);
	for (ns = 0; ns < 10; ns++) //전체입력완료시 타자종료할때 필요
		allletters += strlen(moongoo[r][ns]);

	//표시하는 부분//
	system("clear");
	printf("[option] ESC : 메뉴로 복귀하기\n");
	printf("< < < 영문 타자 연습 :: 긴 글 연습 > > >\n");
	printf("현재타수: %-5.0f  정확도: %4.0f%%\n", nowspeed, accuracy);
	printf("\n\n");
	while (line < 5)
	{
		printf("%s\n\n", moongoo[r][line]);
		line++;
	}
	printf("\n\n");
	////////////////

	//입력 부분 //
	while (1)
	{
		alpha = getch();

		if (alpha == 27)
			return ;//esc를 누르면 함수를 종료합니다.
		if (alpha == 10)
			; //엔터 입력을 무시합니다.

		else if (alpha == 8 || alpha == 127) // 백스페이스
		{
			if (pointing != 0)
			{
				if (thislinept == 0) //이전줄로 갈 수 있도록 합니다.
				{
					nowjul--;
					thislinept = strlen(moongoo[r][nowjul]);
				}
				if (pointing == prnujeock && nextpage) //이전페이지로 갑니다.
					nextpage = 0;

				if (typing[pointing - 1] == moongoo[r][nowjul][thislinept - 1])
					okletter--;  //맞은타수 감수
				pointing--;  //포인터감소
				thislinept--; //현재줄포인터 감소

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
				{
					if (okletter)
						nowspeed = 1000.0; //입력 초기에는 분모가 0이므로 1000으로 설정하였습니다. 
					else
						nowspeed = 0.0;
				}
				else
					nowspeed = (60 * okletter) / payt; // 분당 타수를 저장합니다.
				///////////////

				//표시하는 부분//
				system("clear");
				printf("[option] ESC : 메뉴로 복귀하기\n");
				printf("< < < 영문 타자 연습 :: 긴 글 연습 > > >\n");
				printf("현재타수: %-5.0f  정확도: %4.0f%%\n", nowspeed, accuracy);
				printf("\n\n");
				if (nextpage) //nextpage인가 아닌가에 따라 구별해서 문구를 출력합니다.
				{
					line = 5;
					while (line<10)
					{
						printf("%s\n\n", moongoo[r][line]);
						line++;
					}
				}
				else
				{
					line = 0;
					while (line<5)
					{
						printf("%s\n\n", moongoo[r][line]);
						line++;
					}
				}
				////////////////
				printf("\n\n");
				//사용자 입력 표시부//
				b = 0;
				if (nextpage)
				{
					a = prnujeock;
					prjul = 5;
					while (a < pointing)
					{
						printf("%c", typing[a++]);
						b++; //한줄 내에서 글자를 셉니다.
						if (strlen(moongoo[r][prjul]) <= b)
						{
							printf("\n\n");
							prjul++; //다음줄에 출력합니다.
							b = 0;
						}
					}
				}
				else
				{
					a = 0;
					prjul = 0;
					while (a < pointing)
					{
						printf("%c", typing[a++]);
						b++;  //한줄 내에서 글자를 셉니다.
						if (strlen(moongoo[r][prjul]) <= b)
						{
							printf("\n\n");
							prjul++;  //다음줄에 출력합니다.
							b = 0;
						}
					}
				}
				//////////////////////

			}
		}
		else // 타자 입력(엔터가 아닐 때)
		{
			if (pvs == 0)
			{
				time(&begint);  //처음이면 시작시간을 설정.
				pvs = 1; //시작한 순간은 한번만 측정되야되므로 pvs를 1로 설정하였습니다.
			}

			typing[pointing] = alpha;

			if (typing[pointing] == moongoo[r][nowjul][thislinept])
				okletter++;   //현재문장의 맞은타수 증가
			pointing++;     //포인터증가
			thislinept++;   //현재줄의 포인터 증가

			//긴글추가//
			if (strlen(moongoo[r][nowjul]) == thislinept) //한줄을 다 채우면
			{
				nowjul++; //줄을 바꿉니다.
				thislinept = 0; //현재줄의 포인터를 0으로 설정합니다.

				if (nowjul >= 5)
					nextpage = 1; //다음 페이지로 넘어갑니다.
			}

			if (pointing == allletters) // 타자 마침
				break;

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
			{
				if (okletter)
					nowspeed = 1000.0; //입력 초기에는 분모가 0이므로 1000으로 설정하였습니다. 
				else
					nowspeed = 0.0;
			}
			else
				nowspeed = (60 * okletter) / payt;
			///////////////

			//표시하는 부분//
			system("clear");
			printf("[option] ESC : 메뉴로 복귀하기\n");
			printf("< < < 영문 타자 연습 :: 긴 글 연습 > > >\n");
			printf("현재타수: %-5.0f  정확도: %4.0f%%\n", nowspeed, accuracy);
			printf("\n\n");
			if (nextpage) //다음페이지인가 아닌가 구별해서 문구를 출력합니다.
			{
				line = 5;
				while (line<10)
				{
					printf("%s\n\n", moongoo[r][line]);
					line++;
				}
			}
			else
			{
				line = 0;
				while (line<5)
				{
					printf("%s\n\n", moongoo[r][line]);
					line++;
				}
			}
			////////////////
			printf("\n\n");
			//사용자 입력 표시부//
			b = 0;
			if (nextpage)
			{
				a = prnujeock;
				prjul = 5;
				while (a < pointing)
				{
					printf("%c", typing[a++]);
					b++; //한줄 내에서 글자를 셉니다.
					if (strlen(moongoo[r][prjul]) <= b)
					{
						printf("\n\n");
						prjul++; //다음 줄에 출력합니다.
						b = 0;
					}
				}
			}
			else
			{
				a = 0;
				prjul = 0;
				while (a < pointing)
				{
					printf("%c", typing[a++]);
					b++; //한줄 내에서 글자를 셉니다.
					if (strlen(moongoo[r][prjul]) <= b)
					{
						printf("\n\n");
						prjul++; //다음 줄에 출력합니다.
						b = 0;
					}
				}
			}
			//////////////////////
		}
	}

	//통계//
	system("clear");
	printf("******************통계*******************\n");
	printf("                                         \n");
	printf("      영문 타자 연습 :: 긴글 연습     \n");
	printf("      타수 : %.0f                       \n", nowspeed);
	printf("      정확도 : %4.0f%% 	          \n", accuracy);
	printf("    ESC키를 누르면 메뉴로 복귀합니다.    \n");
	printf("                                         \n");
	printf("*****************************************\n");
	////////////////
	while (1)
	{
		alpha = getch();
		if (alpha == 27) //ESC를 입력받으면 함수를 종료합니다. 
		{
			system("clear");
			return ;
		}
	}
}

