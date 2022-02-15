#include <iostream>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

extern int c; // прототип глобальной переменной
static int d = 0; // статическая переменная текущего модуля Source.cpp
                  // в остальных модулях проекта она не видна, не доступна

void func1()
{
    int a = 0; // локальная переменная ф-ции func1();
    a++;
    cout << "a = " << a;
}

void func2()
{
    static int b = 0; // статическая переменная ф-ции func2()
    b++;
    cout << "b = " << b;
}

int main()
{
    cout << "c = " << c << endl;
    for (int i = 0; i < 5; i++) {
        func1(); cout << "\t";
        func2(); cout << endl;
    }
}


// модуль Source2.cpp
int c = 0; // глобальная переменная - видна во
           // всем проекте

#include <iostream>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

//int a; // статическая переменная класса
class Sample {
private:
    static int a; // статическая переменная класса
    int b; // простая переменная класса
public:
    Sample() : b(a) { a++; }
    // статические методы SetA(), GetA() класса Sample
    static void SetA(int newA) { a = newA; }
    static int  GetA() { return a; }
    // простой геттер - нестатический метод для b
    int GetB() const { return b; }
    void Show() {
        cout << "a = " << a << "\t"
            << "b = " << b << endl;
    }
}; // class Sample;

// создание и ниц-ция статической переменной класса
int Sample::a = 0; // ?

int main()
{
    //cout << "Sample::a = " << Sample::a << endl;
    // Sample::GetA() - вызов статического метода класса
    //  вызов без экземпляра класса
    cout << "Sample::a = " << Sample::GetA() << endl;

    Sample A;  A.Show();
    Sample B;  B.Show();
    Sample mas[5];
    A.GetA(); // так тоже можно вызвать статический метод
    A.Show();
    B.Show();
    //mas[-100].Show();
    for (int i = 0; i < 5; i++) {
        // mas[i].GetB() - вызов простого метода класса
        cout << "ID of mas[i] = " << mas[i].GetB() << endl;
    }
    Sample Q;
    cout << "ID of Q = " << Q.GetB() << endl;

    //cout << "Sample::a = " << Sample::a << endl;
    cout << "Sample::a = " << Sample::GetA() << endl;
}



#define _USE_MATH_DEFINES
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
Создайте класс для подсчета площади геометрических фигур.
Класс должен предоставлять функциональность для подсчета
площади треугольника по разным формулам, площади
прямоугольника, площади квадрата, площади ромба.
Функции-члены для подсчета площади должны быть
реализованы с помощью статических функций-членов.
Также класс должен считать количество подсчетов площади
и возвращать это значение с помощью статической функции-члена.
*/

class FigureArea {
private:
    static int count;
    int id;
    static int next_id;
public:
    FigureArea() : id(next_id++) {}
    static double SquareArea(double a) {
        count++;
        return a * a;
    }
    static double RectArea(double a, double b) {
        count++;
        return a * b;
    }
    static double CirculeArea(double R) {
        count++;
        return M_PI * R * R;
        //return M_PI * pow(R,2);
    }
    static double RhombusArea(double d1, double d2) {
        count++;
        return  ((d1 * d2) / 2);
    }
    static double TriangleArea(double a, double b, double c) {
        double p = (a + b + c) / 2;
        count++;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    // статические геттеры
    static int GetCount() { return count; }
    static int GetNextID() { return next_id; }
    // обычный геттер
    int GetID() const { return this->id; }
    // статический метод Set (сеттер) сброса для count
    static int ResetCount() { count = 0; }
};
int FigureArea::count = 0;
int FigureArea::next_id = 1000;

void Input() {
    while (true) {
        int choice;
        cout << "1.Square Area    : " << endl;
        cout << "2.Rectangle Area : " << endl;
        cout << "3.Circule Area   : " << endl;
        cout << "4.Rhombus Area   : " << endl;
        cout << "5.Triangle Area  : " << endl;
        cout << "0.Exit           : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter side square : " << endl;
            double l;
            cin >> l;
            FigureArea L;
            cout << "Square area equal : "
                << L.SquareArea(l) << endl;
            break;
        }
        case 2:
        {
            cout << "Enter rictengle site : " << endl;
            double a, b;
            cin >> a >> b;
            cout << "Rictengle area equal : "
                << FigureArea::RectArea(a, b) << endl;
            break;
        }
        case 3:
        {
            cout << "Enter circule site : " << endl;
            double r;
            cin >> r;
            cout << "Circule area equal : "
                << FigureArea::CirculeArea(r) << endl;
            break;
        }
        case 4:
        {
            cout << "Enter rhombus site : " << endl;
            double d1, d2;
            cin >> d1 >> d2;
            cout << "Rhombus area equal : "
                << FigureArea::RhombusArea(d1, d2) << endl;
            break;
        }
        case 5:
        {
            cout << "Enter tringle site : " << endl;
            double a, b, c;
            cin >> a >> b >> c;
            cout << "Tringle area equal : "
                << FigureArea::TriangleArea(a, b, c) << endl;
            break;
        }
        case 0: cout << "Good bye!" << endl;
            return;
        default:
            break;
        }
    }
}

int main()
{
    /*
    FigureArea Ex;
    FigureArea Ex2;

    cout << "Area Square : " << Ex.SquareArea(4) << endl;
    cout << "Area Triangle : " << Ex2.TriangleArea(3,4,5)
      << endl;
    // статический геттер
    cout << "Count = " << FigureArea::GetCount() << endl;
    // обычные геттеры
    cout << "Ex1 id = " << Ex.GetID() << endl;
    cout << "Ex2 id = " << Ex2.GetID() << endl;
   */

    Input();
    cout << "Count = " << FigureArea::GetCount() << endl;
}
