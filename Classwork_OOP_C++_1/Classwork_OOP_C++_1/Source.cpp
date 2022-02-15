#include <iostream>
#include <time.h>
using namespace std;
/*
������� 1
���������� ����� "�����".
���������� ������� ���������� x, y, z � ���������� - ������ ������.
���������� ������� - ����� ������ ��� ����� ������, ������ ������,
���������� ��������� ��� ������� � ���������� - ������, ����������
���������� � ���� � �������� ������ �� �����.
*/
// Point - ���������
/*struct Point {
  int x, y, z; // ���������� ���������
  void Print() { // ����� Print() ��������� Point
    // (x,y,z)
    cout << "(" << x << "," << y << "," << z << ")\n";
  }
};*/
// Point - �����
// �������, �������� ���
// 1) ����������
// 2) ������������ - � �������
// 3) ����������� - ��������� ��������� �� ������� ������
// 4) �������������
//
class Point
{
private:    // ������������ ������� - ��������, ������� ������� ������, �� ���������
    int x, y; // ���������� ���������

protected:  // ������������ ������� ��� ���������� �������
    int z;    // ���������� ���������

public:    // ������������ ��� ���������� �������
  // ������ ������� � ���������� ������ - �������� (access)
  // ������������, setters, �������
    void SetX(int newX) { x = newX; } // ������ ��� ���������� x
    void SetY(int newY) { y = newY; }
    void SetZ(int newZ) {
        if (newZ >= 0) { z = newZ; }
        else { cout << "Error: z < 0!\n"; }
    }
    // ������������� ������
    void Set(int _X, int _Y, int _Z) {
        //x = _X; y = _Y; z = _Z; // �� ������ �������!
        // ���������� ������ ��� �������
        SetX(_X);
        SetY(_Y);
        SetZ(_Z);
    }
    // ������ ����������, getters, �������
    int GetX() { return x; } // ������ ��� ���������� x
    int GetY() { return y; } // ������ ��� ���������� y
    int GetZ() { return z; } // ������ ��� ���������� z
    // ������������� ������
    void Get(int& _X, int& _Y, int& _Z) {
        //_X = x; _Y = y; _Z = z; // �� ������ �������!
        _X = GetX(); // ���������� ���
        _Y = GetY();
        _Z = GetZ();
    }
    void Input() {
        cout << "Enter x,y,z: ";
        //cin >> x >> y >> z; // ������ ��������������, ������ � ���������� �����
        int temp;
        cin >> temp; SetX(temp); // x = temp;
        cin >> temp; SetY(temp); // y = temp;
        cin >> temp; SetZ(temp); // z = temp;
    }

    void Print() { // ����� Print() ��������� Point
      // (x,y,z)
        cout << "(" << GetX() << ","
            << GetY() << ","
            << GetZ() << ")\n";
    }
    // ������������ ������ Point - ����������� ������ ������
    //  ��� ��� ��������� ����-���
    Point() { // ����������� �� ���������, ����������� ��� ����������
        x = y = z = 0; // ������� ���������� ������ ����� ��� �������
    }
    // ����������� � ����� �����������
    Point(int _X, int _Y, int _Z) {
        //x = _X; y = _Y; z = _Z; // ������ �������!
        x = y = z = 0; // ������� ���������� ������ ����� ��������������
        Set(_X, _Y, _Z); // ����-��� ���������� ����� ������
    }
}; // class Point;

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    Point A; // A - ����������, ��������� ��������� ���� Point
             // ��� �������� ���������� A ������ ����������
             //  ����������� �� ���������, A.Point();
    //A.Point(); - ��� ������!

    //A.x = 1; // ��� ������� ������� � ���������� ������ Point
    //A.y = 2;
    //A.z = 3;
    A.Input();
    A.Print();

    A.SetX(-10);
    A.SetY(-20);
    A.SetZ(-30); // ������ ������ z < 0
    A.Print();

    Point B(11, 22, -33); // �������� ������, ���������� B
                         // � ������� ������������ � �����
                         // �����������
    B.Print();

    //Point C(); - ��������� �������� �-��� C() ������������ ������ ���� Point
    //Point C; // ����������� �� ���������
    //C.Print();

    cin.get(); cin.get();
}


#include <iostream>
#include <string>
#include <time.h>
using namespace std;
/*
���������� ����� ��� ������-���� ��������� ���������.
��������� ����� ������������ ����������� (���, ��� ���������,
������, ������� � �.�.)
� ��������: �������-����� ������ ��� ����� ������ � �������,
������ ������ �� �������, ���������� ��������� ��� �������
� ��������� ����������-������.
*/
class Cat {
private:
    string Name;
    string Breed;
    bool Sex; // true - female, false - male
    int Age;
    float Weigth;
public:
    // ������������ ����������� ����������� �����
    // ������ ��������
    //  ������������, setter, �������
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

    //  ������ ����������, getter, �������
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

    // ������ ����� ������
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

    // ������������
    // ����������� �� ���������, ����������� ��� ����������
    Cat() {
        cout << "����������� �� ���������\n";
        Name = "��� �����"; // Name ="";
        Breed = "�� ����";
        Sex = true;
        Age = 0;
        Weigth = 0; // 0.001; // ????
    }
    //Cat(int _Age, string _Breed ) {}
    Cat(string _Name, int _Age) : Cat() // ������������� � ������������ �� ���������
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
        // 1 ������� - ����-�� ��������� ���������� ������
        //Sex = true;
        //Weigth = 0;
    }
}; // class Cat;

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    //int a;
    //cout << a << endl; - ������-��� ����������
    Cat Push; // Push.Cat() - ������� ���� ������������ �� ���������
    //Push.Cat(); - ������, ����������� ��� ������� ������
    Push.Print();

    // �������� ������� Push2 ����� ����������� � ����� �����������
    //  ����� ��������� � ������������ � �����������
    Cat Push2("Barsik", "Sibirskaya", 10);
    Push2.SetSex("Male"); // ��������� ���� ���������
    Push2.SetWeight(12.5); // ��������� ���� ���������
    Push2.Print();

    /*Push.Input();
    Push.Print();
    Push.Set("Bublik", "British", "Female", 5, 15);
    Push.Print();*/
    cin.get(); cin.get();
}
