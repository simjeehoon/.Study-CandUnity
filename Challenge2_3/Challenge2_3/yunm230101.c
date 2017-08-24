#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point1;

void swaptheposition(Point1 * p1, Point1 * p2) {
	Point1 tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void printthepoint(Point1 * p1) {
	printf("[%d, %d]", p1->xpos, p1->ypos);
}
int yunm230101() {

	Point1 pos1 = { 2, 4 }, pos2 = { 5, 7 };
	swaptheposition(&pos1, &pos2);
	printf("pos1 : ");
	printthepoint(&pos1);
	printf("\npos2 : ");
	printthepoint(&pos2);
	printf("\n");
	
	return 0;
}