#ifndef __WINDOWS_HEADER__
#define __WINDOWS_HEADER__

#include <windows.h>

#endif

#ifndef __COLOR_FUNC__
#define __COLOR_FUNC__

typedef enum color {
	black = 0, blue = 1, green = 2, mint = 3, red = 4, purple = 5, yellow = 6,
	white = 7, grey = 8, light_blue = 9, light_green = 10, light_mint = 11, light_red = 12,
	light_purple = 13, light_yellow = 14, real_white = 15
}Color;

void Setcolor(Color cor);

#endif