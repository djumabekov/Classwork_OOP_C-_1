//
// Drob.cpp
//

Drob::Drob() : a(), b(1) {}

Drob::Drob(int a, int b) : a(a), b(b) {}

Drob::Drob(const Drob& obj) {
    a = obj.a;  // this->a = obj.a;
    b = obj.b;  // this->b = obj.b;
    //*this = obj; - вызов оператора копирования
}

Drob& Drob::operator=(const Drob& obj)
{
    if (this == &obj) { return*this; }
    a = obj.a;  // this->a = obj.a;
    b = obj.b;  // this->b = obj.b;
    return *this;
    /*
    if (this != &obj) {
      a = obj.a;  // this->a = obj.a;
      b = obj.b;  // this->b = obj.b;
    }
    return *this;
    */
}

// C = A + B; *this + B ==> result ==> C
Drob Drob::operator+(const Drob& B) const {
    Drob result; // локальная переменная метода operator+()
    result.a = this->a * B.b + this->b * B.a; // числитель результата
    result.b = this->b * B.b; // знаменатель результата - общий знаменатель
    return result; // возвращаем результат по значению - копию result
}

// A += B; *this += B
Drob& Drob::operator+=(const Drob& B) {
    this->a = this->a * B.b + this->b * B.a;
    this->b = this->b * B.b;
    return *this;
}

// C = A + 10; *this + 10 ==> result ==> C
Drob Drob::operator+(int val) const {
    //Drob temp(val); // va/1
    Drob temp;
    temp.a = val;
    temp.b = 1;
    return *this + temp;
}

// глобальный оператор + для сложения int и Drob
// C = 10 + A;
// int + Drob;
Drob operator+(int val, const Drob& A) {
    return A + val;
    //Drob temp(val);
    Drob temp;
    temp.a = val;
    temp.b = 1;
    return A + temp;
}

void Drob::Show() const {
    cout << a << "/" << b << endl;
}


// реализация дружественной ф-ции для вывода в поток
ostream& operator<<(ostream& os, const Drob& obj) {
    return os << obj.getA() << "/" << obj.getB();
}


inline int Drob::getA() const { return a; }
inline int Drob::getB() const { return b; }


// Source.cpp
#include <iostream>
#include <time.h>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

int main()
{
    Drob A(1, 2);
    Drob B;
    B = A + 10;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
}

//
// Drob.h
//
#pragma once

#include <iostream>
using namespace std;

// интерфейс класса Drob
class Drob
{
private:
    int a, b; // числ, знамен
public:
    Drob();
    //Drob(int chisl);
    //Drob(int, int = 1);
    Drob(int chisl, int znam = 1);
    Drob(const Drob& obj);
    Drob& operator=(const Drob& obj);

    // C = A + B; *this + B ==> result ==> C
    Drob operator+(const Drob& B) const;
    // A += B; *this += B
    Drob& operator+=(const Drob& B);
    // C = A + 10; *this + 10 ==> result ==> C
    Drob operator+(int val) const;
    friend Drob operator+(int val, const Drob& A);

    void Show() const;
    //virtual void Show() const override;
    //void Drob::Show() const {}

    // объявление дружественной ф-ции для вывода в поток
    friend ostream& operator<<(ostream& os, const Drob& obj);

    inline int getA()const; // { return a; }
    inline int getB()const; // { return b; }

}; // class Drob;

#include <iostream>
#include <time.h>
//using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { std::cin.get(); std::cin.get(); } }_;

/*
 Пространства имен
*/

namespace MyLib { // именнованная область MyLib
    int size = 10;   // MyLib::size - полное имя переменной size
    //long size = 10;
    void Show() {
        std::cout << "size = " << size << std::endl;
    }
    namespace MyLib2 {
        long size = 50; //MyLib::MyLib2::size - полное имя переменной size из Lib2
    }
}

namespace OtherLib {
    int size = 20;
    void Show(int a = 1) {
        std::cout << "SIZE = " << size << std::endl;
    }
}

namespace MyLib { // продолжение именнованой области MyLib
    std::string cout = "This my cout!";
    int cin = 123;
    char string[] = "Hello World!";
    //float long = 123.2;
}

// прототипы для ф-ций и переменных из именнованных областей
//  чаще делается в header-файле
void MyLib::Show();
void OtherLib::Show(int);
extern int MyLib::size;
extern long MyLib::MyLib2::size;

// глобальная переменная безымянной области
int size = 100;


int main()
{
    MyLib::Show(); // вызов ф-ции Show() из именнованной области MyLib
    MyLib::size = 444;
    std::cout << "MyLib::size = " << MyLib::size << "\n";
    std::cout << MyLib::cout << std::endl;
    OtherLib::Show();

    { // начало проекции OtherLib
        using namespace OtherLib;
        Show(); // OtherLib::Show();

        std::cout << OtherLib::size << std::endl;
        std::cout << MyLib::size << std::endl;
        std::cout << ::size << std::endl; // :: - доступ к именам из глобальной безымянной области

    } // конец проекции OtherLib

    //Show(); // OtherLib::Show();

}


