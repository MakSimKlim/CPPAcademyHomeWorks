﻿// Задание #5
// 
// ДЗ №8 Климов (таблица умножения).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Написать программу, которая выводит на экран таблицу
//умножения на k, где k — номер варианта.Например, для 7 - го
//варианта :
//7 x 2 = 14;
//7 x 3 = 21.

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int k = 0, p = 0;

	cout << "*******************************************************************************" << endl;
	cout << "*     Программа вывода таблицы умножения выбранного варианта от '1' до '9'    *" << endl;
	cout << "*******************************************************************************" << endl << endl;

	cout << "Введите вариант от 1 до 9: ";
	cin >> k;
	cout << "\n";

	if (k >= 1 && k <=9 )//проверка условия 1<= k <=9
	{
		for (int i = 1; i <= 9; i++)//цикл умножения выбранного варианта k на числа от 1 до 9
		{
			p = k * i;
			cout << k << " x " << i << " = " << p << endl;
		}
	}
	else
	{
		cout << "\nВведены некорректные данные. Перезапустите программму " << endl << endl;
	}
	
	cout << "\n";


	system("pause");

	return 0;

}
