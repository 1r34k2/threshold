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
		cout << "������ �����. ���������: ";
	}
	return a;
}

void Add()
{
	int number;
	cout << "������� ����� ���������: ";
	number = failure();
	if (trans->Add(number)) cout << "���������� �������!\n";
	else cout << "���������� �� �������!\n";
}
void AddQ()
{
	int number, year;
	string brand;
	cout << "������� ����� ���������, � ������� ������ �������� ����� �������: ";
	number = failure();
	cout << "������� ����� �������:";
	cin >> brand;
	cout << "������� ��� �������:";
	year = failure();
	if (trans->AddQ(number, brand, year)) cout << "���������� �������!\n";
	else cout << "���������� �� �������!\n";
}
void Del()
{
	int number;
	cout << "������� ����� ��������� ��� ��������: ";
	number = failure();
	if (trans->Del(number)) cout << "�������� �������!\n";
	else cout << "�������� �� �������!\n";
}
void DelQ()
{
	int number;
	cout << "������� ����� ���������, � ������� ������ ������� �������:";
	number = failure();
	if (trans->DelQ(number)) cout << "�������� �������!\n";
	else cout << "�������� �� �������!\n";
}
void Find()
{
	int number;
	cout << "������� ����� ��������� ��� ������: ";
	number = failure();
	if (trans->Find(number)) cout << "�������� ������!\n";
	else cout << "�������� �� ������!";
}
void FindQ()
{
	int number;
    string brand;
	cout << "������� ����� ���������, � ������� ������ ������� �������:";
	number = failure();
    cout << "������� ����� �������:";
	cin >> brand;
	if (trans->FindQ(number, brand)) cout << "������� ������!\n";
	else cout << "������� �� ������!\n";

}
void Show()
{
	{
		cout << "\n----------------------------------------------------\n";
		cout << "|    ��������������� '" << trans->GetName() << "'";
		cout << "\n----------------------------------------------------";
		cout << "\n|     �����     |" << "        �����             ���           ";
		cout << "\n|   ���������   |" << "       �������          �������         \n";
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
		cout << "\n �������� ��������:\n";
		cout << " 1. �������� ��������\n";
		cout << " 2. �������� �������\n";
		cout << " 3. ������� ��������\n";
		cout << " 4. ������� �������\n";
		cout << " 5. ����� ��������\n";
		cout << " 6. ����� �������\n";
		cout << " 7. ������������� ���������������\n";
		cout << " 8. ������� ��������������� � ������� ������\n";
		cout << " 9. ��������� ��������������� �� �����\n";
		cout << " 10. ��������� ��������������� � ����\n";
		cout << " 0. �����\n";
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
			cout << "������� �������� ����������������: ";
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
			if (file.InputData(trans)) cout << "�������� �������!";
			else
			{
				cout << "������!";
				delete(trans);
				trans = new Trans();
			}
		}
		else if (n == 10)
		{
			if (trans != NULL)
			{
				if (file.OutputData(trans)) cout << "�������� �������!";
				else cout << "������";
			}
			else cout << "������!";
		}
		else if (n == 0) {
			delete(trans);
			break;
		}
	}
}
