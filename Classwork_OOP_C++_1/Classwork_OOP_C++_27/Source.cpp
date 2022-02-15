#include <iostream>
#include <iomanip>
#include <fstream>    // �������� ��������� ��� ������ � ��������� ��������
// ����������
#include <string>     // ��������� ��� ��������� ��������
#include <array>      // array<> - ����� ��� ������ � ����������� ��������
#include <vector>     // vector<> - ����� ��� ������ � ������������ ��������
#include <list>       // list<> - ����� ����������� ������
#include <set>        // set<> - ������ ����������� ������ tree<>
#include <map>        // map<>, multimap<> - ������������ �������, ������
// ���������
#include <iterator>   // ������ ���������� ��� ������ � ������������
// ���������
#include <algorithm>  // ���� � ���������� ��������� STL C++
#include <random>     // ������ STL ��� ������ � ����. �������

#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  STL C++ - Standart Template Library C++
  map<>, multimap<>, set<>
*/
/*
������� ����� ��� ������ � �������� �������, ����������
�����-������� �������.
*/
// map< type_Key, type_Data >;
using MyType = typename map<string, string>;  // ������� ��� ������
//using MyType = typename multimap<string, string>;  // ������� ��� ������
using MyIter = typename MyType::iterator;     // �������� ��� ����

int main()
{
    MyType en_ru_diction; // ����-������� �������
    MyType ru_en_diction; // ������-��������� �������

    while (true) {
        string en_word, ru_word;
        cout << "Enter english word: ";
        getline(cin, en_word);
        cout << "Enter translate on russian: ";
        getline(cin, ru_word);
        // ����� �� �����
        if (en_word == "END" || ru_word == "END") { break; }
        // ������ ���� std::pair<> ��� ������ � ������� ���� map/multimap
        pair<string, string> pr(en_word, ru_word);
        en_ru_diction.insert(pr); // �������� ����-������ � ������ map
        // ��� ������� ru_en_diction
        pr.first = ru_word;
        pr.second = en_word;
        // swap(pr.first, pr.second);
        // swap(pr.second, pr.first);
        ru_en_diction.insert(pr);
    }
    // 2) ����� ��������
    //for(pair<string, string> a : en_ru_diction)
    //  cout << pair<string, string>;
    cout << endl;
    cout << "English - Russian\n";
    for (auto a : en_ru_diction) {
        cout << a.first << " - " << a.second << endl;
    }
    cout << endl;
    cout << "Russian - English\n";
    for (auto a : ru_en_diction) {
        cout << a.first << " - " << a.second << endl;
    }
    cout << endl;
    // 3) ����� �� ���������� en_ru_diction
    string temp;
    cout << "Enter english word: ";
    getline(cin, temp);
    MyIter itFind = en_ru_diction.find(temp); // ����� �� �����
    if (itFind != end(en_ru_diction)) {
        //cout << itFind->first << " - " << itFind->second << endl;
        // ������������� �������������� ��������� [] 
        //cout << temp << " - " << en_ru_diction[temp] << endl;

        // ������� ���������� en_ru_diction � ������ ����������
        //  ����� ������ (temp)
        for (int i = 0; i < en_ru_diction.count(temp); i++) {
            cout << itFind->first << " - " << itFind->second << endl;
            ++itFind; // ������� � ���������� ��������,
                      //  ������������� �� ������ � temp
        }
    }
    else {
        cout << "Error: this word is not found!\n";
    }
}


