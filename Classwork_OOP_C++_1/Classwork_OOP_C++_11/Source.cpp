#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  ����������� ������
*/
/*
������� ������� ����� Employer
(��������) � ����������� �������� Print().
�������� ��� ����������� ������:
President, Manager, Worker.
�������������� ������� Print() ��� ������
����������, ��������������� ������� ����
���������.
*/

// ������� ����� Employer
class Employer {
private:
    string Type; // ��� ���������
public:
    Employer() = delete; // ������������� ������� �����. �� ���������
    Employer(string type) :Type(type) {}
    // ����������� ����� Print()
    virtual void Print() {
        cout << typeid(*this).name() << endl;
        cout << "Employer type: " << Type << endl;
    }
};

// ����� President
class President : virtual public Employer {
public:
    President() :Employer("President") {}
    virtual void Print() override {
        cout << "** President **\n";
        Employer::Print(); // ����� ������ �� �������� ������
    }
}; // class President

// ����� Manager
class Manager : virtual public Employer {
public:
    Manager() :Employer("Manager") {}
    virtual void Print() {
        cout << "** Manager **\n";
        Employer::Print(); // ����� ������ �� �������� ������
    }
}; // class Manager

// ����� Worker
class Worker : virtual public Employer {
public:
    Worker() :Employer("Worker") {}
    virtual void Print() {
        cout << "** Worker **\n";
        Employer::Print(); // ����� ������ �� �������� ������
    }
}; // class Worker;


Employer* CreateEmployer() {
    cout << "�������� ��� ����������: " << endl;
    cout << "1 - President\n";
    cout << "2 - Manager\n";
    cout << "3 - Worker\n";
    cout << "4 - Employer\n";
    cout << "0 - Exit\n";
    int choose;
    (cin >> choose).ignore();
    switch (choose) {
        // ����������� ������� �������� ������ �
        //  ���������� ����� ��������� �� ������� �����
    case 1: return new President;
    case 2: return new Manager;
    case 3: return new Worker;
        //case 4: return new Employer("���������");
    case 0: return nullptr; // ������ � ������
    default:
        cout << "�������� �����!" << endl;
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
  ����������� ������. ����������� ������� �����
*/
/*
������� 2
������� ����������� ������� ����� ������ � �����������
�������� - �������.
������� ����������� ������:
�������������, ����, ������������� �����������,
�������� �� ������ ��������� �������.
��� �������� ���������� ������ ������ �� ����������� �����,
������� ������������� ������ ��������� ��������.
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
        cout << "�� ������ �����!" << endl;
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
  ����������� ������. ����������� ������� �����
*/
/*
������� 3
������� ����������� ������� ����� � �����������
�������� - ����� ���������.
������� ����������� ������:
1) ����� �������� ���������;
2) ����� ���������� ���������.
���������� ������� ���������� ������ ���������.
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

// ������� ����� ��� ������ � ����
class DataBase {
private:
    string  typeDB; // ��� ���� - ��� ������
protected:
    bool    bIsOpen; // =true, ���� �� �������
public:
    DataBase();
    virtual void init();
    virtual void open(string& user, string& pass);
    virtual bool IsOpen() const;

    // ��������� ������ - ����� ����������� �����
    virtual void Execute(string& reqSql) = 0;
    virtual string Result() = 0;
    virtual void close();
    string getTypeBD() const;
    ~DataBase() {}
}; // class DataBase


// ����������� ������
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
    string resTable; // ��������� �������
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


// ����� ���� � ������� ��������� ���������� ��
DataBase* SelectDB()
{
    return nullptr;
}

// rand()
string CreateReqSQL() {
    return "�������������� ������������� ������ SQL-�������";
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
                // �������� SQL-�������
                reqSQL = CreateReqSQL();
                pDB->Execute(reqSQL);
                string result = pDB->Result();
                cout << result << endl;
            }
            pDB->close();
        }
        else {
            cout << "�������� ��� ������������\n";
        }
    }
}
