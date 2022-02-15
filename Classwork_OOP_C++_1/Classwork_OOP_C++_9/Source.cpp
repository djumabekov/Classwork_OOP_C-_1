#include <iostream>
#include <iomanip>
#include <string>
#include <array>  // ��� ������ std::array<> - ������ ������������ �������
#include <vector> // ��� ������ std::vector<>- ����� �������������, "����������" �������
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

/*
  ���������� ����������
  ������ ������ � ������� std::vector<>
*/

/*
// ���������� � ��������� .h
int main();
class Book {
private:
  string s1;
public:
  Book(string s) { cout << s << endl; }
};

// ���������� ���������� ���� Book .cpp
Book book1("������"), book2("�������");

// ���������� ���������� ���� int
int  q(10); // q = 10;
*/

int main()
{
    const int size = 10;
    array<int, size> arr1;  // int arr1[10];
    array<int, 20> arr2;    // int arr1[20];
    //
    vector<int>    mas1;   // int * mas = nullptr;
    vector<string> mas2;   // string * mas = nullptr;
    // ������ � ������� array<>
    for (int i = 0; i < 10; i++) {
        arr1[i] = RAND(1, 10);
    }
    // arr2.size() - ������ ��� ������� �������
    for (int i = 0; i < arr2.size(); i++) {
        arr2[i] = RAND(20, 40);
    }
    cout << "arr2[" << arr2.size() << "]: "; // arr2[20]: ....
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    // ������ � ������� vector<>
    cout << "size of mas1 = " << mas1.size() << endl;
    for (int i = 0; i < 10; i++) {
        int t = RAND(100, 300);
        mas1.push_back(t); // ������� � � ����� ������� ����� �������
                           // ����� ������� +1
    }
    cout << "size of mas1 = " << mas1.size() << endl;
    for (int a : mas1) { // for(int i=0; i<mas1.size(); i++){
        cout << a << " ";  //   int a = mas[i]; 
    }
    cout << endl;
    // vector<string> mas2;
    mas2.resize(5); // ������ SetSize( newSize );
    cout << "������� " << mas2.size() << " ����:\n";
    /*for (int i = 0; i < mas2.size(); i++) {
      //cin >> mas2[i];
      string &s = mas2[i];
      cin >> s;
    }*/
    for (string& s : mas2) {
        cin >> s;
    }
    cout << endl;
    // ����� mas2[]  == vector<string> mas2;
    for (auto s : mas2) { // string s = mas2[i];
        cout << s << endl;
    }
    cout << endl;
    //mas2.resize(10);
    mas2.resize(10, "New string");
    cout << "size of mas2: " << mas2.size() << endl;
    for (auto& s : mas2) { // string &s = mas2[i];
        cout << s << endl;   // cout << mas2[i]
    }
    /*
    int* p = new int[10]{};
    int& p2 =  p[0];
    int* p3 = &p[0];
    cout << p2; // cout << *p2;
    cout << p3; // cout << 0x123456
    cout << *p3; // cout << int value
    */
} // mas1.~vector(); mas2.~vector();


#include <iostream>
#include <iomanip>
#include <string>
#include <array>  // ��� ������ std::array<> - ������ ������������ �������
#include <vector> // ��� ������ std::vector<>- ����� �������������, "����������" �������
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  ���������� ����������
  ������ ������ � ������� std::vector<>
*/
class Drob
{
public:
    int a, b;
    Drob() {
        a = RAND(0, 10); // ��������� 
        b = RAND(1, 20); // �����������
    }
    // ������������� �������� ������������ ������ ����� ��� �����
    // Drob = int; A = 10;  ==> 10/1
    Drob& operator=(int B)
    { // B/1
        a = B;
        b = 1;
        return *this;
    }
    // ���������� ������������� ������� ������ � ����� ��� ������ Drob
    friend ostream& operator << (ostream& os, const Drob& B) {
        return os << B.a << "/" << B.b; // return os;
    }
    //friend class vector<int>;
    // Drob + int <>   left + right
    //friend Drob operator+(const Drob& left, int right);

}; // class Drob;
//Drob operator+(const Drob& left, int right) {
//}

