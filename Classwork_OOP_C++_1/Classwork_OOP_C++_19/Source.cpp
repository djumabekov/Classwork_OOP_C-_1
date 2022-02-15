#include <iostream>
#include <initializer_list>
#include <time.h>
#include "List2.h"
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// структра для настройки консоли с глобальной переменой с именем "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// Списки
//  Двусвязанный список

int main()
{
    TList<string> A("First value");
    string s = "Second value";
    A.AddHead(s);
    s = "Third value";
    A.AddTail(s);
    s = "Fourth value";
    A.Insert(s, 1);
    cout << A << endl;
    cout << endl;
    for (int i = 0; i < A.GetCnt(); i++) {
        cout << i + 1 << ") " << A.GetAt(i) << endl;
        //cout << i+1 << ") " << A[i] << endl;
    }
}



/*
 List2.h
*/
#pragma once
#include <iostream>
#include <string>  // для string
using namespace std;

/*
 Шаблонный двусвязанный список
  class TList
*/

template <class T>
struct Node {
    // Область полезных данных
    T Data;

    // область ссылок на связанные элементы
    Node<T>* pNext; // Указатель на следующий элемент
    Node<T>* pPrev; // Указатель на предыдущий элемент
    //
    Node() : Data(), pNext(nullptr), pPrev(nullptr) {}
    Node(T data) : Data(data), pNext(), pPrev() {} //Указатели на нулевые адреса
    Node(T data, Node<T>* next, Node<T>* prev) //иницаилизация указателей 
        : Data(data), pNext(next), pPrev(prev) {}

    Node<T>* GetNext() { return pNext; }
    void  SetNext(Node<T>* next) { pNext = next; }
    Node<T>* GetPrev() { return pPrev; }
    void  SetPrev(Node<T>* prev) { pPrev = prev; }
};

template <class T>
class TList {

    Node<T>* Head; // голова списка
    Node<T>* Tail; // хвост списка
    int       cnt;  // кол-во элементов в списке

public:
    TList() : Head(nullptr), Tail(nullptr), cnt() {}
    TList(const T& Val) : TList() { AddHead(Val); } // AddTail(Val);
    TList(const TList<T>& V) : TList() { *this = V; }
    TList<T>& operator=(const TList<T>& V)
    {
        Node<T>* temp = V.Head;
        for (int i = 0; i < V.cnt; i++)
        {
            //AddTail(temp->Data);  //Первый вариант
            //temp = temp->pNext;   //Быстрее чем второй вариант
            AddTail(V.GetAt(i));    //Второй вариант
        }
        return *this;
    }
    ~TList() { Clear(); }

    Node<T>* GetNode(int idx)
    {
        if (idx < 0 || idx >= cnt) { return nullptr; }
        Node<T>* temp = GetHead();
        for (int i = 0; i < idx; i++)
        {
            temp = temp->pNext;
        }
        return temp;
    }

    Node<T>* GetHead() { return Head; }
    Node<T>* GetTail() { return Tail; }
    Node<T>* NewNode(const T& data) { return new Node<T>(data); }

    bool isEmpty() { return Head == nullptr; }

    void AddTail(const T& data)  // void push_back(const T& data);
    {
        Node<T>* newNode = NewNode(data); //создаем новый узел
        if (isEmpty()) { Head = Tail = newNode; }
        else
        {
            Tail->pNext = newNode;
            newNode->pPrev = Tail;
            Tail = newNode;
        }
        cnt++;
    }
    void AddHead(const T& data)  // void push_front(const T& data);
    {
        Node<T>* newNode = NewNode(data);
        if (isEmpty()) { Head = Tail = newNode; }
        else
        {
            Head->pPrev = newNode;
            newNode->pNext = Head;
            Head = newNode;
        }
        cnt++;
    }
    void Insert(const T& data, int idx)
    {
        if (idx == 0) { AddHead(data); }
        else if (idx == cnt) { AddTail(data); }
        else
        {
            Node<T>* Next = GetNode(idx);
            if (Next != nullptr)
            {
                Node<T>* newNode = NewNode(data);
                Node<T>* Prev = Next->pPrev;

                newNode->pNext = Next;
                newNode->pPrev = Prev;
                Prev->pNext = newNode;
                Next->pPrev = newNode;
                cnt++;
            }
            else { cout << "Error! Out of range!\n"; }
        }
    }
    void Delete(int idx)
    {
        Node<T>* toDelete = GetNode(idx);
        if (toDelete)
        {
            Node<T>* Prev = toDelete->pPrev;
            Node<T>* Next = toDelete->pNext;
            if (Prev) { Prev->pNext = Next; }
            else { Head = Next; }
            if (Next) { Next->pPrev = Prev; }
            else { Tail = Prev; }
            delete toDelete;
            cnt--;
        }
        else { cout << "Error! Out of range!\n"; }
    }
    T& GetAt(int idx)
    {
        Node<T>* temp = GetNode(idx);
        if (temp) { return temp->Data; }
        throw "Exception! out of range!";
    }
    //const T&   operator[](int idx) const;
    //T&   operator[](int idx);
    int  GetCnt()const { return cnt; }
    int  Search(const T& data)
    {
        Node<T>* temp = Head;
        for (int i = 0; i < cnt; i++)
        {
            if (temp->Data == data) { return i; }
            temp = temp->pNext;
        }
        return -1;
    }
    void Clear() { while (Head) { Delete(0); } }

}; // class TList


template <class T>
ostream& operator<<(ostream& os, TList<T>& obj)
{
    cout << "List size: " << obj.GetCnt() << endl;
    for (int i = 0; i < obj.GetCnt(); i++)
    {
        os << obj.GetAt(i) << endl;
    }
    cout << endl;
    return os;
}


