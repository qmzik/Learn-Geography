#pragma once
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Structures.h"

using namespace std;

/*������� �������� �� ���������� ������ ������������� �������*/
void printpraise();


/*������� �������� �� ��������� ������������ �������������� �������*/
void printsympathy();

/*������� �������� �� ���������� HP � ������������*/
void printlives(int lives);

/*������������ ���������� ����� � �����*/
int str_counter(char* filename);

/*��������� ��������� ������ �� �����*/
void fin(int count, string arrname[], string filename);

/*��������� ������ �������� ���� gaming �� �����*/
void fin(int count, gaming arrname[], string filename);

/*��������� � ������������ ����� � �������� ������*/
void incorrect_input();

void desire_playing(void game());