// ���������� �������� ������ � ����� ������� ���� Drob
// cout << A;
ostream& operator<<(ostream& os, const vector<Drob>& obj)
{ // [6]: 2/2 2/5 7/1 81/12 3/7
    os << "[" << obj.size() << "]: ";
    for (auto& d : obj) {
        os << d << " ";
    }
    os << endl;
    return os;
}

int main()
{
    vector<Drob> A; // ������ ������ � �������
    cout << "������� ������ �������: ";
    int size;
    cin >> size; // ���� �������
    A.resize(size); // ������ ������ �������
    vector<Drob> B(size); // ������� ������ � �������� �������

    cout << "������� ������ ��� ������: " << endl;
    for (Drob& d : A) { // ���� ������, ������� & �����������
        int temp;
        cin >> temp;
        d = temp; // d <= temp/1  ==>  A[i].operator=( temp );
    }
    cout << endl;
    for (auto& d : A) { // & - �� �����������, �� ����������
                        // auto ==> Drob
        cout << d << " "; // cout << A[i]
    }
    cout << endl;
    //
    cout << "A" << A << endl;
    cout << "B" << B << endl;
}


#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  ���������� ����������
  ����� Vector ��� ������ � ������������� ��������
*/
class Vector
{
private:
    int* Data; // ������� ��������� �� ������ ������
    int  Size; // ������ �������� �������
public:
    Vector() : Data(), Size() {}
    Vector(int size) : Vector() { SetSize(size); }
    Vector(const int* mas, int size) : Vector() { SetData(mas, size); }

    // ����������� �����������, �������� �����������, ��������� - �����������!!
    Vector(const Vector& obj) :Vector() { *this = obj; }
    Vector& operator=(const Vector& obj)
    {
        SetData(obj.GetData(), obj.GetSize());
        return *this;
    }
    ~Vector() { delete[] Data; }

    // set/get-������
    // ������ vector<>::resize()
    void SetSize(int newSize)
    {
        int* temp = new int[newSize];
        int minSize;
        if (Size < newSize) { minSize = Size; }
        else { minSize = newSize; }
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i];
        }
        for (int i = minSize; i < newSize; i++)
        {
            temp[i] = RAND(1000, 9999);
        }
        delete[] Data;
        Data = temp;
        Size = newSize;
    }
    void SetData(const int* mas, int size)
    {
        this->Size = 0;
        SetSize(size);
        for (int i = 0; i < size; i++)
        {
            Data[i] = mas[i];
        }
    }
    //
    // ������� vector<>::size()
    int  GetSize() const { return Size; }
    const int* GetData() const { return Data; }
    //
    // ������� vector<>::push_back() - �������� ������� � ����� �������
    void push_back(int val)
    {
        SetSize(GetSize() + 1);
        Data[GetSize() - 1] = val;
    }
    //
    friend ostream& operator<<(ostream& os, const Vector& B);
    friend istream& operator>>(istream& is, Vector& B);

    // ������������� ��������� []
    int operator[](int index)const;
    int& operator[](int index);
    // ����������� ���� �������� (��������� - ����� ������, ������� �������� � ���� �������� ���� ����������� ��������);
    Vector operator+(const Vector& obj) const {}

    // ������������� ��������� ������� ������
    operator()(int val); // ����������� ��� �������� ������� �� ��������� ��������;
    ��������()(int Min, int Max); // �������������� �������� �������� ������� ���������� ���������� � ���������[Min; Max];

    // ��������� ��������� ��������� ���� �������� �� ���������, �����������, ������
    operator == ();
    operator != ();
    operator < ();

    // ��������� �������������� �����
    operator int();    // �������������� � int  - ���������� ����� ��������� �������;
    operator string(); // �������������� � string - ���������� �������� ��������� ������� � ���� ������.

}; // class Vector;


int main()
{
}
