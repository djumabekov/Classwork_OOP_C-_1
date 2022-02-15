#include <iostream>
#include <string>
#include <algorithm>  // библиотека алгоритмов
#include <time.h>     // time(), clock()
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иници-ции параметров консоли и генератора случ. чисел
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;

/*
Создайте класс Book
Необходимо хранить данные:
Автор, Название, Год, Количество страниц.
Создать массив объектов в виде класса Library.
Вывести:
- сортировка списка книг: по названию, по году издания....
- список книг заданного автора;
- список книг, выпущенных заданным издательством;
- список книг, выпущенных после заданного года.
Используйте конструктор и константные функции-члены (например, для отображения данных о книге и т.д.)
*/

class Book
{
private:
    string Autor;
    string Name;
    int Year;
    int Pages;
public:
    Book() : Autor("Неизвестно"), Name("Без имени"),
        Year(2000), Pages(1) {}
    Book(string _Autor, string _Name, int _Year, int _Pages)
        : Autor(_Autor), Name(_Name), Year(_Year), Pages(_Pages) {}
    Book(string _Autor, string _Name, int _Year)
        :Book() {
        SetAutor(_Autor);
        SetName(_Name);
        SetYear(_Year);
    }

    void SetAutor(const string& newAutor) { this->Autor = newAutor; }
    void SetName(const string& newName) { Name = newName; }
    void SetYear(int newYear) {
        if (newYear >= 0 && newYear <= 2021) { Year = newYear; }
        else { cout << "Ошибка, не верный ввод года!\n"; }
    }
    bool SetPages(int newPages) {
        if (newPages <= 0 || newPages > 10'000) {
            cout << "Ошибка не верное коичество страниц!\n";
            return false;
        }
        else { Pages = newPages; return true; }
    }

    string GetAutor()const { return Autor; }
    string GetName()const { return Name; }
    int GetYear()const { return Year; }
    int GetPages() const { return Pages; }

    void Input() {
        cout << "Введите автора: ";
        string tmp;
        getline(cin, tmp);
        SetAutor(tmp);
        cout << "Введите название книги: ";
        getline(cin, tmp);
        SetName(tmp);

        cout << "Введите год книги: ";
        int temp;
        cin >> temp;
        SetYear(temp);
        bool a = false;
        while (a != true)
        {
            cout << "Введите количество страниц: ";
            cin >> temp;
            a = SetPages(temp);
        }
        cout << endl;
        cin.ignore();
    }
    void Print()const {
        cout << "Автор: " << GetAutor() << endl;
        cout << "Название книги: " << GetName() << endl;
        cout << "Год издания: " << GetYear() << endl;
        cout << "Количество страниц: " << GetPages() << endl;
    }
}; // class Book;

