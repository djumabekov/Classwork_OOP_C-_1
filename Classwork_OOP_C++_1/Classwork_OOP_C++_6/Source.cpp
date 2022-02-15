#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
 ���������� ����������
 ����� �������� ��� ���� int - Integer
*/
class CInt {
private:
    int Data; // ������� ���������� ������
    //int Data[64]; // ��� �������� 2048-������� ����� 
    //int* Data, size; // ��� �������� ����� ������������� �������
public:
    CInt() : Data() {} // Data = 0;
    CInt(int val) :Data(val) {} // Data = val;
    /*// ����������� ����������� - ����� �� �����������
    CInt(const CInt& obj) { Data = obj.Data; }
    // �������� �����������
    // A = B;  => CInt = CInt
    CInt& operator = (const CInt& obj) {
      this->Data = obj.Data;
      return *this;
    }*/
    // �������� ������������
    // A = 123; => CInt = int
    CInt& operator = (int val) {
        this->Data = val;
        return *this;
    }
    // A = "123456";
    CInt& operator = (string str) {
        Data = stoi(str); // stoi("  123 45") => 123
                          // stoi(" w 123 45") => 0
        return *this; // A = B = C = "123456";
    }
    // A + B ==> A.operator+( B ) ==> C;
    // A - this
    // B - right
    // 1 + 2 ==> 3
    CInt operator + (const CInt& right) const
    {
        CInt result; // ���������, ��������� ����������
                     // ��� �������� ���������� �����
        result = this->Data + right.Data; // ������������
        return result; // ���������� ��������� �� ��������
                       // ����� ��������� result
    } // result.~CInt();

    // A - B;  *this - right
    CInt operator - (const CInt& right) const
    {
        CInt result; // ���������, ��������� ����������
                     // ��� �������� ��������
        result = this->Data - right.Data;
        return result; // ���������� ��������� �� ��������
                       // ����� ��������� result
    } // result.~CInt();

    // c = a + "10"; =>  c = a.operator+( "10" );
    CInt operator+(const string& str) const
    {
        CInt right;// = str; // CInt(string)
        right = str; // right.operator=( string );
        // CInt + CInt
        CInt res = *this + right; // this->operator+( right );
        //res.Data = this->Data + right.Data;
        //res.Data = (*this).Data + right.Data;
        return res;
    }
    // �������� ^ - ���������� � �������
    // A = B ^ 4;
    CInt operator^(int power) const
    {
        CInt A; // ��������� ����������
        A.Data = pow(this->Data, power);
        return A; // ��������� - ����� ��������� ���������� A
    }

    int getData() const { return Data; }
    void setData(int Data) { this->Data = Data; }

    // ������������� �������� ��� ������ CInt
    friend istream& operator>>(istream& is, CInt& right);

}; // class CInt;

// ������������� ��������� �����-������
// cout << A;  ==>  os << right; 
// file << A;
// operator<<(cout, A);
ostream& operator<<(ostream& os, const CInt& right)
{
    //os << "Data: " << right.getData();
    os << right.getData();
    return os; // ���������� ������ �� ������� ����� ������
}

// cin >> A >> B >> C;
istream& operator>>(istream& is, CInt& right)
{
    is >> right.Data;
    return is; // ���������� ������ �� ������� ����� �����
}

int main()
{
    /*//int t;
    //cout << t; - ������, �� ����-��� ����������
    CInt t;
    cout << t; // 0 - ������ �� �����*/

    CInt a = 123, b = 456;
    b = "456";
    CInt c = a + b; // CInt c(a+b);
    //c = a.operator+(b); // ������ ����� ������ ��������� +

    cout << a << " + " << b << " = " << c << endl;
    c = a - b; // c.operator=(a-b);
    cout << a << " - " << b << " = " << c << endl;

    c = a + "10"; // CInt + string
    CInt d = (a + b) - c;

    CInt t;
    cout << "������� �����: ";
    cin >> t; // operator>>(cin, t);
    cout << "t = " << t << endl;
    cout << "t^3 = " << (t ^ 3) << endl;
}

