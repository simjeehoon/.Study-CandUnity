#include <stdio.h>
#include <string.h>

int main(void)
{
	char text[3][101] = { 0 };
	int i = 0, a = 0;
	while (i < 3)
	{
		gets(text[i]);
		if (text[i][0] == ' ')
			continue;
		if (text[i][strlen(text[i]) - 1] == ' ')
			continue;
		if (strlen(text[i]) > 100)
			continue;
		if (text[i][0] == '\0')
			continue;
		for (a = 0; a < strlen(text[i]); a++)
		{
			if (('a' <= text[i][a] && 'z' >= text[i][a]) || ('A' <= text[i][a] && 'Z' >= text[i][a]) || ('0' <= text[i][a] && '9' >= text[i][a]) || (text[i][a] == ' '))
				continue;
			else
			{
				--i;
				break;
			}
		}
	
		++i;
	}
	for (i = 0; i < 3; i++)
		printf("%s\n", text[i]);
	
	return 0;
}