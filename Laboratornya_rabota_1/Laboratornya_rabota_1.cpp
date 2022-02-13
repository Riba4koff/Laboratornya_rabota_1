﻿#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <Windows.h>

using namespace std;

int human_height_int;
int human_weight_int;

bool is_number(char number[]);
int char_to_int(char number[]);

void mainScreen();
void operationScreen();
void inputData();
void lifeCircle();



int main(){
	setlocale(LC_ALL, "rus");

	lifeCircle();
	
	return 0;
}

//Проверка на валидность
bool is_number(char number[]) {
	for (int i = 0; i < 100; i++) {
		if ((char)number[i] != -52 && number[i] != '\0') {
			if (!((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]))
				return false;
		}
		else
			return true;
	}
}
//Перевод из char в int массива
int char_to_int(char number[]) {
	int number_of_digits = 0;

	for (int i = 0; number[i] != '\0'; i++) {
		if ((char)number[i] != -52) {
			number_of_digits++;
		}
	}

	if (number_of_digits == 1) {
		return ((char)(number[0] - 48));
	}
	if (number_of_digits == 2) {
		return ((char)(number[0] - 48) * 10 + (char)(number[1] - 48));
	}
	if (number_of_digits == 3) {
		return (((char)(number[0] - 48) * 100) + (((char)(number[1])) - 48) * 10 + (char)(number[2]) - 48);
	}
}

////////////////////////////////////////////

