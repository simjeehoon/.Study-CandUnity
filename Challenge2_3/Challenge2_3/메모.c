/*
	C���

	I. 2���� �迭 �����Ҵ���

	1) num1+1�� �Ҵ�

		//���� 
		int **arr;
		int i;

		arr = (int**)malloc(sizeof(int)*num1);
		for (i = 0; i < num1; i++)
			arr[i] = (int*)malloc(sizeof(int)*num2);

		//����
		for (i = 0; i < num1; i++)
			free(arr[i]);
		free(arr);

	2) 2�� �Ҵ�
	
		//����
		int **arr;
		int i;

		arr = (int**)malloc(sizeof(int)*num1);
		arr[0] = (int*)malloc(sizeof(int)*num1*num2);
		for (i = 1; i < num1; i++)
			arr[i] = arr[i-1] + num2;

		//����
		free(arr[0]);
		free(arr);

*/