#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
2. ������� ����� �����:
- �������� ��������,
- �����-����,
- ���������.
�) *������� ��������� ������ ����� � �������� ��� ���� ������:
- ����������,
- ������,
- ���������� � ����,
- �������� �� �����.
�) **������� ������ ������� � �������� ���������, �����������:
- ����������� �������� ������ �������;
- �������� ������ ������� �� ���������� ����;
- �������� ������ ������� �� ������ ������������ �����;
- ������ ����� ������ �������.
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
            os << "������� - " << obj.GetNameRoute() << endl;
            os << "���� � ����� - " << obj.GetDataTime() << endl;
            os << "��������� ������� - " << obj.GetCost() << endl;
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
            cout << "������� ������� - ";
            getline(is, temp);
            obj.SetNameRoute(temp);
            cout << "������� ���� � ����� - ";
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            cout << "������� ��������� ������� - ";
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

    // ����� ��� ���������� �������� ������� � ����
    bool Save(string FileName) {
        ofstream oFile; // �������� ������,����� ��� ������
        oFile.open(FileName); // �������� �����
        if (oFile.is_open()) { // �������� �� �������� �����
            oFile << GetNameRoute() << endl;
            oFile << GetDataTime() << endl;
            oFile << GetCost() << endl;
            return true;
        }
        else { cout << "������ �������� �����!!!" << endl; return false; }
    }

    // ����� ��� ������ �������� ������� �� �����
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // �������� ������,����� ��� ������
        if (!LFile.is_open()) {  // �������� �� ������ ��� �������� �����
            cout << "������ �������� �����!!" << endl;
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
    A.Save("File1.txt"); // ��������� � ����
    B.Load("File1.txt"); // ��������� �� ����
    cout << endl << B << endl;

    ofstream F1("File2.txt");
    F1 << A; // ��������� � �������� ����� ������ A
    F1.close();
    ifstream F2("File2.txt");
    Tikket C;
    F2 >> C; // �������� �� ��������� ������ � ������ C
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
2. ������� ����� �����:
- �������� ��������,
- �����-����,
- ���������.
�) *������� ��������� ������ ����� � �������� ��� ���� ������:
- ����������,
- ������,
- ���������� � ����,
- �������� �� �����.
�) **������� ������ ������� � �������� ���������, �����������:
- ����������� �������� ������ �������;
- �������� ������ ������� �� ���������� ����;
- �������� ������ ������� �� ������ ������������ �����;
- ������ ����� ������ �������.
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
            os << "������� - " << obj.GetNameRoute() << endl;
            os << "���� � ����� - " << obj.GetDataTime() << endl;
            os << "��������� ������� - " << obj.GetCost() << endl;
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
            cout << "������� ������� - ";
            getline(is, temp);
            obj.SetNameRoute(temp);
            cout << "������� ���� � ����� - ";
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            cout << "������� ��������� ������� - ";
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

    // ����� ��� ���������� �������� ������� � ����
    bool Save(string FileName) {
        ofstream oFile; // �������� ������,����� ��� ������
        oFile.open(FileName); // �������� �����
        if (oFile.is_open()) { // �������� �� �������� �����
            oFile << GetNameRoute() << endl;
            oFile << GetDataTime() << endl;
            oFile << GetCost() << endl;
            return true;
        }
        else { cout << "������ �������� �����!!!" << endl; return false; }
    }

    // ����� ��� ������ �������� ������� �� �����
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // �������� ������,����� ��� ������
        if (!LFile.is_open()) {  // �������� �� ������ ��� �������� �����
            cout << "������ �������� �����!!" << endl;
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
      A.Save("File1.txt"); // ��������� � ����
      B.Load("File1.txt"); // ��������� �� ����
      cout << endl << B << endl;

      ofstream F1("File2.txt");
      F1 << A; // ��������� � �������� ����� ������ A
      F1.close();
      ifstream F2("File2.txt");
      Tikket C;
      F2 >> C; // �������� �� ��������� ������ � ������ C
      cout << C << endl;
    */

    // 1 �������
    //const int size = 4;
    //Tikket mas[size]; // ����������� ������

    /*// 2 ������� � ������������ ��������
    int size = 4;
    cout << "Enter tickets number: ";
    cin >> size; cin.ignore();
    Tikket* mas = new Tikket[size]; // �������� ������������� ������� �������
    for (int i = 0; i < size; i++) { // ���� ������ � �������
      cin >> mas[i];
    }
    cout << endl;
    for (int i = 0; i < size; i++) { // ���� ������ �� �������
      cout << mas[i];
    }
    delete[]mas; // �������� ������������� �������
    */
    // 3 ������� - vector<>
    //list<Tikket> mas; // ������ ���� std::vector<>
    vector<Tikket> mas; // ������ ���� std::vector<>
    int size;
    cout << "Enter size: ";
    (cin >> size).ignore();
    // 1)���� ���������� �������� � ������-������
    /*for (int i = 0; i < size; i++) {
      Tikket temp; // ��������� ������ ��� �����
      cin >> temp;
      mas.push_back(temp); // �������� � ����� ������� - � ����� �������
    }*/
    // 2)���� ����-��� ������� � �������� ��������
    mas.resize(size); // ������ ������ �������
    /*for (int i = 0; i < size; i++) {
      cin >> mas[i];
    }*/
    for (auto& t : mas) { cin >> t; } // ����������� ���� ��� ����� � �������

    cout << endl;
    for (int i = 0; i < mas.size(); i++) {
        cout << mas[i];
    }
    cout << endl;
    // ����������� ���� � ����������� ���� �++
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
2. ������� ����� �����:
- �������� ��������,
- �����-����,
- ���������.
�) *������� ��������� ������ ����� � �������� ��� ���� ������:
- ����������,
- ������,
- ���������� � ����,
- �������� �� �����.
�) **������� ������ ������� � �������� ���������, �����������:
- ����������� �������� ������ �������;
- �������� ������ ������� �� ���������� ����;
- �������� ������ ������� �� ������ ������������ �����;
- ������ ����� ������ �������.
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
            os << "������� - " << obj.GetNameRoute() << endl;
            os << "���� � ����� - " << obj.GetDataTime() << endl;
            os << "��������� ������� - " << obj.GetCost() << endl;
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
            cout << "������� ������� - ";
            getline(is, temp);
            obj.SetNameRoute(temp);
            cout << "������� ���� � ����� - ";
            getline(is, temp);
            obj.SetDataTime(temp);
            float tmp;
            cout << "������� ��������� ������� - ";
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

    // ����� ��� ���������� �������� ������� � ����
    bool Save(string FileName) {
        ofstream oFile; // �������� ������,����� ��� ������
        oFile.open(FileName); // �������� �����
        if (oFile.is_open()) { // �������� �� �������� �����
            oFile << GetNameRoute() << endl;
            oFile << GetDataTime() << endl;
            oFile << GetCost() << endl;
            return true;
        }
        else { cout << "������ �������� �����!!!" << endl; return false; }
    }

    // ����� ��� ������ �������� ������� �� �����
    bool Load(string LoadFile) {
        ifstream LFile(LoadFile); // �������� ������,����� ��� ������
        if (!LFile.is_open()) {  // �������� �� ������ ��� �������� �����
            cout << "������ �������� �����!!" << endl;
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

