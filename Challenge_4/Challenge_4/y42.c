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
	printf("도서 정보 입력\n");

	for (i = 0; i < 3; i++)
	{
		books[i] = (Book *)malloc(sizeof(Book));
		printf("저자: ");
		gets(books[i]->writer);
		printf("제목: ");
		gets(books[i]->name);
		printf("페이지 수: ");
		scanf("%d", &(books[i]->page));
		getchar();
	}

	printf("도서 정보 출력\n");
	for (i = 0; i < 3; i++)
	{
		printf("book %d", i + 1);
		printf("저자: %s\n", books[i]->writer);
		printf("제목: %s\n", books[i]->name);
		printf("페이지 수: %d\n", books[i]->page);
		free(books[i]);
	}
	return 0;
}
