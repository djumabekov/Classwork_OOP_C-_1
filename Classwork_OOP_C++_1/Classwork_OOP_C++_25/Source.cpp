#include <iostream>
#include <iomanip>
#include <string>     // контейнер для строковых значений
#include <fstream>    // поточный контейнер для работы с файловыми потоками
#include <array>      // array<> - класс для работы с статическим массивом
#include <vector>     // vector<> - класс для работы с динамическим массивом
#include <list>       // list<> - класс двусвязного списка
#include <iterator>   // классы итераторов для работы с контейнерами
#include <algorithm>  // файл с шаблонными функциями STL C++
#include <random>     // классы STL для работы с случ. числами
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;
/*
  STL C++ - Standart Template Library C++

  Сортировка

Задачи по Спискам list<>
Написать программу, формирующую списки присутствующих и отсутствующих студентов из общего списка группы.
Добавить возможность добавлять новых и удалять существующих студентов из списка группы.
Сделать сортировку списков по алфавиту.

2.Написать программу "справочник".
Создать два одномерных массива. Один массив хранит номера ICQ, второй – телефонные номера.
Реализовать меню для пользователя:
a) отсортировать по номерам ICQ
b) отсортировать по номерам телефона
c) вывести список пользователей
d) выход
*/

class MyList : public list<int> {
public:
    int operator[](int index) {
        auto it = begin();
        advance(it, index);
        return *it;
    }
};

// 1) typedef - оператор языка C/C++ для создания псевдонимов типов (type define)
/*
typedef vector<int>             MyVector;    // псевдоним для контейнера
//typedef vector<int>::iterator   MyVecIter;   // псевдоним для итератора MyVector
typedef MyVector::iterator      MyVecIter;   // псевдоним для итератора MyVector
*/

// 2) using - оператор языка C++ для создания, использования имен
//using MyVector  = typename vector<int>; // обявление имени для типа vector<int>
//using MyVector  = typename list<int>; // обявление имени для типа vector<int>
using MyVector = typename MyList; // обявление имени для типа vector<int>
using MyVecIter = typename MyVector::iterator; // обявление имени для итератора контейнера MyVector


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
    mas.resize(size); // задаем размер контейнера
    // 1)
    for (auto& a : mas) { a = RAND(1, 20); }
    cout << "mas: " << mas << endl;
    for (size_t i = 0; i < mas.size(); i++) {
        cout << mas[i] << ", ";
    }
    cout << endl;

    // 2) generate() - ф-ция STL C++ для иниц-ции элементов контейнера
    generate(mas.begin(), mas.end(), []() { return RAND(1, 20); });
    cout << "mas: " << mas << endl;
    // 3) generate_n() - ф-ция STL C++ для иниц-ции элементов контейнера с заданым коол-вом
    generate_n(begin(mas), mas.size(), []() { return RAND(1, 20); });
    cout << "mas: " << mas << endl;

    // 4) [1/4 ... 3/4]  [12]:{ 1,2,3, -1,-2,-3,-4,-5,-6, 1,2,3 };
    //MyVector::iterator it = begin(mas); // начало контейнера
    MyVecIter it = begin(mas); // начало контейнера
    // advance() - изменить, сдвинуть итератор на заданное число шагов +/-
    advance(it, mas.size() / 4);  // it += 1/4*size
    /*MyVecIter it2 = begin(mas);
    advance(it2, mas.size()*3/4); // it2 += 3/4*size
    int i = -1;
    generate(it, it2, [&i]() { return i--; });
    cout << "mas: " << mas << endl;*/
    int i = 0;
    generate_n(it, mas.size() / 2, [&i]() { return --i; });
    cout << "mas: " << mas << endl;

    // сортировка
    MyVector mas2 = mas; // копия оригинального массива

    //sort( begin(mas), end(mas) ); // сортировка по умолчанию - по возрастанию - для vector<>, array<>
    //sort( begin(mas), end(mas), [](auto e1, auto e2) { return e1 < e2; } );
    mas.sort(); // сортировка для списка - сортировка по умолчанию - по возрастанию

    cout << "mas1: " << mas << endl;

    // if(mas[j] < mas[j-1]) { swap(mas[j], mas[j-1]); }
    // сортировка по убыванию - необходима ф-ция предикат для сравнения двух элементов контейнера
    //  [](auto e1, auto e2) { return e2 < e1; } - лямбда-функция, безымянная ф-ция - предикат для сортировки
    //sort( begin(mas2), end(mas2), [](auto e1, auto e2) { return e2 < e1; } ); // для vector<>, array<>
    mas2.sort([](auto e1, auto e2) { return e2 < e1; }); // для list<>
    cout << "mas2: " << mas2 << endl;

    // Compare - имя ф-ции предиката для сортировки по особому уловию
    bool Compare(int e1, int e2); // локальный прототип для Compare
    //sort( begin(mas), end(mas), Compare ); // для vector<>, array<>
    mas.sort(Compare); // для list<>
    cout << "mas1: " << mas << endl;


    // объяснение работы сортировки
    // 5,4,6,3,1,6,4,6,1,6,8,4,_
    // ^                       ^
    // for(int i=0; i<size; i++){
    //   for(int j=size-1; j > i; j--){
    //     if(mas[j] < mas[j-1]){  compare(mas[j], mas[j-1]) ==> true/false
    //                             compare( e1,     e2 ) ==> true/false
    //       swap(mas[j], mas[j-1]);
    //     }
}

