#include "virtual effect.h"

/* 콘솔 텍스트의 색깔을 지정하는 함수 */

void SetColor(Color cor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void NormalColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
}