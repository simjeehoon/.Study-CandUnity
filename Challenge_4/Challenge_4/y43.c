#include <stdio.h>

typedef struct complex
{
	double real;
	double imaginary;
}Complex;

Complex Complex_Add(Complex a, Complex b) {
	Complex res;
	res.real = a.real + b.real;
	res.imaginary = a.imaginary + b.imaginary;
	return res;
}

Complex Complex_Mul(Complex a, Complex b) {
	Complex res;
	res.real = (a.real * b.real) - (a.imaginary * b.imaginary);
	res.imaginary = (a.imaginary * b.real) + (a.real * b.imaginary);
	return res;
}

void Complex_print(Complex a) {
	printf("실수: %f, 허수: %f", a.real, a.imaginary);
}

int y43()
{
	Complex co1, co2;

	printf("복소수 입력1[실수 허수]: ");
	scanf("%lf %lf", &co1.real, &co1.imaginary);
	getchar();
	printf("복소수 입력2[실수 허수]: ");
	scanf("%lf %lf", &co2.real, &co2.imaginary);
	getchar();

	printf("합의 결과] ");
	Complex_print(Complex_Add(co1, co2));
	printf("\n");
	printf("곱의 결과] ");
	Complex_print(Complex_Mul(co1, co2));
	printf("\n");
	return 0;
}