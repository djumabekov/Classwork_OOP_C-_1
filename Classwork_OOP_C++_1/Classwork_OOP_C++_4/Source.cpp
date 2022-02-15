#include <iostream>
#include <string>
#include <algorithm>  // ���������� ����������
#include <time.h>     // time(), clock()
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

    void SetAutor(const string& newAutor) { this->Autor = newAutor; }
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
        Book* temp = new Book[newSize]; // �������� ������ �������� �������
        // ����������� ������������ ������� ���
        //  ����������� ������ ������
        int minSize = (newSize > Size) ? Size : newSize; // ��������� ��������
        //if (newSize > Size) { minSize = Size; }
        //else { minSize = newSize; }
        // ���� ����������� ������ ������
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i]; // ����������� �� Data � temp
        }
        delete[] Data; // �������� ������ ������
        Data = temp;   // ���������� ����� ������ �������� �������
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
        //return ?????;
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
    // ���������� �� �������
    void Sort() {
        bool CmpBookAutor(Book b1, Book b2); // ��������� �������� �-���
        // if(Data[j] < Data[j-1])
        sort(Data, Data + Size, CmpBookAutor);
    }
    // ���������� �� ��������
    void SortName() {
        sort(Data, Data + Size,
            // ������-�������, ���������� ������� ��� ��������� ����
            //  ���� �� ��������
            [](Book b1, Book b2) {return (b1.GetName() < b2.GetName()); }
        );
    }
    // ���������� �� ���� ������� � �������� ����������� - �� ��������
    void SortYear() {
        /*auto t = 1; ==> int t = 1;
        auto d = 1.23; ==> double d = 1.23;
        auto q; // ������
        */
        auto cmpFunc =
            [](auto a, auto b) {return a.GetYear() > b.GetYear(); };
        sort(Data, Data + Size, cmpFunc);
    }

}; // class Library

// if(b1.Author < b2.Author) ==> True
bool CmpBookAutor(Book b1, Book b2) {
    // 1 �������
    //if (b1.GetAutor() < b2.GetAutor()) { return true; }
    //else                               { return false; }
    // 2 �������
    //return (b1.GetAutor() < b2.GetAutor()) ? true : false;
    // 3 �������
    return (b1.GetAutor() < b2.GetAutor());
}

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

    cout << "\n---------------------\n";
    library.Sort(); // ���������� �� �������
    library.Print();
    cout << "\n---------------------\n";
    library.SortName(); // ���������� �� ��������� ����
    library.Print();
    cout << "\n---------------------\n";
    library.SortYear(); // ���������� �� ���� �������
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
* ����������� �����������
* ����������
* �����������, ���� � ������ ���� ������������ ������, ������������ ������
*/
class Mas
{
public:
    int* data; // ��������� �� ������
    int size;   // ����� �������

    Mas() :data(), size() {} // Mas():data(nullptr),size(0){}
    Mas(int newSize) // : Mas()
    {
        data = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            data[i] = RAND(1, 20);
        }
        size = newSize;
    }
    // ����������� ����������� - ���������� ����� � ������ ���� ��������� �� ������������ ������
    // Mas B = A; ==> Mas B(A);
    // B - ������� ������, this
    // A - obj - �������� ��� �����������
    Mas(const Mas& obj) {
        data = new int[obj.size]; // ����� ������ ��� �����
        for (int i = 0; i < obj.size; i++) {
            data[i] = obj.data[i]; // ����������� ������ �� obj � ������� ������
        }
        size = obj.size;
    }
    // ����������� ����������� �� �����������
    //  ��������� �����������
    /*Mas(const Mas& obj) {
      data = obj.data;
      size = obj.size;
    }*/

    // �������� ����������� - ����������� ������
    // A = B; ==> A.operator=( B );
    // A - ������� ������, ���� ����������
    // B - obj, �������� ��� �����
    Mas& operator=(const Mas& obj) {
        delete[]data; // ������� ������ ������, ������ ������
        data = new int[obj.size]; // ����� ������� ������
        for (int i = 0; i < obj.size; i++) {
            this->data[i] = obj.data[i]; // �����������
        }
        size = obj.size; // ���������� ������
        return *this; // ������� ������ �� ������� ������
    }
    /*void setSize(int size) { this->size = size;} */


    // ���������� - ���������� ����� � ������ ���� ��������� �� ������������ ������
    ~Mas() { delete[]data; }

    // A.Print("Massiv A"); ==> Massiv A[4]: 1 2 3 4
    Mas& Print(string title = "") {
        cout << title
            << "(" << data << ")" // ����� ������� data, ���������
            << ":[" << size << "] "; // ����� �������
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
    return A; // ������� ����� ������������ �����������
} // A.~Mas()

