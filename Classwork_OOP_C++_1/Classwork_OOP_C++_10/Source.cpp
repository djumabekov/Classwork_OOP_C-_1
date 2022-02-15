#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
 ������������

������� 2
�������� ����� ������������� �ertificate, �������
����� ��������� ���������� � ���������� ����������.
� ������� ��������� ������������, ���������� �����
ForeignPassport (������.�������) ����������� �� �ertificate.
��������, ��� ����������� ������� �������� ������ ���������� ������, ����� ������ � �����, ����� ������������ ��������.
*/

// ������� ����� �ertificate
class �ertificate {
};

// �������� (�����������) ����� ForeignPassport
class ForeignPassport {
};

int main()
{
	�ertificate cert;
	cin >> cert;
	cout << cert << endl;

	ForeignPassport fpass;
	cin >> fpass;
	cout << fpass << endl;
}

#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


/*
������ �������������� ������������
*/

// ������� ������
class Base1 {
public:
    int a;
    Base1() :a(1) { cout << "Base1::Base1();\n"; }
    Base1(const Base1& v) {
        cout << "Base1::Base1(Base1&);\n";
        a = v.a;
    }
    ~Base1() { cout << "Base1::~Base1();\n"; }
};

class Base2 {
public:
    int b;
    Base2() :b(2) { cout << "Base2::Base2();\n"; }
    Base2(const Base2& v) {
        cout << "Base2::Base2(Base2&);\n";
        b = v.b;
    }
    ~Base2() { cout << "Base2::~Base2();\n"; }
};

// ������� �����
class A : public Base2, public Base1 {
    // + ���� ������� Base1 � Base2
public:
    int a, b;
    A() :a(10), b(20) { cout << "A::A()\n"; }
    A(const A& v) {
        cout << "A::A(A&);\n";
        a = v.a;  // A::a = v.a;
        b = v.b;  // A::b = v.b
        Base1::a = v.a;
        Base2::b = v.b;
    }
    ~A() { cout << "A::~A()\n"; }
};

int main()
{
    A varA;
    cout << "varA.a = " << varA.a << endl;
    cout << "varA.b = " << varA.b << endl;
    ((Base1&)varA).a = 100;
    ((Base2&)varA).b = 200;
    cout << "varA::Base.a = " << ((Base1)varA).a << endl;
    cout << "varA::Base2.b= " << ((Base2)varA).b << endl;
} // A::~A() ==> Base1::Base1(); Base2::Base2();


#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  ������������� ������������
   ����� CatDog
*/

// ������� ����� "�������� ��������"
class Pet {
private:
    string Type; // Cat/Dog/CatDog
    string Name; // ��� ���������
    string Breed; // ������
    int Age; // �������
protected:
    bool signal; //if true print Pet // false dont print Pet 
public:
    Pet(string type) :Type(type), Name(), Breed(), Age(), signal(true) {}
    Pet(string type, string name) :Type(type), Name(name), Breed(),
        Age(), signal(true) {}
    void SetType(string type) { Type = type; }
    void SetName(string var) { Name = var; }
    void SetBreed(string var) { Breed = var; }
    void SetAge(int var) { Age = var; }
    string GetType()const { return Type; }
    string GetName()const { return Name; }
    string GetBreed()const { return Breed; }
    int GetAge()const { return Age; }
    friend ostream& operator<<(ostream& os, const Pet& obj) {
        os << "Type :" << obj.Type << endl;
        os << "Name :" << obj.GetName() << endl;
        os << "Breed :" << obj.GetBreed() << endl;
        os << "Age :" << obj.GetAge() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Pet& obj) {
        cout << "Enter Type : ";
        getline(is, obj.Type);
        cout << "Enter Name : ";
        getline(is, obj.Name);
        cout << "Enter Breed : ";
        getline(is, obj.Breed);
        cout << "Enter Age : ";
        (is >> obj.Age).ignore();
        //is.ignore();
        return is;
    }
};

// ����������� ����� "�����"
class Cat : virtual public Pet {
private:
    int livecount;
public:
    Cat() :Pet("cat"), livecount(9) {}
    Cat(string name, int age) :Pet("cat", name), livecount(9)
    {
        SetAge(age);
    }
    //Cat(string name, int age) :Cat() {
    //  SetName(name); 
    //  SetAge(age);
    //}
    void SetLivecount(int var) { livecount = var; }
    int GetLivecount()const { return livecount; }
    friend ostream& operator<<(ostream& os, const Cat& obj) {
        os << typeid(obj).name() << endl;
        if (obj.signal == true) { os << (Pet&)obj << endl; }
        return  os << "Livecount : " << obj.livecount << endl;
    }
    friend istream& operator>>(istream& is, Cat& obj) {
        cout << "Enter TypeId : " << typeid(obj).name() << endl;
        if (obj.signal == true) { is >> (Pet&)obj; }
        cout << "Enter Livecount : ";
        return (is >> obj.livecount).ignore();
    }
};

// ����������� ����� "������"
class Dog : virtual public Pet {
private:
    int bonecount;
public:
    Dog() :Pet("Dog"), bonecount() {}
    Dog(string name, int age) :Pet("Dog", name), bonecount()
    {
        SetAge(age);
    }
    void SetBonecount(int var) { bonecount = var; }
    int GetBonecount()const { return bonecount; }
    friend ostream& operator<<(ostream& os, const Dog& obj) {
        os << typeid(obj).name() << endl;
        if (obj.signal == true) { os << (Pet&)obj << endl; }
        return  os << "Bonecount : " << obj.bonecount << endl;
    }
    friend istream& operator>>(istream& is, Dog& obj) {
        cout << "Enter TypeId : " << typeid(obj).name() << endl;
        if (obj.signal == true) { is >> (Pet&)obj; }
        cout << "Enter bonecount : ";
        return (is >> obj.bonecount).ignore();
    }
};

// ����������� ����� "�������"
class CatDog : virtual public Cat, virtual public Dog,
    virtual public Pet
{
public:
    CatDog() : Pet("CatDog") { signal = false; }
    CatDog(Cat cat, Dog dog) :Cat(cat), Dog(dog), Pet("Catdog")
    {
        signal = false;
        SetName(cat.GetName() + "-" + dog.GetName());
        SetBreed(cat.GetBreed() + "-" + dog.GetBreed());
        SetAge(cat.GetAge() + dog.GetAge());
    }
    friend ostream& operator<<(ostream& os, const CatDog& obj) {
        os << "TypeID :" << typeid(obj).name() << endl;
        const_cast<bool&>(obj.signal) = false; // ������� ����������� ��������
        os << (Pet&)obj << endl;
        os << (Cat&)obj << endl;
        os << (Dog&)obj << endl;
        return os;
    }
    friend istream& operator>>(istream& is, CatDog& obj) {
        obj.signal = false;
        return is >> (Pet&)obj >> (Cat&)obj >> (Dog&)obj;
    }
};

int main()
{
    // ������� ������ � ��������
    /*
    // 1 �������
    CatDog cd;
    cin >> cd;          // cd.Input();
    cout << cd << endl; // cd.Print();
     */

     // 2 �������
    Cat cat;
    cin >> cat; // cat.Input();
    Dog dog;
    cin >> dog; // dog.Input();
    CatDog cd2(cat, dog);

    cout << cd2 << endl; // cd2.Print();

}


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
    virtual void Print() {
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
    Employer* mas[] = { new President, new Manager,
                        new Worker, new Worker };
    int size = sizeof(mas) / sizeof(mas[0]);
    for (int i = 0; i < size; i++)
    {
        mas[i]->Print();
        cout << endl;
    }
}


