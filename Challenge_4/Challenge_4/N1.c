#include <stdio.h>
#include <stdlib.h>

char * whatisyourname()
{
	char * name = (char *)malloc(sizeof(char) * 30);
	printf("What is your name? : ");
	gets(name);
	return name;
}
int N1() {
	char * name1;
	char * name2;
	name1 = whatisyourname();
	puts(name1);
	name2 = whatisyourname();
	puts(name2);

	puts(name1);
	puts(name2);
	
	free(name1);
	free(name2);
	
	return 0;
}