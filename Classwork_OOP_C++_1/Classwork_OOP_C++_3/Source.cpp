#include <iostream>
#include <string>
#include <time.h>// time(), clock()
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

    void SetAutor(const string& newAutor) { Autor = newAutor; }
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
        Book* temp = new Book[newSize];
        int minSize = (newSize > Size) ? Size : newSize;
        //if (newSize > Size) { minSize = Size; }
        //else { minSize = newSize; }
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i];
        }
        delete[] Data;
        Data = temp;
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
        //return ? ? ? ? ? ;
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
    //Sort();
}; // class Library

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
}
