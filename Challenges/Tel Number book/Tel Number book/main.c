#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

void scanf_reset();
int first_read(Phone ** ph_list, int * const count);
void file_write(FILE * const wf, Phone * const ph_list, const int count);
void Insert(Phone ** ph_list, int * const count);
void Delete(Phone ** ph_list, int * const count);
void Search(Phone * ph_list, const int count);
void Print_All(Phone * ph_list, const int count);
_Bool same_name_check(char * name, Phone * ph_list, const int count);

int main(void)
{
	FILE * ph_file;
	int option;
	int count = 0;
	Phone * phone_list;

	if (first_read(&phone_list, &count))
	{
		printf("새 파일을 생성하였습니다.\n");
	}
	else
	{
		printf("기존 파일을 불러왔습니다.\n");
	}

	ph_file = fopen("phone_list.bin", "wt");
	file_write(ph_file, phone_list, count);

	while (1)
	{
		printf("***** MENU *****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Print All\n");
		printf("5. Exit\n");
		printf("Choose the item: ");
		scanf("%d", &option);
		getchar();
		switch (option)
		{
		case 1:
			Insert(&phone_list, &count);
			file_write(ph_file, phone_list, count);
			break;
		case 2:
			Delete(&phone_list, &count);
			file_write(ph_file, phone_list, count);
			break;
		case 3:
			Search(phone_list, count);
			break;
		case 4:
			Print_All(phone_list, count);
			break;
		case 5:
			file_write(ph_file, phone_list, count);
			fclose(ph_file);
			if (count > 0)
				free(phone_list);
			return 0;
			break;
		default:
			printf("잘못된 번호입니다.\n");
		}
	}
	file_write(ph_file, phone_list, count);
	fclose(ph_file);
	return -1;
}

void Insert(Phone ** ph_list, int * const count)
{
	char name[30];
	if (*count == 0)
	{
		*ph_list = (Phone *)malloc(sizeof(Phone) * (++(*count)));
	}
	else
	{
		*ph_list = (Phone *)realloc(*ph_list, sizeof(Phone) * (++(*count)));
	}
	
	puts("[ INSERT ]");

	printf("Input Name: ");
	while (1)
	{
		gets(name);
		if (same_name_check(name, *ph_list, (*count)-1))
		{
			printf("Already same name is in the list. Please input another name.\nInput Name :");
			continue;
		}
		break;
	}
	strcpy((*ph_list)[(*count) - 1].name, name);
	printf("Input Tel Number: ");
	gets((*ph_list)[(*count) - 1].tel_number);

	printf("				Data Inserted\n\n");
}

void Delete(Phone ** ph_list, int * const count)
{
	char name[30];
	int i;
	char ch;
	if (*count == 0) {
		printf("현재 전화번호가 하나도 없으므로 수행 불가능합니다.\n\n");
		return;
	}

	puts("[ DELETE ]");
	printf("Input Name: ");
	gets(name);
	
	for (i = 0; i < *count; ++i) {
		if (strcmp((*ph_list)[i].name, name) == 0)
			break;
	}
	if (i < *count)
	{
		puts("This is the data for delete");
		printf("Name: %s\n", (*ph_list)[i].name);
		printf("Number: %s\n", (*ph_list)[i].tel_number);
		printf("Do you really want to erase it? (y/n)\n");
		while (1)
		{
			scanf("%c", &ch);
			scanf_reset();
			if (ch == 'y' || ch == 'Y')
			{
				for (int j = i; j < *count - 1; j++)
				{
					(*ph_list)[j] = (*ph_list)[j+1];
				}
				
				memset(&( (*ph_list)[*count - 1] ), 0, sizeof(Phone));

				if(*count > 1)
				{
					*ph_list = realloc(*ph_list, sizeof(Phone) * (--(*count)));
				}
				else
				{
					--(*count);
					free(*ph_list);
				}
				puts("Delete Complete.");
				break;
			}
			else if (ch == 'n' || ch == 'N')
			{
				return;
			}
			else
			{
				printf("You have entered incorrectly.\n");
				printf("Do you really want to erase it? (y/n)\n");
			}
		}
	}
	else
	{
		printf("There's no data\n");
	}
	printf("\n");
}

void Search(Phone * ph_list, const int count)
{
	int i;
	char name[30];
	if (count == 0)
	{
		printf("현재 전화번호가 하나도 없으므로 수행 불가능합니다.\n\n");
		return;
	}
	puts("[ SEARCH ]");
	printf("Name to look for: ");
	gets(name);
	for (i = 0; i < count; ++i)
	{
		if (strcmp(ph_list[i].name, name) == 0)
			break;
	}
	if (i < count)
	{
		printf("Number: %s\n", ph_list[i].tel_number);
	}
	else
	{
		printf("There is no such data.\n");
	}
	printf("\n");
}

void Print_All(Phone * ph_list, const int count)
{
	int i;

	if (count == 0) {
		printf("저장된 전화번호가 없습니다.\n\n");
		return;
	}
	puts("[ Print All Data ]");
	for (i = 0; i < count; i++)
	{
		printf("Name: %s	Tel: %s\n", ph_list[i].name, ph_list[i].tel_number);
	}
	printf("\n");
	
}

_Bool same_name_check(char * name, Phone * ph_list, const int count)
{
	int i;
	if (count > 0) {
		for (i = 0; i < count; ++i)
		{
			if (strcmp(name, ph_list[i].name) == 0)
				return 1;
		}
	}
	return 0;
}