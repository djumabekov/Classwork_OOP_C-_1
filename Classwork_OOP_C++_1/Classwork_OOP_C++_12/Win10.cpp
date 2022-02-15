//
// Win10.cpp
//

#include <stdlib.h>
#include <stdio.h>
#include "Win10.h"


// Функция для скрытия/отображения каретки,
//  установки размера курсора
void CursorHide( BOOL bVisible, DWORD dwSize ) {
  HANDLE hOUTPUT = GetStdHandle( STD_OUTPUT_HANDLE ); // Get console handle
  CONSOLE_CURSOR_INFO cursorInfo;
  cursorInfo.dwSize = dwSize;
  cursorInfo.bVisible = bVisible;
  SetConsoleCursorInfo( hOUTPUT, &cursorInfo ); // Hide/Show console cursor
}


// функция для смена цвета
void SetColor( WORD wAttributes ) {
  HANDLE hOUTPUT = GetStdHandle( STD_OUTPUT_HANDLE );
  SetConsoleTextAttribute( hOUTPUT, wAttributes );
}

void SetColor( int colBkgr, int colSym ) {
  SetColor( colBkgr * 16 + colSym );
}


// Функция для выбора позиции курсора на экране
void SetPos( int row, int col ) {
  COORD cd;
  cd.X = col;
  cd.Y = row;
  SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), cd );
}


void ConsoleSetSize( int row, int col )
{
  // установка размера шрифта
  CONSOLE_FONT_INFOEX cfon{};
  cfon.cbSize = sizeof( CONSOLE_FONT_INFOEX );
  GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfon );
  cfon.nFont = 10;
  cfon.dwFontSize.X = 20;
  cfon.dwFontSize.Y = 30;
  cfon.FontFamily = 54;
  cfon.FontWeight = 400;
  wcscpy( cfon.FaceName, L"Lucida Console" );
  SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfon );

  // установка размера окна консоли
  char str[100];
  sprintf_s( str, "mode con cols=%d lines=%d", col, row );
  system( str );
  system( "cls" );
}
