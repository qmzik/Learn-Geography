#include "utility.h"


/*заполняет строковый массив из файла*/
void fin(int count, string arrname[], string filename)
{
	char BUF[51];																						// задаем буфер для строк из файла
	ifstream fout(filename);																			// открываем файл

	/*заполнет массив размерностью count*/
	for (int i = 0; i < count; i++)	
	{
		fout.getline(BUF, 50);																			// считываем i-ую из файла в буфер 
		arrname[i] = BUF;																				// присваиваем i-ой ячейке массива значение буфера 
	}
	fout.close();																						// закрываем файл
}


/*заполняет массив структур типа gaming из файла*/
void fin(int count, gaming arrname[], string filename)
{																		// задаём буфер для строк из файла
	ifstream fout(filename);																	// открываем первый файл																	// открываем второй файл

	/*заполнет поле captal_cnc структурного массива размерностью count*/
	for (int counter = 0; counter < count; counter++)
	{
		int i = 0, j = 0;
		char BUF[51] = "\0", BUF_question[51] = "\0", BUF_answer[51] = "\0";
		fout.getline(BUF, 50);																	// считываем i-ую строку из файла в буфер 
		while (BUF[j] != '\t')// присваиваем полю capital_cnc i-ой ячейке массива значение буфера 
		{
			BUF_answer[j] = BUF[j];
				j++;
		}
		j++;
		while (BUF[j])
		{
			BUF_question[i] = BUF[j];
			j++; i++;
		}

		arrname[counter].question = BUF_question;
		arrname[counter].answer = BUF_answer;
	
	}

	fout.close();																				// закрываем файл																				// закрываем второй файл
}


/*функция поощеряет пользователя мотивирующими фразами*/
void printpraise()
{
	int count = str_counter("praise.txt");																// подсчитываем количество строк в файле "praise.txt" и присваиваем переменной count
	int random = 0;																						// переменная для генерации случайного числа
	
	srand(time(0));
	string *praise = new string[count];																	// выделяем память для строкового массива praise
	
	fin(count, praise, "praise.txt");																	// заполняем массив praise[count] фразами из файла "praise.txt"
	
	random = rand() % count;																			// присваиваем переменной random случайное число
	cout << praise[random];																				// выводим случайную фразу
	delete[] praise;																					// освобождаем память выделенную под массив sympathy
}


/*функция выводит на экран успокаювающие фразы*/
void printsympathy()
{
	int count = str_counter("sympathy.txt");															// подсчитываем количество строк в файле "sympath.txt" и присваиваем переменной count
	int random = 0;																						// переменная для генерации случайного числа
	
	srand(time(0));
	string *sympathy = new string[count];																// выделяем память для строкового массива sympathy
	
	fin(count, sympathy, "sympathy.txt");																// заполняем массив sympathy[count] фразами из файла "sympathy.txt"
	
	random = rand() % count;																			// присваиваем переменной random случайное число
	cout << sympathy[random];																			// выводим случайную фразу
	delete[] sympathy;																					// освобождаем память выделенную под массив sympathy
}


/*выводит количество HP у пользователя*/
void printlives(int lives)
{
	/*в зависимости от HP у пользователя на экран выводится такое же количество сердец*/
	switch(lives)
		{
			case 3: cout << "Your HP: <3 <3 <3"; break;
			case 2: cout << "Your HP: <3 <3"; break;
			case 1: cout << "Your HP: <3"; break;
			default: cout << ""; 
		}
	
}


/*подсчитывает количество строк в файле*/
int str_counter(char* filename)
{
	int counter = 0;																					// переменная для подсчета количество строк
	char buf[50];																						// задаем буфер для строк из файла 
	char *end = "";																						// переменная для определения конца файла
	ifstream fout(filename);																			// открываем файл для чтения

	/*считаем количество строк пока не дойдем до конца файла*/
	while (strcmp(buf, end) != 0)
	{
		fout.getline(buf, 50);
		counter++;
	}
	counter += -1;																						// вычитаем лишнюю строку
	return counter;																						// возвращаем значение переменной counter(количество строк в файле)
	fout.close();																						// закрываем файл
}


/*извещение о неправильном вводе и очищение потока*/
void incorrect_input()
{
		cin.clear();																					//очищаем поток cin
		cin.ignore(cin.rdbuf()->in_avail());															//игнорируем символы содержащиеся в буфере чтения
		system("cls");																					//команда для очиски экрана
		cout << "Input was incorrect, try again" << endl; 
		system("pause");																				//команда для задержки экрана
		system("cls");																					//команда для очиски экрана
}


/*желание игрока сыграть в игру ещё раз*/
void desire_playing(void game())
{
	char playing;																						// решение пользователя продолжить игру или нет

	system("cls");																						// команда для очистки экрана

	/*пока пользователь не дает отказ от продолжения игры, то игра продолжается*/
	do
	{


		game();																							// вызываем функцию, которая отвечает за работоспособность игры "Counties and Capital Cities"

		cout << "Do you want to play again? (y or n)" << endl;
		cin >> playing;																					// пользователь вводит своё решение


																										/*проверяем корректность ввода*/
		switch (playing)
		{
		case 'n': break;																				// если пользователь ввёл 'n', то ввод корректен и программа продолжает работу
		case 'y': break;																				// если пользователь ввёл 'y', то ввод корректен и программа продолжает работу
		default: {incorrect_input(); }																	// извещает пользователя о некоректном вводе
		}


		system("cls");																					// команда для очистки экрана
	}

	while (playing == 'y');

}
















