#include <iostream>
#include <fstream> // ��� ������ � �������
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  ���������� ����������
1. �������� ����� �����.
��������� ���������� ���������� ���������� ��� ����
�������������� �������� ��� ������ � �������:
�������� +, -, *, /, >>, <<
*/

class Drob {
private:
    int Chisl;
    int Znamen;
public:
    Drob() :Chisl(0), Znamen(1) {};
    Drob(int a, int b = 1) :Chisl(a), Znamen(b) {}
    //Setters
    void SetChisl(int newChisl) { Chisl = newChisl; }
    void SetZnamen(int newZnamen) {
        if (newZnamen != 0) {
            Znamen = newZnamen;
        }
        else { cout << "Error! Devide by zero!" << endl; }
    }
    void Set(int a, int b) {
        SetChisl(a);
        SetZnamen(b);
    }
    //Getters
    int GetChisl()const { return Chisl; }
    int GetZnamen()const { return Znamen; }

    // Input
    friend istream& operator >> (istream& is, Drob& obj) {
        int tmpChisl, tmpZnamen;
        if (&is == &cin) { // cin >> A; ������ � �������
            cout << "Enter Chislitel:";
            is >> tmpChisl;
            cout << "Enter Znamenatel:";
            is >> tmpZnamen;
            obj.Set(tmpChisl, tmpZnamen);
        }
        else { // file >> A; - ������ �� ��������� ������
            is >> tmpChisl >> tmpZnamen;
            obj.Set(tmpChisl, tmpZnamen);
        }
        return is;
    }

    // Output
    friend ostream& operator <<(ostream& os, const Drob& obj)
    {
        if (&os == &cout) { // cout << A; ����� �� �������
            os << obj.GetChisl() << " / " << obj.GetZnamen();
        }
        else { // file << A; ����� � ����
            os << obj.GetChisl() << " " << obj.GetZnamen();
        }
        return os;
    }
    Drob operator + (const Drob& right) const {
        //*this + right;
        Drob Result;
        Result.Chisl = this->Chisl * right.Znamen +
            this->Znamen * right.Chisl;
        Result.Znamen = this->Znamen * right.Znamen;
        return Result;
    }
    Drob operator - (const Drob& right) const {
        //*this - right;
        Drob Result;
        Result.Chisl = this->Chisl * right.Znamen -
            this->Znamen * right.Chisl;
        Result.Znamen = this->Znamen * right.Znamen;
        return Result;
    }
    Drob operator * (const Drob& right) const {
        Drob Result;
        Result.Chisl = this->Chisl * right.Chisl;
        Result.Znamen = this->Znamen * right.Znamen;
        return Result;
    }
    Drob operator / (const Drob& right) const {
        Drob Result;
        Result.Chisl = this->Chisl * right.Znamen;
        Result.Znamen = this->Znamen * right.Chisl;
        return Result;
    }
    friend Drob operator + (int left, const Drob& right) {
        Drob Result(left);
        return Result + right;
    }
    // Drob A;
    // A[0] ==> �������� ��������� �����
    // A[1] ==> �������� ����������� �����
    // ��� ��������� �������� - ������
    // A[0] ==> A.operator[]( 0 );
    int operator[](int index) const
    {
        switch (index) {
        case 0: return GetChisl();  // A[0]
        case 1: return GetZnamen(); // A[1]
        default: // ������
            cout << "������: ����� �� ������� ��������!\n";
            //return ?
            throw "����������: ����� �� ������� ��������!";
            // throw �� ���� const char*
        }
    }
    // �� ����������� �������� [] ��� ��������� ������ �� �������
    int& operator[](int index) {
        switch (index) {
        case 0: return Chisl; // ���������� ������ �� ���������
        case 1: return Znamen;// ���������� ������ �� �����������
        default:
            cout << "������: ����� �� ������� ��������!\n";
            //return ?
            throw "����������: ����� �� ������� ��������!";
            // throw �� ���� const char*
        }
    }
    // cout << A["Chislitel"] << endl;
    int operator[](string Name) {
        if (Name == "Chislitel") { return GetChisl(); }
        if (Name == "Znamenatel") { return GetZnamen(); }
        cout << "������: ��� ������ ��������� � ������!\n";
        throw "����������: ������� �� ������!";
    }
    // ���������� ���������
    // if(A == B)
    bool operator==(const Drob& B) const {
        // 1/3 == 3/9 ==> 0.333 == 0.333
        double d1 = (double)Chisl / (double)Znamen;
        double d2 = (double)B.Chisl / (double)B.Znamen;
        //if (d1 == d2) { return true; }
        //else          { return false; }
        return (d1 == d2);
    }

    // if(A < B)
    bool operator < (const Drob& B) const {
        double d1 = (double)Chisl / (double)Znamen;
        double d2 = (double)B.Chisl / (double)B.Znamen;
        return (d1 < d2);
    }

};
//operator==()
//Drob operator + (int left, const Drob&right) {
  //Drob Result(left);
  //return Result + right;
//}


int main()
{
    Drob A, B;
    cin >> A;
    try { // ���������� ���� ���� ��� ��������� ���������� throw
        cout << "Chislitel  = " << A[0] << endl;
        cout << "Znamenatel = " << A[1] << endl;
        cout << "���������  = " << A[2] << endl; // throw const char*
    }
    catch (const char* ex) {
        // ������� ��� ��������� ���������� ���� const char*
        cout << "Ex1: " << ex << endl;
    }

    A[0] += 10; // A[0] - ����� �� ������������ ��������� []

    cin.ignore();
    string name;
    cout << "Enter attribute name (Chislitel, Znamenatel): ";
    cin >> name;
    try {
        cout << name << ": " << A[name] << endl;
    }
    catch (const char* e) {
        cout << "Ex2: " << e << endl;
    }
    cin >> B;
    // if (A == B) ==>  A.operator==( B );
    if (A == B) { cout << "A == B\n"; }
    else { cout << "A != B\n"; }


    /*Drob A, B(5,2);
    cin >> A >> B;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    Drob C = A + B;
    cout << "A + B = " << C << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    cout << "A / B = " << A / B << endl;
    //C = Drob(2) + A;
    C = 2 + A;
    cout << "2 + A = " << C << endl;
    C = 2;
    cout << "C = " << C << endl;
    // ����� � �������� �����
    ofstream ofile("Drob1.txt");
    if (ofile.is_open() == true) {
      ofile << A << endl
            << B << endl
            << C << endl;
      ofile.close(); // �������������� �������� �����
    }
    else {
      cout << "Error: can't create output file!\n";
    }
    // ������ �� ��������� ������
    ifstream ifile("Drob1.txt");
    if (ifile.is_open()) {
      Drob temp1, temp2, temp3;
      ifile >> temp1 >> temp2 >> temp3;
      cout << "Drob1 = " << temp1 << endl;
      cout << "Drob2 = " << temp2 << endl;
      cout << "Drob3 = " << temp3 << endl;
    }
    else {
      cout << "Error: file is not found!\n";
    }*/
}






