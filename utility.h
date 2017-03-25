#pragma once
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Structures.h"

using namespace std;

/*функция отвечает за поощерение игрока мотивирующими фразами*/
void printpraise();


/*функция отвечает за сочуствие пользователю успокаивающими фразами*/
void printsympathy();

/*функция отвечает за количество HP у пользователя*/
void printlives(int lives);

/*подсчитывает количество строк в файле*/
int str_counter(char* filename);

/*заполняет строковый массив из файла*/
void fin(int count, string arrname[], string filename);

/*заполняет массив структур типа gaming из файла*/
void fin(int count, gaming arrname[], string filename);

/*извещение о неправильном вводе и очищение потока*/
void incorrect_input();

void desire_playing(void game());