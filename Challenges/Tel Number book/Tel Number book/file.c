#include <stdio.h>
#include <stdlib.h>
#include "phone.h"
#define ORIGIN_SAVE 0
#define MODIFIED 1

void file_read(FILE * rf, Phone ** ph_list, int * const count)
{
	// 자료 개수 계산 //
	fseek(rf, 0, SEEK_SET);
	fread(count, sizeof(int), 1, rf);

	// 자료 불러들이기 //
	*ph_list = (Phone*)malloc(sizeof(Phone) * (*count));
	fread(*ph_list, sizeof(Phone), *count, rf);
}

void file_write(FILE * const wf, Phone * const ph_list, const int count)
{
	fseek(wf, 0, SEEK_SET);
	fwrite(&count, sizeof(int), 1, wf);
	fwrite(ph_list, sizeof(Phone), count, wf);
	fflush(wf);
}

int first_read(Phone ** ph_list, int * const count)
{
	FILE * rf = fopen("phone_list.bin", "rt");
	if (rf == NULL)
		return -1; //파일이 없다.
	file_read(rf, ph_list, count);
	fclose(rf);
	return 0; //파일이 있다.
}

int Save_file(FILE **const wf, Phone * const ph_list, const int count, int mode)
{
	if (MODIFIED)
	{
		fclose(*wf);
		*wf = fopen("phone_list.bin", "wt");
	}
	
	file_write(*wf, ph_list, count);
}
