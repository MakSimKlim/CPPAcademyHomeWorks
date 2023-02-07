﻿// ДЗ #4 Климов (скорость бегуна).cpp 
//Написать программу, вычисляющую, с какой скоростью
//бегун пробежал дистанцию.Рекомендуемый вид экрана во
//время выполнения программы приведен ниже : см. учебник

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    float distance = 0, speed = 0, time = 0; // назначаем вещественные переменные
    // одинароной тоности и идентифицируем их
    int timeSec = 0, timeMin = 0; // назначаем целочисленные переменные и идентефицируем их
    
    cout << "Программа вычмсляющая скорость бегуна" << endl;
    cout << "============================================================" << endl;
    cout << "Ведите длину дистанции в метрах: ";
    cin >> distance;
   
    cout << "Ведите время забега в минутах с точностью до сотых: ";
    cin >> time; 
        
    timeMin = time;//расчет кол-ва минут (целое число)
    
    timeSec = (time - timeMin) * 60;//расчет кол-ва секунд (целое число, 
    //перевод в секунды из сотых значений минут)

    speed = (distance/1000)/(time/60);//вычисление скорости в км/час
    //перевод метров в километры, а минуты в часы
    
    //исключаем ошибку ввода пользователя отрицательных значений
    if (distance >= 0 && time>=0) //при выполнении условия ввода положительных значений происходит расчет
    {
        cout << "Дистанция: " << distance << " м" << endl;
        cout << "Время: " << timeMin << " мин " << timeSec << " сек " << endl;
        cout << "Скорость при беге: " << speed << " км/час" << endl;
    }
    else
    {
        //в противном случае расчет не выполняется
        cout << "Значение должно быть положительным. Перезапустите программу" << endl << endl;
    }

    system("pause");

    return 0;

}

