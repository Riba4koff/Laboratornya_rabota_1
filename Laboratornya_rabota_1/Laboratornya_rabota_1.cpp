#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <Windows.h>

using namespace std;

int human_height_int_;
int human_weight_int_;

int height_ = 10; //высота окна
int weight_ = 40; //ширина окна

enum { NORMAL_WEIGHT, OVERWEIGHT, UNDERWEIGHT };

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

COORD position = { 0, 0 };

bool is_number(char number[]);
int char_to_int(char number[]);

void Frame1(int weight, int height);
void Frame2(int weight, int height);
void mainScreen(int height, int weight);
void operationScreen(int height, int weight);
void endScreen(int height, int weight);
void errorScreen(int human_weight, int human_height, int height_or_weight, int height, int weight);
void answerScreen(int how_much_weight, int human_weight, int human_height, int height, int weight);
void inputData(int* human_height_, int* human_weight_, int weight, int height);
void lifeCycle(int human_height_int, int human_weight_int, int weight, int height);


//////////////////////////////////


int main() {

	setlocale(LC_ALL, "rus");


	lifeCycle(human_height_int_, human_weight_int_, weight_, height_);


	return 0;

}


//////////////////////////////////


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
//Перевод из char в int
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

//Рамка с 1 строкой снизу
void Frame1(int weight, int height) {
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < height - 1; i++) {

		for (int j = 0; j <= weight; j++)
		{
			if (j == 0 || j == weight) cout << "|";
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
			if (j == 0 || j == weight)
				cout << "|";
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

}
//Рамка с 2 строками снизу
void Frame2(int weight, int height) {
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < height - 1; i++) {

		bool i_is_not_a_second_third_fourth = (i == 2 || i == 3 || i == 4) ? 0 : 1;

		for (int j = 0; j <= weight; j++)
		{
			if (j == 0 || j == weight) cout << "|";
			else cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

	cout << "\n";

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || j == weight)
				cout << "|";
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}

}
//Главный экран
void mainScreen(int height, int weight) {

	Frame1(weight, height);

	position = { 15, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Программа";

	position = { 12, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Оптимальный вес";

	position = { 7, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Рыбаков Павел Алексеевич";
	
	position = { 15, 6 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Гр. 1092";


	position = { 8 , 11 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Esc - Выход, Enter - Далее";

	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);
}
//Рабочий экран
void operationScreen(int height, int weight) {

	Frame1(weight, height);

	position = { 17, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Введите";

	position = { 10, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "свой рост: ";

	position = { 11, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "свой вес: ";

	position = { 14, 11 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter - Ввод";
	
	position = { 0, 12 };
	SetConsoleCursorPosition(hConsole, position);

}
//Экран ошибки
void errorScreen(int human_weight, int human_height, int height_or_weight, int height, int weight) {

	system("cls");

	Frame2(weight, height);

	if (height_or_weight == 0) {

		position = { 17, 3 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Введите";

		position = { 10, 4 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "свой рост: ";

		position = { 11, 5 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "свой вес: ";

		position = { 8, 11 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Ошибка, попробуйте снова";

		position = { 5, 12 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Подсказка, рост от 100 до 230 см";

		position = { 21, 4 };
		SetConsoleCursorPosition(hConsole, position);
	} 
	else
		if (height_or_weight == 1) {

			position = { 17, 3 };
			SetConsoleCursorPosition(hConsole, position);
			cout << "Введите";

			position = { 10, 4 };
			SetConsoleCursorPosition(hConsole, position);
			cout << "свой рост: ";

			position = { 11, 5 };
			SetConsoleCursorPosition(hConsole, position);
			cout << "свой вес: ";

			position = { 8, 11 };
			SetConsoleCursorPosition(hConsole, position);
			cout << "Ошибка, попробуйте снова";

			position = { 5, 12 };
			SetConsoleCursorPosition(hConsole, position);
			cout << "Подсказка, вес от 30 до 200 кг";

			position = { 21, 4 };
			SetConsoleCursorPosition(hConsole, position);
			cout << human_height;

			position = { 21, 5 };
			SetConsoleCursorPosition(hConsole, position);
		}

}
//Ввод данных
void inputData(int* human_height_, int* human_weight_, int weight, int height) {

	char human_height[100]; //человеческий рост
	char human_weight[100]; //человеческий вес

	position = { 21, 4 };
	SetConsoleCursorPosition(hConsole, position);

	cin >> human_height;

	if ((char_to_int(human_height) > 230 || char_to_int(human_height) < 100) && char_to_int(human_height) > 0 || !is_number(human_height)) {
		do
		{
			system("cls");
			if ((char_to_int(human_height) > 230 || char_to_int(human_height) < 100) && char_to_int(human_height) > 0) { errorScreen(char_to_int(human_weight), char_to_int(human_height), 0, height, weight); }
			else if (!is_number(human_height)) { errorScreen(char_to_int(human_weight), char_to_int(human_height), 0 ,height, weight); }

			cin >> human_height;

		} while ((char_to_int(human_height) > 230 || char_to_int(human_height) < 100) && char_to_int(human_height) > 0 || !is_number(human_height));
	}

	*human_height_ = char_to_int(human_height);

	position = { 21, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cin >> human_weight;

	if ((char_to_int(human_weight) < 30 || (char_to_int(human_weight)) > 200 || (!is_number(human_weight)))) {
		do
		{
			system("cls");

			position = { 21, 4 };
			SetConsoleCursorPosition(hConsole, position);
			cout << human_height;

			if (char_to_int(human_weight) < 30 || char_to_int(human_weight) > 200) { errorScreen(char_to_int(human_weight), char_to_int(human_height), 1, height, weight); }
			else if (!is_number(human_weight)) { errorScreen(char_to_int(human_weight), char_to_int(human_height), 1, height, weight); }

			position = { 21, 5 };
			SetConsoleCursorPosition(hConsole, position);
			cin >> human_weight;

		} while (char_to_int(human_weight) < 30 || char_to_int(human_weight) > 200 || !is_number(human_weight));
	}

	*human_weight_ = char_to_int(human_weight);

	position = { 0, 15 };
	SetConsoleCursorPosition(hConsole, position);

}
//Жизненный цикл
void lifeCycle(int human_height_int, int human_weight_int, int weight, int height) {
	bool life_circle = true;
	char chose;

	mainScreen(height, weight);

	do {
		//ASCII "Esc" = 27, ASCII "Enter" = 13;

		life_circle = ((chose = _getch()) == 27) ? 0 : 1;

		if (chose == 27) {
			life_circle = false;
			system("cls");
		}
		else if (chose == 13) {
			system("cls");
			operationScreen(height, weight);
			inputData(&human_height_int, &human_weight_int, weight, height);

			int max_average_weight = human_height_int - 100 + 15;
			int min_average_weight = human_height_int - 100 - 15;


			if (min_average_weight <= human_weight_int && human_weight_int <= max_average_weight) {
				answerScreen(NORMAL_WEIGHT, human_weight_int, human_height_int, height, weight);
			}
			else if (human_weight_int > max_average_weight) {
				answerScreen(OVERWEIGHT, human_weight_int, human_height_int, height, weight);
			}
			else
				if (human_weight_int < min_average_weight) {
					answerScreen(UNDERWEIGHT, human_weight_int, human_height_int, height, weight);
				}

			cout << "\n\n";
		}
		else {
			system("cls");
			mainScreen(height, weight);
		}

	} while (life_circle);

	endScreen(height, weight);

	cout << "\n\n\n";
}
//Завершающий экран
void endScreen(int height, int weight) {

	Frame1(weight, height);

	position = { 16,3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Программа";

	position = { 13,4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Оптимальный вес";

	position = { 10,5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Завершила свою работу";

	position = { 13,11 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "До новых встреч";


	position = { 0, 13 };
	SetConsoleCursorPosition(hConsole, position);

}
//Экран ответа
void answerScreen(int how_much_weight, int human_weight, int human_height, int height, int weight) {

	system("cls");

	Frame2(weight, height);

	position = { 17, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Введите";

	position = { 10, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "свой рост: ";

	position = { 11, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "свой вес: ";


	switch (how_much_weight) {
	case 0:
		position = {13, 11};
		SetConsoleCursorPosition(hConsole, position);
		cout << "Ваш вес в норме";

		position = { 8, 12 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Esc - Выход, Enter - Далее";

		break;
	case 1:
		position = { 11, 11 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Ваш вес выше нормы";

		position = { 8, 12 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Esc - Выход, Enter - Далее";
		break;
	case 2:
		position = { 11, 11 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Ваш вес ниже нормы";

		position = { 8, 12 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Esc - Выход, Enter - Далее";
		break;
	}

	position = { 21, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << human_height;

	position = { 21, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << human_weight;

	position = { 0, 12 };
	SetConsoleCursorPosition(hConsole, position);


}

///////////////////////////////////////////