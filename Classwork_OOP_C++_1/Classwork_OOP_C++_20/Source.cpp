#include <iostream>
#include <initializer_list> // class std::initializer_list<>
#include <time.h>
#include <list>     // std::list<>
#include <iterator> // std::iterator
#include <algorithm> // for_each(), swap(), copy(), move()
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// �������� ��� ��������� ������� � ���������� ��������� � ������ "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// �-��� ����������� ����-���� ������
//  ���������� ����� ��������� ������
float func2(initializer_list<float> il) {
    float sum = 0;
    // 1 �������
    for (auto a : il) { sum += a; }
    return sum;
    // 2 �������
    //initializer_list<float>::iterator it = begin(il);
    auto it = begin(il);
    for (int i = 0; i < il.size(); i++) {
        sum += *it; // sum += il[i];
        ++it; // ��� ������ �� ����-���� ������ il
    }
    return sum;
    // 3 �������
    for (auto it = begin(il); it != end(il); ++it) {
        sum += *it;
    }
    return sum;
}
// ������
//  ������������ ������

int main()
{
    cout << func2({ 1.1f, 2.2f, 3.3f, 4.4f });
    // func2(initializer_list<float>{ 1.1f, 2.2f, 3.3f, 4.4f });

    //int mas[] = { 1,2,3,4,5,6,7,8 };
    list<int> A;
    list<int> B({ 1,2,3,4,5 }); // {1,2,3,4,5} ==> initializer_list<int>
    int cnt = 10;
    // ������� ���� ���������� ������ ����������
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
    // ����������� ������������ for(int a : A)
    list<int>::iterator it1; // �������� ��� ������ ���������
                             // ���������� ���� list<int>
    it1 = begin(B); // �������� ������ ����������� B (list<int>)
    for (; it1 != end(B); ++it1) {
        int a = *it1; // auto a = *it1;
        // *it1 - ��������������� ��������� - ������ � ��������
        //        �������� ����������
        cout << a << " ";
    }
    cout << endl;
    // ��� ���������� A
    // cbegin(A) - �������� ����������� �������� �� ������ ����������
    // cend(A) - �������� ����������� �������� �� ����� ����������
    void func1(int a); // ��������� �������� �-���
    for_each(cbegin(A), cend(A), func1);
    cout << endl;
    // ��� ���������� B
    int temp = 10;
    for_each(begin(B), end(B),
        [temp](int& a) { a *= temp; } // ����������, ������ �-���
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
        cout << "�������" << endl;
    }
    else {
        cout << "������ �������� � ������ ���!" << endl;
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
    T key;    // �������� ������
              // ��������� �� ��������, ������ � ������� ��������
    int cnt;  // ������� ����������
    Node<T>* parent;
    Node<T>* left, * right;
    Node() : parent(), left(), right(), key(), cnt() {}
    Node(T key) :Node() { this->key = key; }
};

template<class T>
class Tree
{
    Node<T>* root;    // ������
public:
    // ����������� �� ���������
    Tree() :root() {};

    // ����������� ����������� ������ ���������
    Tree(Node<T>* mas, size_t size);

    // �������� ������ ������
    Node<T>* GetRoot() { return root; }

    // ���������� ��������
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
    // ����������� ������ � ���������� ����
    void Print(Node<T>* pNode);
    // ����������� ����� ������
    void Print();

    // ����� ������ � ���� 
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
    }// ����� ��������

    Node<T>* Max(Node<T>* Node) {
        if (root == nullptr) { return nullptr; }
        Node<T>* temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }		// ����� ���������

    // �������� ����/�����
    //  (nullptr �������� ����� ������)
    void Del(Node<T>* Node = nullptr);
}; // class Tree


// ����������� ����������� ������ ���������
template<class T>
Tree<T>::Tree(Node<T>* mas, size_t size) {
}

// ���������� ��������
template<class T>
void Tree<T>::push(const T& val) {
}

// ����������� ������ � ���������� ����
template<class T>
void Tree<T>::Print(Node<T>* Node) {
}

// ����������� ����� ������
template<class T>
void Tree<T>::Print() {
}

// ����� ������ � ���� 
// Search(GetRoot(), key)
template<class T>
Node<T>* Tree<T>::Search(Node<T>* Node, const T& key)
{
}

// ����� ��������
template<class T>
Node<T>* Tree<T>::Min(Node<T>* Node) {
}

// ����� ���������
template<class T>
Node<T>* Tree<T>::Max(Node<T>* Node) {
}

// �������� ����/����� (nullptr �������� ����� ������)
template<class T>
void Tree<T>::Del(Node<T>* Node) {
}
