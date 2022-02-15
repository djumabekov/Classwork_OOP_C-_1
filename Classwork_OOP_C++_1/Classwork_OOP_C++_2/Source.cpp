#include <iostream>
#include <time.h>// time(), clock()
#include "Win10.h"
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// ��������� ��� �����-��� ���������� ������� � ���������� ����. �����
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } }_;

/* ����� �������������� _Rectangle
����������� ����� �������������� _Rectangle
���� ������
	������� ��������������
	������ ����������� �������������� �� ������
	���������� �������������� �� ������
������ ������
		������������
		��������: get/set-������
		���� � ������� ���������� ��� ���������� ������
		����� �� ������� ���������� ������
		����� (���������) �������������� �� �����
	����������� ��������������
	��������� ������� ��������������*/
class _Rectangle
{
private:
	int Row = 5; //	������
	int Col = 10; // �������
	int Wight = 3; // ������
	int Height = 7;// ������
	char Symbol = '#';

public:
	_Rectangle() : Row(1), Col(3), Wight(), Height(), Symbol('*')
	{
		//Col = Row = 0;
		//Wight = Height = 0;
		//Symbol = '*';
	}
	_Rectangle(int _Wight, int _Height, char _Sym) : _Rectangle()
	{
		SetWight(_Wight);
		SetHeight(_Height);
		SetSymbol(_Sym);
	}
	_Rectangle(int _Wight, int _Height, char _Sym,
		int _Row, int _Col) : _Rectangle(_Wight, _Height, _Sym)
	{
		SetCoor(_Row, _Col);
	}

	void SetHeight(int newHeight)
	{
		if (newHeight >= 0 && newHeight <= 100) { Height = newHeight; }
		else { cout << "Error! Incorrect height!\n"; }
	}
	void SetWight(int newWight)
	{
		if (newWight >= 0 && newWight <= 100) { Wight = newWight; }
		else { cout << "Error! Incorrect wight!\n"; }
	}
	void SetSymbol(char newSymbol) { Symbol = newSymbol; }
	void SetCoor(int _Row, int _Col)
	{
		if ((_Row >= 0 && _Row <= 50) && (_Col >= 0 && _Col <= 100))
		{
			Row = _Row;
			Col = _Col;
		}
		else
		{
			cout << "Error! Incorrect row and col!\n";
			//Row = Col = 0;
		}
	}

	int GetHeight() { return Height; }
	int GetWight() { return Wight; }
	char GetSymbol() { return Symbol; }
	int GetRow() { return Row; }
	int GetCol() { return Col; }
	int GetArea() { return GetHeight() * GetWight(); }
	int GetPerimtr() { return (GetHeight() + GetWight()) * 2; }

	void Input();
	void Print();
	void Draw();
	void ChangeRow(int step)
	{
		SetCoor(GetRow() + step, GetCol());
	}
	void ChangeCol(int step)
	{
		SetCoor(GetRow(), GetCol() + step);
	}
};

inline void _Rectangle::Input()
{
	int tmp1, tmp2;

	cout << "Enter Wight: ";
	cin >> tmp1;
	SetWight(tmp1);
	cout << "Enter Height: ";
	cin >> tmp1;
	SetHeight(tmp1);
	cout << "Enter Row: ";
	cin >> tmp1;
	cout << "Enter Col: ";
	cin >> tmp2;
	SetCoor(tmp1, tmp2);
	char sym;
	cout << "Enter Symbol: ";
	cin >> sym;
	SetSymbol(sym);
	cout << endl << endl;
}
void _Rectangle::Print()
{
	cout << "Wight: " << GetWight() << endl;
	cout << "Height: " << GetHeight() << endl;
	cout << "Row: " << GetRow() << endl;
	cout << "Col: " << GetCol() << endl;
	cout << "Symbol: " << GetSymbol() << endl;
	cout << "Area: " << GetArea() << endl;
	cout << "Perimtr: " << GetPerimtr() << endl;
}
void _Rectangle::Draw()
{
	for (int i = 0; i < GetHeight(); i++)
	{
		SetPos(GetRow() + i, GetCol());
		for (int k = 0; k < GetWight(); k++)
		{
			cout << GetSymbol();
		}
	}
}

void Logic(_Rectangle obj)
{
	while (true)
	{
		system("cls");
		obj.Draw();
		int key = _getch();
		switch (key)
		{
		case _KEY::UP: obj.ChangeRow(-1); break;
		case _KEY::DOWN: obj.ChangeRow(+1); break;
		case _KEY::LEFT: obj.ChangeCol(-1); break;
		case _KEY::RIGHT: obj.ChangeCol(+1); break;
		case '+':
			obj.SetWight(obj.GetWight() + 1);
			obj.SetHeight(obj.GetHeight() + 1);
			break;
		case '-':
			obj.SetWight(obj.GetWight() - 1);
			obj.SetHeight(obj.GetHeight() - 1);
			break;
		case _KEY::ESC: return;
		}
	}
}

int main()
{
	_Rectangle Ab;
	Ab.Input();
	Ab.Print();
	system("cls");
	//Ab.Draw();
	Logic(Ab);
}


#include <iostream>
#include <time.h>   // time(), clock()
using namespace std;

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))

class LC {
public:
	LC() { cout << "����������� �� ���������" << endl; }
	~LC() { cout << "���������� ������ LC\n"; }
	void Show() { cout << "LC::Show();" << endl; }
};

LC lc; // ���������� ��������� ������ LC

int main()
{
	cout << "Hello World!\n";
	system("chcp 1251 > nul");
	srand(time(0));
	/*LC a,c,d; // ����������� �� ���������
	a.Show();
	{
	  LC b;
	  //b.LC(); - ������, ����������� �� ��������� ��� �������� ������!
	  b.Show();
	} // b.~LC();
	//a.~LC(); // �� ���������, �� ��� �� ������� �������� ����������
	*/
	cin.get(); cin.get();
} // d.~LC(); c.~LC(); a.~LC();

#include <iostream>
#include <time.h>   // time(), clock()
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
// ��������� ��� �����-��� ���������� ������� � ���������� ����. �����
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } }_;

//LC lc; // ���������� ��������� ������ LC
int ____ = 10;
int main()
{
	cout << ____ << endl;
	cout << "������, ���!" << endl;
	cout << RAND(1, 10) << endl;
}

