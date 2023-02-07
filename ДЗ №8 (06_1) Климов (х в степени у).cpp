﻿// Задание #2
// 
// ДЗ #8 Климов (х в степени у)

//Напишите программу, которая запрашивает два целых числа
//x и y, после чего вычисляет и выводит значение x в степени y.

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int x = 0, y = 0;
	float p = 1;//переменная произведения числа "х" само на себя "у" раз, начиная с 1 (для 0 степени отдельное условие,
	// т.к. любое число в степени 0 равно 1)

	cout << "*******************************************************" << endl;
	cout << "*     Программа вычисления числа 'Х' в степени 'У'    *" << endl;
	cout << "*******************************************************" << endl << endl;

	cout << "Введите любое целое число 'X': " << endl;
	cin >> x;
	cout << "Введите любое целое число возведения в степень 'Y': " << endl;
	cin >> y;
	
	//решение #1 самое простое: через формулу
	//cout << "Значение Х в степени У равно: "<< pow (x,y) << endl;

	
	
	
	//Решение #2 через цикл for
	
	if (y > 0)//проверка положительности степени "у"
	{
		for (int i = 1; i <= y; i++)
		{
			p = p * x;

		}

		cout << "Значение 'Х' в степени 'У' равно: " << p << endl;
	}
	else if (y < 0)//проверка отрицательности степени "у" 
	{
		for (int i = 1; i <= (y*(-1)); i++)
		{
			p = p / x;
			
		}

		cout << "Значение 'Х' в степени 'У' равно: " << p << endl;
	}
	else//условие при значении "у" = 0
	{
		cout << "Значение 'Х' в степени 'У' равно: 1" << endl;
	}
		

		system("pause");

		return 0;
	
}
