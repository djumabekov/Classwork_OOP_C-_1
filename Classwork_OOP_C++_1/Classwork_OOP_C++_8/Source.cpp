#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Перегрузка операторов

CatDog = Cat + Dog

*/

class Dog;
class CatDog;

class Cat
{
private:
    string Name;
    string Breed;
    int CountLive;
public:
    Cat() :Name("Unknown"), Breed("Dvornyaga"), CountLive(9) {}
    Cat(string Name, string Breed, int CountLive)
        : Name(Name), Breed(Breed), CountLive(CountLive) {}

    string GetName()const { return Name; }
    string GetBreed()const { return Breed; }
    int GetCountLive()const { return CountLive; }

    friend istream& operator>> (istream& is, Cat& obj)
    {
        cout << "Enter name : ";
        //is >> obj.Name;
        getline(is, obj.Name);
        cout << "Enter breed : ";
        //is >> obj.Breed;
        getline(is, obj.Breed);
        cout << "Enter count live : ";
        is >> obj.CountLive;
        is.ignore();
        return is;
    }

    friend ostream& operator<< (ostream& os, const Cat& obj)
    {
        os << "Name : " << obj.Name << endl;
        os << "Breed : " << obj.Breed << endl;
        os << "Count live : " << obj.CountLive << endl;
        return os;
    }

    CatDog operator+ (const Dog& objd)const; // cat + dog
    friend CatDog operator+(const Dog& dog, const Cat& cat);
}; // class Cat;

class Dog
{
private:
    string Name;
    string Breed;
    int Victims;
    // дружественный метод класса Cat
    friend CatDog Cat::operator+ (const Dog& objd)const; // cat + dog
public:
    Dog() : Name("Unknown"), Breed("Tobet"), Victims(0) {}
    Dog(string Name, string Breed, int Victims)
        : Name(Name), Breed(Breed), Victims(Victims) {}

    string GetName()const { return Name; }
    string GetBreed()const { return Breed; }
    int GetVictims()const { return Victims; }

    friend istream& operator>> (istream& is, Dog& obj)
    {
        cout << "Enter name : ";
        //is >> obj.Name;
        getline(is, obj.Name);
        cout << "Enter breed : ";
        //is >> obj.Breed;
        getline(is, obj.Breed);
        cout << "Enter victims : ";
        is >> obj.Victims;
        is.ignore();
        return is;
    }

    friend ostream& operator<< (ostream& os, const Dog& obj)
    {
        os << "Name : " << obj.Name << endl;
        os << "Breed : " << obj.Breed << endl;
        os << "Count victims : " << obj.Victims << endl;
        return os;
    }
    friend CatDog operator+(const Dog& dog, const Cat& cat);
}; // class Dog

class CatDog
{
private:
    string Name;
    string Breed;
    int CountLive;
    int Victims;
    friend CatDog operator+(const Dog& dog, const Cat& cat);
public:
    CatDog() : Name("Unknown"),
        Breed("Unknown"), CountLive(9), Victims() {}
    CatDog(string Name, string Breed, int CountLive, int Victims)
        : Name(Name), Breed(Breed), CountLive(CountLive),
        Victims(Victims) {}

    void SetName(string Name) { this->Name = Name; }
    void SetBreed(string Breed) { this->Breed = Breed; }
    void SetCountLive(int CountLive) { this->CountLive = CountLive; }
    void SetVictims(int Victims) { this->Victims = Victims; }

    friend istream& operator>> (istream& is, CatDog& obj)
    {
        cout << "Enter name : ";
        //is >> obj.Name;
        getline(is, obj.Name);
        cout << "Enter breed : ";
        //is >> obj.Breed;
        getline(is, obj.Breed);
        cout << "Enter count live : ";
        is >> obj.CountLive;
        cout << "Enter victims : ";
        is >> obj.Victims;
        is.ignore();
        return is;
    }

    friend ostream& operator<< (ostream& os, const CatDog& obj)
    {
        os << "Name : " << obj.Name << endl;
        os << "Breed : " << obj.Breed << endl;
        os << "Count live : " << obj.CountLive << endl;
        os << "Victims : " << obj.Victims;
        return os;
    }
}; // class CatDog;