int main()
{
    Mas A(10);
    A.Print("A");
    // ����������� ����� �����������
    Mas B = A; // ������� ����� ������������ �����������
    B.Print("B");

    A.data[0] = 999;
    A.Print("A");
    B.Print("B");

    Mas C(B); // ����� ��������� � ������������ �����������
    C.Print("C");

    C = A; // �������� �����������
    B = C; // �������� �����������
    C = B; // �������� �����������

    //C = func1(); // func1 �� ��������� ������ ��� ����� ���. ���������� A
    C = func1().Print("temp");
    C.Print("C");
}


#include <iostream>
#include <string>
#include <algorithm>  // ���������� ����������
#include <time.h>     // time(), clock()
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

    void SetAutor(const string& newAutor) { this->Autor = newAutor; }
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

    // ����������� �����������
    Library(const Library& obj) :Library() { *this = obj; } // this->operator(obj);
    //Library(const Library& obj) :Data(),Size() { *this = obj; }

    // �������� �����������, �������� ������������
    // A = B; ==>
    // Library * const this = &A;
    // Library         obj  = B;
    Library& operator=(const Library& obj) {
        //this = nullptr; this - ����������� ���������
        SetBook(obj.GetBook(), obj.GetSize());
        return *this;
    }

    // ���������� - ����� ����������!!! �.�. ���� ���. ������ - ������ Data
    ~Library() { delete[] Data; }
    // set
    void SetSize(int newSize)
    {
        Book* temp = new Book[newSize]; // �������� ������ �������� �������
        // ����������� ������������ ������� ���
        //  ����������� ������ ������
        int minSize = (newSize > Size) ? Size : newSize; // ��������� ��������
        //if (newSize > Size) { minSize = Size; }
        //else { minSize = newSize; }
        // ���� ����������� ������ ������
        for (int i = 0; i < minSize; i++)
        {
            temp[i] = Data[i]; // ����������� �� Data � temp
        }
        delete[] Data; // �������� ������ ������
        Data = temp;   // ���������� ����� ������ �������� �������
        Size = newSize;
    }
    void SetBook(const Book* mas, int size)
    {
        //Size = 0; // ���� �� ����� ���������� ������ �����
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
    // ���������� �� �������
    void Sort() {
        bool CmpBookAutor(Book b1, Book b2); // ��������� �������� �-���
        // if(Data[j] < Data[j-1])
        sort(Data, Data + Size, CmpBookAutor);
    }
    // ���������� �� ��������
    void SortName() {
        sort(Data, Data + Size,
            // ������-�������, ���������� ������� ��� ��������� ����
            //  ���� �� ��������
            [](Book b1, Book b2) {return (b1.GetName() < b2.GetName()); }
        );
    }
    // ���������� �� ���� ������� � �������� ����������� - �� ��������
    void SortYear() {
        /*auto t = 1; ==> int t = 1;
        auto d = 1.23; ==> double d = 1.23;
        auto q; // ������
        */
        auto cmpFunc =
            [](auto a, auto b) {return a.GetYear() > b.GetYear(); };
        sort(Data, Data + Size, cmpFunc);
    }

}; // class Library

// if(b1.Author < b2.Author) ==> True
bool CmpBookAutor(Book b1, Book b2) {
    // 1 �������
    //if (b1.GetAutor() < b2.GetAutor()) { return true; }
    //else                               { return false; }
    // 2 �������
    //return (b1.GetAutor() < b2.GetAutor()) ? true : false;
    // 3 �������
    return (b1.GetAutor() < b2.GetAutor());
}

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

    cout << "\n---------------------\n";
    library.Sort(); // ���������� �� �������
    library.Print();
    cout << "\n---------------------\n";
    library.SortName(); // ���������� �� ��������� ����
    library.Print();
    cout << "\n---------------------\n";
    library.SortYear(); // ���������� �� ���� �������
    library.Print();
}
