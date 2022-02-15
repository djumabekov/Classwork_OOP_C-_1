#include <iostream>
#include <time.h>
using namespace std;
/*
Задание 1
Реализуйте класс "Точка".
Необходимо хранить координаты x, y, z в переменных - членах класса.
Реализуйте функции - члены класса для ввода данных, вывода данных,
реализуйте аксессоры для доступа к переменным - членам, реализуйте
сохранение в файл и загрузку данных из файла.
*/
// Point - структура
/*struct Point {
  int x, y, z; // переменные структуры
  void Print() { // метод Print() структуры Point
    // (x,y,z)
    cout << "(" << x << "," << y << "," << z << ")\n";
  }
};*/
// Point - класс
// Подходы, принципы ООП
// 1) Абстракция
// 2) Инкапсуляция - в капсуле
// 3) Полиморфизм - различное поведение от внешних данных
// 4) Населедование
//
class Point
{
private:    // спецификатор доступа - закрытая, частная область класса, по умолчанию
    int x, y; // переменные структуры

protected:  // спецификатор доступа для защищенной области
    int z;    // переменные структуры

public:    // спецификатор для публичного доступа
  // методы доступа к переменным класса - асессоры (access)
  // модификаторы, setters, сеттеры
    void SetX(int newX) { x = newX; } // сеттер для переменной x
    void SetY(int newY) { y = newY; }
    void SetZ(int newZ) {
        if (newZ >= 0) { z = newZ; }
        else { cout << "Error: z < 0!\n"; }
    }
    // универсальный сеттер
    void Set(int _X, int _Y, int _Z) {
        //x = _X; y = _Y; z = _Z; // не лучший вариант!
        // правильный подход для сеттера
        SetX(_X);
        SetY(_Y);
        SetZ(_Z);
    }
    // методы инспекторы, getters, геттеры
    int GetX() { return x; } // геттер для переменной x
    int GetY() { return y; } // геттер для переменной y
    int GetZ() { return z; } // геттер для переменной z
    // универсальный геттер
    void Get(int& _X, int& _Y, int& _Z) {
        //_X = x; _Y = y; _Z = z; // не лучший вариант!
        _X = GetX(); // правильный код
        _Y = GetY();
        _Z = GetZ();
    }
    void Input() {
        cout << "Enter x,y,z: ";
        //cin >> x >> y >> z; // прямой безконтрольный, доступ к переменным класс
        int temp;
        cin >> temp; SetX(temp); // x = temp;
        cin >> temp; SetY(temp); // y = temp;
        cin >> temp; SetZ(temp); // z = temp;
    }

    void Print() { // метод Print() структуры Point
      // (x,y,z)
        cout << "(" << GetX() << ","
            << GetY() << ","
            << GetZ() << ")\n";
    }
    // конструкторы класса Point - специальные методы класса
    //  для его первичной иниц-ции
    Point() { // конструктор по умолчанию, конструктор без параметров
        x = y = z = 0; // очистка переменных класса перед его работой
    }
    // конструктор с тремя параметрами
    Point(int _X, int _Y, int _Z) {
        //x = _X; y = _Y; z = _Z; // плохой вариант!
        x = y = z = 0; // очистка переменных класса перед использованием
        Set(_X, _Y, _Z); // иниц-ция переменных через сеттер
    }
}; // class Point;

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    Point A; // A - переменная, экземпляр структуры типа Point
             // при создании переменной A неявно вызывается
             //  конструктор по умолчанию, A.Point();
    //A.Point(); - так нельзя!

    //A.x = 1; // нет прямого доступа к переменным класса Point
    //A.y = 2;
    //A.z = 3;
    A.Input();
    A.Print();

    A.SetX(-10);
    A.SetY(-20);
    A.SetZ(-30); // печать ошибки z < 0
    A.Print();

    Point B(11, 22, -33); // создание обекта, экземпляра B
                         // с помощью конструктора с тремя
                         // параметрами
    B.Print();

    //Point C(); - локальный прототип ф-ции C() возвращающей объект типа Point
    //Point C; // конструктор по умолчанию
    //C.Print();

    cin.get(); cin.get();
}


