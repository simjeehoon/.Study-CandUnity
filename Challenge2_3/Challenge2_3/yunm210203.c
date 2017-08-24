#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30

int comparedata(char *d1, char *d2);

void bufferreset();

int yunm210203()
{
	char data1[N] = { 0 };
	char data2[N] = { 0 };
	bufferreset();
	gets(data1);
	gets(data2);
	comparedata(data1, data2);

}

int comparedata(char *d1, char *d2)
{
	int i = 0, j = 0;
	int k1 = 0, k2 = 0;
	char name1[N] = { 0 };
	char name2[N] = { 0 };
	char age1[10], age2[10];
	while (d1[i] != ' ')
	{
		if (i >= N - 1) {
			printf("Error\n");
			return 0;
		}
		++i;
	}
	while (d2[j] != ' ')
	{
		if (j >= N - 1) {
			printf("Error\n");
			return 0;
		}
		++j;
	}
	strncpy(name1, d1, i);
	name1[i] = '\0';
	strncpy(name2, d2, j);
	name2[j] = '\0';
	i++;
	j++;
	while (d1[i] != '\0') {
		age1[k1++] = d1[i++];
	}
	while (d2[j] != '\0') {
		age2[k2++] = d2[j++];
	}
	if (strcmp(name1, name2) == 0)
		printf("같은 이름\n");
	else
		printf("다른 이름\n");
	if (atoi(age1)==atoi(age2))
		printf("같은 나이\n");
	else
		printf("다른 나이\n");

	return 0;
}