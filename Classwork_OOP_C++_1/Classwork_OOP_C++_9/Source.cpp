#include <iostream>
#include <iomanip>
#include <string>
#include <array>  // для класса std::array<> - класса статического массива
#include <vector> // для класса std::vector<>- класс динамического, "резинового" массива
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

/*
  Перегрузка операторов
  Пример работы с классом std::vector<>
*/

/*
// объявления и прототипы .h
int main();
class Book {
private:
  string s1;
public:
  Book(string s) { cout << s << endl; }
};

// экземпляры переменных типа Book .cpp
Book book1("Пушкин"), book2("Толстой");

// экземпляры переменных типа int
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
    // Пример с классом array<>
    for (int i = 0; i < 10; i++) {
        arr1[i] = RAND(1, 10);
    }
    // arr2.size() - геттер для размера массива
    for (int i = 0; i < arr2.size(); i++) {
        arr2[i] = RAND(20, 40);
    }
    cout << "arr2[" << arr2.size() << "]: "; // arr2[20]: ....
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    // Пример с классом vector<>
    cout << "size of mas1 = " << mas1.size() << endl;
    for (int i = 0; i < 10; i++) {
        int t = RAND(100, 300);
        mas1.push_back(t); // положит ь в конец массива новый элемент
                           // длина вектора +1
    }
    cout << "size of mas1 = " << mas1.size() << endl;
    for (int a : mas1) { // for(int i=0; i<mas1.size(); i++){
        cout << a << " ";  //   int a = mas[i]; 
    }
    cout << endl;
    // vector<string> mas2;
    mas2.resize(5); // аналог SetSize( newSize );
    cout << "Введите " << mas2.size() << " слов:\n";
    /*for (int i = 0; i < mas2.size(); i++) {
      //cin >> mas2[i];
      string &s = mas2[i];
      cin >> s;
    }*/
    for (string& s : mas2) {
        cin >> s;
    }
    cout << endl;
    // вывод mas2[]  == vector<string> mas2;
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
#include <array>  // для класса std::array<> - класса статического массива
#include <vector> // для класса std::vector<>- класс динамического, "резинового" массива
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Перегрузка операторов
  Пример работы с классом std::vector<>
*/
class Drob
{
public:
    int a, b;
    Drob() {
        a = RAND(0, 10); // числитель 
        b = RAND(1, 20); // знаменатель
    }
    // перегруженный оператор присваивания целого числа для дроби
    // Drob = int; A = 10;  ==> 10/1
    Drob& operator=(int B)
    { // B/1
        a = B;
        b = 1;
        return *this;
    }
    // глобальная дружественная функция вывода в поток для класса Drob
    friend ostream& operator << (ostream& os, const Drob& B) {
        return os << B.a << "/" << B.b; // return os;
    }
    //friend class vector<int>;
    // Drob + int <>   left + right
    //friend Drob operator+(const Drob& left, int right);

}; // class Drob;
//Drob operator+(const Drob& left, int right) {
//}

// глобальный оператор вывода в поток вектора типа Drob
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
    vector<Drob> A; // пустой вектор с дробями
    cout << "Введите размер вектора: ";
    int size;
    cin >> size; // ввод размера
    A.resize(size); // задаем размер вектора
    vector<Drob> B(size); // создаем вектор с заданным рамером

    cout << "Введите данные для дробей: " << endl;
    for (Drob& d : A) { // ввод данных, поэтому & обязательна
        int temp;
        cin >> temp;
        d = temp; // d <= temp/1  ==>  A[i].operator=( temp );
    }
    cout << endl;
    for (auto& d : A) { // & - не обязательно, но эффективна
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
  Перегрузка операторов
  Класс Vector для работы с целочисленным массивом
*/
class Vector
{
private:
    int* Data; // рабочий указатель на массив класса
    int  Size; // размер рабочего массива
public:
    Vector() : Data(), Size() {}
    Vector(int size) : Vector() { SetSize(size); }
    Vector(const int* mas, int size) : Vector() { SetData(mas, size); }

    // конструктор копирования, оператор копирования, дестуктор - ОБЯЗАТЕЛЬНО!!
    Vector(const Vector& obj) :Vector() { *this = obj; }
    Vector& operator=(const Vector& obj)
    {
        SetData(obj.GetData(), obj.GetSize());
        return *this;
    }
    ~Vector() { delete[] Data; }

    // set/get-методы
    // аналог vector<>::resize()
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
    // аналого vector<>::size()
    int  GetSize() const { return Size; }
    const int* GetData() const { return Data; }
    //
    // аналого vector<>::push_back() - добавить элемент в конец массива
    void push_back(int val)
    {
        SetSize(GetSize() + 1);
        Data[GetSize() - 1] = val;
    }
    //
    friend ostream& operator<<(ostream& os, const Vector& B);
    friend istream& operator>>(istream& is, Vector& B);

    // перегруженные операторы []
    int operator[](int index)const;
    int& operator[](int index);
    // объединение двух массивов (результат - новый массив, который включает в себя элементы двух суммируемых массивов);
    Vector operator+(const Vector& obj) const {}

    // перегруженные операторы круглых скобок
    operator()(int val); // увеличивает все элементы массива на указанную величину;
    оператор()(int Min, int Max); // инициализирует элементы текущего массива случайными значениями в диапазоне[Min; Max];

    // операторы сравнения элементов двух массивов на равенство, неравенство, меньше
    operator == ();
    operator != ();
    operator < ();

    // операторы преобразования типов
    operator int();    // преобразование к int  - возвращает сумму элементов массива;
    operator string(); // преобразование к string - возвращает значения элементов массива в виде строки.

}; // class Vector;


int main()
{
}
