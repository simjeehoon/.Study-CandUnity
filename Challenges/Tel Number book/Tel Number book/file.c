#include <stdio.h>
#include <stdlib.h>
#include "phone.h"

void file_read(FILE * rf, Phone ** ph_list, int * const count)
{
	// �ڷ� ���� ��� //
	fseek(rf, 0, SEEK_SET);
	fread(count, sizeof(int), 1, rf);

	// �ڷ� �ҷ����̱� //
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
		return -1; //������ ����.
	file_read(rf, ph_list, count);
	fclose(rf);
	return 0; //������ �ִ�.
}

