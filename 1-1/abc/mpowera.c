#include <stdio.h>
int gcd(int x, int y);

int main(void)
{
	int b, n, m;

	printf("최대공약수를 구할 두 수를 주지 않겠니? : ");
	scanf("%d %d", &num1, &num2);
	printf("%d와 %d의 최대공약수는 %d입니다.\n", num1, num2, gcd(num1, num2));
	return 0;
}

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	else
		return gcd(y%x, x);
}