// класса Библиотеки для хранения и управлением массивом книг
class Library {
private:
    Book* Data; // рабочий указатель на дин. массив книг
    int   Size; // текущее кол-во книг в массиве Data
public:
    Library() : Data(), Size() {}
    Library(int _Size) : Library() { SetSize(_Size); }
    Library(Book* mas, int size) : Library() { SetBook(mas, size); }
    // деструктор - здесь ОБЯЗАТЕЛЕН!!! т.к. есть дин. объект - массив Data
    ~Library() { delete[] Data; }
    // set
    void SetSize(int newSize)
    {
        Book* temp = new Book[newSize]; // создание нового рабочего массива
        // определение минимального размера для
        //  копирования старых данных
        int minSize = (newSize > Size) ? Size : newSize; // тернарный оператор
        //if (newSize > Size) { minSize = Size; }
        //else { minSize = newSize; }
        // цикл копирования старых данных
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i]; // копирование из Data в temp
        }
        delete[] Data; // удаление старых данных
        Data = temp;   // запоминаем адрес нового рабочего массива
        Size = newSize;
    }
    void SetBook(Book* mas, int size)
    {
        //Size = 0; // Если не хотим копировать старые книги
        SetSize(size);
        for (int i = 0; i < size; i++)
        {
            Data[i] = mas[i];
        }
    }
    void SetAt(Book book, int index) // Library[index] = book;
    {
        if (index >= 0 && index < Size) { Data[index] = book; }
        else { cout << "Error! Incorrect index!\n"; }
    }
    // get
    int GetSize()const { return Size; }
    const Book* GetBook()const { return Data; }

    Book GetAt(int index)const    // Book book = Library[index];
    {
        if (index >= 0 && index < Size) { return Data[index]; }
        cout << "Error! Incorrect index!\n";
        //return ?????;
        throw "Exception! Incorrect index";
    }
    // 
    void Input()
    {
        int temp;
        cout << "Сколько книг вы хотите ввести: ";
        cin >> temp; SetSize(temp);
        cin.ignore();
        for (int i = 0; i < GetSize(); i++)
        {
            Data[i].Input();
        }
    }
    void Print()
    {
        for (int i = 0; i < GetSize(); i++)
        {
            cout << i + 1 << ":" << endl;
            Data[i].Print();
            cout << endl;
        }
    }
    void PrintAutor(string _Autor)
    {
        for (int i = 0; i < GetSize(); i++)
        {
            if (Data[i].GetAutor() == _Autor) { Data[i].Print(); }
        }
    }
    // сортировка по авторам
    void Sort() {
        bool CmpBookAutor(Book b1, Book b2); // локальный прототип ф-ции
        // if(Data[j] < Data[j-1])
        sort(Data, Data + Size, CmpBookAutor);
    }
    // сортировка по названию
    void SortName() {
        sort(Data, Data + Size,
            // лямбда-функция, безымянная функция для сравенния двух
            //  книг по названию
            [](Book b1, Book b2) {return (b1.GetName() < b2.GetName()); }
        );
    }
    // сортировка по году издания в обратном направлении - по убыванию
    void SortYear() {
        /*auto t = 1; ==> int t = 1;
        auto d = 1.23; ==> double d = 1.23;
        auto q; // ошибка
        */
        auto cmpFunc =
            [](auto a, auto b) {return a.GetYear() > b.GetYear(); };
        sort(Data, Data + Size, cmpFunc);
    }

}; // class Library

// if(b1.Author < b2.Author) ==> True
bool CmpBookAutor(Book b1, Book b2) {
    // 1 вариант
    //if (b1.GetAutor() < b2.GetAutor()) { return true; }
    //else                               { return false; }
    // 2 вариант
    //return (b1.GetAutor() < b2.GetAutor()) ? true : false;
    // 3 вариант
    return (b1.GetAutor() < b2.GetAutor());
}

int main()
{
    /*Book obj;
    obj.Input();
    obj.Print();
    cout << endl;
    Book obj2("Януш", "Одиночество в сети", 2020, 500);
    obj2.Print();*/

    Library library(5);
    //library.Print();

    library.Input();
    library.Print();
    library.PrintAutor("Pupkin");

    cout << "\n---------------------\n";
    library.Sort(); // сортировка по авторам
    library.Print();
    cout << "\n---------------------\n";
    library.SortName(); // сортировка по названиям книг
    library.Print();
    cout << "\n---------------------\n";
    library.SortYear(); // сортировка по году издания
    library.Print();
}

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
* Конструктор копирования
* Деструктор
* Обязаельные, если в классе есть динамический массив, динамический объект
*/
class Mas
{
public:
    int* data; // указатель на массив
    int size;   // длина массива

    Mas() :data(), size() {} // Mas():data(nullptr),size(0){}
    Mas(int newSize) // : Mas()
    {
        data = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            data[i] = RAND(1, 20);
        }
        size = newSize;
    }
    // конструктор копирования - ОБЯЗАТЕЛЕН когда в классе есть указатель на динамический массив
    // Mas B = A; ==> Mas B(A);
    // B - текущий объект, this
    // A - obj - оригигал для копирования
    Mas(const Mas& obj) {
        data = new int[obj.size]; // новый массив для копии
        for (int i = 0; i < obj.size; i++) {
            data[i] = obj.data[i]; // копирование данных из obj в текущий объект
        }
        size = obj.size;
    }
    // конструктор копирования от компилятора
    //  побитовое копирование
    /*Mas(const Mas& obj) {
      data = obj.data;
      size = obj.size;
    }*/

    // оператор копирования - специальный сеттер
    // A = B; ==> A.operator=( B );
    // A - текущий объект, куда копируется
    // B - obj, оригинал для копии
    Mas& operator=(const Mas& obj) {
        delete[]data; // удалить старый массив, старые данные
        data = new int[obj.size]; // новый рабочий массив
        for (int i = 0; i < obj.size; i++) {
            this->data[i] = obj.data[i]; // копирование
        }
        size = obj.size; // запоминаем размер
        return *this; // вернуть ссылку на текущий объект
    }
    /*void setSize(int size) { this->size = size;} */


    // деструктор - ОБЯЗАТЕЛЕН когда в классе есть указатель на динамический массив
    ~Mas() { delete[]data; }

    // A.Print("Massiv A"); ==> Massiv A[4]: 1 2 3 4
    Mas& Print(string title = "") {
        cout << title
            << "(" << data << ")" // адрес массива data, указатель
            << ":[" << size << "] "; // длина массива
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        return *this;
    } // void Print();

}; // calss Mas;

