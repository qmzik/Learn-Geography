#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "sights.h"


using namespace std;



/*работоспособность игры "Sights Of The World"*/
void sights()
{
	system("cls");																						// команда для очистки экрана
	int count_sight = str_counter("country_sight.txt");													// считаем количество строк в файле "sights_sotw.txt" и присваиваем переменной country_counter
	
	gaming *sotw = new gaming[count_sight];																	// выделяем память для массива структур типа SOTW размерностью count_sight

	fin(count_sight, sotw, "country_sight.txt");										// заполняем массив cns из файлов "sights_sotw.txt" и "country_sotw.txt"

	string answer;																						// переменная для ответа пользователя
	int random = 0;																						// переменная для генерации случайного числа
	srand(time(0));
	int hearts = 3;																						// количество HP у игрока
	int score = 0;																						// счёт игрока

	/*пока количество жизней не равно нулю, игра продолжается*/
	while (hearts != 0)
	{
		system("cls");																					// команда для очистки экрана

		random = rand() % (count_sight);																// присваиваем пременной random случайное значение
		cout << "In what country is the " << sotw[random].question << "?\t";

		
		printlives(hearts);																				// выводим количесвто HP у пользователя

		cout << endl;																					// пропуск строки
		cin >> answer;																					// пользователь вводит свой ответ

		/* если пользователь отвечает правильно, то игра продолжается, и к общему счету добавляется одно очко*/
		if (answer == sotw[random].answer)
		{
			
			printpraise();																				// хвалим пользователя поощерительной фразой

			score++;																					// прибавляем 1 к счёту
			cout << "\tScore: " << score << endl;														// выводим значение счёта
			system("pause");																			// команда для задержки экрана
		}

		/*иначе появляется правильный ответ и количество набранных очков, и игра заканчиватеся*/
		else
		{
			hearts = hearts - 1;																		// вычитаем одно HP у пользователя

			cout << "\nRight answer is " << sotw[random].answer << endl;							// выводим правильный ответ на поставленный вопрос
			cout << "Your score: " << score << endl;													// выводит набранный за игру счёт пользователя

			
			printsympathy();																			// сочувствуем пользователю успокаивающей фразой
			cout << endl;																				// пропуск строки

			system("pause");																			// команда для задержки экрана


		}

	}
	system("cls");																						// команда для очистки экрана
	cout << "Game Over!\n" << "Your score: " << score << endl;											// выводим "Game over" и набранный пользователем счёт 
	system("pause");																					// команда для задержки экрана
	system("cls");																						// команда для очистки экрана

	delete[] sotw;																						// освобождаем память выделенную под массив snc
}
