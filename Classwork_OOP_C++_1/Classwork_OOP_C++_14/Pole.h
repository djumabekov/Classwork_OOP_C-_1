//
// Pole.h
//  class CPole;
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Win10.h"
using namespace std;

class CPole {
protected:
  //vector<vector<int>> m_Bitmap;
  vector<string> m_Canvas;    // ����� ���� ����
  vector<string> m_CanvasOld; // ������� ���� ����
  int m_nRow, m_nCol; // �������� �����. ����
  int m_nHeight, m_nWidth; // ������� ����
public:
  CPole() : m_nRow(3), m_nCol(5),
    m_nHeight(12), m_nWidth(25)
  {
    Create();
  }
  // ����� ��� �������� ������� ����
  virtual void Create() {
    m_Canvas.clear(); // ������� ������� ����
    m_Canvas.resize(m_nHeight); // ������
    for (auto& s : m_Canvas) {
      s.resize(m_nWidth, ' '); // �������
    }
    m_CanvasOld = m_Canvas;
  }
  // ����� ���� �� �����
  virtual void Draw(/*bool IsRedarw = true*/)
  {
    for (int i = 0; i < m_Canvas.size(); i++) { // Height
      for (int j = 0; j < m_Canvas[0].size(); j++) { // Width
        if (m_Canvas[i][j] != m_CanvasOld[i][j]) {
          SetPos(m_nRow + i, m_nCol + j);
          cout << m_Canvas[i][j];
        }
      }
    }
    m_CanvasOld = m_Canvas;
  }
  // ������ �������������� ����
  virtual void ReDraw() {
    system("cls"); // �������� �����
    DrawBorder(); // ���������� ������
    for (int i = 0; i < m_Canvas.size(); i++) { // Height
      for (int j = 0; j < m_Canvas[0].size(); j++) { // Width
        SetPos(m_nRow + i, m_nCol + j);
        cout << m_Canvas[i][j];
      }
    }
    m_CanvasOld = m_Canvas;
  }
  virtual void DrawBorder() {}

}; // class CPole