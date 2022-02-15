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
//using MyType = typename multimap<string, string>;  // рабочий тип данных
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
    // 3) поиск по контейнеру en_ru_diction
    string temp;
    cout << "Enter english word: ";
    getline(cin, temp);
    MyIter itFind = en_ru_diction.find(temp); // поиск по ключу
    if (itFind != end(en_ru_diction)) {
        //cout << itFind->first << " - " << itFind->second << endl;
        // использование перегруженного оператора [] 
        //cout << temp << " - " << en_ru_diction[temp] << endl;

        // перебор контейнера en_ru_diction в рамках найденного
        //  ключа поиска (temp)
        for (int i = 0; i < en_ru_diction.count(temp); i++) {
            cout << itFind->first << " - " << itFind->second << endl;
            ++itFind; // переход к следующему значению,
                      //  закрепленному за ключем в temp
        }
    }
    else {
        cout << "Error: this word is not found!\n";
    }
}


