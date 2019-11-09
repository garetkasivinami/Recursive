#include <stdio.h>
#include <Windows.h>
// обчислення N-го перших члена послідовності Фібоначчі
int FibonacciNum(int);
int main() {
	SetConsoleCP(1251);SetConsoleOutputCP(1251);
	int a;
	printf_s("N = ");
	scanf_s("%d", &a);
	printf_s("Fibonacci number[%d] = %d\n", a, FibonacciNum(a));
}
int FibonacciNum(int index) {
	// можна спростити до index <= 1
	return (index == 0 || index == 1) ? 1: FibonacciNum(index - 1) + FibonacciNum(index - 2);
	/* без тернарної операції варіант
	if (index == 0 || index == 1) { // можна спростити до index < 1
		return 1;
	} else {
		return FibonacciNum(index - 1) + FibonacciNum(index - 2);
	}
	*/
}