#include "virtual effect.h"

/* �ܼ� �ؽ�Ʈ�� ������ �����ϴ� �Լ� */

void SetColor(Color cor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void NormalColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
}