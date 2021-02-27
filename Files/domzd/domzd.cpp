#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    /*
        ДЗ:
        Посчитать в файле количество 
        1. букв
        2. цифр 
        3. чисел 
        4. Вывести, сколько раз встречается каждый символ
        5. Напечатать 5 самых частых символов
        
    */

	int wordsf = 0;
	string nfile;
	cout << "Enter the file name: \n";
	cin >> nfile;
	ifstream f;
	f.open(nfile, ios::in);

	if(!f.is_open())
		cout << "There is no file in the directory, error\n";
    else
    {
        cout << "File is open" << endl;
        string s;

        while(1)
        {
            getline(f, s, ' ');
            if (f.eof())
                break;
            wordsf++;
        }

        cout << "Words n: " << wordsf;
    }

    return 0;
}