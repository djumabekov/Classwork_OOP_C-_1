#include <iostream>
#include <initializer_list> // class std::initializer_list<>
#include <time.h>
#include <string>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
// структра для настройки консоли с глобальной переменой с именем "_"
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// ф-ция эмуляции потока симолов с неопределенным кол-вом симолов в потоке
char fun() {
    int prop = RAND(1, 10);
    if (prop == 5) {
        return '\0'; // конец потока
    }
    return RAND('A', 'Z');
}

// ф-ция эмуляции потока симолов с бесконечным кол-вом символов
char fun2() {
    return RAND('a', 'z');
}

int main()
{
    //vector<chat> str;
    string str;
    //
    while (true) {
        char c = fun();
        //string s = "Hello";
        if (c == '\0') { cout << "END" << endl; break; }
        //str += c; // накопление символов в строку str + '\0'
        str.push_back(c); // накопление символов в строку str
    }
    cout << "str: " << str << endl;
    // 2 - кол-во симолов в потоке известна
    str = ""; // 
    int count = 10; // ожидаем 10 символов
    str.resize(count, ' ');
    for (int i = 0; i < count; i++) {
        char c = fun2(); // накопление символов в строку str + '\0'
        //str += c;
        //str.push_back(c); // накопление символов в строку str
        str[i] = c;
    }
    cout << "str: " << str << endl;
    cout << str + " - " << str << endl;
}


#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
 Наследование

Задание 1
Создайте класс Student, который будет содержать
информацию о студенте.
С помощью механизма наследования, реализуйте
класс Aspirant (аспирант - студент, который
готовится к защите кандидатской работы)
производный от Student.
*/
class Aspirant;
// базовый класс Student
class Student
{
private:
    string Name;
protected:
    string endTime; // дата окончания учебы
public:
    string Diplom; // дипломная работа
    Student() {};
    Student(string name) : Name(name) {};
    void SetName(string var) { Name = var; }
    void SetEndTime(string var) { endTime = var; }
    void SetDiplom(string var) { Diplom = var; }
    string GetName() const { return Name; }
    string GetEndTime() const { return endTime; }
    string GetDiplom() const { return Diplom; }
    friend ostream& operator <<(ostream& os, const Student& obj)
    {
        os << "name : " << typeid(obj).name() << endl;
        os << "raw_name : " << typeid(obj).raw_name() << endl;
        os << "hash_code : " << typeid(obj).hash_code() << endl;
        os << "Name : " << obj.GetName() << endl;
        os << "EndTime : " << obj.GetEndTime() << endl;
        os << "Diplom : " << obj.GetDiplom() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Student& obj) {
        cout << "Enter Name : ";
        getline(is, obj.Name);
        cout << "Enter EndTime : ";
        getline(is, obj.endTime);
        cout << "Enter Diplom : ";
        getline(is, obj.Diplom);
        return is;
    }

    friend istream& operator>> (istream& is, Aspirant& obj);
};

// производный класс Aspirant
class Aspirant : public Student
{
    // + тело класса Student [Name]
private:
    string Diser; // диссертация
protected:
    string endTime; // дата окончания аспирантуры
public:
    //Aspirant():Student(){};
    Aspirant() {};
    Aspirant(string name) :Student(name) {};
    void SetDiser(string var) { Diser = var; }
    void SetendTime(string var) { endTime = var; }
    string GetDiser()const { return Diser; }
    string GetendTime()const { return endTime; }
    friend ostream& operator<<(ostream& os, const Aspirant& obj)
    {
        os << "name : " << typeid(obj).name() << endl;
        os << "raw_name : " << typeid(obj).raw_name() << endl;
        os << "hash_code : " << typeid(obj).hash_code() << endl;
        //os << (Student)obj << endl;
        os << (const Student&)obj << endl;
        os << "Diser : " << obj.Diser << endl;
        os << "End Time Aspirant :" << obj.endTime << endl;
        return os;
    }
    friend istream& operator>> (istream& is, Aspirant& obj) {
        // for Student
        //string temp;
        //cout << "Enter Name : ";
        //getline(is, temp);
        //obj.SetName(temp);
        //cout << "Enter EndTime : ";
        //getline(is, ((Student&)obj).endTime );
        //cout << "Enter Diplom : ";
        //getline(is, obj.Diplom);
        //    for Aspirant
        is >> (Student&)obj;
        cout << "Enter EndTime : ";
        getline(is, obj.endTime);
        cout << "Enter Diser : ";
        getline(is, obj.Diser);
        return is;
    }
};

/*
class Doctor : public Aspirant
{
  // class Student from Aspirant
  // class Aspirant

};

class Acdemik : Doctor {
  // class Student from Aspirant
  // class Aspirant form Doctor
  // class Doctor
public:
  void Show() {
    Student::setName("Имя студента");
    ((Student&)(*this)).Diplom = "Диплом студента";
  }
};
*/
int main()
{
    Aspirant as;
    cin >> as;
    cout << as;
}
