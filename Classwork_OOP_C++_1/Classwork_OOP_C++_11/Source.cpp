#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Виртуальные методы
*/
/*
Создать базовый класс Employer
(служащий) с виртуальной функцией Print().
Создайте три производных класса:
President, Manager, Worker.
Переопределите функцию Print() для вывода
информации, соответствующей каждому типу
служащего.
*/

// базовый класс Employer
class Employer {
private:
    string Type; // тип служащего
public:
    Employer() = delete; // принудительно удаляем конст. по умолчанию
    Employer(string type) :Type(type) {}
    // виртуальный метод Print()
    virtual void Print() {
        cout << typeid(*this).name() << endl;
        cout << "Employer type: " << Type << endl;
    }
};

// класс President
class President : virtual public Employer {
public:
    President() :Employer("President") {}
    virtual void Print() override {
        cout << "** President **\n";
        Employer::Print(); // вызов метода из базового класса
    }
}; // class President

// класс Manager
class Manager : virtual public Employer {
public:
    Manager() :Employer("Manager") {}
    virtual void Print() {
        cout << "** Manager **\n";
        Employer::Print(); // вызов метода из базового класса
    }
}; // class Manager

// класс Worker
class Worker : virtual public Employer {
public:
    Worker() :Employer("Worker") {}
    virtual void Print() {
        cout << "** Worker **\n";
        Employer::Print(); // вызов метода из базового класса
    }
}; // class Worker;


Employer* CreateEmployer() {
    cout << "Выберите тип сотрудника: " << endl;
    cout << "1 - President\n";
    cout << "2 - Manager\n";
    cout << "3 - Worker\n";
    cout << "4 - Employer\n";
    cout << "0 - Exit\n";
    int choose;
    (cin >> choose).ignore();
    switch (choose) {
        // динамически создаем дочерние классы и
        //  возвращаем через указатель на базовый класс
    case 1: return new President;
    case 2: return new Manager;
    case 3: return new Worker;
        //case 4: return new Employer("Секретарь");
    case 0: return nullptr; // сигнал о выходе
    default:
        cout << "Неверный выбор!" << endl;
        break;
    }
    return nullptr;
}

int main()
{
    /*
    Employer emp("Unknown");
    President pr;// ("Name of President");
    Manager man;// ("Name of Manager");
    Worker wrk;// ("Name of Worker");
    emp.Print(); cout <<endl;
    pr.Print();  cout <<endl;
    man.Print(); cout <<endl;
    wrk.Print(); cout <<endl;
    */
    /*President Pres;
    Employer* mas[] = { &Pres, new President, new Manager,
                        new Worker, new Worker };
    int size = sizeof(mas) / sizeof(mas[0]);
    for (int i = 0; i < size; i++)
    {
      mas[i]->Print();
      cout << endl;
    }*/

    Employer* pEmpl = nullptr;
    while (true) {
        pEmpl = CreateEmployer();
        if (!pEmpl) { break; } //if (pEmpl == nullptr) { break; }
        pEmpl->Print();
    }
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Виртуальные методы. Абстрактный базовый класс
*/
/*
Задание 2
Создать абстрактный базовый класс фигура с виртуальной
функцией - площадь.
Создать производные классы:
прямоугольник, круг, прямоугольный треугольник,
трапеция со своими функциями площади.
Для проверки определить массив ссылок на абстрактный класс,
которым присваиваются адреса различных объектов.
*/

class Shape {
protected:
    float S;
public:
    Shape() : S() {}
    virtual ~Shape() {}
    virtual void Area() = 0;
    virtual void Input() = 0;
    virtual void Show() {
        cout << typeid(*this).name() << endl;
        cout << "S = " << S << endl;
    }
};

class Square : virtual public Shape {
protected:
    float A;
public:
    Square() : A() {}
    virtual void Area() override { S = pow(A, 2); }
    virtual void Input() override {
        cout << "Enter square side: ";
        (cin >> A).ignore();
    }

};
class Rectangle : virtual public Shape {
protected:
    float A, B;
public:
    Rectangle() : A(), B() {}
    virtual void Area() override { S = A * B; }
    virtual void Input() override {
        cout << "Enter rectangle side A, B: ";
        (cin >> A >> B).ignore();
    }
};
class Circle : virtual public Shape {
protected:
    float R;
public:
    Circle() : R() {}
    virtual void Area() override { S = R * M_PI; }
    virtual void Input() override {
        cout << "Enter circle R: ";
        (cin >> R).ignore();
    }
    virtual void Show() override {
        cout << "*** Circle *** " << endl;
        cout << "Area = " << S << endl;
    }
};

Shape* CreatShape() {
    cout << "1 - Square" << endl;
    cout << "2 - Rectangle" << endl;
    cout << "3 - Circle" << endl;
    cout << "0 - Exit" << endl;
    int choose;
    (cin >> choose).ignore();
    switch (choose)
    {
    case 1: return new Square;
    case 2: return new Rectangle;
    case 3: return new Circle;
    case 0: return nullptr;
    default:
        cout << "не верный выбор!" << endl;
        break;
    }
    return nullptr;
}

int main()
{
    Shape* Sp = nullptr;
    while (true)
    {
        Sp = CreatShape();
        if (!Sp) { break; }
        Sp->Input();
        Sp->Area();
        Sp->Show();
        delete Sp;
    }
} // main()

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;
/*
  Виртуальные методы. Абстрактный базовый класс
*/
/*
Задание 3
Создать виртуальный базовый класс с виртуальной
функцией - корни уравнения.
Создать производные классы:
1) класс линейных уравнений;
2) класс квадратных уравнений.
Определить функцию вычисления корней уравнений.
*/

int main()
{

} // main()


/*
 DataBase.h
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

// базовый класс для работы с СУБД
class DataBase {
private:
    string  typeDB; // тип СУБД - имя класса
protected:
    bool    bIsOpen; // =true, если БД открыта
public:
    DataBase();
    virtual void init();
    virtual void open(string& user, string& pass);
    virtual bool IsOpen() const;

    // Обнуление метода - чисто виртуальный метод
    virtual void Execute(string& reqSql) = 0;
    virtual string Result() = 0;
    virtual void close();
    string getTypeBD() const;
    ~DataBase() {}
}; // class DataBase


// производные классы
class MsSQL {
public:
    MsSQL();
    virtual void init();
    virtual void open(string& user, string& pass);
    virtual bool IsOpen() const;
    virtual void Execute(string& reqSql);
    virtual string Result();
    virtual void close();
private:
    string resTable; // результат запроса
}; // class MsSQL



class ORACLE
{
public:
    ORACLE();
    virtual string Result();
};


#include <iostream>
#include <string>
#include <time.h>
#include "DataBase.h"

using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// выбор СУБД и возврат указателя экземпляра БД
DataBase* SelectDB()
{
    return nullptr;
}

// rand()
string CreateReqSQL() {
    return "Самостоятельно снегерировать строку SQL-запроса";
}

int main()
{
    DataBase* pDB = nullptr;
    pDB = SelectDB();
    if (pDB) { // OK
        string user = "Admin";
        string pass = "123456";
        pDB->init();
        pDB->open(user, pass);
        if (pDB->IsOpen()) { // OK
            for (int i = 0; i < 5; i++) {
                string reqSQL;
                // создание SQL-запроса
                reqSQL = CreateReqSQL();
                pDB->Execute(reqSQL);
                string result = pDB->Result();
                cout << result << endl;
            }
            pDB->close();
        }
        else {
            cout << "Неверное имя пользователя\n";
        }
    }
}
