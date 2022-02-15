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
  vector<string> m_Canvas;    // новый кадр поля
  vector<string> m_CanvasOld; // страрый кадр поля
  int m_nRow, m_nCol; // экранные коорд. поля
  int m_nHeight, m_nWidth; // размеры поля
public:
  CPole() : m_nRow(3), m_nCol(5),
    m_nHeight(12), m_nWidth(25)
  {
    Create();
  }
  // метод для создания пустого поля
  virtual void Create() {
    m_Canvas.clear(); // удалене старого поля
    m_Canvas.resize(m_nHeight); // строки
    for (auto& s : m_Canvas) {
      s.resize(m_nWidth, ' '); // столбцы
    }
    m_CanvasOld = m_Canvas;
  }
  // вывод поля на экран
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
  // полная перепрорисовка игры
  virtual void ReDraw() {
    system("cls"); // очистить экран
    DrawBorder(); // нарисовать бордюр
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