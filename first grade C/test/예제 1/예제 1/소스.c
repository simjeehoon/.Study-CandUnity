#include <stdio.h>
void duetime(int hour, int min, int sec, int taketime)
{
	int nhour, nmin, nsec;
	unsigned long long ressec = 0;
	ressec += sec;
	ressec += min * 60;
	ressec += hour * 60 * 60;
	ressec += taketime;
	while (ressec >= 24 * 60 * 60)
	{
		ressec -= 24 * 60 * 60;
	}
	nhour = ressec / (60 * 60);
	ressec %= 3600;
	nmin = ressec / 60;
	ressec %= 60;
	nsec = ressec;
	printf("%d ", nhour);
	printf("%d ", nmin);
	printf("%d\n", nsec);
}
int main(void)
{
	int hour, min, sec;
	int taketime;
	scanf("%d %d %d", &hour, &min, &sec);
	scanf("%d", &taketime);
	duetime(hour, min, sec, taketime);
	return 0;
}