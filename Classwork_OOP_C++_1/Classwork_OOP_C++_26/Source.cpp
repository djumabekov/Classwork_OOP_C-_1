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

int main()
{
    random_device rd; // ���������� ��������� ����. �����
    // ������ ������
    std::set<int> data({ 30,2,9,4,70,9,3,7,4,23 }); // ����-��� �������
    // 1) ���������� ������ ������ ����������
    //data.clear(); - �������� ������ �� ������� ��������
    for (int i = 0; i < 10; i++) {
        int temp = rd() % 20 + 1; // [1;20]
        cout << temp << " ";
        data.insert(temp); // �������� � ������ ����� ��������
    }
    cout << endl;
    // 2) ����� ����� ������ �� �����
    for (auto a : data) { cout << a << " "; }
    cout << endl;
    // 3) ����� ������ ������ ���� set<>
    cout << "Enter value for search: ";
    int temp;
    cin >> temp;
    // �������� ��� ���� set<int> - ������ ����������� ���������
    //set<int>::iterator itFind = data.find(temp);
    auto itFind = data.find(temp); // auto = set<int>::iterator
    if (itFind != end(data)) { // ������� � ������
        cout << "Value is found: ";
        cout << *itFind << endl; // *itFind - ������ � �������� ����������
        // �� ������� ��������� itFind
        // std::distance() - �-��� ���������� ���������� ����� �����������
        // dist = itFind - begin(data);
        int dist = distance(begin(data), itFind);
        cout << "Distance at begin (index): " << dist << endl;
    }
    else { // �� �������
        cout << "Error: this value is not found in data!" << endl;
    }
}

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

class Sample {
public:
    char S;
    Sample() : S(RAND('a', 'z')) {}
    Sample(char v) :S(v) {}
    // ���������� ��������� ������ - ��� STL �����������
    bool operator<(const Sample& obj)const {
        return this->S < obj.S;
    }
    friend ostream& operator<<(ostream& os, const Sample& obj) {
        return os << obj.S;
    }
};

using MyType = typename set<Sample>;      // ������� ��� ������
using MyIter = typename MyType::iterator; // �������� ��� ����

int main()
{
    MyType data;
    for (int i = 0; i < 10; i++) {
        //Sample A;
        //cout << A;
        //data.insert(A);
        data.insert(Sample()); // Sample() - �������� ����������� ������� ���� Sample
    }
    // insert_iterator<> - ���������� ��������
    insert_iterator<MyType> ins_it(data, begin(data));
    Sample A('S'), B('E');
    *ins_it = A;
    ++ins_it; // �������� �� ����������� ��������� ������
    *ins_it = B;

    // �������� ��� ������ ������
    ostream_iterator<Sample> os_it(cout, ", ");
    copy(begin(data), end(data), os_it); // copy(data, os_it);
    // cout << data;
    cout << endl;
    // ����������� ������ copy()
    ostream_iterator<Sample> os_it2(cout, "; ");
    for_each(begin(data), end(data),
        [&os_it2](auto a) { *os_it2 = a; ++os_it2; });
    cout << endl;
    // ��������� ��������
    // rbegin(), rend() - �-��� ������ � ����� ���������� ���
    //  ���������� ���������
    MyType::reverse_iterator rit = rbegin(data);
    for (; rit != rend(data); ++rit) {
        cout << *rit << "  ";
    }
    cout << endl;
    int a = int();
    os_it2 = ostream_iterator<Sample>(cout, ": ");
    copy(rbegin(data), rend(data), os_it2);
}
/*
template <class T = Cat>
void func1(T a) {
  T temp = 0; // ??? Cat = 0
  T temp = T(0); // ?? Cat(0)
  T temp = T(); // !!!!! temp = Cat()
}
*/


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
        cout << itFind->first << " - " << itFind->second << endl;
        // ������������� �������������� ��������� [] 
        cout << temp << " - " << en_ru_diction[temp] << endl;
    }
    else {
        cout << "Error: this word is not found!\n";
    }
}

