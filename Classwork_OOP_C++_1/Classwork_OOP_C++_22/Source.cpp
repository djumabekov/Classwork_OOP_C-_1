#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
2. Описать класс билет:
- название маршрута,
- время-дата,
- стоимость.
А) *Создать экземпляр класса билет и написать для него методы:
- заполнения,
- печати,
- сохранения в файл,
- загрузки из файла.
Б) **Создать массив билетов и написать программу, позволяющую:
- динамически изменять размер массива;
- выводить список билетов на конкретную дату;
- выводить список билетов не дороже определенной суммы;
- печать всего списка билетов.
*/

class Tikket {
private:
    string NameRoute;
    string DataTime;
    float Cost;
public:
    Tikket() :NameRoute("no name"), DataTime("01.01.2000"), Cost(0) {}
    // set/get
    void SetNameRoute(string var) { NameRoute = var; }
    void SetDataTime(string var) { DataTime = var; }
    void SetCost(float var) { Cost = var; }
    string GetNameRoute()const { return NameRoute; }
    string GetDataTime()const { return DataTime; }
    float GetCost()const { return Cost; }

    // cout << Tikket
    friend ostream& operator<<(ostream& os, const Tikket& obj) {
        if (&os == &cout) {
            os << "Маршрут - " << obj.GetNameRoute() << endl;
            os << "Дата и время - " << obj.GetDataTime() << endl;
            os << "Стоимость проезда - " << obj.GetCost() << endl;
        }
        else {
            os << obj.GetNameRoute() << endl;
            os << obj.GetDataTime() << endl;
            os << obj.GetCost() << endl;
        }
        return os;
    }
    // cin >> Tikket
    friend istream& operator>>(istream& is, Tikket& obj) {
        if (&is == &cin) {
            string temp;
            cout << "Введите маршрут - ";
            getline(is, temp);
            obj.SetNameRoute(temp);
            cout << "Введите дату и время - ";
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            cout << "ВВедите стоимость проезда - ";
            is >> tmp;
            obj.SetCost(tmp);
            is.ignore();
        }
        else {
            string temp;
            getline(is, temp);
            obj.SetNameRoute(temp);
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            is >> tmp;
            obj.SetCost(tmp);
            is.ignore();
        }
        return is;
    }

    // метод для сохранения текущего объекта в файл
    bool Save(string FileName) {
        ofstream oFile; // файловый объект,поток для записи
        oFile.open(FileName); // открытие файла
        if (oFile.is_open()) { // проверка на открытие файла
            oFile << GetNameRoute() << endl;
            oFile << GetDataTime() << endl;
            oFile << GetCost() << endl;
            return true;
        }
        else { cout << "Ошибка создания файла!!!" << endl; return false; }
    }

    // метод для чтения текущего объекта из файла
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // файловый объект,поток для чтения
        if (!LFile.is_open()) {  // проверка на ошибку при открытии файла
            cout << "Ошибка открытия файла!!" << endl;
            return false;
        }
        string temp;
        getline(LFile, temp);
        SetNameRoute(temp);
        getline(LFile, temp);
        SetDataTime(temp);
        float tmp;
        LFile >> tmp;
        LFile.ignore();
        SetCost(tmp);
        return true;
    }
};


int main()
{
    Tikket A, B;
    cin >> A;
    cout << A << endl;
    A.Save("File1.txt"); // сохранить в файл
    B.Load("File1.txt"); // загрузить из фала
    cout << endl << B << endl;

    ofstream F1("File2.txt");
    F1 << A; // сохранить в файловый поток объект A
    F1.close();
    ifstream F2("File2.txt");
    Tikket C;
    F2 >> C; // прочесть из файлового потока в объект C
    cout << C << endl;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
2. Описать класс билет:
- название маршрута,
- время-дата,
- стоимость.
А) *Создать экземпляр класса билет и написать для него методы:
- заполнения,
- печати,
- сохранения в файл,
- загрузки из файла.
Б) **Создать массив билетов и написать программу, позволяющую:
- динамически изменять размер массива;
- выводить список билетов на конкретную дату;
- выводить список билетов не дороже определенной суммы;
- печать всего списка билетов.
*/

