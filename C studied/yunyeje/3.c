#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void reverse_print(int length);

int main()
{
	int length;

	printf("문자열 최대길이 : ");
	scanf("%d", &length);
	getchar();
	reverse_print(length);

	return 0;
}

void reverse_print(const int length)
{
	int i = length - 1;
	int endpos;
	int p;
	_Bool word = false;

	char * str = (char *)malloc(sizeof(char) * length);
	memset(str, 0, length);

	printf("입력 : ");
	scanf("%s", str);
	getchar();

	for (i = length - 1; i >= 0; --i)
	{
		if (str[i] != 0) {
			if (str[i] != ' ' && !word)
			{
				endpos = i;
				word = true;
			}

			if (str[i] == ' ' && word)
			{
				for (p = i + 1; p <= endpos; p++)
					putchar(str[p]);
				putchar(' ');
				word = false;
			}
		}
	}
	
	putchar('\n');

}