Mas func1() {
    Mas A(5);
    A.data[0] = 123;
    A.Print("func1()::A");
    return A; // неявный вызов конструктора копирования
} // A.~Mas()

int main()
{
    Mas A(10);
    A.Print("A");
    // копирование через конструктор
    Mas B = A; // неявный вызов конструктора копирования
    B.Print("B");

    A.data[0] = 999;
    A.Print("A");
    B.Print("B");

    Mas C(B); // явное обращение к конструктору копирования
    C.Print("C");

    C = A; // оператор копирования
    B = C; // оператор копирования
    C = B; // оператор копирования

    //C = func1(); // func1 из временный объект как копия лок. переменной A
    C = func1().Print("temp");
    C.Print("C");
}


#include <iostream>
#include <string>
#include <algorithm>  // библиотека алгоритмов
#include <time.h>     // time(), clock()
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// структура для иници-ции параметров консоли и генератора случ. чисел
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;

/*
Создайте класс Book
Необходимо хранить данные:
Автор, Название, Год, Количество страниц.
Создать массив объектов в виде класса Library.
Вывести:
- сортировка списка книг: по названию, по году издания....
- список книг заданного автора;
- список книг, выпущенных заданным издательством;
- список книг, выпущенных после заданного года.
Используйте конструктор и константные функции-члены (например, для отображения данных о книге и т.д.)
*/

class Book
{
private:
    string Autor;
    string Name;
    int Year;
    int Pages;
public:
    Book() : Autor("Неизвестно"), Name("Без имени"),
        Year(2000), Pages(1) {}
    Book(string _Autor, string _Name, int _Year, int _Pages)
        : Autor(_Autor), Name(_Name), Year(_Year), Pages(_Pages) {}
    Book(string _Autor, string _Name, int _Year)
        :Book() {
        SetAutor(_Autor);
        SetName(_Name);
        SetYear(_Year);
    }

    void SetAutor(const string& newAutor) { this->Autor = newAutor; }
    void SetName(const string& newName) { Name = newName; }
    void SetYear(int newYear) {
        if (newYear >= 0 && newYear <= 2021) { Year = newYear; }
        else { cout << "Ошибка, не верный ввод года!\n"; }
    }
    bool SetPages(int newPages) {
        if (newPages <= 0 || newPages > 10'000) {
            cout << "Ошибка не верное коичество страниц!\n";
            return false;
        }
        else { Pages = newPages; return true; }
    }

    string GetAutor()const { return Autor; }
    string GetName()const { return Name; }
    int GetYear()const { return Year; }
    int GetPages() const { return Pages; }

    void Input() {
        cout << "Введите автора: ";
        string tmp;
        getline(cin, tmp);
        SetAutor(tmp);
        cout << "Введите название книги: ";
        getline(cin, tmp);
        SetName(tmp);

        cout << "Введите год книги: ";
        int temp;
        cin >> temp;
        SetYear(temp);
        bool a = false;
        while (a != true)
        {
            cout << "Введите количество страниц: ";
            cin >> temp;
            a = SetPages(temp);
        }
        cout << endl;
        cin.ignore();
    }
    void Print()const {
        cout << "Автор: " << GetAutor() << endl;
        cout << "Название книги: " << GetName() << endl;
        cout << "Год издания: " << GetYear() << endl;
        cout << "Количество страниц: " << GetPages() << endl;
    }
}; // class Book;

// класса Библиотеки для хранения и управлением массивом книг
class Library {
private:
    Book* Data; // рабочий указатель на дин. массив книг
    int   Size; // текущее кол-во книг в массиве Data
public:
    Library() : Data(), Size() {}
    Library(int _Size) : Library() { SetSize(_Size); }
    Library(Book* mas, int size) : Library() { SetBook(mas, size); }

    // конструктор копирования
    Library(const Library& obj) :Library() { *this = obj; } // this->operator(obj);
    //Library(const Library& obj) :Data(),Size() { *this = obj; }

