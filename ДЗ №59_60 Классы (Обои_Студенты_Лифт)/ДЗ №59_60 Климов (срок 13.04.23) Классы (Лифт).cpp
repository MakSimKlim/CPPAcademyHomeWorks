﻿// ДЗ №59_60 Климов (срок 13.04.23) Классы (Лифт).
//
// Создать класс «Лифт», представляющий собой предельно упрощенную модель лифта. 
// Класс должен обеспечить:
// ▷ установку диапазона движения лифта(нижний и верхний этаж);
// ▷ включение / выключение лифта;
// ▷ возвращение текущего состояния лифта(работает / не работает);
// ▷ возвращение текущего положения лифта(этаж);
// ▷ обработку вызова лифта(этаж).
// Написать программу, тестирующую класс «Лифт»


#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h>   // нужен для вызова функции time()

using namespace std;

// Класс — один в отличие от объектов класса. Класс — это описание, набор правил, схема.
// Определение класса равносильно определению нового типа данных

// определние класса Лифт или описание объектов, которые могут быть созданы на основе этого класса

class Elevator    // заголовок класса
	              // Elevator - имя класса
{                 // { } - тело класса
public:



	Elevator()    //конструктор по умолчанию (всегда пустой и всегда необходимый)
	{
		numberFloors = upFloor = downFloor = onOffDefault = onOffCurrent = floorStartPosition = floorBoarding = floorUnloading = /*speedLift = */timeWork = 0; //чтобы там не хранился мусор
	}

	Elevator (int upFloor_, int downFloor_, int onOffDefault_, int onOffCurrent_, int floorStartPosition_, int floorBoarding_, int floorUnloading_, /*int speedLift_,*/ int timeWork_)// конструктор
	{
		//вызов переменных из привата через конструктор класса с помощью опереатора this 
		this->upFloor = upFloor_;                         //номер верхнего этажа, на который приходит лифт
		this->downFloor = downFloor_;                     //номер нижнего этажа, на который приходит лифт
		this->onOffDefault = onOffDefault_;               //лифт включен или выключен
		this->onOffCurrent = onOffCurrent_;               //текущее состояние лифта (работает / не работает) т.е. везет уже кого-нибудь или нет
		this->floorStartPosition = floorStartPosition_;   //номер этажа на котором сейчас лифт до его вызова
		this->floorBoarding = floorBoarding_;             //номер этажа на котором сейчас лифт в месте посадки (или с какого этажа вызывается лифт)
		this->floorUnloading = floorUnloading_;           //номер этажа на котором сейчас лифт в месте высадки 
		//this->speedLift = speedLift_;                     //скорость лифта 3м/с, т.е при высоте этажа 3м, скорость = 1 этаж в секунду
		this->timeWork = timeWork_;                       //время работы лифта до приезда к пассажиру
	}

	int getPrivateUpfloor() // метод возывающий приватную переменную upFloor
	{
		return upFloor;
	}
	int getPrivateDownFloor() // метод возывающий приватную переменную downFloor
	{
		return downFloor;
	}

	
	//~Elevator(); // деструктор

	int numberFloors;         //количество этажей, обслуживаемых лифтом (публичная переменная)
	int countFloor = 0;       //переменная определение количества этажей от нахождения лифта до места вызова лифта

	int setPositionPassanger(int value)// метод определения на каком этаже нажата кнопка вызова (значение задается единожды для всех лифтов в main)
	{
		floorBoarding = value;                         // на каком этаже нажата кнопка 
		return value; 
	}

	int getParametresLift()   // метод класса ввода начальных параметров о лифте 
	{
		// Генерирование случайного целочисленного числа в указанных пределах.
		srand(time(NULL));
		cout << "\n";
		cout << "Лифт включен (1) или выключен (0)?:" << "\n";
		cin >> onOffDefault;
		while (onOffDefault < 0 || onOffDefault > 1)
		{
			cout << "Введено некорректное значение, если лифт включен, нажмите (1), если не работает нажмите (0):" << "\n";
			cin >> onOffDefault;
		}
		
		if (onOffDefault == 1)
		{
			cout << "Введите номер верхнего этажа, на который приходит лифт:" << "\n";
			cin >> upFloor;
			cout << "Введите номер нижнего этажа, на который приходит лифт:" << "\n";
			cin >> downFloor;
			numberFloors = upFloor - downFloor + 1; // количество этажей, обслуживаемых лифтом
			cout << "Количество этажей, обслуживаемых лифтом = " << numberFloors << "\n";
			
			onOffCurrent = 0 + rand() % (2 - 0);// рандомное значение для текущего состояния лифта 1- не занят, 0 - занят
			//cout << "Текущее положение лифта"<< onOffCurrent << "\n";//проверка выдаваемого рандомного значения

			if (onOffCurrent==1)// если лифт в настоящее время не перевозит пассажиров, работает и свободен
			{
				// Диапазон чисел: [downFloor, upFloor]
				// Установить генератор случайных чисел

				// Получить случайное число - формула
				int num = downFloor + rand() % (upFloor - downFloor + 1);
				cout << "Лифт находится на " << num << " этаже " << "\n";
				//cout << "На каком этаже нажата кнопка вызова?:" << "\n";
				//cin >> floorBoarding;
				// определение количества этажей от нахождения лифта до места вызова лифта
				int value2 = 0;//вводим переменную
				value2 = this->floorBoarding;//приравниваем ее с помощью указателя this к переменной floorBoarding из main через метод setPositionPassanger
				this->countFloor = fabs(num - value2);//fabs - значение по модулю, this - указатель на поле класса с переменной countFloor, для последующей возможности обращения к этой переменной
				cout << "Количество этажей до пассажира: " << countFloor << "\n";
				//cout << "\n";
			}
			else
			{
				countFloor = -1;//принудительно приравниваем значение до пассажира в отрицательное значение, чтобы исключить занятый лифт из массива лифтов
				cout << "В настоящее время Лифт занят, перевозит пассажиров." << "\n";
				exit;
			}
			
			
		}
		else
		{
			cout << "Лифт сломан, приносим свои извинения." << "\n";
			exit;
		}
		return onOffDefault;
	}

	void setPrivateSpeed(int value) //метод вызова из привата для установки значения скорости лифта
	{
		speedLift = value;
	}
	int getPrivateSpeed() //метод вызова из привата для получения значения скорости лифта
	{
		return speedLift;
	}


private:

	int upFloor;              //номер верхнего этажа, на который приходит лифт
	int downFloor;            //номер нижнего этажа, на который приходит лифт
	int onOffDefault;         //лифт включен или выключен
	int onOffCurrent;         //текущее состояние лифта (работает / не работает) т.е. везет уже кого-нибудь или нет
	int floorStartPosition;   //номер этажа на котором сейчас лифт до его вызова
	int floorBoarding;        //номер этажа на котором сейчас лифт в месте посадки
	int floorUnloading;       //номер этажа на котором сейчас лифт в месте высадки 
	int speedLift;            //скорость лифта 6м/с, т.е при высоте этажа 3м, скорость = 2 этажа в секунду
	int timeWork;             //время работы лифта до приезда к пассажиру

};


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "********************************************"<<"\n";
	cout << "*       Программа 'Лифт' на классах        *"<<"\n";
	cout << "********************************************" << "\n";

	int floorBoarding1 = 0;
	cout << "На каком этаже нажата кнопка вызова?:" << "\n";
	cin >> floorBoarding1;
	cout << "\n";

	int countElevators = 0;//инициализация переменной количества лифтов в доме
	cout << "Введите количество лифтов в доме:" << "\n";
	cin >> countElevators;
	while (countElevators<0)
	{
		cout << "Введено некорректное количество лифтов, попробуйте ещё раз:" << "\n";
		cin >> countElevators;
	}
	
	if (countElevators==0)
	{
		cout << "\nВ доме отсутствуют лифты, для спуска/подъема пройдите к лестнице" << "\n";
		return 0;
		
	}

	// Объектов — может быть много. 
	// Объекты — это переменные, которые хранят конкретные данные. 
	// Каждый объект хранит свои индивидуальные данные

	// определение массива объектов Lift класса Elevator или
	// определение массива переменных Lift, которые представляют конкретный объект,
	// созданный на основе класса Elevator

	Elevator* Lift = new Elevator[countElevators]; // динамический массив объектов Lift класса Elevator 
	for (int i = 0; i < countElevators; i++)
	{
		//system("cls");                             // очистка экрана консоли от предыдущих записей
		Lift[i].setPositionPassanger(floorBoarding1); //задание значения на каком этаже вызывается лифт для всех лифтов
		cout << "\nВведите параметры для лифта №" << i+1 << ": " << "\n";
		Lift[i].getParametresLift();                 //вызов метода getParametresLift класса Elevator для объекта Lift определяющий параметры лифтов и их положение при вызове
	}
	
	// сравниваем какой из свободных лифтов находится ближе к этажу вызова лифта
	int min = -1;          // задаем начальное значение для минимального положительного числа
	int numberElevator = 0;//номер ближайшего к пассажиру лифта

	for (int i = 0; i < countElevators; i++)
	{
		if (Lift[i].countFloor > 0 && (min == -1 || Lift[i].countFloor < min))
		{
			min = Lift[i].countFloor;//выбор минимального значения количества этажей между положением лифта и этажом вызова из всех свободных лифтов , то есть при вызове приедет ближайший к пассажиру лифт
			numberElevator = i;//номер ближайшего свободного лифта
		}
	}
	if (min != -1)//если хотя бы один лифт не занят
	{
		Lift[numberElevator].setPrivateSpeed(2);//задание скорости движения лифта 6м/с, т.е при высоте этажа 3м, скорость = 2 этажа в секунду
		int time = min / Lift[numberElevator].getPrivateSpeed();//вычисление времени в секундах, когда приедет лифт
		cout << "\nЧерез "<< time <<" секунд(у)(ы) к вам приедет ближайший свободный рабочий лифт № : " << numberElevator + 1 << ", находящийся на расстоянии " << min << " этажей " << "\n";
	}
	else
	{
		cout << "\nВсе лифты заняты, попробуйте нажать кнопку вызова ещё раз или пройдите к лестнице для самостоятельного подъема/спуска" << "\n";
	}

	int floorMoving;//переменная выбора этажа на который едет пассажир
	cout << "Выберите этаж, на который поедете" << "\n";
	cin >> floorMoving;
	//проверка правильности выбора этажа высадки (этажи должны быть в диапазоне работы данного лифта)
	while (floorMoving > Lift[numberElevator].getPrivateUpfloor() || floorMoving < Lift[numberElevator].getPrivateDownFloor())
	{
		cout << "\nВыбран некорректный этаж. Данный лифт не приходит на эти этажи. Введите номер этажа ещё раз:"<<"\n";
		cin >> floorMoving;
	}
	cout << "Вы приехали!" << "\n";
	
	
	cout << "\n";

	delete[]Lift;// обязательная очистка памяти при создании динамических массивов

	//вариант обращения к объектам Lift класса Elevator, если массив не динамический
	//Elevator Lift; // определение переменной Lift типа Elevator
	//Lift.getParametresLift();//вызов метода getParametresLift класса Elevator для объекта Lift 

	_getch();// ожидание ввода, чтобы программа (консоль) сразу не закрылась.
	
	return 0;
}
