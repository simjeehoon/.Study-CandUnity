#include <stdio.h>
#define PLUS3(X, Y, Z) ((X)+(Y)+(Z))
#define MULTIPLICATION3(X, Y, Z) ((X)*(Y)*(Z))

#define PI 3.14
#define AREA(R) ((R)*(R)*PI)

#define MAX(A,B) ( (A) > (B) ? (A) : (B) )

int ym2611()
{
	printf("7 + 2 + 3 = %d\n", PLUS3(7, 2, 3));
	printf("4 * 2 * 3 = %d\n", MULTIPLICATION3(4, 2, 3));
	printf("r=3.0 AREA = %f\n", AREA(3.0));
	printf("3과 4중에 %d가 더 큽니다.\n", MAX(3, 4));
	printf("7과 5중에 %d가 더 큽니다.\n", MAX(7, 5));
	return 0;

}
