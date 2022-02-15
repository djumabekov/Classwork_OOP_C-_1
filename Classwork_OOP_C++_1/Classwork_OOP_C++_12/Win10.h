//
// Win10.h
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
using namespace std;
#pragma warning(disable:4996)

// перечень кодов клавиш
enum KEY {
  ESC = 27,
  SPACE = 32,
  ENTER = 13,

  CURSOR1 = 0, CURSOR2 = 224,
  LEFT = 75,
  RIGHT = 77,
  UP = 72,
  DOWN = 80,
};

// перечень цветов
enum COLOR {
  _BLACK,
  _BLUE,
  _GREEN,
  _AQUA,
  _RED,
  _PURPLE,
  _YELLOW,
  _WHITE,
  _GRAY,
  _LIGHT_BLUE,
  _LIGHT_GREEN,
  _LIGHT_AQUA,
  _LIGHT_RED,
  _LIGHT_PURPLE,
  _LIGHT_YELLOW,
  _BRIGHT_WHITE,
};

// прототипы ф-ций Win10.cpp
void CursorHide(BOOL bVisible = 0, DWORD dwSize = 20);
void SetColor(WORD wAttributes);
void SetColor(int colBkgr, int colSym);
void SetPos(int row, int col);
void ConsoleSetSize(int row = 25, int col = 80);
