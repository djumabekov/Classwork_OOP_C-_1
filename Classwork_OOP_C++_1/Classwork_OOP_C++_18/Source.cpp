
#include <iostream>
#include <initializer_list>
#include <time.h>
#include <Windows.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// �������� ��� ��������� ������� � ���������� ��������� � ������ "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// ������
//  ������������� ������

// ������ ��������� ������ ���� ������
template <class T>
struct Element
{
    Element<T>* next;   // ��������� �� ��������� �������
    T data;             // �������� ������
    //
    Element() : next(), data() {}
    Element(T data, Element<T>* next = nullptr)
        :data(data), next(next) {}
    Element<T>* GetNext() { return next; }
    void SetNext(Element<T>* other) { next = other; }
    void SetData(T data) { this->data = data; }
    T GetData() { return data; }
};

// ������ ������ ������������ ������
template <class T>
class List
{
private:
    Element<T>* head, * tail; // ��������� �� �������� � ������� �������� ������
    int cnt; // ������� ���������� ����� � ������
public:
    List() : head(), tail(), cnt() {}
    List(const T& val) :List() {
        AddHead(val);
    } // ����-��� ����� ���������
    List(initializer_list<T> mas) {
        for (auto a : mas) { AddTail(a); }
        //for (T a : mas) { AddTail(a); }


    }// ����-��� �������
    List(const T* mas, int size) : List() {
        for (int i = 0; i < size; i++)
        {
            AddTail(mas[i]);
        }
    }  // ����-��� ��������
    List(const List& obj);
    List& operator=(const List& obj);

    ~List() { Clear(); }
    // ������� ���� - ������� ���� ��������� ������
    void Clear() {
        while (cnt) {
            DeleteHead();
        }
    }

    // �������� ����� ������� � ������ ������
    //  ������ ������ list<T>::push_front();
    void AddHead(const T& val);

    // �������� ����� ������� � ����� ������
    //  ������ ������ list<T>::push_back();
    void AddTail(const T& val);

    // ������� �������� �������
    //  ������ ������ list<T>::pop_front();
    void DeleteHead();

    // ������� ��������� �������
    //  ������ ������ list<T>::pop_back();
    void DeleteTail();

    // �������� ������� � ������ � ��������� ������� index
    void Insert(const T& val, int index);

    // �������� ������� ���-�� ����� � ������
    int GetCnt() const { return cnt; }

    // �������� �������� ���� �� ��������� �������
    T Get(int index = 0) {
        if (index > -1 && index < cnt) {
            Element<T>* other = head;
            for (int i = 0; i < index; i++) {
                other = other->next;
            }
            return other->data;
        }
        //throw exception("uncorrect index");
        throw 1;
    }
    // ������������� ��������� ���������� []
    T& operator[](int index) const {
        return Get(index);
    } // ��� ������
    T& operator[](int index) { return Get(index); } // ��� ������ (���������)

    // ����� ���� � �������� ���������
    // ���������� ������ ���������� ���� ��� -1 � ��������� ������
    int Search(const T& val) {
        Element<T>* temp = head;
        for (int i = 0; i < cnt; i++) {
            if (temp->data == val) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    template <class T>
    friend ostream& operator<<(ostream& os, const List<T>& obj);

};

// �������� ����� ������� � ������ ������
//  ������ ������ list<T>::push_front();
template <class T>
void List<T>::AddHead(const T& val)
{
    Element<T>* newel = new Element<T>(val);
    if (!cnt) {
        head = tail = newel;
    }
    else {
        newel->next = head;
        head = newel;
    }
    cnt++;
}

// �������� ����� ������� � ����� ������
//  ������ ������ list<T>::push_back();
template <class T>
void List<T>::AddTail(const T& val)
{
    Element<T>* newel = new Element<T>(val);
    if (!cnt) {
        head = tail = newel;
    }
    else {
        tail->next = newel;
        tail = newel;
    }
    cnt++;

}

// ������� �������� �������
//  ������ ������ list<T>::pop_front();
template <class T>
void List<T>::DeleteHead()
{
    if (cnt) {
        Element<T>* temp = head->next;
        delete head;
        head = temp;
        //cnt--;
        if (!--cnt) { tail = nullptr; }
    }
    else {
        cout << "\nlist's empty\n";
    }


}

// ������� ��������� �������
//  ������ ������ list<T>::pop_back();
template <class T>
void List<T>::DeleteTail()
{
    if (cnt) {
        Element<T>* temp = head;
        for (int i = 0; i < cnt - 2; i++) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        if (!--cnt) {
            head = tail = nullptr;
        }
        else {
            tail->next = nullptr;
        }
    }
    else {
        cout << "\n list's empty\n";
    }
}

// �������� ������� � ������ � ��������� ������� index
template <class T>
void List<T>::Insert(const T& val, int index)
{
    if (index == 0) { AddHead(val); }
    else if (index == cnt) { AddTail(val); }
    else if (index > 0 && index < cnt)
    {
        Element<T>* newel = new Element<T>(val);
        Element<T>* count = head;
        Element<T>* next = nullptr;
        for (int i = 0; i < index - 1; i++) {
            count = head->next;
        }
        next = count->next;
        count->next = newel;
        newel->next = next;
        //swap(newel, count->next);
        //count->next->next = newel;
        cnt++;
    }
    else {
        cout << "\nout of range\n";
        //throw out_of_range("out of range")
    }
}


template <class T>
ostream& operator<<(ostream& os, const List<T>& obj)
{
}

int main()
{
    List<string> A("First value");
    string s = "Second value";
    A.AddHead(s);
    s = "Third value";
    A.AddTail(s);
    s = "Fourth value";
    A.Insert(s, 1);
    cout << A << endl;
    cout << endl;
    for (int i = 0; i < A.GetCnt(); i++) {
        cout << i + 1 << ") " << A.Get(i) << endl;
        //cout << i+1 << ") " << A[i] << endl;
    }
}
