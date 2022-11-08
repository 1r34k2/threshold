#include "Storage.h"
#include <stdlib.h>
#include <Windows.h>


Trans* trans = NULL;
Storage file("text.txt");

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Повторите: ";
	}
	return a;
}

void Add()
{
	int number;
	cout << "Введите номер трампарка: ";
	number = failure();
	if (trans->Add(number)) cout << "Добавление успешно!\n";
	else cout << "Добавление не успешно!\n";
}
void AddQ()
{
	int number, year;
	string brand;
	cout << "Введите номер трампарка, в который хотите добавить новый трамвай: ";
	number = failure();
	cout << "Введите марку трамвая:";
	cin >> brand;
	cout << "Введите год выпуска:";
	year = failure();
	if (trans->AddQ(number, brand, year)) cout << "Добавление успешно!\n";
	else cout << "Добавление не успешно!\n";
}
void Del()
{
	int number;
	cout << "Введите номер трампарка для удаления: ";
	number = failure();
	if (trans->Del(number)) cout << "Удаление успешно!\n";
	else cout << "Удаление не успешно!\n";
}
void DelQ()
{
	int number;
	cout << "Введите номер трампарка, в котором хотите удалить трамвай:";
	number = failure();
	if (trans->DelQ(number)) cout << "Удаление успешно!\n";
	else cout << "Удаление не успешно!\n";
}
void Find()
{
	int number;
	cout << "Введите номер трампарка для поиска: ";
	number = failure();
	if (trans->Find(number)) cout << "Трампарк найден!\n";
	else cout << "Трампарк не найден!";
}
void FindQ()
{
	int number;
    string brand;
	cout << "Введите номер трампарка, в котором хотите удалить трамвай:";
	number = failure();
    cout << "Введите марку трамвая:";
	cin >> brand;
	if (trans->FindQ(number, brand)) cout << "Трамвай найден!\n";
	else cout << "Трамвай не найден!\n";

}
void Show()
{
	{
		cout << "\n----------------------------------------------------\n";
		cout << "|    Горэлектротранс '" << trans->GetName() << "'";
		cout << "\n----------------------------------------------------";
		cout << "\n|     Номер     |" << "        Марка             Год           ";
		cout << "\n|   трампарка   |" << "       трамвая          выпуска         \n";
		trans->Show();
		cout << "----------------------------------------------------\n";
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	trans = new Trans();
	while (true) {
		Show();
		cout << "\n Выберите действие:\n";
		cout << " 1. Добавить трампарк\n";
		cout << " 2. Добавить трамвай\n";
		cout << " 3. Удалить трампарк\n";
		cout << " 4. Удалить трамвай\n";
		cout << " 5. Найти трампарк\n";
		cout << " 6. Найти трамвай\n";
		cout << " 7. Переименовать горэлектротранс\n";
		cout << " 8. Удалить горэлектротранс и создать пустой\n";
		cout << " 9. Загрузить горэлектротранс из файла\n";
		cout << " 10. Выгрузить горэлектротранс в файл\n";
		cout << " 0. Выход\n";
		n = failure();
		if (n == 1)
			Add();
		else if (n == 2)
			AddQ();
		else if (n == 3)
			Del();
		else if (n == 4)
			DelQ();
		else if (n == 5)
			Find();
		else if (n == 6)
			FindQ();
		else if (n == 7)
		{
			string newName;
			cout << "Введите название горэлектротранса: ";
			cin >> newName;
			trans->SetName(newName);
		}
		else if (n == 8)
		{
			delete(trans);
			trans = new Trans();
		}
		else if (n == 9)
		{
			delete(trans);
			trans = new Trans();
			if (file.InputData(trans)) cout << "Загрузка успешна!";
			else
			{
				cout << "Ошибка!";
				delete(trans);
				trans = new Trans();
			}
		}
		else if (n == 10)
		{
			if (trans != NULL)
			{
				if (file.OutputData(trans)) cout << "Выгрузка успешна!";
				else cout << "Ошибка";
			}
			else cout << "Ошибка!";
		}
		else if (n == 0) {
			delete(trans);
			break;
		}
	}
}
