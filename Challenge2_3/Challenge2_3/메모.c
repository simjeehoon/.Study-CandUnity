/*
	C언어

	I. 2차원 배열 동적할당방법

	1) num1+1번 할당

		//설정 
		int **arr;
		int i;

		arr = (int**)malloc(sizeof(int)*num1);
		for (i = 0; i < num1; i++)
			arr[i] = (int*)malloc(sizeof(int)*num2);

		//해제
		for (i = 0; i < num1; i++)
			free(arr[i]);
		free(arr);

	2) 2번 할당
	
		//설정
		int **arr;
		int i;

		arr = (int**)malloc(sizeof(int)*num1);
		arr[0] = (int*)malloc(sizeof(int)*num1*num2);
		for (i = 1; i < num1; i++)
			arr[i] = arr[i-1] + num2;

		//해제
		free(arr[0]);
		free(arr);

*/