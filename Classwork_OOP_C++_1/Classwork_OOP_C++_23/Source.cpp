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

    friend ostream& operator<< (ostream& os,
        const ArrTicket& obj)
    {
        if (&os == &cout) {
            cout << "Size = " << obj.GetMas().size() << endl;
        }
        else {
            os << obj.GetMas().size() << endl;
        }
        for (int i = 0; i < obj.GetMas().size(); i++)
        {
            os << obj[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, ArrTicket& obj) {
        if (&is == &cin) { cout << "Enter number of tickets : "; }
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


#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
1. ���� ��� ��������� �����.
��������, ��������� �� �� ������.
���� ���, �� ������� ������������� ������ �� ������� �����.
*/

//int __cdecl main(int argc, char ** argv, char** env)
// int argc - ���-�� ����� � ������� argv
// char ** argv - ������ ����� ���������� ��������� ������
// char ** env - ������ ����� ���������� ��������� ����������� ����� (enveroment)
int main(int argc, char** argv, char** env)
{
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = \"" << argv[i] << "\"\n";
    }
}
