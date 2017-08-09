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
	printf("¿¿¿(4) = %d", strlen(text[2]));
	printf("¿¿¿¿\n");
	printf("¿¿\n");
	system("slee(3)p");
	printf("< S T A R T>\n\n");

	time(&tStart);   
	for (i = 0; i < 5; i++)				
	{
		puts(text[i]);  
		gets(input);
		total += strlen(text[i]);	

		for (j = 0; j < (int)strlen(text[i]); j++)  
		{
			if (input[j])
			{

				if (input[j] != text[i][j]) 
					wrong_count++;		
			}
			else 
			{
				wrong_count += (strlen(text[i]) - j); 
				break;
			}
		}
	}
	time(&tEnd);

	accuracy = (float)(total - wrong_count) / (float)total * 100.0f;
	elapsed_time = difftime(tEnd, tStart);
	printf("\n¿¿ ¿¿ %0.0lf\n ¿¿¿ : %3.2f%%\n", elapsed_time, accuracy);
	printf("\n ¿¿ ¿ : %d\n", wrong_count);
	return 0;

}
