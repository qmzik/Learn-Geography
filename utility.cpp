#include "utility.h"


/*��������� ��������� ������ �� �����*/
void fin(int count, string arrname[], string filename)
{
	char BUF[51];																						// ������ ����� ��� ����� �� �����
	ifstream fout(filename);																			// ��������� ����

	/*�������� ������ ������������ count*/
	for (int i = 0; i < count; i++)	
	{
		fout.getline(BUF, 50);																			// ��������� i-�� �� ����� � ����� 
		arrname[i] = BUF;																				// ����������� i-�� ������ ������� �������� ������ 
	}
	fout.close();																						// ��������� ����
}


/*��������� ������ �������� ���� gaming �� �����*/
void fin(int count, gaming arrname[], string filename)
{																		// ����� ����� ��� ����� �� �����
	ifstream fout(filename);																	// ��������� ������ ����																	// ��������� ������ ����

	/*�������� ���� captal_cnc ������������ ������� ������������ count*/
	for (int counter = 0; counter < count; counter++)
	{
		int i = 0, j = 0;
		char BUF[51] = "\0", BUF_question[51] = "\0", BUF_answer[51] = "\0";
		fout.getline(BUF, 50);																	// ��������� i-�� ������ �� ����� � ����� 
		while (BUF[j] != '\t')// ����������� ���� capital_cnc i-�� ������ ������� �������� ������ 
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

	fout.close();																				// ��������� ����																				// ��������� ������ ����
}


/*������� ��������� ������������ ������������� �������*/
void printpraise()
{
	int count = str_counter("praise.txt");																// ������������ ���������� ����� � ����� "praise.txt" � ����������� ���������� count
	int random = 0;																						// ���������� ��� ��������� ���������� �����
	
	srand(time(0));
	string *praise = new string[count];																	// �������� ������ ��� ���������� ������� praise
	
	fin(count, praise, "praise.txt");																	// ��������� ������ praise[count] ������� �� ����� "praise.txt"
	
	random = rand() % count;																			// ����������� ���������� random ��������� �����
	cout << praise[random];																				// ������� ��������� �����
	delete[] praise;																					// ����������� ������ ���������� ��� ������ sympathy
}


/*������� ������� �� ����� ������������� �����*/
void printsympathy()
{
	int count = str_counter("sympathy.txt");															// ������������ ���������� ����� � ����� "sympath.txt" � ����������� ���������� count
	int random = 0;																						// ���������� ��� ��������� ���������� �����
	
	srand(time(0));
	string *sympathy = new string[count];																// �������� ������ ��� ���������� ������� sympathy
	
	fin(count, sympathy, "sympathy.txt");																// ��������� ������ sympathy[count] ������� �� ����� "sympathy.txt"
	
	random = rand() % count;																			// ����������� ���������� random ��������� �����
	cout << sympathy[random];																			// ������� ��������� �����
	delete[] sympathy;																					// ����������� ������ ���������� ��� ������ sympathy
}


/*������� ���������� HP � ������������*/
void printlives(int lives)
{
	/*� ����������� �� HP � ������������ �� ����� ��������� ����� �� ���������� ������*/
	switch(lives)
		{
			case 3: cout << "Your HP: <3 <3 <3"; break;
			case 2: cout << "Your HP: <3 <3"; break;
			case 1: cout << "Your HP: <3"; break;
			default: cout << ""; 
		}
	
}


/*������������ ���������� ����� � �����*/
int str_counter(char* filename)
{
	int counter = 0;																					// ���������� ��� �������� ���������� �����
	char buf[50];																						// ������ ����� ��� ����� �� ����� 
	char *end = "";																						// ���������� ��� ����������� ����� �����
	ifstream fout(filename);																			// ��������� ���� ��� ������

	/*������� ���������� ����� ���� �� ������ �� ����� �����*/
	while (strcmp(buf, end) != 0)
	{
		fout.getline(buf, 50);
		counter++;
	}
	counter += -1;																						// �������� ������ ������
	return counter;																						// ���������� �������� ���������� counter(���������� ����� � �����)
	fout.close();																						// ��������� ����
}


/*��������� � ������������ ����� � �������� ������*/
void incorrect_input()
{
		cin.clear();																					//������� ����� cin
		cin.ignore(cin.rdbuf()->in_avail());															//���������� ������� ������������ � ������ ������
		system("cls");																					//������� ��� ������ ������
		cout << "Input was incorrect, try again" << endl; 
		system("pause");																				//������� ��� �������� ������
		system("cls");																					//������� ��� ������ ������
}


/*������� ������ ������� � ���� ��� ���*/
void desire_playing(void game())
{
	char playing;																						// ������� ������������ ���������� ���� ��� ���

	system("cls");																						// ������� ��� ������� ������

	/*���� ������������ �� ���� ����� �� ����������� ����, �� ���� ������������*/
	do
	{


		game();																							// �������� �������, ������� �������� �� ����������������� ���� "Counties and Capital Cities"

		cout << "Do you want to play again? (y or n)" << endl;
		cin >> playing;																					// ������������ ������ ��� �������


																										/*��������� ������������ �����*/
		switch (playing)
		{
		case 'n': break;																				// ���� ������������ ��� 'n', �� ���� ��������� � ��������� ���������� ������
		case 'y': break;																				// ���� ������������ ��� 'y', �� ���� ��������� � ��������� ���������� ������
		default: {incorrect_input(); }																	// �������� ������������ � ����������� �����
		}


		system("cls");																					// ������� ��� ������� ������
	}

	while (playing == 'y');

}
















