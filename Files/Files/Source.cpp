#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
struct patrons
{
	string name;
	double donation = 0;
};

void print(const std::string& title, const std::vector<patrons*>& patrons) {
	cout << title << "\n";
	for (auto& item : patrons)
	{
		cout << item->name << endl;
	}
	cout << "\n";
}

void load(std::vector<patrons>& items) {
	ifstream file("test.txt");
	
	//todo: add some code

	/*string buf;
	file >> buf;
	while (!file.eof()) {
		cout << buf;
		file >> buf;
	}*/

	//char buf[1024] = { 0 };
	//file.getline(buf, sizeof(buf));
	//while (!file.eof()) {
	//	cout << buf << "\n";
	//	file.getline(buf, sizeof(buf));
	//}

	/*string carName;
	int wheelsCount;
	file >> carName >> wheelsCount;
	while (!file.eof()) {
		cout << "Car name: " << carName << ", wheels=" << wheelsCount << endl;
		file >> carName >> wheelsCount;
	}*/

	char buf[1024] = { 0 };
	file.getline(buf, sizeof(buf));
	while (!file.eof()) {
		istringstream f(buf);
		string test;
		while (std::getline(f, test, ';')) {
			cout << test << " ";
		}
		cout << endl;
		file.getline(buf, sizeof(buf));
	}

	file.close();

	/*
		1. Подсчитать количество слов в файле.
		2. Вывести патронов в разные файлы (grand.txt, common.txt)
		3. Зарегиться на гитхабе
		4. Установить гит клиент
	*/

}

int main()
{
	std::vector<patrons> ps;
	load(ps);
	
	return 0;

	int mec;
	cout << "Enter the number of patrons: ";
	cin >> mec;
	

	size_t testVal = sizeof(patrons);

	
	ps.reserve(mec);
	for (int i = 0; i < mec; i++)
	{
		cout << "Enter " << i + 1 << " patrons" << endl;
		/*	
		string name;
		double donate;

		cout << "Name "; 
		cin >> name;
		cout << "\nDonation: ";
		cin >> donate;
		
		ps.push_back(patrons{ name , donate}); 
		*/

		ps.emplace_back();
		auto& item = ps.back();
		cout << "Name ";
		cin >> item.name;
		cout << "\nDonation: ";
		cin >> item.donation;
	}


	std::vector<patrons*> grandPatrons;
	std::vector<patrons*> commonPatrons;
	for (auto& patron : ps)
	{
		if (patron.donation >= 10000) {
			grandPatrons.push_back(&patron);
		}
		else {
			commonPatrons.push_back(&patron);
		}
	}

	print("GRAND PATRONS!!!", grandPatrons);
	print("PATRONS!!!", commonPatrons);

	return 0;
}