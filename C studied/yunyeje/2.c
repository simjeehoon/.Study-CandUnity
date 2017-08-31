#include <stdio.h>

int main(void){
	FILE * txt = fopen("some.txt", "rt");
	char name[10];
	char sex;
	int age;

	int ret;
	while(1){
		ret = fscanf(txt, "%s %c %d", name, &sex, &age);
		if(ret == EOF)
			break;
		printf("%s %c %d\n", name, sex, age);
	}
	fclose(txt);

	return 0;
}
