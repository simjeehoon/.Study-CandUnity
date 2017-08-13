#include <stdio.h>

int main(void)
{
	unsigned long long f;
	int n;
	printf("계승 입력:");
	scanf("%d", &n);
	f=n;
	printf("%d! = ",n);
	while(--n > 0)
	{
		f *= n;
	}
	printf("%lld\n", f);
	return 0;
}

	
