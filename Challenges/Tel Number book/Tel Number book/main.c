#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_num {
	char name[30];
	char tel_number[40];
}Phone;

void scanf_reset();
void Insert(Phone ** ph_list, int * const count);
void Delete(Phone ** ph_list, int * const count);
void Search(Phone ** ph_list, const int * const count);
void Print_All(Phone ** ph_list, const int const * count);


int main(void)
{
	int option;
	int count = 0;
	Phone * phone_list;

	while (1)
	{
		printf("***** MENU *****\n", count);
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
			break;
		case 2:
			Delete(&phone_list, &count);
			break;
		case 3:
			Search(&phone_list, &count);
			break;
		case 4:
			Print_All(&phone_list, &count);
			break;
		case 5:
			return 0;
			break;
		default:
			printf("잘못된 번호입니다.\n");
		}
	}
	return -1;
}

void Insert(Phone ** ph_list, int * const count)
{
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
	gets((*ph_list)[(*count) - 1].name);
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
		while (1) {
			scanf("%c", &ch);
			scanf_reset();
			if (ch == 'y' || ch == 'Y')
			{
				if (i != *count - 1)
				{
					for (int j = i; j < *count - 1; j++)
					{
						(*ph_list)[j] = (*ph_list)[j+1];
					}
				}
				if(*count > 1)
				{
					*ph_list = realloc(*ph_list, sizeof(Phone) * (--(*count)));
				}
				else
				{
					--(*count);
					free(*ph_list);
				}
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

void Search(Phone ** ph_list, const int * const count)
{
	int i;
	char name[30];
	if (*count == 0) {
		printf("현재 전화번호가 하나도 없으므로 수행 불가능합니다.\n\n");
		return;
	}
	puts("[ SEARCH ]");
	printf("Name to look for: ");
	gets(name);
	for (i = 0; i < *count; ++i)
	{
		if (strcmp((*ph_list)[i].name, name) == 0)
			break;
	}
	if (i < *count)
	{
		printf("Number: %s\n", (*ph_list)[i].tel_number);
	}
	else
	{
		printf("There's No data\n");
	}
	printf("\n");
}

void Print_All(Phone ** ph_list, const int const * count)
{
	int i;

	if (*count == 0) {
		printf("저장된 전화번호가 없습니다.\n\n");
		return;
	}
	puts("[ Print All Data ]");
	for (i = 0; i < *count; i++)
	{
		printf("Name: %s	Tel: %s\n", (*ph_list)[i].name, (*ph_list)[i].tel_number);
	}
	printf("\n");
	
}
