#include <iostream>
#include <fstream> // для работы с файлами
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Перегрузка операторов
1. Создайте класс Дробь.
Используя перегрузку операторов реализуйте для него
арифметические операции для работы с дробями:
операции +, -, *, /, >>, <<
*/

class Drob {
private:
    int Chisl;
    int Znamen;
public:
    Drob() :Chisl(0), Znamen(1) {};
    Drob(int a, int b = 1) :Chisl(a), Znamen(b) {}
    //Setters
    void SetChisl(int newChisl) { Chisl = newChisl; }
    void SetZnamen(int newZnamen) {
        if (newZnamen != 0) {
            Znamen = newZnamen;
        }
        else { cout << "Error! Devide by zero!" << endl; }
    }
    void Set(int a, int b) {
        SetChisl(a);
        SetZnamen(b);
    }
    //Getters
    int GetChisl()const { return Chisl; }
    int GetZnamen()const { return Znamen; }

    // Input
    friend istream& operator >> (istream& is, Drob& obj) {
        int tmpChisl, tmpZnamen;
        if (&is == &cin) { // cin >> A; чтение с консоли
            cout << "Enter Chislitel:";
            is >> tmpChisl;
            cout << "Enter Znamenatel:";
            is >> tmpZnamen;
            obj.Set(tmpChisl, tmpZnamen);
        }
        else { // file >> A; - чтение из файлового потока
            is >> tmpChisl >> tmpZnamen;
            obj.Set(tmpChisl, tmpZnamen);
        }
        return is;
    }

    // Output
    friend ostream& operator <<(ostream& os, const Drob& obj)
    {
        if (&os == &cout) { // cout << A; вывод на консоль
            os << obj.GetChisl() << " / " << obj.GetZnamen();
        }
        else { // file << A; вывод в файл
            os << obj.GetChisl() << " " << obj.GetZnamen();
        }
        return os;
    }
    Drob operator + (const Drob& right) const {
        //*this + right;
        Drob Result;
        Result.Chisl = this->Chisl * right.Znamen +
            this->Znamen * right.Chisl;
        Result.Znamen = this->Znamen * right.Znamen;
        return Result;
    }
    Drob operator - (const Drob& right) const {
        //*this - right;
        Drob Result;
        Result.Chisl = this->Chisl * right.Znamen -
            this->Znamen * right.Chisl;
        Result.Znamen = this->Znamen * right.Znamen;
        return Result;
    }
    Drob operator * (const Drob& right) const {
        Drob Result;
        Result.Chisl = this->Chisl * right.Chisl;
        Result.Znamen = this->Znamen * right.Znamen;
        return Result;
    }
    Drob operator / (const Drob& right) const {
        Drob Result;
        Result.Chisl = this->Chisl * right.Znamen;
        Result.Znamen = this->Znamen * right.Chisl;
        return Result;
    }
    friend Drob operator + (int left, const Drob& right) {
        Drob Result(left);
        return Result + right;
    }
    // Drob A;
    // A[0] ==> Получить числитель дроби
    // A[1] ==> Получить занменатель дроби
    // для остальных индексов - ошибка
    // A[0] ==> A.operator[]( 0 );
    int operator[](int index) const
    {
        switch (index) {
        case 0: return GetChisl();  // A[0]
        case 1: return GetZnamen(); // A[1]
        default: // ошибка
            cout << "Ошибка: выход за границы индексов!\n";
            //return ?
            throw "Исключение: выход за границы индексов!";
            // throw по типу const char*
        }
    }
    // не константный оператор [] для изменения объека по индексу
    int& operator[](int index) {
        switch (index) {
        case 0: return Chisl; // возвращаем ссылку на числитель
        case 1: return Znamen;// возвращаем ссылку на знаменатель
        default:
            cout << "Ошибка: выход за границы индексов!\n";
            //return ?
            throw "Исключение: выход за границы индексов!";
            // throw по типу const char*
        }
    }
    // cout << A["Chislitel"] << endl;
    int operator[](string Name) {
        if (Name == "Chislitel") { return GetChisl(); }
        if (Name == "Znamenatel") { return GetZnamen(); }
        cout << "Ошибка: нет такого аттрибута в классе!\n";
        throw "Исключение: атрибут не найден!";
    }
    // логические операторы
    // if(A == B)
    bool operator==(const Drob& B) const {
        // 1/3 == 3/9 ==> 0.333 == 0.333
        double d1 = (double)Chisl / (double)Znamen;
        double d2 = (double)B.Chisl / (double)B.Znamen;
        //if (d1 == d2) { return true; }
        //else          { return false; }
        return (d1 == d2);
    }

    // if(A < B)
    bool operator < (const Drob& B) const {
        double d1 = (double)Chisl / (double)Znamen;
        double d2 = (double)B.Chisl / (double)B.Znamen;
        return (d1 < d2);
    }

};
//operator==()
//Drob operator + (int left, const Drob&right) {
  //Drob Result(left);
  //return Result + right;
//}


int main()
{
    Drob A, B;
    cin >> A;
    try { // защищенный блок кода для перехвата исключений throw
        cout << "Chislitel  = " << A[0] << endl;
        cout << "Znamenatel = " << A[1] << endl;
        cout << "Остальное  = " << A[2] << endl; // throw const char*
    }
    catch (const char* ex) {
        // ловушка для перехвата исключения типа const char*
        cout << "Ex1: " << ex << endl;
    }

    A[0] += 10; // A[0] - вызов не константного оператора []

    cin.ignore();
    string name;
    cout << "Enter attribute name (Chislitel, Znamenatel): ";
    cin >> name;
    try {
        cout << name << ": " << A[name] << endl;
    }
    catch (const char* e) {
        cout << "Ex2: " << e << endl;
    }
    cin >> B;
    // if (A == B) ==>  A.operator==( B );
    if (A == B) { cout << "A == B\n"; }
    else { cout << "A != B\n"; }


    /*Drob A, B(5,2);
    cin >> A >> B;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    Drob C = A + B;
    cout << "A + B = " << C << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    cout << "A / B = " << A / B << endl;
    //C = Drob(2) + A;
    C = 2 + A;
    cout << "2 + A = " << C << endl;
    C = 2;
    cout << "C = " << C << endl;
    // вывод в файловый поток
    ofstream ofile("Drob1.txt");
    if (ofile.is_open() == true) {
      ofile << A << endl
            << B << endl
            << C << endl;
      ofile.close(); // принудительное закрытие файла
    }
    else {
      cout << "Error: can't create output file!\n";
    }
    // чтение из файлового потока
    ifstream ifile("Drob1.txt");
    if (ifile.is_open()) {
      Drob temp1, temp2, temp3;
      ifile >> temp1 >> temp2 >> temp3;
      cout << "Drob1 = " << temp1 << endl;
      cout << "Drob2 = " << temp2 << endl;
      cout << "Drob3 = " << temp3 << endl;
    }
    else {
      cout << "Error: file is not found!\n";
    }*/
}






