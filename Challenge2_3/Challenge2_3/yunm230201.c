#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;

typedef struct rectangle {
	Point Upper_left;
	Point Lower_right;
}Rectangle;

void showpoint(Point * pt) {
	printf("[%d, %d] ", pt->xpos, pt->ypos);
}

void showarea(Rectangle * reg) {
	int area = ((reg->Lower_right).xpos - (reg->Upper_left).xpos) * ((reg->Lower_right).ypos - (reg->Upper_left).ypos);
	printf("Area : %d\n", area);
}

void showRecpoint(Rectangle * reg) {
	Point Upper_right = { (reg->Lower_right).xpos ,(reg->Upper_left).ypos };
	Point Lower_left = { (reg->Upper_left).xpos ,(reg->Lower_right).ypos };
	showpoint(&(reg->Upper_left));
	showpoint(&Upper_right);
	showpoint(&Lower_left);
	showpoint(&(reg->Lower_right));
}

int yunm230201() {
	Rectangle rec = { { 0,0 },{ 10,10 } };
	showarea(&rec);
	showRecpoint(&rec);
	return 0;
}