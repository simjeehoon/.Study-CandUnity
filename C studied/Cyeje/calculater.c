#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CAL_LENGTH 300

typedef enum operator_types
{
	IS=0, ADD=1, SUB=2, MUL=3, DIV=4
} Operator;

int calculator(char str[]);
void * count_alloc(void * pos, char * type, unsigned int *count);
char * operator_check(char * opers, char operator, unsigned int * count);

int main()
{
	char calculus[CAL_LENGTH] = {0};
	int cal_option;

	printf("****계산기****\n");
	while(1)
	{
		printf("* 종료하려면 EXIT를 입력하세요.\n");
		gets(calculus);
		cal_option = calculator(calculus);
		if (cal_option==1)
			break;
		if (cal_option==-1)
			printf("Error : 지원하지 않는 연산자입니다.\n");
		if (cal_option==-2)
			printf("Error : 문자열 길이 초과.\n");

		printf("\n");
	}

	return 0;
}

int calculator(char str[])
{
	char tmpstr[CAL_LENGTH] = {0};
	int str_index = 0, tmp_index = 0;
	int num_set;
	bool isnum = false;

	unsigned int number_count = 0;
	unsigned int operator_count = 0;

	int * numbers = NULL;
	char * operators = NULL;

	if (strcmp(str, "EXIT") == 0)
		return 1;

	do
	{
		if(!('0'<=str[str_index] && str[str_index]<='9') && isnum)
		{
			for(tmp_index = 0; tmp_index < str_index-num_set ; tmp_index++)
			{
				tmpstr[tmp_index] = str[num_set + tmp_index];
			}
			numbers = (int*)count_alloc(numbers, "int", &number_count);

			numbers[number_count - 1] = atoi(tmpstr);
			memset(tmpstr, 0, sizeof(tmpstr));
			isnum = false;
		}

		if(('0'<=str[str_index] && str[str_index]<='9') && !isnum)
		{
			num_set = str_index;
			isnum = true;
		}

		if((33<=str[str_index] && str[str_index]<=47) || (58<=str[str_index] && str[str_index]<=64) 
			|| (91<=str[str_index] && str[str_index]<=96) || (123<=str[str_index] && str[str_index]<=126))
		{
			operators = operator_check(operators, str[str_index], &operator_count);
			if(operators == NULL)
				return -1;//없는 연산자
		}	
		if(('a'<=str[str_index] && str[str_index]<='z') || ('A'<=str[str_index] && str[str_index]<='Z'))
		{
			//미지수 설정.
		}

		if(CAL_LENGTH <= str_index)
		{
			return -2;//글자수 초과
		}	

	} while(str[str_index++] != '\0');
	if(number_count == 0 )
	return 0;
}

char * operator_check(char * opers, char operator, unsigned int * count)
{
	switch(operator)
	{
		case '+':
			opers = (char*)count_alloc(opers,"char",count);
			opers[*count - 1] = ADD;
			break;
		case '-':
			opers = (char*)count_alloc(opers,"char",count);
			opers[*count - 1] = SUB;
			break;
		case '*':
			opers = (char*)count_alloc(opers,"char",count);
			opers[*count - 1] = MUL;
			break;
		case '/':
			opers = (char*)count_alloc(opers,"char",count);
			opers[*count - 1] = DIV;
			break;
		default :
			opers = NULL;
			break;
	}
	return opers;
}

void * count_alloc(void * pos, char * type, unsigned int *count)
{
	if (*count == 0)
	{
		if(strcmp(type, "int") == 0)
		{
			(*count)++;
			pos = (int *)malloc(sizeof(int)* (*count));
		}
		else if(strcmp(type, "char") == 0)
		{
			(*count)++;
			pos = (char *)malloc(sizeof(char) * (*count));
		}
		else
			return NULL;
	}
	else
	{
		if(strcmp(type, "int") == 0)
		{
			(*count)++;
			pos = (int *)realloc(pos, sizeof(int)* (*count));
		}
		else if(strcmp(type, "char") == 0)
		{
			(*count)++;
			pos = (char *)realloc(pos, sizeof(char) * (*count));
		}
		else
			return NULL;
	}
	return pos;
}