// ф-ции предиката для сортировки по абмолютным значениям контейнера
bool Compare(int e1, int e2) {
    //if(abs(e1) < abs(e2)) { return true; }
    //return false;
    // return  abs(e1) < abs(e2);

    // условие для сортровки по четности
    if (e1 % 2 == 0 && e2 % 2 != 0) { return true; }
    return false;
}


#include <iostream>
#include <iomanip>
#include <string>     // контейнер для строковых значений
#include <fstream>    // поточный контейнер для работы с файловыми потоками
#include <array>      // array<> - класс для работы с статическим массивом
#include <vector>     // vector<> - класс для работы с динамическим массивом
#include <list>       // list<> - класс двусвязного списка
#include <iterator>   // классы итераторов для работы с контейнерами
#include <algorithm>  // файл с шаблонными функциями STL C++
#include <random>     // классы STL для работы с случ. числами
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  STL C++ - Standart Template Library C++

  Сортировка

Задачи по Спискам list<>
Написать программу, формирующую списки присутствующих и отсутствующих студентов из общего списка группы.
Добавить возможность добавлять новых и удалять существующих студентов из списка группы.
Сделать сортировку списков по алфавиту.
*/

class Student {
private:
    string Name;
    int Posesh; // переменная для посещаемости: 0-отсутствовал, 1-присутствовал, 2-опоздал
public:
    Student() {
        Name.resize(RAND(4, 8)); // случ. размер имени студента
        generate_n(begin(Name), Name.size(), []() { return RAND('A', 'Z'); });
        Posesh = RAND(0, 2); // для переменной Посещаемость
    }
    string GetName() const { return Name; }

    friend ostream& operator<<(ostream& os, const Student& obj) {
        os << left << setw(10) << obj.Name << " : " << right;
        switch (obj.Posesh) {
        case 0:  os << "Отсутствовал"; break;
        case 1:  os << "Присутствовал"; break;
        case 2:  os << "Опоздал"; break;
        default: os << "Не понятно!"; break;
        }
        return os;
    }
    // if( A < B ) ==> if( *this < right )
    bool operator < (const Student& right) const
    { // для сортировки, упорядочивания по именам
      // "AAAAAA" < "Z"
        if (this->Name < right.Name) { return  true; }
        return false;
        // return this->Name < right.Name;
    }
    // ф-ция для сравнения по посещаемости - предикат для сортировки
    static bool CmpPosesh(const Student& e1, const Student& e2) {
        if (e1.Posesh < e2.Posesh) { return true; }
        return false;
        // return e1.Posesh < e2.Posesh;
    }

}; // class Student;


using MyData = typename list<Student>;  // тип рабочего контейнера
using MyDataIter = typename MyData::iterator; // итератор для MyData

ostream& operator<<(ostream& os, const MyData& obj) {
    // Табличный вывод спсика студентов
    os << "N  Имя студента  Посещаемость\n"; // шапка таблицы
    int i = 0; // для нумерации строк вывода
    for (auto& a : obj) { os << setw(3) << ++i << ") " << a << endl; }
    return os;
}

ostream& operator<<(ostream& os, const vector<Student>& obj) {
    // Табличный вывод спсика студентов
    os << "N  Имя студента  Посещаемость\n"; // шапка таблицы
    int i = 0; // для нумерации строк вывода
    for (auto& a : obj) { os << setw(3) << ++i << ") " << a << endl; }
    return os;
}


int main()
{
    MyData lstStud; // список студентов - контейнер по типу MyData
    int size;
    cout << "Enter number of students: ";
    (cin >> size).ignore();

    lstStud.resize(size); // задать размер списка студентов
    cout << lstStud << endl;

    lstStud.sort(); // сортировка по молчанию - по именам, в алфавитном порядке
    cout << lstStud << endl;

    lstStud.sort(Student::CmpPosesh); // сортировка по посещаемости
    cout << lstStud << endl;

    // сортировка по именам в обратном порядке - по убыванию
    lstStud.sort([](auto e1, auto e2) { return e2.GetName() < e1.GetName(); });
    cout << lstStud << endl;

    /*
    // для vector<>
    vector<Student> mas2(10);
    cout << mas2 << endl;
    sort(begin(mas2), end(mas2));
    cout << mas2 << endl;
    */
}
