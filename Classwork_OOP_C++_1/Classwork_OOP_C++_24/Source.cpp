#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
1. ���� ��� ��������� �����.
��������, ��������� �� �� ������.
���� ���, �� ������� ������������� ������ �� ������� �����.
*/

//int __cdecl main(int argc, char ** argv, char** env)
// int argc - ���-�� ����� � ������� argv
// char ** argv - ������ ����� ���������� ��������� ������
// char ** env - ������ ����� ���������� ��������� ����������� ����� (enveroment)
int main(int argc, char** argv, char** env)
{
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = \"" << argv[i] << "\"\n";
    }
    cout << endl << endl;
    // char ** env - ������ ����� ���������� ��������� ����������� ����� (enveroment)
    int i = 0;
    while (env[i] != nullptr) {
        cout << "env[" << i << "]: " << env[i] << endl;
        i++;
    }
}


#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
1. ���� ��� ��������� �����.
��������, ��������� �� �� ������.
���� ���, �� ������� ������������� ������ �� ������� �����.
Drag-and-Drop
*/

void PrintFile(const string& fileName);

//int __cdecl main(int argc, char ** argv, char** env)
// int argc - ���-�� ����� � ������� argv
// char ** argv - ������ ����� ���������� ��������� ������
// char ** env - ������ ����� ���������� ��������� ����������� ����� (enveroment)
int main(int argc, char** argv)
{
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = \"" << argv[i] << "\"\n";
    }
    cout << endl << endl;
    //
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            cout << "--------------------------------\n";
            cout << "����: \"" << argv[i] << "\"\n";
            // ������ ���������� �����
            PrintFile(argv[i]);
        }
    }
    else {
        // ����� ��������� ������������� ���������
        cout << "��������� ������ ������.\n"
            "�������������:\n  project1.exe <��� ��. �����> [��� 2-�� ��. �����]"
            " [��� 3-�� ��. �����] ...\n";
    }
}

void PrintFile(const string& fileName)
{
    //ofstream - ������ ��������� ������ ��� ������/����������
    //ifstream - ������ ��������� ������ ��� ������

    ifstream file(fileName); // �������� ����� ��� ������
    // �������� �� ������ ��� �������� �����
    if (!file.is_open()) // if( file.is_open() == false )
    {
        cout << "������: ���� �� ������!\n";
        return; // ����� �� ������
    }
    int line = 0; // ��� �������� �����
    while (!file.eof()) { // while( file.eof() == false )
        string str;
        getline(file1, str1);
        getline(file2, str2);
        cout << ++line << ") " << str << endl;
    }
    //file.close(); // �� �����������, �.�. ���������� file ���������
} // file.~ifstream() ==> file.close()




#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>  // array<>  - ���������
#include <vector> // vector<> - ���������
#include <list>   // list<>   - ���������
#include <iterator> // ��������� ��� �����������
#include <algorithm> // ����� �������� �-��� ���������� STL C++
#include <random>    // ����� ������� ��� ������ � ������������ ����. �����
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  STL C++ - Standart Template Library C++

1. **� ���������� �������, ��������� �� N ������������ ����� ���������:
a) ����� ������������� ���������.
b) ������������ ���������, ����������� ����� min � max ����������.
c) ������������ ��������� � ������� ��������.
d) �����  ���������, ����������� ����� ������ � ��������� �������������� ����������.
*/

