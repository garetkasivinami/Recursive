#include <stdio.h>
#include <Windows.h>
/*
приклад роботи
Напишіть максимальний елемент для виводу чисел
5
5 4 3 2 1 0 1 2 3 4 5
*/
void HappyPrint(int);
int main() {
	SetConsoleCP(1251);SetConsoleOutputCP(1251);
	int a;
	printf_s("Напишіть максимальний елемент для виводу чисел\n");
	scanf_s("%d", &a);
	HappyPrint(a);
}
void HappyPrint(int n) {
	if (n < 1) {
		printf_s("%d ", n);
	}
	else {
		printf_s("%d ", n);
		HappyPrint(n - 1);
		printf_s("%d ", n);
	}
}