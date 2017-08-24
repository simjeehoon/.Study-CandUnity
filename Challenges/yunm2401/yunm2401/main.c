#include <stdio.h>

int main()
{
	FILE * txt = fopen("mystory.txt", "rt");
	char buf[2];

	while (feof(txt) == 0)
	{
		fgets(buf, sizeof(buf), txt);
		printf("%s", buf);
	}
	
	fclose(txt);
	return 0;
}