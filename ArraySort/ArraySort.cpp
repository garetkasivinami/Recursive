#include <stdio.h>
#include <Windows.h>
// модифіковане сортування бульбашкою
void SortArray(int*,int);
void Swap(int&,int&);
void PrintArray(int*,int);
int main() {
	SetConsoleOutputCP(1251);
	int* arr, length;
	printf_s("Напишіть розмір масива\n");
	scanf_s("%d", &length);
	arr = (int*)malloc(sizeof(int) * length);
	printf_s("Напишіть елементи масиву (через ентер або пробіл)\n");
	for (int i = 0; i < length; i++) {
		scanf_s("%d", &arr[i]);
	}
	SortArray(arr, length);
	PrintArray(arr, length);
}
void SortArray(int* arr, int length) {
	if (length == 1) {
		return;
	}
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i - 1]) {
			Swap(arr[i], arr[i - 1]);
		}
	}
	SortArray(arr, length - 1);
}
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void PrintArray(int *arr, int length) {
	printf_s("Array = {");
	for (int i = 0; i < length; i++) {
		printf_s("%d", arr[i]);
		if (i < length - 1) {
			printf_s(", ");
		}
	}
	printf_s("}\n");
}