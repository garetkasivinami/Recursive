#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <time.h>
// напевно добре, але доволі дивно
int SummArr(int, int*, int);
int main() {
	srand(time(0));
	SetConsoleCP(1251);SetConsoleOutputCP(1251);
	int length = 6;
	int* arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 21 - 10;
	}
	printf_s("Сума елементів масиву: %d\n", SummArr(0, arr, length));
}
// і - початковий індекс
int SummArr(int i, int* arr, int length) {
	if (i == length - 1) {
		return arr[i];
	}
	else {
		return arr[i] + SummArr(i + 1, arr, length);
	}
}