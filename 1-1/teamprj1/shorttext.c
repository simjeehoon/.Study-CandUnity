#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i, total = 0, wrong_count = 0, j;
	time_t tStart, tEnd;
	double elapsed_time, accuracy;
	char input[100];
	char text[5][100] =
	{
		"there are boys",
		"aoao",
		"rpap",
		"slslsl",
		"aqw",
	};
	puts(text[2]);
	printf("���� ��(4) = %d", strlen(text[2]));
	printf("���\n");
	printf("��!.\n");
	system("slee(3)p");
	printf("< S T A R T>\n\n");

	time(&tStart);   //���۽ð� ����
	//���� for���� ������� ����� ������ �����ϰ� �Ѵ�.
	//�̸� rand �Լ��� �̿��Ͽ� ���� �������� �ٲٰ� �Ѵ�.
	for (i = 0; i < 5; i++)				
	{
		puts(text[i]);  //ȭ�鿡 �ش��ϴ� ���ڿ�(text[i])�� ���� �Լ��� puts�̴�. 
		gets(input);	//input�̶�� char�� ���� 100�� ���ڿ��� �ֱ� ���� ���� �Է��� ���� gets�� ���� �޾Ƴ���.
		total += strlen(text[i]);	//��Ż ���� ���� ����� ������ ���̸� ���ϴ� ���̴�.

		for (j = 0; j < (int)strlen(text[i]); j++)  
		{
			if (input[j])	//���� �Է��� ������ �ϳ��ϳ� ���ڸ� �˻��Ѵ�.
			{
				if (input[j] != text[i][j]) //���� �Է��� ���ڿ� ������ ���ڰ� ���� ������
					wrong_count++;		//��Ÿ�� �ø���.
			}
			else //��Ʋ������
			{
				wrong_count += (strlen(text[i]) - j); //������ ���̿��� (ex.5) �˻��ϴ� ��ġ��ŭ ����(ex.3) ���Ѵ�.
				break;
			}
		}
	}
	time(&tEnd);

	accuracy = (float)(total - wrong_count) / (float)total * 100.0f;
	elapsed_time = difftime(tEnd, tStart);
	printf("\n�� �� %0.0lf\n ��� : %3.2f%%\n", elapsed_time, accuracy);
	printf("\n��� : %d\n", wrong_count);
	return 0;

}
/* ������
1. time.h�� time_t�� ���� ����(time_t�� ��� ����?)
2. time(&tStart) <- ����ð��� �ش� ������ �����ϴ� ��. NULL ���� �׳� ����ð�, �����͸� �̿��� �����ϴµ�.
    > time�Լ��� ����
    ����ð� > time(&������ġ) =>�̰� ��ü ���� �ð��� ���̴�. �׷��� rand������ �ξ��� �����Ѵ�.
3. puts(text[i]) <- ȭ��� ���ڿ��� ���´�.
4. gets(input) ���ڸ� �޾Ƽ� �ִ´�. ���ڿ��� �޾������� ���־���. ���̰� 100�϶� 99�ڰ��ƴϴ��� ������ ����ġ�� �ű��� �ִ´�.
5. �νð��� ���̸� ��Ÿ����. difftime(tEnd, tStart)

*/
