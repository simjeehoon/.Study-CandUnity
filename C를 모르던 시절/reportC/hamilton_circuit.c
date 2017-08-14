#include <stdio.h>

#define N 100
//입력할 수 있는 최대 도시 개수를 설정.

int input_city(void) // 도시 개수를 입력하는 함수입니다.
{
	int city = 0;
	while(city < 3)
	{
		printf("도시 개수(3개 이상) : ");
		scanf("%d", &city);
		if (city < 3)
			printf("도시는 3개 이상이여야 합니다.\n");
	} 

	return city;
}

void input_ways(int city, int ways[N][N]) // 도시간의 도로 개수를 입력하는 함수입니다.
{
	int i, line = 0;
	int linked;
	printf("도시의 연결을 파악합니다.\n두 도시 A-B에 존재하는 도로 수를 입력하세요.\n두 도시 A-B에 도로가 없으면 0을 입력하세요.\n\n");
			
	while (line < city)
	{
		i = line + 1;
		while (i < city)
		{
			printf("%d - %d : ", line + 1, i + 1); // 사용자가 보기엔 0번째는 곧 1번째입니다.
			scanf("%d", &linked);
			ways[line][i++] = linked;
		}
		line++;
	}
	return;
}

void automatic_setting(int city, int ways[N][N]) // 입력된 도로를 바탕으로 행렬을 적용합니다.
{
	int i = 0, j = 0;

	while (i < city)
	{
		ways[i][i] = 0;
		i++;
	} //루프는 없습니다.
	
	
	while (j < city)
	{
		i = j + 1;
		while (i < city)
		{
			ways[i][j] = ways[j][i];
			i++;
		}
		j++;
	} //a-b간의 연결은 곧 b-a간의 연결입니다.
	return;
}

void set_list(int city, int loading[]) //해밀턴 순환 검사시 사용된 도시는 제외시킵니다.
{
	int i;
	for (i = 0; i < city; i++)
		loading[i] = 1;
	return;
}

int test_hamilton(int start, int ways[N][N], int city, int loading[], int result[N])
{
	static int count = 0;
	int s = 0;
	int ok = 0;
	
	loading[start] = -1; //스타트 도시는 남아있는 도시에서 제외시킵니다.
	result[count++] = start + 1; //경로를 저장합니다.

	if (count == city)//만약 모든 도시를 탐방했다면
	{
		if (ways[start][0])//스타트 도시로 갈 수 있는가
		{
			result[count++] = 1;
			return 1;
		}
		else//다시 돌아가기
		{
			count--;
			loading[start] = 1;
			return 0;
		}
	}//마지막 도시에 도달했을때 사이클인지 판별합니다.

	else
	{
		for (s = 0;s < city;s++)
		{
			if (loading[s] == -1) //이미 갔던 도시는 제외.
				continue;
			if (ways[start][s])
			{
				ok = test_hamilton(s, ways, city, loading, result); //그 다음점에서 해밀턴 서킷 탐색
				if (ok)//해밀턴 서킷 조건을 만족하면 1을 리턴.
					return 1;
			}
		}
		//해밀턴 서킷을 못찾았을 때 리턴 0
		count--;
		loading[start] = 1;//다시 돌아가기 위한 복구
		return 0;
	}
}

int main(void)
{
	int city;
	int ways[N][N] = { 0 };
	int loading[N] = { 0 };
	int result[N+1] = { 0 };
	int circuit;
	int i;

	printf("이 프로그램에서는 시작 도시를 1로 가정합니다.\n");
	city = input_city();
	input_ways(city, ways);
	automatic_setting(city, ways);

	set_list(city, loading);
	circuit = test_hamilton(0, ways, city, loading, result);
	//해밀턴 경로이면 1을 리턴하고, 아니면 0을 리턴합니다.
	if (circuit)
	{
		printf("이것은 해밀턴 순환입니다. 즉, 미션을 완료할 수 있습니다.\n가능한 경로들 중 하나는 아래와 같습니다.\n");
		for (i = 0;i <= city;i++)
		{
			printf("%d", result[i]);
			if (i != city)
				printf(" - ");
			else
				printf("\n");
		}

	}
	else
		printf("이것은 해밀턴 순환이 아닙니다.\n즉, 미션을 완료할 수 없습니다.");

	return 0;
}


