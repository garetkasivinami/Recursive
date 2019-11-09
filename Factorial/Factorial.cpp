#include <stdio.h>
#include <Windows.h>
// класичний варіант рекурсії
// неефективно, проте можна легко пояснити
int Fact(int);
int main() {
	SetConsoleCP(1251);SetConsoleOutputCP(1251);
	int number;
	printf_s("Напишіть для розрахунку його факторіала\n");
	scanf_s("%d", &number);
	printf_s("%d! = %d\n", number, Fact(number));
}
int Fact(int target) {
	if (target <= 1) {
		return 1;
	}
	return target * Fact(target);
}