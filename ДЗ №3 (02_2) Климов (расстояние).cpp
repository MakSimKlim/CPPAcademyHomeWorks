﻿// ДЗ #3 Климов (расстояние).cpp 
//Вычислить пройденное расстояние при прямолинейном 
//равноускоренном движении по формуле S = v * t + (a * t^2) / 2,
//где v— скорость, t— время, а— ускорение.


#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	double speed = 0, time = 0, acceleration = 0, distance = 0;//назначаем вещественные переменные двойной точности
	
	//вывод на экран текста с помощью escape последовательностей
	cout << R"(     Программа вычисления пройденного расстояния
        при прямолинейном ускоренном движении 
====================================================)" << endl;

	cout << "Введите значение скорости: " << endl;
	cin >> speed;//предлагаем пользователю ввести данные о скорости

	cout << "Введите значение времени: " << endl;
	cin >> time;//предлагаем пользователю ввести данные о времени

	cout << "Введите значение ускорения: " << endl;
	cin >> acceleration;//предлагаем пользователю ввести данные об ускорении

	distance = (speed * time) + ((acceleration * pow(time, 2)) / 2); //вычисляем пройденное расстояние
	

	cout << "Пройденное расстояние = " << distance << endl << endl;//выводим на экран значение расстояния

	system("pause");

	return 0;

}