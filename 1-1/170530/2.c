#include <stdio.h>
void my_print(char a, int n)
{
	int i=0;
	while(i<n){
		printf("%c", a);
		i++;
	}
	return;
}

int main(void)
{
	my_print('*', 1);
	printf("\n");
	my_print('#', 5);
	printf("\n");
	my_print('@', 7);
	printf("\n");
	return 0;
}

