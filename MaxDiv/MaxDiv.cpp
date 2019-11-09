#include <stdio.h>
#include <Windows.h>

// найбільший спільний дільник за алгоритмом Евкліда
int MaxDiv(int, int);
int main() {
	SetConsoleCP(1251);SetConsoleOutputCP(1251);
	int a, b;
	printf_s("Напишіть два числа для пошуку найбільшого спільного дільника\n");
	scanf_s("%d %d", &a, &b);
	printf_s("Найбільший спільний дільник %d\n", MaxDiv(a,b));
}
int MaxDiv(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (a > b) {
		return MaxDiv(a - b, b);
	}
	else {
		return MaxDiv(a, b - a);
	}
}