CatDog Cat::operator+ (const Dog& objd)const
{
    CatDog Result;
    Result.SetName(this->GetName() + "-" + objd.GetName());
    Result.SetBreed(this->GetBreed() + "-" + objd.GetBreed());
    Result.SetCountLive(this->GetCountLive());
    Result.SetVictims(objd.GetVictims());
    return Result;
}

CatDog operator+(const Dog& dog, const Cat& cat)
{
    //return dog + cat; // operator+(Dog, Cat) - ошибка - рекурсивный вызов этого оператора
    //return cat + dog; // простой вариант реализации
                        // ==> cat.operator+( dog );
    CatDog Result;
    Result.Name = dog.Name + "-" + cat.Name;
    Result.Breed = dog.Breed + "-" + cat.Breed;
    Result.CountLive = cat.CountLive;
    Result.Victims = dog.Victims;
    return Result;
}

int main()
{
    Cat cat;
    Dog dog;

    cout << "Enter cat : \n";
    cin >> cat;
    cout << "Enter dog : \n";
    cin >> dog;
    cout << endl;

    cout << cat << endl
        << dog << endl;


    CatDog cd;
    //cout << "Enter CatDog : \n";
    //cin >> cd;
    //cout << cd << endl;


    cd = cat + dog;  	// cd.operator = ( cat.operator + ( dog ) );
    cout << cd << endl << endl;

    cd = dog + cat; 	// dog.operator+( cat ) ==> CatDog
                      // operator+( Dog, Cat ) ==> CatDog
    cout << cd << endl;
}


#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
//#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Перегрузка операторов
*/

/*
Создайте класс Circle (окружность):
- Реализуйте через перегруженные операторы;
- Проверка на равенство радиусов двух окружностей
(операция ==);
- Сравнения длин двух окружностей (операция >).
Пропорциональное изменение размеров окружности,
путем изменения ее радиуса (операция += и -=)
*/

int main()
{
    Circle A, B;
    cin >> A >> B;
    cout << "A : " << A << endl;
    cout << "B : " << B << endl;
    if (A == B) { cout << "A = B" << endl; }
    else if (A > B) { cout << "A > B" << endl; }
    else { cout << "A != B" << endl; }
    A += 10;
    cout << "A = " << A << endl;
}


#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
/*
Создайте класс Circle (окружность):
- Реализуйте через перегруженные операторы;
- Проверка на равенство радиусов двух окружностей
(операция ==);
- Сравнения длин двух окружностей (операция >).
Пропорциональное изменение размеров окружности,
путем изменения ее радиуса (операция += и -=)
*/
class Circle
{
private:
    double r;
public:
    Circle() :r() {}
    Circle(double R) :r(R) {}
    void SetR(double R) {
        if (R < 0) {
            cout << "Error cant create circle!" << endl;
            throw "Exception! cant create circle!";
        }
        this->r = R;
    }
    double GetR() const { return r; }
    double GetS() const { return M_PI * (r * r); }
    double GetLength() const { return 2 * M_PI * r; }
    friend istream& operator>>(istream& is, Circle& obj)
    {
        cout << "Enter R : ";
        double tmp;
        is >> tmp;
        obj.SetR(tmp);
        is.ignore();
        return is;
    }
    friend ostream& operator<<(ostream& os, const Circle& obj)
    {
        os << "R : " << obj.GetR() << endl;
        os << "S : " << obj.GetS() << endl;
        os << "L : " << obj.GetLength() << endl;
        return os;
    }
    bool operator == (const Circle& obj) const
    {
        // if (this->GetR() == obj.GetR()) { return true; }
        // else { return false; }
        return this->GetR() == obj.GetR();
    }
    //-Сравнения длин двух окружностей(операция > ).
    //  Пропорциональное изменение размеров окружности,
    //  путем изменения ее радиуса(операция += и -= )
    bool operator > (const Circle& obj) const
    {
        return this->GetLength() > obj.GetLength();
    }
    Circle& operator += (double addR)
    {   //this->r += addR;
        this->SetR(this->GetR() + addR);
        return *this;
    }
    Circle& operator -= (double minusR)
    {
        this->SetR(this->GetR() - minusR);
        return *this;
    }
};


