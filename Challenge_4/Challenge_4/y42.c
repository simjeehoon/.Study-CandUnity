#include <stdio.h>
#include <string.h>

typedef struct book {
	char writer[50];
	char name[100];
	int page;
}Book;

int y42()
{
	int i;
	Book * books[3];
	printf("���� ���� �Է�\n");

	for (i = 0; i < 3; i++)
	{
		books[i] = (Book *)malloc(sizeof(Book));
		printf("����: ");
		gets(books[i]->writer);
		printf("����: ");
		gets(books[i]->name);
		printf("������ ��: ");
		scanf("%d", &(books[i]->page));
		getchar();
	}

	printf("���� ���� ���\n");
	for (i = 0; i < 3; i++)
	{
		printf("book %d", i + 1);
		printf("����: %s\n", books[i]->writer);
		printf("����: %s\n", books[i]->name);
		printf("������ ��: %d\n", books[i]->page);
		free(books[i]);
	}
	return 0;
}
