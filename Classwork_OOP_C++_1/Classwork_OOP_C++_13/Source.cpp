#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

class Cat {
public:
    Cat() {}
    friend ostream& operator<<(ostream& os, const Cat& obj) {
        return os << typeid(obj).name() << endl;
    }
    //virtual void Move() {}
    virtual ~Cat() {}
};

class LCat : public Cat {
    int* p, size;
public:
    LCat() : size(10), p(new int[size]) { /*p = new int[10];*/ }
    virtual ~LCat() override { delete[]p; }
};


int main() {
    Cat A;
    cout << "A: " << A << endl;
    LCat B;
    cout << "B: " << B << endl;
    //B.~LCat(); - 
    //B.LCat(); - так нельзя
    //B.Show();
} // B.~LCat();

#include <iostream>
#include <time.h>
#include <winerror.h> // файл с кодами ошибок ОС Windows
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

// Обработка исключительных ситуаций

// ф-ция деления двух целых чисел
int Div(int a, int b)
{
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        //return ??
        //throw "Деление на ноль!"; // исключение по типу const char*
        //throw exception("Деление на ноль!"); // исключение по типу class exception
        //throw string("Деление на ноль!"); // исключение по типу string
        //throw Cat("Мурзик"); // исключение по типу Cat
        throw 1;   // исключение по типу int
        //throw 3.567; // исключение по типу double
    }
    return a / b;
}

// ф-ция извлечения корня квадратного из int
int Sqrt(int a) {
    if (a < 0) {
        cout << "Ошибка: корень из отриц. числа!" << endl;
        //throw "корень из отриц. числа!"; // const char*
        throw 2;
    }
    return (int)(sqrt(a) + 0.5); // корень с округлением
}

int main()
{
    int t1, t2;
    cout << "Введите два целых числа: ";
    cin >> t1 >> t2;
    try { // блок ожидания и перехвата исключений
        int res1 = Div(t1, t2);
        cout << "t1 / t2 = " << res1 << endl;
        int res2 = Sqrt(res1);
        cout << "Sqrt(res1) = " << res2 << endl;
    }
    // ловушки, перехватчики исключений по типам
    catch (char* e) {}
    catch (const char* ex) {
        cout << "Сработал перехватчик по типу const char*" << endl;
        cout << "ex = " << ex << endl;
        if (strcmp(ex, "Привет") == 0) {
            cout << "Мы поимали Привет!" << endl;
        }
    }
    catch (const string& e) {
        cout << "Сработал перехватчик по типу std::string" << endl;
        cout << "e = " << e << endl;
    }
    catch (int errorCode) {
        cout << "Сработал перехватчик по типу int" << endl;
        cout << "errorCode = " << errorCode << endl;
        switch (errorCode)
        {
        case 1: cout << "Исключение: деление на ноль!\n"; break;
        case 2: cout << "Исключение: корень из отриц. числа!\n"; break;
        default:
            cout << "Неизвестная ошибка!" << endl
                << "Обратитесь к разработчикам" << endl;
            break;
        }
    }
    catch (const exception& e) {
        cout << "Сработал перехватчик по типу std::exception" << endl;
        cout << "e = " << e.what() << endl;
    }
    catch (...) { // универсальный перехватчик
        cout << "Неизвестная ошибка!" << endl;
        cout << "Обратитесь к разработчикам" << endl;
    }
    //
}



