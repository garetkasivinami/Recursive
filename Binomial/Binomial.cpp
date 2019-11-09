#include <stdio.h>
#include <Windows.h>
// для перевірки правильності роботи алгоритма
// http://mathforum.org/dr.cgi/pascal.cgi?rows=6

// знаходження елемента трикутника Паскаля
int PascalTriangle(int,int);
int main() {
	SetConsoleOutputCP(1251);
	int a, b;
	printf_s("Напишіть рівень трикутника Паскаля та індекс його елемента (починаючи з нуля)\n");
	scanf_s("%d %d", &a, &b);
	printf_s("%d", PascalTriangle(a,b));
}
// n - рівень, к - елемент рівня
int PascalTriangle(int n, int k) {
	if (n == k || k == 0) {
		return 1;
	}
	return PascalTriangle(n - 1, k - 1) + PascalTriangle(n - 1, k);
}