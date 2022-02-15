//
// Menu.h
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <conio.h>  // _getch(), _kbhit()
#include "Win10.h"
using namespace std;

// ��������� ��� �������� ����������� ���������� ������
struct MColor {
  int Fon, Sym; // ����� ��� � �������
};

class CMenu {
private:
  vector<string>  m_vItems;    // ������ ������� ����
  int             m_nSelect;   // ������ ��������� ������ ����
  int             m_nRow, m_nCol; // �����. �����. ����
  // ���������� ��� ������ ������ ����
  MColor m_colSel;     // ���� ��� ��������� ������ ����
  MColor m_colUnSel;   // ���� ��� ���������� ������� ����
  MColor m_colDefault; // ���� �� ��������� (0,7)
public:
  CMenu() : m_vItems(), m_nSelect(), m_nRow(2), m_nCol(5),
    m_colSel({ COLOR::_BLUE, COLOR::_BRIGHT_WHITE }),
    m_colUnSel({ COLOR::_BLACK, COLOR::_YELLOW }),
    m_colDefault({ COLOR::_BLACK, COLOR::_WHITE })
  {}
  CMenu(const vector<string>& mItems) : CMenu() {
    m_vItems = mItems; // Set(mItems);
  }
  CMenu(int row, int col) : CMenu() {
    m_nRow = row, m_nCol = col;
  }
  void Set(const vector<string>& mItems) {
    m_vItems = mItems;
  }
  // ������� ���� �� �����
  int Show(int select = 0) {
    m_nSelect = select;
    while (true) {
      // 1) ������ ������� ���� �� �����
      int row = m_nRow;
      for (auto item : m_vItems) {
        if (m_nSelect == row - m_nRow) {
          // ���� ��� ��������� ������ ����
          SetColor(m_colSel.Fon, m_colSel.Sym);
        }
        else { // ���� ��� ���������� ������� ����
          SetColor(m_colUnSel.Fon, m_colUnSel.Sym);
        }
        SetPos(row++, m_nCol);
        cout << item;
      } // for (auto item : m_vItems)
      // �������������� ���� ������� �� ���������
      SetColor(m_colDefault.Fon, m_colDefault.Sym);
      // 2)
      int key = _getch();
      switch (key) {
        case KEY::UP: case KEY::LEFT: case 'w': case 'a': // ����
          if (m_nSelect > 0) { m_nSelect--; }
          else               { m_nSelect = m_vItems.size()-1; }
          break;
        case KEY::DOWN: case KEY::RIGHT: case 's': case 'd': // ����
          if (m_nSelect < m_vItems.size() - 1) { m_nSelect++; }
          else { m_nSelect = 0; }
          break;
        case KEY::ENTER: return m_nSelect; // ���������� ������ ���������� ������ ����
        case KEY::ESC:   return -1; // ����� �� ������
      }
    } // while(true);
  } // int Show()

  // ������� ���� �� �����
  int Show(int row, int col, int select = 0) {
    m_nRow = row;
    m_nCol = col;
    return Show(select);
  }
}; // class CMenu;

