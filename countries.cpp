#include "countries.h"






/*������� �������� �� ����������������� ���� "Countries and Capital Cities"*/
void countries()
{
	int capital_counter = str_counter("capital_country.txt");												// ������� ���������� ����� � ����� "capital_cnc.txt" � ����������� ���������� capital_counter												// ������� ���������� ����� � ����� "country_cnc.txt" � ����������� ���������� country_counter
	int score = 0;																						// ���� ������
	gaming *cnc = new gaming[capital_counter];																// �������� ������ ��� ������� �������� ���� CNC ������������ capital_counter

	fin(capital_counter, cnc, "capital_country.txt");									// ��������� ������ cncs �� ������ "capital_cnc.txt" � "country_cnc.txt"

	string answer;																						// ���������� ��� ������ ������������
	int random = 0;																						// ���������� ��� ��������� ���������� �����
	srand(time(0));

	/* ���� ������������ �������� ���������, ���� ������������ */
	while (score != -1)
	{
		random = rand() % capital_counter;																// ����������� ���������� random ��������� �����
		cout << "What is the capital of " << cnc[random].question << "?" << endl;					// ����� ������ ������������
		cin >> answer;																					// ������������ ������ �����

		/* ���� ������������ �������� ���������, �� ���� ������������, � � ������ ����� ����������� ���� ����*/
		if (answer == cnc[random].answer)
		{
			
			printpraise();																				// ������ ������ �������������� ������
			score++;																					// ���������� � ����� ���� ����
			cout << "\tScore: " << score << endl;														// ������� ���� �� �����
		}

		/*����� ���������� ���������� ����� � ���������� ��������� �����, � ���� �������������*/
		else
		{
			cout << "You lose:(\n";

			
			printsympathy();																			// ����������� ������ ��� �������� ������
			cout << "\nRight answer is " << cnc[random].answer;									// ������� ���������� ����� �� ������������ ������
			cout << "\nYour score: " << score << endl;													// ������� ��������� ������������ �� ���� ���� �� �����
			score = -1;																					// ����������� �������� -1 ���������� score, �� ���� ������� �� ���� Country and Capital Cities
		}

		cout << endl;																					// ������� ������

		system("pause");																				// ������� ��� �������� ������
		system("cls");																					// ������� ��� ������� ������
	}

	delete[] cnc;																						// ����������� ������ ���������� ��� ������ cncs
}