class Tikket {
private:
    string NameRoute;
    string DataTime;
    float Cost;
public:
    Tikket() :NameRoute("no name"), DataTime("01.01.2000"), Cost(0) {}
    // set/get
    void SetNameRoute(string var) { NameRoute = var; }
    void SetDataTime(string var) { DataTime = var; }
    void SetCost(float var) { Cost = var; }
    string GetNameRoute()const { return NameRoute; }
    string GetDataTime()const { return DataTime; }
    float GetCost()const { return Cost; }

    // cout << Tikket
    friend ostream& operator<<(ostream& os, const Tikket& obj) {
        if (&os == &cout) {
            os << "Маршрут - " << obj.GetNameRoute() << endl;
            os << "Дата и время - " << obj.GetDataTime() << endl;
            os << "Стоимость проезда - " << obj.GetCost() << endl;
        }
        else {
            os << obj.GetNameRoute() << endl;
            os << obj.GetDataTime() << endl;
            os << obj.GetCost() << endl;
        }
        return os;
    }
    // cin >> Tikket
    friend istream& operator>>(istream& is, Tikket& obj) {
        if (&is == &cin) {
            string temp;
            cout << "Введите маршрут - ";
            getline(is, temp);
            obj.SetNameRoute(temp);
            cout << "Введите дату и время - ";
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            cout << "ВВедите стоимость проезда - ";
            is >> tmp;
            obj.SetCost(tmp);
            is.ignore();
        }
        else {
            string temp;
            getline(is, temp);
            obj.SetNameRoute(temp);
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            is >> tmp;
            obj.SetCost(tmp);
            is.ignore();
        }
        return is;
    }

    // метод для сохранения текущего объекта в файл
    bool Save(string FileName) {
        ofstream oFile; // файловый объект,поток для записи
        oFile.open(FileName); // открытие файла
        if (oFile.is_open()) { // проверка на открытие файла
            oFile << GetNameRoute() << endl;
            oFile << GetDataTime() << endl;
            oFile << GetCost() << endl;
            return true;
        }
        else { cout << "Ошибка создания файла!!!" << endl; return false; }
    }

    // метод для чтения текущего объекта из файла
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // файловый объект,поток для чтения
        if (!LFile.is_open()) {  // проверка на ошибку при открытии файла
            cout << "Ошибка открытия файла!!" << endl;
            return false;
        }
        string temp;
        getline(LFile, temp);
        SetNameRoute(temp);
        getline(LFile, temp);
        SetDataTime(temp);
        float tmp;
        LFile >> tmp;
        LFile.ignore();
        SetCost(tmp);
        return true;
    }
};


int main()
{
    /*  Tikket A , B;
      cin >> A;
      cout << A << endl;
      A.Save("File1.txt"); // сохранить в файл
      B.Load("File1.txt"); // загрузить из фала
      cout << endl << B << endl;

      ofstream F1("File2.txt");
      F1 << A; // сохранить в файловый поток объект A
      F1.close();
      ifstream F2("File2.txt");
      Tikket C;
      F2 >> C; // прочесть из файлового потока в объект C
      cout << C << endl;
    */

    // 1 вариант
    //const int size = 4;
    //Tikket mas[size]; // статический массив

    /*// 2 вариант с динамическим массивом
    int size = 4;
    cout << "Enter tickets number: ";
    cin >> size; cin.ignore();
    Tikket* mas = new Tikket[size]; // создание динамического массива билетов
    for (int i = 0; i < size; i++) { // цикл чтения с консоли
      cin >> mas[i];
    }
    cout << endl;
    for (int i = 0; i < size; i++) { // цикл вывода на консоль
      cout << mas[i];
    }
    delete[]mas; // удаление динамического массива
    */
    // 3 вариант - vector<>
    //list<Tikket> mas; // массив типа std::vector<>
    vector<Tikket> mas; // массив типа std::vector<>
    int size;
    cout << "Enter size: ";
    (cin >> size).ignore();
    // 1)цикл добавления объектов в массив-вектор
    /*for (int i = 0; i < size; i++) {
      Tikket temp; // временный объект для ввода
      cin >> temp;
      mas.push_back(temp); // добавить в конец вектора - в конец массива
    }*/
    // 2)цикл иниц-ции массива с заданным размером
    mas.resize(size); // задать размер массива
    /*for (int i = 0; i < size; i++) {
      cin >> mas[i];
    }*/
    for (auto& t : mas) { cin >> t; } // аналогичный цикл для ввода с консоли

    cout << endl;
    for (int i = 0; i < mas.size(); i++) {
        cout << mas[i];
    }
    cout << endl;
    // аналогичный цикл в сокращенном виде С++
    for (auto t : mas) {
        cout << t;
    }
}


