﻿// Герасимчук Віктор КБ-19-2
#include <stdio.h>
#include <windows.h>
#include <time.h>
void Task();
void Swap(int&, int&);
void PrintMatrix(int**, int, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Task();
	return 0;
}

void Task() {
	int size;
	printf_s("Напишіть розмір квадратної матриці (n*n)\n");
	scanf_s("%d", &size);
	int sizeInt = sizeof(int);
	int** matrix = (int**)malloc(sizeInt * size);
	for (int i = 0; i < size; i++) {
		matrix[i] = (int*)malloc(sizeInt * size);
		for (int h = 0; h < size; h++) {
			matrix[i][h] = rand() % 21 - 10;
			printf_s("%4d", matrix[i][h]);
		}
		printf_s("\n");
	}
	//
	int summ1 = 0, summ2 = 0;
	for (int i = 0; i < size; i++) {
		summ1 += matrix[i][i];
		summ2 += matrix[i][size - i - 1];
	}
	printf_s("Сума головної діагоналі %d\nСума додаткової діагоналі %d\n", summ1, summ2);
	if (summ2 < summ1) {
		Swap(summ1, summ2);
		printf_s("Відбулася зміна місцями сум діагоналей\n");
		for (int i = 0; i < size; i++) {
			Swap(matrix[i][i], matrix[i][size - i - 1]);
		}
		PrintMatrix(matrix, size, size);
	}
}

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void PrintMatrix(int** arr, int sizeX, int sizeY) {
	for (int i = 0; i < sizeX; i++) {
		for (int h = 0; h < sizeY; h++) {
			printf_s("%4d", arr[i][h]);
		}
		printf_s("\n");
	}
}