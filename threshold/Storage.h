#define _CRT_SECURE_NO_WARNINGS
#include "Trans.h"
#pragma once
#include <fstream>

using namespace std;

class Storage
{
private:
	string address;
public:
	Storage(string _address) {
		address = _address;
	};

	bool InputData(Trans* _trans) {
		string name, brand;
		int number,year;
		char buffer[100];
		char* f;

		ifstream file(address);

		if (!file.is_open()) return false;
		file.getline(buffer, 100);
		if (buffer != " ")
		{
			name = buffer;
			_trans->SetName(name);
		}
		else {
			cout << "Файл пуст\n";
			return false;
		}
		while (!file.eof()) {
			file.getline(buffer, 100);
			f = strtok(buffer, " ");
			if (f == NULL) continue;
			number = atoi(f);
			_trans->Add(number);
			f = strtok(NULL, " ");
			while (f) {
				brand = f;
				f = strtok(NULL, " ");
				year = atoi(f);
				_trans->AddQ(number,brand,year);
				f = strtok(NULL, " ");
			}
		}
		file.close();
		return true;
	}

	bool OutputData(Trans* _trans) {
		ofstream file(address);
		if (!file.is_open())
			return false;
		file << _trans->GetName() + '\n' + _trans->getString();
		file.close();
		return true;
	};

	~Storage() { };
};




