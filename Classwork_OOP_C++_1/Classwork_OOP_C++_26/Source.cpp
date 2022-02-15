#include <iostream>
#include <iomanip>
#include <fstream>    // поточный контейнер для работы с файловыми потоками
// контейнеры
#include <string>     // контейнер для строковых значений
#include <array>      // array<> - класс для работы с статическим массивом
#include <vector>     // vector<> - класс для работы с динамическим массивом
#include <list>       // list<> - класс двусвязного списка
#include <set>        // set<> - дерево аналогичное нашему tree<>
#include <map>        // map<>, multimap<> - асоциативные деревья, списки
// итераторы
#include <iterator>   // классы итераторов для работы с контейнерами
// алгоритмы
#include <algorithm>  // файл с шаблонными функциями STL C++
#include <random>     // классы STL для работы с случ. числами

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
    random_device rd; // аппаратный генератор случ. чисел
    // объект дерево
    std::set<int> data({ 30,2,9,4,70,9,3,7,4,23 }); // иниц-ция списком
    // 1) наполнение дерева новыми значениями
    //data.clear(); - очистить дерево от текущих значений
    for (int i = 0; i < 10; i++) {
        int temp = rd() % 20 + 1; // [1;20]
        cout << temp << " ";
        data.insert(temp); // добавить в дерево новое значение
    }
    cout << endl;
    // 2) вывод всего дерева на экран
    for (auto a : data) { cout << a << " "; }
    cout << endl;
    // 3) поиск внутри дерева типа set<>
    cout << "Enter value for search: ";
    int temp;
    cin >> temp;
    // итератор для типа set<int> - объект эмулирующий указатель
    //set<int>::iterator itFind = data.find(temp);
    auto itFind = data.find(temp); // auto = set<int>::iterator
    if (itFind != end(data)) { // найдено в дереве
        cout << "Value is found: ";
        cout << *itFind << endl; // *itFind - доступ к элементу контейнера
        // на который указавает itFind
        // std::distance() - ф-ция вычисления расстояния между итераторами
        // dist = itFind - begin(data);
        int dist = distance(begin(data), itFind);
        cout << "Distance at begin (index): " << dist << endl;
    }
    else { // не найдено
        cout << "Error: this value is not found in data!" << endl;
    }
}

#include <iostream>
#include <iomanip>
#include <fstream>    // поточный контейнер для работы с файловыми потоками
// контейнеры
#include <string>     // контейнер для строковых значений
#include <array>      // array<> - класс для работы с статическим массивом
#include <vector>     // vector<> - класс для работы с динамическим массивом
#include <list>       // list<> - класс двусвязного списка
#include <set>        // set<> - дерево аналогичное нашему tree<>
#include <map>        // map<>, multimap<> - асоциативные деревья, списки
// итераторы
#include <iterator>   // классы итераторов для работы с контейнерами
// алгоритмы
#include <algorithm>  // файл с шаблонными функциями STL C++
#include <random>     // классы STL для работы с случ. числами

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
    // перегрузка оператора меньше - для STL обязательно
    bool operator<(const Sample& obj)const {
        return this->S < obj.S;
    }
    friend ostream& operator<<(ostream& os, const Sample& obj) {
        return os << obj.S;
    }
};

using MyType = typename set<Sample>;      // рабочий тип данных
using MyIter = typename MyType::iterator; // итератор для него

int main()
{
    MyType data;
    for (int i = 0; i < 10; i++) {
        //Sample A;
        //cout << A;
        //data.insert(A);
        data.insert(Sample()); // Sample() - создание безымянного объекта типа Sample
    }
    // insert_iterator<> - вставочный итератор
    insert_iterator<MyType> ins_it(data, begin(data));
    Sample A('S'), B('E');
    *ins_it = A;
    ++ins_it; // движение по вставочному итератору вперед
    *ins_it = B;

    // итератор для потока вывода
    ostream_iterator<Sample> os_it(cout, ", ");
    copy(begin(data), end(data), os_it); // copy(data, os_it);
    // cout << data;
    cout << endl;
    // расшифровка работы copy()
    ostream_iterator<Sample> os_it2(cout, "; ");
    for_each(begin(data), end(data),
        [&os_it2](auto a) { *os_it2 = a; ++os_it2; });
    cout << endl;
    // реверсный итератор
    // rbegin(), rend() - ф-ции начала и конца контейнера для
    //  реверсного итератора
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
#include <fstream>    // поточный контейнер для работы с файловыми потоками
// контейнеры
#include <string>     // контейнер для строковых значений
#include <array>      // array<> - класс для работы с статическим массивом
#include <vector>     // vector<> - класс для работы с динамическим массивом
#include <list>       // list<> - класс двусвязного списка
#include <set>        // set<> - дерево аналогичное нашему tree<>
#include <map>        // map<>, multimap<> - асоциативные деревья, списки
// итераторы
#include <iterator>   // классы итераторов для работы с контейнерами
// алгоритмы
#include <algorithm>  // файл с шаблонными функциями STL C++
#include <random>     // классы STL для работы с случ. числами

#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  STL C++ - Standart Template Library C++
  map<>, multimap<>, set<>
*/
/*
Создать класс для работы с бинарным деревом, содержащим
англо-русский словарь.
*/
// map< type_Key, type_Data >;
using MyType = typename map<string, string>;  // рабочий тип данных
using MyIter = typename MyType::iterator;     // итератор для него

int main()
{
    MyType en_ru_diction; // анго-русский словарь
    MyType ru_en_diction; // русско-ангийский словарь

    while (true) {
        string en_word, ru_word;
        cout << "Enter english word: ";
        getline(cin, en_word);
        cout << "Enter translate on russian: ";
        getline(cin, ru_word);
        // выход из цикла
        if (en_word == "END" || ru_word == "END") { break; }
        // объект типа std::pair<> для работы с деревом типа map/multimap
        pair<string, string> pr(en_word, ru_word);
        en_ru_diction.insert(pr); // добавить ключ-данные в дерево map
        // для словоря ru_en_diction
        pr.first = ru_word;
        pr.second = en_word;
        // swap(pr.first, pr.second);
        // swap(pr.second, pr.first);
        ru_en_diction.insert(pr);
    }
    // 2) вывод словарей
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
    // 3) поиск по контейнеру en_ru_diction
    string temp;
    cout << "Enter english word: ";
    getline(cin, temp);
    MyIter itFind = en_ru_diction.find(temp); // поиск по ключу
    if (itFind != end(en_ru_diction)) {
        cout << itFind->first << " - " << itFind->second << endl;
        // использование перегруженного оператора [] 
        cout << temp << " - " << en_ru_diction[temp] << endl;
    }
    else {
        cout << "Error: this word is not found!\n";
    }
}