    // оператор копирования, оператор присваивания
    // A = B; ==>
    // Library * const this = &A;
    // Library         obj  = B;
    Library& operator=(const Library& obj) {
        //this = nullptr; this - константный указатель
        SetBook(obj.GetBook(), obj.GetSize());
        return *this;
    }

    // деструктор - здесь ОБЯЗАТЕЛЕН!!! т.к. есть дин. объект - массив Data
    ~Library() { delete[] Data; }
    // set
    void SetSize(int newSize)
    {
        Book* temp = new Book[newSize]; // создание нового рабочего массива
        // определение минимального размера для
        //  копирования старых данных
        int minSize = (newSize > Size) ? Size : newSize; // тернарный оператор
        //if (newSize > Size) { minSize = Size; }
        //else { minSize = newSize; }
        // цикл копирования старых данных
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i]; // копирование из Data в temp
        }
        delete[] Data; // удаление старых данных
        Data = temp;   // запоминаем адрес нового рабочего массива
        Size = newSize;
    }
    void SetBook(const Book* mas, int size)
    {
        //Size = 0; // Если не хотим копировать старые книги
        SetSize(size);
        for (int i = 0; i < size; i++) { Data[i] = mas[i]; }
    }
    void SetAt(Book book, int index) // Library[index] = book;
    {
        if (index >= 0 && index < Size) { Data[index] = book; }
        else { cout << "Error! Incorrect index!\n"; }
    }
    // get
    int GetSize()const { return Size; }
    const Book* GetBook()const { return Data; }

    Book GetAt(int index)const    // Book book = Library[index];
    {
        if (index >= 0 && index < Size) { return Data[index]; }
        cout << "Error! Incorrect index!\n";
        //return ?????;
        throw "Exception! Incorrect index";
    }
    // 
    void Input()
    {
        int temp;
        cout << "Сколько книг вы хотите ввести: ";
        cin >> temp; SetSize(temp);
        cin.ignore();
        for (int i = 0; i < GetSize(); i++)
        {
            Data[i].Input();
        }
    }
    void Print()
    {
        for (int i = 0; i < GetSize(); i++)
        {
            cout << i + 1 << ":" << endl;
            Data[i].Print();
            cout << endl;
        }
    }
    void PrintAutor(string _Autor)
    {
        for (int i = 0; i < GetSize(); i++)
        {
            if (Data[i].GetAutor() == _Autor) { Data[i].Print(); }
        }
    }
    // сортировка по авторам
    void Sort() {
        bool CmpBookAutor(Book b1, Book b2); // локальный прототип ф-ции
        // if(Data[j] < Data[j-1])
        sort(Data, Data + Size, CmpBookAutor);
    }
    // сортировка по названию
    void SortName() {
        sort(Data, Data + Size,
            // лямбда-функция, безымянная функция для сравенния двух
            //  книг по названию
            [](Book b1, Book b2) {return (b1.GetName() < b2.GetName()); }
        );
    }
    // сортировка по году издания в обратном направлении - по убыванию
    void SortYear() {
        /*auto t = 1; ==> int t = 1;
        auto d = 1.23; ==> double d = 1.23;
        auto q; // ошибка
        */
        auto cmpFunc =
            [](auto a, auto b) {return a.GetYear() > b.GetYear(); };
        sort(Data, Data + Size, cmpFunc);
    }

}; // class Library

// if(b1.Author < b2.Author) ==> True
bool CmpBookAutor(Book b1, Book b2) {
    // 1 вариант
    //if (b1.GetAutor() < b2.GetAutor()) { return true; }
    //else                               { return false; }
    // 2 вариант
    //return (b1.GetAutor() < b2.GetAutor()) ? true : false;
    // 3 вариант
    return (b1.GetAutor() < b2.GetAutor());
}

int main()
{
    /*Book obj;
    obj.Input();
    obj.Print();
    cout << endl;
    Book obj2("Януш", "Одиночество в сети", 2020, 500);
    obj2.Print();*/

    Library library(5);
    //library.Print();

    library.Input();
    library.Print();
    library.PrintAutor("Pupkin");

    cout << "\n---------------------\n";
    library.Sort(); // сортировка по авторам
    library.Print();
    cout << "\n---------------------\n";
    library.SortName(); // сортировка по названиям книг
    library.Print();
    cout << "\n---------------------\n";
    library.SortYear(); // сортировка по году издания
    library.Print();
}
