#include <iostream>
#include <initializer_list> // class std::initializer_list<>
#include <time.h>
#include <list>     // std::list<>
#include <iterator> // std::iterator
#include <algorithm> // for_each(), swap(), copy(), move()
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// структра для настройки консоли с глобальной переменой с именем "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// ф-ция принимающая иниц-нный список
//  возвращает сумму элементов списка
float func2(initializer_list<float> il) {
    float sum = 0;
    // 1 вариант
    for (auto a : il) { sum += a; }
    return sum;
    // 2 вариант
    //initializer_list<float>::iterator it = begin(il);
    auto it = begin(il);
    for (int i = 0; i < il.size(); i++) {
        sum += *it; // sum += il[i];
        ++it; // шаг вперед по иниц-ному списку il
    }
    return sum;
    // 3 вариант
    for (auto it = begin(il); it != end(il); ++it) {
        sum += *it;
    }
    return sum;
}
// Списки
//  Двусвязанный список

int main()
{
    cout << func2({ 1.1f, 2.2f, 3.3f, 4.4f });
    // func2(initializer_list<float>{ 1.1f, 2.2f, 3.3f, 4.4f });

    //int mas[] = { 1,2,3,4,5,6,7,8 };
    list<int> A;
    list<int> B({ 1,2,3,4,5 }); // {1,2,3,4,5} ==> initializer_list<int>
    int cnt = 10;
    // простой цикл заполнения списка значениями
    for (int i = 0; i < cnt; i++) {
        A.push_back(RAND(1, 10));
    } // i = cnt
    //
    /*for (int i = 0; i < cnt; i++) {
      cout << A[i] << " ";
    }*/
    for (int a : A) { // for (auto a : A)
        cout << a << " ";
    }
    cout << endl;
    // расшифровка сокращенного for(int a : A)
    list<int>::iterator it1; // итератор для обхода элементов
                             // контейнера типа list<int>
    it1 = begin(B); // получить начало контейнейра B (list<int>)
    for (; it1 != end(B); ++it1) {
        int a = *it1; // auto a = *it1;
        // *it1 - разыменовывание итератора - доступ к текущему
        //        элементу контейнера
        cout << a << " ";
    }
    cout << endl;
    // для контейнера A
    // cbegin(A) - получить константный итератор на начало контейнера
    // cend(A) - получить константный итератор на конец контейнера
    void func1(int a); // локальный прототип ф-ции
    for_each(cbegin(A), cend(A), func1);
    cout << endl;
    // для контейнера B
    int temp = 10;
    for_each(begin(B), end(B),
        [temp](int& a) { a *= temp; } // безымянная, лямбда ф-ция
    );
    for (auto b : B) { cout << b << " "; }
    cout << endl;
}

void func1(int a) {
    cout << a << ", ";
}

#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <time.h>
using namespace std;
#include "BTree.h"  // class tree


int main()
{
    Tree<int> t1;
    t1.push(5);
    t1.push(4);
    t1.push(10);
    t1.push(1);
    t1.push(11);
    t1.print();

    cout << "Vvedite chislo dla poiska: ";
    int s;
    cin >> s;
    if (t1.Search(t1.GetROOT(), s)) {
        cout << "Найдено" << endl;
    }
    else {
        cout << "Таково значения в дереве нет!" << endl;
    }
}



/*
  BTree.h
  template<class T>
  class Tree;
*/
#pragma once

template<class T>
struct Node {
    T key;    // Полезные данные
              // Указатели на родителя, левого и правого потомков
    int cnt;  // счетчик повторений
    Node<T>* parent;
    Node<T>* left, * right;
    Node() : parent(), left(), right(), key(), cnt() {}
    Node(T key) :Node() { this->key = key; }
};

template<class T>
class Tree
{
    Node<T>* root;    // Корень
public:
    // Конструктор по умолчанию
    Tree() :root() {};

    // Конструктор принимающий массив элементов
    Tree(Node<T>* mas, size_t size);

    // Получить корень дерева
    Node<T>* GetRoot() { return root; }

    // Добавление элемента
    // add();
    void push(const T& val)
    {
        Node<T>* temp = new Node<T>(val);
        if (root == nullptr) { root = temp; }
        else {
            // while (temp)
            Node<T>* temp2 = root;
            Node<T>* pref = nullptr;
            while (temp2 != nullptr) {
                pref = temp2;
                if (val < temp2->key) { temp2 = temp2->left; }
                else if (val > temp2->key) { temp2 = temp2->right; }
                // val == temp2->key
                else {
                    temp2->cnt++;
                    delete temp;
                    return;
                }
            }
            if (val < pref->key) { pref->left = temp; }
            else { pref->right = temp; }
            temp->parent = pref;
        }
    }
    // Отображение дерева с начального узла
    void Print(Node<T>* pNode);
    // Отображение всего дерева
    void Print();

    // Поиск данных в узле 
    Node<T>* Search(Node<T>* Node, const T& key)
    {
        Node<T>* temp = root;
        while (temp != nullptr) {
            if (key < temp->key) { temp = temp->left; }
            else if (key > temp->key) { temp = temp->right; }
            else
            { // key == temp->key
              //return temp;
                break;
            }
        }
        //return nullptr;
        return temp;
    }
    Node<T>* Min(Node<T>* Node)
    {
        if (root == nullptr) { return nullptr; }
        Node<T>* temp = root;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }// Поиск минимума

    Node<T>* Max(Node<T>* Node) {
        if (root == nullptr) { return nullptr; }
        Node<T>* temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }		// Поиск максимума

    // Удаление узла/ветки
    //  (nullptr удаление всего дерева)
    void Del(Node<T>* Node = nullptr);
}; // class Tree


// Конструктор принимающий массив элементов
template<class T>
Tree<T>::Tree(Node<T>* mas, size_t size) {
}

// Добавление элемента
template<class T>
void Tree<T>::push(const T& val) {
}

// Отображение дерева с начального узла
template<class T>
void Tree<T>::Print(Node<T>* Node) {
}

// Отображение всего дерева
template<class T>
void Tree<T>::Print() {
}

// Поиск данных в узле 
// Search(GetRoot(), key)
template<class T>
Node<T>* Tree<T>::Search(Node<T>* Node, const T& key)
{
}

// Поиск минимума
template<class T>
Node<T>* Tree<T>::Min(Node<T>* Node) {
}

// Поиск максимума
template<class T>
Node<T>* Tree<T>::Max(Node<T>* Node) {
}

// Удаление узла/ветки (nullptr удаление всего дерева)
template<class T>
void Tree<T>::Del(Node<T>* Node) {
}
