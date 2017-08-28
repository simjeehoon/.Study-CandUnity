#include <stdio.h>
#include <stdarg.h>

void print_all_num(int count, ...);

int N2()
{
	print_all_num(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	printf("\n");
	return 0;
}

void print_all_num(int count, ...) {
	int i;
	va_list vlist;

	va_start(vlist, count);

	for (i = 0; i < count; i++) {
		printf("%d ", va_arg(vlist, int));
	}

	va_end(vlist);

}