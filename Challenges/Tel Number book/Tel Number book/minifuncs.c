#include <stdio.h>

void scanf_reset() {
	while (getchar() != '\n')
		;
}