#include "countries.h"






/*Фунцкия отвечает за работоспособность игры "Countries and Capital Cities"*/
void countries()
{
	int capital_counter = str_counter("capital_country.txt");												// считаем количество строк в файле "capital_cnc.txt" и присваиваем переменной capital_counter												// считаем количество строк в файле "country_cnc.txt" и присваиваем переменной country_counter
	int score = 0;																						// счёт игрока
	gaming *cnc = new gaming[capital_counter];																// выделяем память для массива структур типа CNC размерностью capital_counter

	fin(capital_counter, cnc, "capital_country.txt");									// заполняем массив cncs из файлов "capital_cnc.txt" и "country_cnc.txt"

	string answer;																						// переменная для ответа пользователя
	int random = 0;																						// переменная для генерации случайного числа
	srand(time(0));

	/* пока пользователь отвечает правильно, игра продолжается */
	while (score != -1)
	{
		random = rand() % capital_counter;																// присваиваем переменной random случайное число
		cout << "What is the capital of " << cnc[random].question << "?" << endl;					// задаём вопрос пользователю
		cin >> answer;																					// пользователь вводит ответ

		/* если пользователь отвечает правильно, то игра продолжается, и к общему счету добавляется одно очко*/
		if (answer == cnc[random].answer)
		{
			
			printpraise();																				// хвалим игрока поощерительной фразой
			score++;																					// прибавляем к счёту одно очко
			cout << "\tScore: " << score << endl;														// выводим счёт на экран
		}

		/*иначе появляется правильный ответ и количество набранных очков, и игра заканчиватеся*/
		else
		{
			cout << "You lose:(\n";

			
			printsympathy();																			// сочувствуем игроку при неверном ответе
			cout << "\nRight answer is " << cnc[random].answer;									// выводим правильный ответ на поставленный вопрос
			cout << "\nYour score: " << score << endl;													// выводим набранный пользователя за игру счёт на экран
			score = -1;																					// присваиваем значение -1 переменной score, то есть выходим из игры Country and Capital Cities
		}

		cout << endl;																					// пропуск строки

		system("pause");																				// команда для задержки экрана
		system("cls");																					// команда для очистки экрана
	}

	delete[] cnc;																						// освобождаем память выделенную под массив cncs
}