int main()
{
    random_device rnd; // ���������� ��������� ������ ����. ����� [0; 2**32-1]

    const int N = 10;
    // ����� ���������� ����������� ���� array<>, vector<>, list<>
    array<int, N> mas1;    // int mas1[N]; - ������ ������������ �������
    vector<int>   mas2(N); // int * mas2 = new int[N]; - ������ ������������� �������
    list<int>     lst1;    // ������ ����������� ������ ���� int

    // 1
    for (int i = 0; i < N; i++) {
        mas1[i] = rnd() % 11 - 5; // [-5; +5]
        cout << mas1[i] << " ";
    }
    cout << endl;
    // 2 ��������� ���������� mas1 � ������� ������������ ����� for
    for (auto& a : mas1) {
        //a = rnd() % 11 - 5; cout << a << " "; 
        cout << (a = rnd() % 11 - 5) << " "; /* [-5;5] */
    }
    cout << endl;
    // 3
    for (auto& a : mas2) {
        cout << (a = rnd() % 21 - 10) << " "; /* [-10;10] */
    }
    cout << endl;
    // 4 
    // for_each()
    // begin()
    // end()
    // [](){}
    for_each(begin(mas2), end(mas2), [&rnd](auto& a) { a = rnd() % 21 - 10; cout << a << " "; });
    cout << endl;
    for_each(begin(mas2), end(mas2), [](auto& a) { cout << (a = RAND(-10, 10)) << " "; });
    cout << endl;
    // C#: for each( auto a in mas2 ){ a = rand(); }

    // 5 � ������� ����������
    int sum = 0;
    array<int, N>::iterator itBegin = begin(mas1); // ��������� ��� ���������� mas1
    for (; itBegin != end(mas1); ++itBegin) {
        // cout << *itBegin << " ";
        // sum += *itBegin;
        if (*itBegin < 0) { sum += *itBegin; } // ����� �����. ���������� ���������� mas1
    }
    cout << "sum1 = " << sum << endl;

    sum = 0;
    //vector<int>::iterator it( begin(mas2) ); // �������� ��� ���������� mas2 ���� vector<int>
    vector<int>::iterator it;
    for (it = begin(mas2); it != end(mas2); ++it) {
        if (*it < 0) { sum += *it; } // *it; - �������� ������� ������� ����������, �� ������� ��������� ��������
    }
    cout << "sum2 = " << sum << endl;

    // 6 ������ � �������
    // ���� ���������� ������ - ���������� ��������� � ������
    for (int i = 0; i < N; i++) {
        lst1.push_back(RAND(-15, 15));
    }
    // 7
    for (auto a : lst1) { cout << a << " "; }
    cout << endl;
    // 8
    list<int>::iterator it3 = begin(lst1); // ������ ��������� lst1
    for (; it3 != end(lst1); ++it3) { cout << *it3 << " "; }
    cout << endl;
    // 9
    sum = 0;
    for_each(begin(lst1), end(lst1), [](auto a) { cout << a << " "; });
    cout << endl;

    void func_for_each(int a); // �������� ���������� �-��� - ��������� ����, ��� ������-������� �� ������� ����
    for_each(begin(lst1), end(lst1), func_for_each);
    cout << endl;

    for_each(begin(lst1), end(lst1), [&sum](auto a) { if (a < 0) { sum += a; } });
    cout << "sum3 = " << sum << endl;
    // ��������� ��������� lst1 ���������� -1
    fill(begin(lst1), end(lst1), -1);
    // ��������� �������� �������������� ��������� ������ ��� ������� ���� list<int>
    ostream& operator<<(ostream & os, const list<int>&obj);
    cout << "lst1: " << lst1 << endl;
}

// �-��� ��� ������� ������ std::for_each()
void func_for_each(int a) { cout << a << " "; }

// [10]: 1 2 3 4 5
ostream& operator<<(ostream& os, const list<int>& obj) {
    os << "[" << obj.size() << "]: ";
    for (auto a : obj) { os << a << " "; }
    return os;
}


/*
5 0 5 -1 4 -1 -5 2 -1 4
-5 -2 2 5 -3 1 -1 -4 4 2
0 -2 -10 6 0 -1 10 -7 -7 3
6 1 -4 1 5 -7 -7 1 5 -3
-6 3 -8 7 10 -4 9 10 -6 0
sum1 = -15
sum2 = -24
13 3 12 -14 13 -5 -9 -14 6 5
13 3 12 -14 13 -5 -9 -14 6 5
13 3 12 -14 13 -5 -9 -14 6 5
sum3 = -42
*/
