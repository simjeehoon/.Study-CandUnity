#include <stdio.h>

int main(void){
	FILE * txt = fopen("some.txt", "wt");
	char name[10];
	char sex;
	int age;

	int i;
	for(i=0;i<3;i++){
		printf("이름, 성별, 나이순 입력:");
		scanf("%s %c %d", name, &sex, &age);
		getchar();
		fprintf(txt, "%s %c %d", name, sex, age);
	}
	fclose(txt);

	return 0;
}
