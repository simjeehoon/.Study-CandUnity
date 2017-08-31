#include <stdio.h>

typedef struct phone
{
	unsigned a:32, b:1, :0, c:1;
}phone;

int main()
{
	printf("%u\n", sizeof(phone));
	return 0;
}
