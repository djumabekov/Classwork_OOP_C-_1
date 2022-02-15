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
class Drob {
    int a, b;
public:
    Drob() : a(RAND(1, 10)), b(RAND(10, 20)) {}
    Drob(double v) {}
    friend ostream& operator<<(ostream& os, const Drob& obj) {
        return os << obj.a << "/" << obj.b;
    }
    // 2/5 = 0.4
    operator double() { return (double)a / (double)b; }
    //operator double() { return a / b; } // int/int
    //operator int() {
    //  int Summ = 0;
    //  for () {
    //    Summ += mas[i];
    //  }
    //  return (double)Summ / (double)Size;
    //}

};

void func(double a) {}
int main()
{
    Drob A;
    cout << "A: " << A << endl;
    double d1 = A, d2;  // d1 = A.operator double();
    d2 = (double)A;     // d2 = A.operator double(); // в стиле языка C
    d2 = double(A);     // d2 = A.operator double(); // в стиле языка C++
    double d3 = A.operator double();
    func(A); // func(A ==> double);
    Drob B = Drob(12.0);
    Drob B = 12.0;
    //Drob C = (Drob)12;
}


#include <iostream>
#include <string>
#include <time.h> // time(), clock()
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иниц-ции консоли
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

// Шаблоны: Шаблоны функций. Шаблоны классов

// Шаблон функции для сложения двух аргументов
// a + b
//class Dog {};
//template<typename T = int>
template<class T = int>
T Add(T a, T b)
{
    return a + b;
}

int main()
{
    int t1 = 10, t2 = 20;
    int res1 = Add(t1, t2); // int Add(int t1, int t2);
    cout << "a + b = " << res1 << endl;

    string s1 = "Hello ";
    string s2 = "World";
    string str = Add(s1, s2); // string Add(string, string);
    cout << "s1 + s2 = " << str << endl;

    double res2 = Add<double>(t1, t2); // double Add(double, double)
    cout << "a + b = " << res2 << endl;
}


#include <iostream>
#include <string>
#include <time.h> // time(), clock()
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иниц-ции консоли
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

// Шаблоны: Шаблоны классов

template<class T = double, class TSize = int>
class Sample // Sample<> A; Sample<string> B; Sample<string, long long> C;
{
public:
    T      Data; // шаблонная переменная класса
    string Name;
    TSize  size;
public:
    Sample() : Data(), Name(), size() {}
    /*Sample() {
      Data = 0;
      Name = "";
      size = 0;
    }*/
};
int main()
{
    Sample<> A; // Sample<double> A;
    cout << "Sample::Data = " << A.Data << endl
        << "Sample::Name = " << A.Name << endl
        << "Sample::size = " << A.size << endl;
    Sample<int> B; // int Data
    cout << "Sample::Data = " << B.Data << endl
        << "Sample::Name = " << B.Name << endl
        << "Sample::size = " << B.size << endl;
    //int a;
    //cout << a << endl;
}


#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иниц-ции консоли
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;


template<class T>
class Stack
{
    T* data;  // рабочий указатель массива для стека
    int  depth; // глубина стека
    int  sp;    // указатель на вершину стека - кол-во элементов в стеке
public:
    Stack() : Stack(10) {}
    explicit Stack(int depth) : data(), sp(), depth() { setDepth(depth); }
    // конструктор и оператор копирования
    Stack(const Stack<T>& obj) : data(), sp(), depth()
    {
        *this = obj;
    }
    Stack<T>& operator=(const Stack<T>& obj)
    {
        setDepth(obj.getDepth());
        /*for (int i = 0; i < obj.getCnt(); i++)
        {
          this->data[i] = obj.data[i];
        }
        this->sp = obj.sp;*/
        for (int i = 0; i < obj.getCnt(); i++)
        {
            push(obj.data[i]);
        }
        return *this;
    }
    ~Stack() { delete[] data; }

    int getSp()const { return sp - 1; }
    int getCnt()const { return sp; }
    int getDepth()const { return depth; }

    void setDepth(int newDepth)
    {
        if (newDepth > 0)
        {
            T* obj = new T[newDepth];
            int minSize = (sp < newDepth) ? sp : newDepth;
            for (int i = 0; i < minSize; i++)
            {
                obj[i] = data[i];
            }
            delete[] data;
            if (newDepth < sp) { sp = newDepth; }
            data = obj;
            depth = newDepth;
        }
        else if (newDepth == 0) { Clear(); }
        else { cout << "Error: new depth is < 0!" << endl; }
    }

    void Clear()
    {
        sp = 0;
    }

    // положить в стек значение в Val
    void push(T Val)
    {
        if (sp >= depth) { setDepth(getDepth() + 10); }
        data[sp] = Val;
        sp++;
    }

    // извлечь из вершины стека занчение - удаление
    T pop()
    {
        if (sp > 0) { return data[--sp]; }
        cout << "Error: count is < 0!" << endl;
        throw "Exception: count is < 0!";
    }

    // получить значение из вершины стека - без удаления
    T top()
    {
        if (sp > 0) return data[sp - 1];
        cout << "Error: count is < 0!" << endl;
        //throw "Exception: count is < 0!";
        throw 10;  // throw int ==>  catch(int)
    }

}; // class Stack<>


int main()
{
    Stack <int> st;
    st.setDepth(rand() % 10 + 10);

    int size = st.getDepth();

    for (int i = 0; i < size + 1; i++)
    {
        int t = rand() % (100 - 10 + 1) + 10;
        cout << t << " ";
        st.push(t);
    }

    cout << endl;
    cout << "Kol = " << st.getCnt() << endl;
    cout << "\n----------------------------\n" << endl;

    try {
        for (int i = 0; i < st.getDepth() + 2; i++)
        {
            int t = st.pop();
            cout << t << " ";
        }
    }
    catch (const char* ex) {
        cout << ex << endl;
    }
    catch (int err_code) {
        cout << "Exception: error code = " << err_code << endl;
    }


    while (st.getCnt()) {
        /*int t = st.pop();
        cout << t << " ";*/
        cout << (st.pop()) << " ";
    }
    cout << endl;
    cout << "Kol = " << st.getCnt() << endl;
}


