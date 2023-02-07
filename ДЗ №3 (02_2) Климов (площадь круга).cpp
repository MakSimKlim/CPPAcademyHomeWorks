﻿//ДЗ #3 Климов (площадь круга).cpp : 
//По заданной длине окружности найти площадь круга 
//по формуле S = pi * R^2, радиус вычислить из формулы длины
//окружности : L = 2 * pi * R


#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	double radius = 0, length = 0, square = 0;//назначаем вещественные переменные двойной точности
	double const Pi = 3.14;//назначаем вещественные константы двойной точности
	
	//вывод на экран текста с помощью escape последовательностей
	cout << R"(Программа вычисления площади круга из длины окружности 
====================================================)" << endl;

	cout << "Введите значение длины окружности: " << endl;
	
	cin >> length;//предлагаем пользователю ввести данные о радиусе окружности
	
	radius = length / (Pi * 2);//вычисляем радиус окружности
	square = Pi * pow(radius, 2);//вычисляем площадь круга
	
	cout << "Площадь круга: " << square << endl << endl;//выводим на экран значение площади круга
	
	system("pause");

	return 0;

}