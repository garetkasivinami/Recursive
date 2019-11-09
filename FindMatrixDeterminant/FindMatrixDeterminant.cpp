#include <stdio.h>
#include <Windows.h>
#include <math.h>
/*ВИЩИЙ ПІЛОТАЖ*/
// рекурсивний пошук детермінанта матриці
int Determinant(int**, int, int);
int main() {
	SetConsoleOutputCP(1251);
	int x;
	printf_s("Введіть порядок квадратної матриці\n");
	scanf_s("%d", &x);
	printf_s("Напишіть матрицю (по рядкам через пробіл)\n");
	int **matr = (int**)malloc(sizeof(int) * x); // створення матриці
	for (int z = 0; z < x; z++) {
		matr[z] = (int*)malloc(sizeof(int) * x);
		for (int i = 0; i < x; i++) {
			scanf_s("%d", &matr[z][i]);
		}
	}
	printf_s("%d",Determinant(matr, x, 1));
}
// coef потрібний для роботи рекурсії та для множення матриці на число
int Determinant(int** matrix, int sizeXnY, int coef) {
	if (sizeXnY == 2) { // матриця 2-го порядку розрахунок
		return coef * (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
	}
	else {
		int summ = 0; // результат
		int newSize = sizeXnY - 1;// розмір для матриці з порядком n-1
		for (int i = 0; i < sizeXnY; i++) { // розклад матриці за рядком
			int delta = 0; // коефіцієнт зміщення
			int**matr = (int**)malloc(sizeof(int) * newSize); // створення вказівників на рядки
			for (int z = 0; z < newSize; z++) { // створення рядків
				matr[z] = (int*)malloc(sizeof(int) * newSize);
			}
			// створення матриці з пониженим порядком
			for (int x = 1; x < sizeXnY; x++) { // викреслення 1 рядку та [і] стовбчика
				for (int y = 0; y < sizeXnY; y++) {
					if (y == i) { // зміщення для дочірньої матриці
						delta = 1;
					}
					else {
						// враховується зміщення для матриці
						matr[x - 1][y - delta] = matrix[x][y];
					}
				}
				// для нового рядка зміщення становить нулю
				delta = 0;
			}
			// детермінант матриці
			summ += Determinant(matr, newSize, matrix[0][i] * pow(-1, i)); // враховується матриця порядків
		}
		return summ * coef;
	}
}