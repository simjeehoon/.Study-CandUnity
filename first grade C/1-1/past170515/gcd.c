#include <stdio.h>

int main(void)
{
	int N = 1, n = 1, m = 1, M = 0;
	printf(" 최대 공약수 두 정수");
	scanf("%d%d", &n, &N);
	while ( m <= n && m <= N)
	{
		if((n % m == 0) && (N%m == 0))
		{
			M = m;
		}
		m++;
	}

	printf("%d",M);
	return 0;
}



