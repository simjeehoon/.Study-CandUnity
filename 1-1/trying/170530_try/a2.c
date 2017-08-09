#include <stdio.h>

int my_strlen (char str[]);

int main(void){
	char str [] = "four";
	printf("%s : %d",str, my_strlen(str));
}

int my_strlen (char str[]){
	int i = 0;

	while (str[i] != '\0')
		i++;
	return i;
}
