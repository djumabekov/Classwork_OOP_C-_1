#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
 Перегрузка операторов
 Класс эмуляции для типа int - Integer
*/
class CInt {
private:
    int Data; // рабочая переменная класса
    //int Data[64]; // для хранения 2048-битного числа 
    //int* Data, size; // для хранения числа произвольного размера
public:
    CInt() : Data() {} // Data = 0;
    CInt(int val) :Data(val) {} // Data = val;
    /*// конструктор копирования - здесь не обязательно
    CInt(const CInt& obj) { Data = obj.Data; }
    // оператор копирования
    // A = B;  => CInt = CInt
    CInt& operator = (const CInt& obj) {
      this->Data = obj.Data;
      return *this;
    }*/
    // оператор присавивания
    // A = 123; => CInt = int
    CInt& operator = (int val) {
        this->Data = val;
        return *this;
    }
    // A = "123456";
    CInt& operator = (string str) {
        Data = stoi(str); // stoi("  123 45") => 123
                          // stoi(" w 123 45") => 0
        return *this; // A = B = C = "123456";
    }
    // A + B ==> A.operator+( B ) ==> C;
    // A - this
    // B - right
    // 1 + 2 ==> 3
    CInt operator + (const CInt& right) const
    {
        CInt result; // локальная, временная переменная
                     // для хранения результата суммы
        result = this->Data + right.Data; // суммирование
        return result; // возвращаем результат по значению
                       // копию переменой result
    } // result.~CInt();

    // A - B;  *this - right
    CInt operator - (const CInt& right) const
    {
        CInt result; // локальная, временная переменная
                     // для хранения разности
        result = this->Data - right.Data;
        return result; // возвращаем результат по значению
                       // копию переменой result
    } // result.~CInt();

    // c = a + "10"; =>  c = a.operator+( "10" );
    CInt operator+(const string& str) const
    {
        CInt right;// = str; // CInt(string)
        right = str; // right.operator=( string );
        // CInt + CInt
        CInt res = *this + right; // this->operator+( right );
        //res.Data = this->Data + right.Data;
        //res.Data = (*this).Data + right.Data;
        return res;
    }
    // оператор ^ - возведение в степень
    // A = B ^ 4;
    CInt operator^(int power) const
    {
        CInt A; // локальная переменная
        A.Data = pow(this->Data, power);
        return A; // результат - копия локальной переменной A
    }

    int getData() const { return Data; }
    void setData(int Data) { this->Data = Data; }

    // дружественный оператор для класса CInt
    friend istream& operator>>(istream& is, CInt& right);

}; // class CInt;

// Перегруженные операторы ввода-вывода
// cout << A;  ==>  os << right; 
// file << A;
// operator<<(cout, A);
ostream& operator<<(ostream& os, const CInt& right)
{
    //os << "Data: " << right.getData();
    os << right.getData();
    return os; // возвращаем ссылку на текущий поток вывода
}

// cin >> A >> B >> C;
istream& operator>>(istream& is, CInt& right)
{
    is >> right.Data;
    return is; // возвращаем ссылку на текущий поток ввода
}

int main()
{
    /*//int t;
    //cout << t; - ошибка, не иниц-ная переменная
    CInt t;
    cout << t; // 0 - ошибки не будет*/

    CInt a = 123, b = 456;
    b = "456";
    CInt c = a + b; // CInt c(a+b);
    //c = a.operator+(b); // прямой вызов метода оператора +

    cout << a << " + " << b << " = " << c << endl;
    c = a - b; // c.operator=(a-b);
    cout << a << " - " << b << " = " << c << endl;

    c = a + "10"; // CInt + string
    CInt d = (a + b) - c;

    CInt t;
    cout << "Введите число: ";
    cin >> t; // operator>>(cin, t);
    cout << "t = " << t << endl;
    cout << "t^3 = " << (t ^ 3) << endl;
}

