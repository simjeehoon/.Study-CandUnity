#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i, total = 0, wrong_count = 0, j;
	time_t tStart, tEnd;
	double elapsed_time, accuracy;
	char input[100];
	char text[5][100] =
	{
		"there are boys",
		"aoao",
		"rpap",
		"slslsl",
		"aqw",
	};
	puts(text[2]);
	printf("문자열의 길이(4) = %d", strlen(text[2]));
	printf("한메타자 게임입니다.\n");
	printf("한문장씩 나오므로 따라 치시면됩니다.\n");
	system("pause");
	printf("< S T A R T>\n\n");

	time(&tStart);   //시작시간 측정
	//이하 for문은 순서대로 저장된 문구가 등장하게 한다.
	//이를 rand 함수를 이용하여 랜덤 등장으로 바꾸게 한다.
	for (i = 0; i < 5; i++)				
	{
		puts(text[i]);  //화면에 해당하는 문자열(text[i])를 놓는 함수가 puts이다. 
		gets(input);	//input이라는 char형 길이 100의 문자열에 넣기 위해 내가 입력한 것을 gets를 통해 받아낸다.
		total += strlen(text[i]);	//토탈 문자 수에 저장된 문구의 길이를 더하는 것이다.

		for (j = 0; j < (int)strlen(text[i]); j++)  
		{
			if (input[j])	//내가 입력한 문장의 하나하나 문자를 검사한다.
			{
				if (input[j] != text[i][j]) //내가 입력한 문자와 문구의 문자가 갖지 않으면
					wrong_count++;		//오타를 늘린다.
			}
			else //안틀렸으면
			{
				wrong_count += (strlen(text[i]) - j); //문구의 길이에서 (ex.5) 검사하는 위치만큼 빼서(ex.3) 더한다.
				break;
			}
		}
	}
	time(&tEnd);

	accuracy = (float)(total - wrong_count) / (float)total * 100.0f;
	elapsed_time = difftime(tEnd, tStart);
	printf("\n경과시간 %0.0lf초\n 확률 %3.2f%%\n", elapsed_time, accuracy);
	printf("\n틀린 문자 수 : %d\n", wrong_count);
	return 0;

}
/* 유의점
   1. time.h로 time_t형 변수 선언(time_t는 사실 뭐지?)
   2. time(&tStart) <- 현재시간을 해당 변수에 저장하는 꼴. NULL 사용시 그냥 현재시간, 포인터를 이용해 저장하는듯.
   > time함수의 개형
   현재시간 > time(&저장위치) =>이거 자체 역시 시간의 값이다. 그래서 rand에서도 널쓰고 배정한다.
   3. puts(text[i]) <- 화면상에 문자열을 놓는다.
   4. gets(input) 문자를 받아서 넣는다. 문자열을 받아적을때 자주쓴다. 길이가 100일땐 99자가아니더라도 이전에 엔터치면 거까지 넣는다.
   5. 두시간의 차이를 나타낸다. difftime(tEnd, tStart)

 */
