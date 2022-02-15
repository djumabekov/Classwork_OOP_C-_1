#include <iostream>
#include <iomanip>
#include <string>     // ��������� ��� ��������� ��������
#include <fstream>    // �������� ��������� ��� ������ � ��������� ��������
#include <array>      // array<> - ����� ��� ������ � ����������� ��������
#include <vector>     // vector<> - ����� ��� ������ � ������������ ��������
#include <list>       // list<> - ����� ����������� ������
#include <iterator>   // ������ ���������� ��� ������ � ������������
#include <algorithm>  // ���� � ���������� ��������� STL C++
#include <random>     // ������ STL ��� ������ � ����. �������
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;
/*
  STL C++ - Standart Template Library C++

  ����������

������ �� ������� list<>
�������� ���������, ����������� ������ �������������� � ������������� ��������� �� ������ ������ ������.
�������� ����������� ��������� ����� � ������� ������������ ��������� �� ������ ������.
������� ���������� ������� �� ��������.

2.�������� ��������� "����������".
������� ��� ���������� �������. ���� ������ ������ ������ ICQ, ������ � ���������� ������.
����������� ���� ��� ������������:
a) ������������� �� ������� ICQ
b) ������������� �� ������� ��������
c) ������� ������ �������������
d) �����
*/

class MyList : public list<int> {
public:
    int operator[](int index) {
        auto it = begin();
        advance(it, index);
        return *it;
    }
};

// 1) typedef - �������� ����� C/C++ ��� �������� ����������� ����� (type define)
/*
typedef vector<int>             MyVector;    // ��������� ��� ����������
//typedef vector<int>::iterator   MyVecIter;   // ��������� ��� ��������� MyVector
typedef MyVector::iterator      MyVecIter;   // ��������� ��� ��������� MyVector
*/

// 2) using - �������� ����� C++ ��� ��������, ������������� ����
//using MyVector  = typename vector<int>; // ��������� ����� ��� ���� vector<int>
//using MyVector  = typename list<int>; // ��������� ����� ��� ���� vector<int>
using MyVector = typename MyList; // ��������� ����� ��� ���� vector<int>
using MyVecIter = typename MyVector::iterator; // ��������� ����� ��� ��������� ���������� MyVector


ostream& operator<<(ostream& os, const MyVector& obj) {
    os << "type info: " << typeid(obj).name() << endl;
    // [4]: {1,2,3,4} \n
    os << "[" << obj.size() << "]: ";
    for (auto a : obj) { os << a << " "; }
    return os << endl;
}

int main()
{
    //MyVector::iterator it00;

    MyVector  mas; // vector<int> mas; list<int> mas;
    int size;
    cout << "Enter size: ";
    cin >> size;
    mas.resize(size); // ������ ������ ����������
    // 1)
    for (auto& a : mas) { a = RAND(1, 20); }
    cout << "mas: " << mas << endl;
    for (size_t i = 0; i < mas.size(); i++) {
        cout << mas[i] << ", ";
    }
    cout << endl;

    // 2) generate() - �-��� STL C++ ��� ����-��� ��������� ����������
    generate(mas.begin(), mas.end(), []() { return RAND(1, 20); });
    cout << "mas: " << mas << endl;
    // 3) generate_n() - �-��� STL C++ ��� ����-��� ��������� ���������� � ������� ����-���
    generate_n(begin(mas), mas.size(), []() { return RAND(1, 20); });
    cout << "mas: " << mas << endl;

    // 4) [1/4 ... 3/4]  [12]:{ 1,2,3, -1,-2,-3,-4,-5,-6, 1,2,3 };
    //MyVector::iterator it = begin(mas); // ������ ����������
    MyVecIter it = begin(mas); // ������ ����������
    // advance() - ��������, �������� �������� �� �������� ����� ����� +/-
    advance(it, mas.size() / 4);  // it += 1/4*size
    /*MyVecIter it2 = begin(mas);
    advance(it2, mas.size()*3/4); // it2 += 3/4*size
    int i = -1;
    generate(it, it2, [&i]() { return i--; });
    cout << "mas: " << mas << endl;*/
    int i = 0;
    generate_n(it, mas.size() / 2, [&i]() { return --i; });
    cout << "mas: " << mas << endl;

    // ����������
    MyVector mas2 = mas; // ����� ������������� �������

    //sort( begin(mas), end(mas) ); // ���������� �� ��������� - �� ����������� - ��� vector<>, array<>
    //sort( begin(mas), end(mas), [](auto e1, auto e2) { return e1 < e2; } );
    mas.sort(); // ���������� ��� ������ - ���������� �� ��������� - �� �����������

    cout << "mas1: " << mas << endl;

    // if(mas[j] < mas[j-1]) { swap(mas[j], mas[j-1]); }
    // ���������� �� �������� - ���������� �-��� �������� ��� ��������� ���� ��������� ����������
    //  [](auto e1, auto e2) { return e2 < e1; } - ������-�������, ���������� �-��� - �������� ��� ����������
    //sort( begin(mas2), end(mas2), [](auto e1, auto e2) { return e2 < e1; } ); // ��� vector<>, array<>
    mas2.sort([](auto e1, auto e2) { return e2 < e1; }); // ��� list<>
    cout << "mas2: " << mas2 << endl;

    // Compare - ��� �-��� ��������� ��� ���������� �� ������� ������
    bool Compare(int e1, int e2); // ��������� �������� ��� Compare
    //sort( begin(mas), end(mas), Compare ); // ��� vector<>, array<>
    mas.sort(Compare); // ��� list<>
    cout << "mas1: " << mas << endl;


    // ���������� ������ ����������
    // 5,4,6,3,1,6,4,6,1,6,8,4,_
    // ^                       ^
    // for(int i=0; i<size; i++){
    //   for(int j=size-1; j > i; j--){
    //     if(mas[j] < mas[j-1]){  compare(mas[j], mas[j-1]) ==> true/false
    //                             compare( e1,     e2 ) ==> true/false
    //       swap(mas[j], mas[j-1]);
    //     }
}