#include <iostream>
#include <string>
#include <time.h>
using namespace std;
/*
Реализуйте класс для какого-либо домашнего животного.
Наполните класс необходимыми переменными (имя, тип животного,
порода, возраст и т.д.)
и методами: функции-члены класса для ввода данных с консоли,
вывода данных на консоль, реализуйте аксессоры для доступа
к отдельным переменным-членам.
*/
class Cat {
private:
    string Name;
    string Breed;
    bool Sex; // true - female, false - male
    int Age;
    float Weigth;
public:
    // конструкторы тардиционно располагают здесь
    // методы асессоры
    //  модификаторы, setter, сеттеры
    void  SetName(string newName) { Name = newName; };
    void  SetBreed(string newBreed) { Breed = newBreed; };
    void  SetSex(string newSex) {
        if (newSex[0] == 'M') {
            //cout << "Male" << endl;
            Sex = false;
        }
        else if (newSex[0] == 'F') {
            //cout << "Female" << endl;
            Sex = true;
        }
        else { cout << "Error cant find sex\n"; }
    }

    void SetAge(int newAge) {
        if (newAge >= 0 && newAge <= 18) { Age = newAge; }
        else { cout << "Error wrong age\n"; }
    }
    void SetWeight(float newWeight) {
        if (newWeight >= 0 && newWeight <= 30) { Weigth = newWeight; }
        else { cout << "Error wrong weigth\n"; }
    }
    void Set(string _Name, string _Breed, string _Sex,
        int _Age, int _Weight)
    {
        SetName(_Name);
        SetBreed(_Breed);
        SetSex(_Sex);
        SetAge(_Age);
        SetWeight(_Weight);
    };

    //  методы инспекторы, getter, геттеры
    string GetName() { return Name; };
    string GetBreed() { return Breed; };
    string GetSex() {
        if (Sex == true) { return "Female"; }
        return "Male";
    };
    int GetAge() { return Age; };
    float GetWeigth() { return Weigth; };
    void Get(string& _Name, string& _Breed, string& _Sex,
        int& _Age, int& _Weight)
    {
        _Name = GetName();
        _Breed = GetBreed();
        _Sex = GetSex();
        _Age = GetAge();
        _Weight = GetWeigth();
    };

    // другие общие методы
    void Input()
    {
        string temp;
        cout << "\nEnter Name : ";
        getline(cin, temp);
        SetName(temp);
        cout << "\nEnter Breed : ";
        getline(cin, temp);
        SetBreed(temp);
        cout << "\nEnter Sex: ";
        getline(cin, temp);
        SetSex(temp);
        cout << "\nEnter Age : ";
        int tmp;
        cin >> tmp;
        SetAge(tmp);
        cout << "\nEnter Weight : ";
        float tmpt;
        cin >> tmpt;
        SetWeight(tmpt);
        cin.ignore();
    }
    void Print()
    {
        cout << "\nName   : " << GetName();
        cout << "\nBreed  : " << GetBreed();
        cout << "\nSex    : " << GetSex();
        cout << "\nAge    : " << GetAge();
        cout << "\nWeigth : " << GetWeigth();
        cout << endl;
    }

    // Конструкторы
    // Конструктор по умолчанию, конструктор без параметров
    Cat() {
        cout << "Конструктор по умолчанию\n";
        Name = "Без имени"; // Name ="";
        Breed = "Не знаю";
        Sex = true;
        Age = 0;
        Weigth = 0; // 0.001; // ????
    }
    //Cat(int _Age, string _Breed ) {}
    Cat(string _Name, int _Age) : Cat() // делегирование к конструктору по умолчанию
    {
        cout << "Cat::Cat(string _Name, int _Age)\n";
        SetName(_Name);
        SetAge(_Age);
    }
    Cat(string _Name, string _Breed, int _Age) : Cat(_Name, _Age)
    {
        cout << "Cat::Cat(string _Name, string _Breed, int _Age)\n";
        //SetName(_Name);
        SetBreed(_Breed);
        //SetAge(_Age);
        // 1 вариант - иниц-ци остальных переменных класса
        //Sex = true;
        //Weigth = 0;
    }
}; // class Cat;

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    //int a;
    //cout << a << endl; - неиниц-ная переменная
    Cat Push; // Push.Cat() - неявный вызо конструктора по умолчанию
    //Push.Cat(); - ошибка, конструктор так вызывть нельзя
    Push.Print();

    // создание объекта Push2 через конструктор с тремя параметрами
    //  явное обращение к конструктору с параметрами
    Cat Push2("Barsik", "Sibirskaya", 10);
    Push2.SetSex("Male"); // установка пола животного
    Push2.SetWeight(12.5); // установка веса животного
    Push2.Print();

    /*Push.Input();
    Push.Print();
    Push.Set("Bublik", "British", "Female", 5, 15);
    Push.Print();*/
    cin.get(); cin.get();
}
