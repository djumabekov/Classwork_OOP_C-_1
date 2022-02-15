#include <iostream>
#include <string>
#include <time.h>// time(), clock()
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// ��������� ��� �����-��� ���������� ������� � ���������� ����. �����
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;

/*
�������� ����� Book
���������� ������� ������:
�����, ��������, ���, ���������� �������.
������� ������ �������� � ���� ������ Library.
�������:
- ���������� ������ ����: �� ��������, �� ���� �������....
- ������ ���� ��������� ������;
- ������ ����, ���������� �������� �������������;
- ������ ����, ���������� ����� ��������� ����.
����������� ����������� � ����������� �������-����� (��������, ��� ����������� ������ � ����� � �.�.)
*/

class Book
{
private:
    string Autor;
    string Name;
    int Year;
    int Pages;
public:
    Book() : Autor("����������"), Name("��� �����"),
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
        else { cout << "������, �� ������ ���� ����!\n"; }
    }
    bool SetPages(int newPages) {
        if (newPages <= 0 || newPages > 10'000) {
            cout << "������ �� ������ ��������� �������!\n";
            return false;
        }
        else { Pages = newPages; return true; }
    }

    string GetAutor()const { return Autor; }
    string GetName()const { return Name; }
    int GetYear()const { return Year; }
    int GetPages() const { return Pages; }

    void Input() {
        cout << "������� ������: ";
        string tmp;
        getline(cin, tmp);
        SetAutor(tmp);
        cout << "������� �������� �����: ";
        getline(cin, tmp);
        SetName(tmp);

        cout << "������� ��� �����: ";
        int temp;
        cin >> temp;
        SetYear(temp);
        bool a = false;
        while (a != true)
        {
            cout << "������� ���������� �������: ";
            cin >> temp;
            a = SetPages(temp);
        }
        cout << endl;
        cin.ignore();
    }
    void Print()const {
        cout << "�����: " << GetAutor() << endl;
        cout << "�������� �����: " << GetName() << endl;
        cout << "��� �������: " << GetYear() << endl;
        cout << "���������� �������: " << GetPages() << endl;
    }
}; // class Book;

// ������ ���������� ��� �������� � ����������� �������� ����
class Library {
private:
    Book* Data; // ������� ��������� �� ���. ������ ����
    int   Size; // ������� ���-�� ���� � ������� Data
public:
    Library() : Data(), Size() {}
    Library(int _Size) : Library() { SetSize(_Size); }
    Library(Book* mas, int size) : Library() { SetBook(mas, size); }
    // ���������� - ����� ����������!!! �.�. ���� ���. ������ - ������ Data
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
        //Size = 0; // ���� �� ����� ���������� ������ �����
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
        cout << "������� ���� �� ������ ������: ";
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
    Book obj2("����", "����������� � ����", 2020, 500);
    obj2.Print();*/

    Library library(5);
    //library.Print();

    library.Input();
    library.Print();
    library.PrintAutor("Pupkin");
}
