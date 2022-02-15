#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

class Cat {
public:
    Cat() {}
    friend ostream& operator<<(ostream& os, const Cat& obj) {
        return os << typeid(obj).name() << endl;
    }
    //virtual void Move() {}
    virtual ~Cat() {}
};

class LCat : public Cat {
    int* p, size;
public:
    LCat() : size(10), p(new int[size]) { /*p = new int[10];*/ }
    virtual ~LCat() override { delete[]p; }
};


int main() {
    Cat A;
    cout << "A: " << A << endl;
    LCat B;
    cout << "B: " << B << endl;
    //B.~LCat(); - 
    //B.LCat(); - ��� ������
    //B.Show();
} // B.~LCat();

#include <iostream>
#include <time.h>
#include <winerror.h> // ���� � ������ ������ �� Windows
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

// ��������� �������������� ��������

// �-��� ������� ���� ����� �����
int Div(int a, int b)
{
    if (b == 0) {
        cout << "������: ������� �� ����!" << endl;
        //return ??
        //throw "������� �� ����!"; // ���������� �� ���� const char*
        //throw exception("������� �� ����!"); // ���������� �� ���� class exception
        //throw string("������� �� ����!"); // ���������� �� ���� string
        //throw Cat("������"); // ���������� �� ���� Cat
        throw 1;   // ���������� �� ���� int
        //throw 3.567; // ���������� �� ���� double
    }
    return a / b;
}

// �-��� ���������� ����� ����������� �� int
int Sqrt(int a) {
    if (a < 0) {
        cout << "������: ������ �� �����. �����!" << endl;
        //throw "������ �� �����. �����!"; // const char*
        throw 2;
    }
    return (int)(sqrt(a) + 0.5); // ������ � �����������
}

int main()
{
    int t1, t2;
    cout << "������� ��� ����� �����: ";
    cin >> t1 >> t2;
    try { // ���� �������� � ��������� ����������
        int res1 = Div(t1, t2);
        cout << "t1 / t2 = " << res1 << endl;
        int res2 = Sqrt(res1);
        cout << "Sqrt(res1) = " << res2 << endl;
    }
    // �������, ������������ ���������� �� �����
    catch (char* e) {}
    catch (const char* ex) {
        cout << "�������� ����������� �� ���� const char*" << endl;
        cout << "ex = " << ex << endl;
        if (strcmp(ex, "������") == 0) {
            cout << "�� ������� ������!" << endl;
        }
    }
    catch (const string& e) {
        cout << "�������� ����������� �� ���� std::string" << endl;
        cout << "e = " << e << endl;
    }
    catch (int errorCode) {
        cout << "�������� ����������� �� ���� int" << endl;
        cout << "errorCode = " << errorCode << endl;
        switch (errorCode)
        {
        case 1: cout << "����������: ������� �� ����!\n"; break;
        case 2: cout << "����������: ������ �� �����. �����!\n"; break;
        default:
            cout << "����������� ������!" << endl
                << "���������� � �������������" << endl;
            break;
        }
    }
    catch (const exception& e) {
        cout << "�������� ����������� �� ���� std::exception" << endl;
        cout << "e = " << e.what() << endl;
    }
    catch (...) { // ������������� �����������
        cout << "����������� ������!" << endl;
        cout << "���������� � �������������" << endl;
    }
    //
}



