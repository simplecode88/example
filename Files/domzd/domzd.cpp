#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

bool isAlpha(char c) {
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'A') return true;
    return false;
}

struct Count {
    int symbols = 0;
    int letters = 0;
    int digits = 0;
    void check(char c) {
        symbols++;
        if (isAlpha(c)) letters++;
        //if (isDigit()) digits++;
    }
};


int main()
{
    /*
        ДЗ:
        Посчитать в файле количество
        0. посчитать число символов в файле
        1. букв
        2. цифр
        3. чисел
        4. Вывести, сколько раз встречается каждый символ
        5. Напечатать 5 самых частых символов
    */

    ifstream file("test.txt");
    if (!file.is_open()) {
        cout << "There is no file in the directory, error\n";
        return 0;
    }

    Count counter;

    char buf;
    while (!file.eof()) {
        file.read(&buf, 1);
        counter.check(buf);
    }
    
    cout << 
        "Symbols = " << counter.symbols << endl <<
        "Letters = " << counter.letters;
  
    file.close();
    return 0;
}