// �-��� ��������� ��� ���������� �� ���������� ��������� ����������
bool Compare(int e1, int e2) {
    //if(abs(e1) < abs(e2)) { return true; }
    //return false;
    // return  abs(e1) < abs(e2);

    // ������� ��� ��������� �� ��������
    if (e1 % 2 == 0 && e2 % 2 != 0) { return true; }
    return false;
}


#include <iostream>
#include <iomanip>
#include <string>     // ��������� ��� ��������� ��������
#include <fstream>    // �������� ��������� ��� ������ � ��������� ��������
#include <array>      // array<> - ����� ��� ������ � ����������� ��������
#include <vector>     // vector<> - ����� ��� ������ � ������������ ��������
#include <list>       // list<> - ����� ����������� ������
#include <iterator>   // ������ ���������� ��� ������ � ������������
#include <algorithm>  // ���� � ���������� ��������� STL C++
#include <random>     // ������ STL ��� ������ � ����. �������
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  STL C++ - Standart Template Library C++

  ����������

������ �� ������� list<>
�������� ���������, ����������� ������ �������������� � ������������� ��������� �� ������ ������ ������.
�������� ����������� ��������� ����� � ������� ������������ ��������� �� ������ ������.
������� ���������� ������� �� ��������.
*/

class Student {
private:
    string Name;
    int Posesh; // ���������� ��� ������������: 0-������������, 1-�������������, 2-�������
public:
    Student() {
        Name.resize(RAND(4, 8)); // ����. ������ ����� ��������
        generate_n(begin(Name), Name.size(), []() { return RAND('A', 'Z'); });
        Posesh = RAND(0, 2); // ��� ���������� ������������
    }
    string GetName() const { return Name; }

    friend ostream& operator<<(ostream& os, const Student& obj) {
        os << left << setw(10) << obj.Name << " : " << right;
        switch (obj.Posesh) {
        case 0:  os << "������������"; break;
        case 1:  os << "�������������"; break;
        case 2:  os << "�������"; break;
        default: os << "�� �������!"; break;
        }
        return os;
    }
    // if( A < B ) ==> if( *this < right )
    bool operator < (const Student& right) const
    { // ��� ����������, �������������� �� ������
      // "AAAAAA" < "Z"
        if (this->Name < right.Name) { return  true; }
        return false;
        // return this->Name < right.Name;
    }
    // �-��� ��� ��������� �� ������������ - �������� ��� ����������
    static bool CmpPosesh(const Student& e1, const Student& e2) {
        if (e1.Posesh < e2.Posesh) { return true; }
        return false;
        // return e1.Posesh < e2.Posesh;
    }

}; // class Student;


using MyData = typename list<Student>;  // ��� �������� ����������
using MyDataIter = typename MyData::iterator; // �������� ��� MyData

ostream& operator<<(ostream& os, const MyData& obj) {
    // ��������� ����� ������ ���������
    os << "N  ��� ��������  ������������\n"; // ����� �������
    int i = 0; // ��� ��������� ����� ������
    for (auto& a : obj) { os << setw(3) << ++i << ") " << a << endl; }
    return os;
}

ostream& operator<<(ostream& os, const vector<Student>& obj) {
    // ��������� ����� ������ ���������
    os << "N  ��� ��������  ������������\n"; // ����� �������
    int i = 0; // ��� ��������� ����� ������
    for (auto& a : obj) { os << setw(3) << ++i << ") " << a << endl; }
    return os;
}


int main()
{
    MyData lstStud; // ������ ��������� - ��������� �� ���� MyData
    int size;
    cout << "Enter number of students: ";
    (cin >> size).ignore();

    lstStud.resize(size); // ������ ������ ������ ���������
    cout << lstStud << endl;

    lstStud.sort(); // ���������� �� �������� - �� ������, � ���������� �������
    cout << lstStud << endl;

    lstStud.sort(Student::CmpPosesh); // ���������� �� ������������
    cout << lstStud << endl;

    // ���������� �� ������ � �������� ������� - �� ��������
    lstStud.sort([](auto e1, auto e2) { return e2.GetName() < e1.GetName(); });
    cout << lstStud << endl;

    /*
    // ��� vector<>
    vector<Student> mas2(10);
    cout << mas2 << endl;
    sort(begin(mas2), end(mas2));
    cout << mas2 << endl;
    */
}
