#include <conio.h>
#include <Windows.h>
#include "countries.h"
#include "utility.h"
#include "sights.h"
#include "Structures.h"


using namespace std;

/*
Образовательный проект, направленный на изучение отдельных областей географии в игровой форме
*/
void main()
{


	system("color F0");																					// задает белый цвет консоли и черный цвет текста

	
	enum Choice { Neutral = -1, Exit, Capital, Sight };													// 

	Choice key = Neutral;																				// объявляем переменную key присваиваем ей нейтральное значение

	int choice = key;																					// переменная для выбора пользователя

	/*пока пользователь не выберет "Exit" работа программы продолжатся*/
	while (choice != Exit)
	{



		cout << "Hey, in which game do you want to play? (Enter a number)\n1. Countries and Capital Cities\n2. Sights Of The World\n0. Exit" << endl;

		cin >> choice;																					// пользователь вводит своё решение


		/*выбор игры или выход из программы*/
		switch (choice)
		{
		case(Capital): desire_playing(countries); break;																// если пользователь вводит 1, то запускается игра "Countries And Capital Cities"
		case(Sight): desire_playing(sights); break;																	// если пользователь вводит 2, то запускается игра "Sights Of The World"
		case(Exit): break;																				// если пользователь вводит 0, то работа программы заканчивается
		default:{incorrect_input();}																	// если пользователь не вводит ни одно из вышеперечисленных значений, то на жкран выводится сообщение об ошибке
		}
	}
}