#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
2. Описать класс билет:
- название маршрута,
- время-дата,
- стоимость.
А) *Создать экземпляр класса билет и написать для него методы:
- заполнения,
- печати,
- сохранения в файл,
- загрузки из файла.
Б) **Создать массив билетов и написать программу, позволяющую:
- динамически изменять размер массива;
- выводить список билетов на конкретную дату;
- выводить список билетов не дороже определенной суммы;
- печать всего списка билетов.
*/

class Tikket {
private:
    string NameRoute;
    string DataTime;
    float Cost;
public:
    Tikket() :NameRoute("no name"), DataTime("01.01.2000"), Cost(0) {}
    // set/get
    void SetNameRoute(string var) { NameRoute = var; }
    void SetDataTime(string var) { DataTime = var; }
    void SetCost(float var) { Cost = var; }
    string GetNameRoute()const { return NameRoute; }
    string GetDataTime()const { return DataTime; }
    float GetCost()const { return Cost; }

    // cout << Tikket
    friend ostream& operator<<(ostream& os, const Tikket& obj) {
        if (&os == &cout) {
            os << "Маршрут - " << obj.GetNameRoute() << endl;
            os << "Дата и время - " << obj.GetDataTime() << endl;
            os << "Стоимость проезда - " << obj.GetCost() << endl;
        }
        else {
            os << obj.GetNameRoute() << endl;
            os << obj.GetDataTime() << endl;
            os << obj.GetCost() << endl;
        }
        return os;
    }
    // cin >> Tikket
    friend istream& operator>>(istream& is, Tikket& obj) {
        if (&is == &cin) {
            string temp;
            cout << "Введите маршрут - ";
            getline(is, temp);
            obj.SetNameRoute(temp);
            cout << "Введите дату и время - ";
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            cout << "ВВедите стоимость проезда - ";
            is >> tmp;
            obj.SetCost(tmp);
            is.ignore();
        }
        else {
            string temp;
            getline(is, temp);
            obj.SetNameRoute(temp);
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            is >> tmp;
            obj.SetCost(tmp);
            is.ignore();
        }
        return is;
    }

    // метод для сохранения текущего объекта в файл
    bool Save(string FileName) {
        ofstream oFile; // файловый объект,поток для записи
        oFile.open(FileName); // открытие файла
        if (oFile.is_open()) { // проверка на открытие файла
            oFile << GetNameRoute() << endl;
            oFile << GetDataTime() << endl;
            oFile << GetCost() << endl;
            return true;
        }
        else { cout << "Ошибка создания файла!!!" << endl; return false; }
    }

    // метод для чтения текущего объекта из файла
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // файловый объект,поток для чтения
        if (!LFile.is_open()) {  // проверка на ошибку при открытии файла
            cout << "Ошибка открытия файла!!" << endl;
            return false;
        }
        string temp;
        getline(LFile, temp);
        SetNameRoute(temp);
        getline(LFile, temp);
        SetDataTime(temp);
        float tmp;
        LFile >> tmp;
        LFile.ignore();
        SetCost(tmp);
        return true;
    }
};

class ArrTicket {
private:
    vector <Tikket> mas;
public:
    ArrTicket() : mas() {}   //without mas()
    ArrTicket(Tikket* arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            mas.push_back(arr[i]);
        }
    }
    void SetMas(Tikket* arr, int size)
    {
        mas.clear();
        for (int i = 0; i < size; i++)
        {
            mas.push_back(arr[i]);
        }
    }

    vector<Tikket> GetMas() const { return mas; }
    Tikket operator[] (int index) const
    {
        return mas[index];
    }

    friend ostream& operator<< (ostream& os, const ArrTicket& obj)
    {
        for (int i = 0; i < obj.GetMas().size(); i++)
        {
            os << obj[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, ArrTicket& obj) {
        cout << "Enter number of tickets : ";
        int tmp;
        (is >> tmp).ignore();
        obj.mas.resize(tmp);
        for (int i = 0; i < tmp; i++)
        {
            is >> obj.mas[i];
        }
        return is;
    }
};

int main()
{
    ArrTicket A;
    cin >> A;
    cout << "Your ticket : \n" << A;

}

