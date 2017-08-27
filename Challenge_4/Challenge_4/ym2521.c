#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void reverse_print(int length);

int ym2521()
{
	int length;

	printf("문자열 최대길이 : ");
	scanf("%d", &length);
	getchar();
	length++;

	reverse_print(length);

	return 0;
}

void reverse_print(const int length)
{
	int i = length - 1;
	int endpos;
	int p;
	_Bool word = false;

	char * str = (char *) calloc(length, sizeof(char));
	//memset(str, 0, length);

	printf("입력 : ");
	gets(str);

	
	for (i = length - 1; i >= 0; --i)
	{
		if (str[i] != 0)
		{
			if (str[i] != ' ' && !word)
			{
				endpos = i;
				word = true;
			}

			if (str[i] == ' ' && word)
			{
				for (p = i + 1; p <= endpos; p++)
					printf("%c", str[p]);
				printf(" ");
				word = false;
			}
			
			if (i == 0 && word)
			{
				for (p = 0; p <= endpos; p++)
					printf("%c", str[p]);
				word = false;
			}
		}
	}
	
	putchar('\n');

	free(str);
}