//Главный экран
void mainScreen() {
	int height = 10;
	int weight = 40;

	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < height - 1; i++) {
		bool i_is_not_a_second_third_fourth_and_fifth = (i == 2 || i == 3 || i == 4 || i == 5) ? 0 : 1;
		for (int j = 0; j <= weight; j++) {
			if ((j == 0 || j == weight) && i_is_not_a_second_third_fourth_and_fifth) {
				cout << "|";
			}
			else if (i == 2) {
				if (j == 0) cout << "|";
				else if (j == 15) cout << "Программа";
				else if (j == weight - 8) cout << "|";
				else cout << " ";
			}
			else if (i == 3) {
				if (j == 0) cout << "|";
				else if (j == 12) cout << "Оптимальный вес";
				else if (j == weight - 14) cout << "|";
				else cout << " ";
			}
			else if (i == 4) {
				if (j == 0) cout << "|";
				else if (j == 15) cout << "Гр. 1092";
				else if (j == weight - 7) cout << "|";
				else cout << " ";
			}
			else if (i == 5) {
				if (j == 0) cout << "|";
				else if (j == 8) cout << "Рыбаков Павел Алексеевич";
				else if (j == weight - 23) cout << "|";
				else cout << " ";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}


	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || j == weight - 25)
				cout << "|";
			else if (j == 7) {
				cout << "Esc - Выход, Enter - Далее";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}
	cout << "\n";
}
//Рабочий экран
void operationScreen() {

	int height = 10; //высота окна
	int weight = 40; //ширина окна

	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < height - 1; i++) {

		bool i_is_not_a_second_third_fourth = (i == 2 || i == 3 || i == 4) ? 0 : 1;

		for (int j = 0; j <= weight; j++)
		{
			if ((j == 0 || j == weight) && i_is_not_a_second_third_fourth) {
				cout << "|";
			}
			else if (i == 2) {
				if (j == 0) cout << "|";
				else if (j == 17) cout << "Введите";
				else if (j == weight - 6) cout << "|";
				else cout << " ";
			}
			else if (i == 3) {
				if (j == 0) cout << "|";
				else if (j == 10) {
					cout << "свой рост: ";
				}
				else if (j == weight - 10) cout << "|";
				else cout << " ";
			}
			else if (i == 4) {
				if (j == 0) cout << "|";
				else if (j == 11) {
					cout << "свой вес: ";
				}
				else if (j == weight - 9) cout << "|";
				else cout << " ";
			}
			else cout << " ";
		}
		cout << "\n";
	}


	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || j == weight - 13)
				cout << "|";
			else if (j == 14) {
				cout << "Введите данные";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}
}
//Ввод данных
void inputData(int &height, int &weight) {

	char human_height[10]; //человеческий рост
	char human_weight[10]; //человеческий вес

	bool error_has_been_used = false;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD position = { 21, 4 };
	SetConsoleCursorPosition(hConsole, position);

	cin >> human_height;

	if ((char_to_int(human_height) > 230 || char_to_int(human_height) < 100) && char_to_int(human_height) > 0 || !is_number(human_height)) {
		do
		{
			system("cls");
			operationScreen();
			if ((char_to_int(human_height) > 230 || char_to_int(human_height) < 100) && char_to_int(human_height) > 0) {
				cout << "\n\nОшибка\nПопробуйте еще раз\nПодсказка: диапазон роста от 100 до 230 см";
				error_has_been_used = true;
			}
			else if (!is_number(human_height)) { 
				cout << "\n\nОшибка\nПопробуйте еще раз\nПодсказка: диапазон роста от 100 до 230 см"; 
				error_has_been_used = true;
			}
			SetConsoleCursorPosition(hConsole, position);
			cin >> human_height;
		} while ((char_to_int(human_height) > 230 || char_to_int(human_height) < 100) && char_to_int(human_height) > 0 || !is_number(human_height));
	}

	if (error_has_been_used) {
		system("cls");
	operationScreen();

	position = { 21, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << char_to_int(human_height);
	}

	human_height_int = char_to_int(human_height);

	position = { 21, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cin >> human_weight;

	if ((char_to_int(human_weight) < 30 && char_to_int(human_weight)) > 200 || !is_number(human_weight)) {
		do
		{
			system("cls");
			operationScreen();

			position = { 21, 4 };
			SetConsoleCursorPosition(hConsole, position);
			cout << human_height;

			position = { 21, 5 };
			SetConsoleCursorPosition(hConsole, position);

			if (char_to_int(human_weight) < 30 || char_to_int(human_weight) > 200) {
				position = { 0, 12 };
				SetConsoleCursorPosition(hConsole, position);
				cout << "\n\nОшибка\nПопробуйте еще раз\nПодсказка: диапазон веса от 30 до 200 кг";
			}
			else if (!is_number(human_weight)) {
				position = { 0, 12 };
				SetConsoleCursorPosition(hConsole, position);
				cout << "\n\nОшибка\nПопробуйте еще раз\nПодсказка: диапазон веса от 30 до 200 кг";
			}
			position = { 21, 5 };
			SetConsoleCursorPosition(hConsole, position);
			cin >> human_weight;

		} while (char_to_int(human_weight) < 30 || char_to_int(human_weight) > 200 || !is_number(human_weight));
	}

	human_weight_int = char_to_int(human_weight);

	position = { 0, 15 };
	SetConsoleCursorPosition(hConsole, position);

}
//Жизненный цикл
void lifeCircle() {
	bool life_circle = true;
	char chose;

	mainScreen();

	do {
		//ASCII "Esc" = 27, ASCII "Enter" = 13;

		life_circle = ((chose = _getch()) == 27) ? 0 : 1;

		if (chose == 27) {
			life_circle = false;
			system("cls");
		}
		else if (chose == 13) {
			system("cls");
			operationScreen();
			inputData(human_height_int, human_weight_int);

			int max_average_weight = human_height_int - 100 + 15;
			int min_average_weight = human_height_int - 100 - 15;


			if (min_average_weight <= human_weight_int && human_weight_int <= max_average_weight ) {
				cout << "Ваш средний вес удовлетворяет норме";
			}
				else if (human_weight_int > max_average_weight) {
				cout << "Ваш вес выше нормы";
			}
			else
				if (human_weight_int < min_average_weight) {
					cout << "Ваш вес меньше нормы";
				}

			cout << "\n\nНажмите Enter, чтобы продолжить\nНажмите Esc, чтобы выйти\n\n";
		}
		else {
			system("cls");
			mainScreen();
		}

	} while (life_circle);
}

///////////////////////////////////////////
