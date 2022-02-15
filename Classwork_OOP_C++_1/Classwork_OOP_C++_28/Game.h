//
// Game.h
//  class Game;
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include "Win10.h"
#include "Menu.h"
#include "BaseTank.h"
//#include "BaseBullet.h"
using namespace std;

// �������� ������� ���������� ����������
extern vector<string> menuItems;

class Game {
private:
  // �������� ���������� �������� ���� ����
  int menuRow;
  int menuCol;
  // 
  int cntHardTank;    // ���-�� ���. ������
  int cntMiddleTank;  // ���-�� ����. ������
  int cntLightTank;   // ���-�� ������ ������
  int cntPlayerTank;  // ���-�� ������ �������
  // ������ ������ - ���������� ����
  vector<BaseTank*> arrTanks;
  // ������ ����� �� ����
  list<BaseBullet*> lstBullets;
  //
  bool IsGameOver; // ���� ��������
  bool IsGame; // ���� �������� ��� ���
  //
  CPole Canvas; // ����� ��� ���������� ����� �������� ����

public:
  Game():menuRow(4),menuCol(9),IsGame(false),IsGameOver(false)
  {
    Init();
  }

  // ����-��� ������ Game ��� ������ ������ ������ ����
  void Init()
  {
    cntHardTank   = 1; // �� ��������� ���� ���. ����
    cntMiddleTank = 2;
    cntLightTank  = 4;
    cntPlayerTank = 1; // �� ��������� ���� �����
    // �������� ������ �� �������
    for (auto t : arrTanks) { delete t; }
    arrTanks.clear();  // ������� �������
    // ���������� � ������ �������� �������
    for (int i = 0; i < cntPlayerTank; i++) {
      arrTanks.push_back( new PlayerTank );
    }
    // ���������� � ������ ���. ��������
    for (int i = 0; i < cntHardTank; i++) {
      arrTanks.push_back( new HardTank );
    }
    // ���������� � ������ ������� ��������
    for (int i = 0; i < cntMiddleTank; i++) {
      arrTanks.push_back( new MiddleTank );
    }
    for (int i = 0; i < cntLightTank; i++) {
      arrTanks.push_back( new LightTank );
    }
    // ������� ������ ������
    for (auto b : lstBullets) { delete b; }
    lstBullets.clear();
    // �������� ���� ����
    Canvas.Clear();
    Canvas.LoadLevel(); // �� ��������� ��������� ������ ������� ����
  }

  // ������� ����� ��������� ���� BattleCity
  void Start() {
    CMenu menu; // Menu menu(menuRow, menuCol);
    menu.Set(menuItems);
    int choose = 0;
    bool isExite = false;
    while ( !isExite ) // <===> while (isExite == false)
    {
      choose = menu.Show(menuRow, menuCol, choose);
      switch (choose)
      {
      case 0: // " Start new game "
        StartNewGame();
        break;
      case 1: // "Continue"
        ContinueGame();
        break;
      case 2: // Settings
        Settings();
        break;
      case 3: // Load game
        Load();
        break;
      case 4: // Save game
        Save();
        break;
      case 5: // Top
        TopShow();
        break;
      case 6: // Statistica
        Statistica();
        break;
      case 7: // About
        About();
        break;
      case 8:  // Exit
      case -1: // ESC
        isExite = true;
        //isExite = IsChechExit();
        break;
        //return; - ������ ������� ������
      } // switch( choose )
    } // while( true )

  } // void Start()

  void StartNewGame() {
    IsGame = false;
    ContinueGame();
  }
  void ContinueGame() {
    if (IsGame == false || IsGameOver == true) {
      IsGame = true;
      IsGameOver = false;
      Init();
    }
    Logic(); // Engine();
  }
  // ����� �������� ������ �������� ��������
  void Logic() {

    while( !IsGameOver ) // while(IsGameOver == false)
    {
      // 1
      for (auto t : arrTanks) { // for(BaseTank * t : arrTanks)
        t->Move( Canvas ); // ������ ������ ����� ������������� �� ����
      }
      // 2
      for (auto t : arrTanks) {
        BaseBullet * pBullet = t->Shoot( Canvas );
        if (pBullet != nullptr) {
          lstBullets.push_back( pBullet );
        }
      }
      // 3 - ����������� ����� �� ����
      for(auto b : lstBullets){
        b->Move( Canvas ); // ����������� ����� �� ����
      }
      // 4 - ���������� �������� �� ����
      for (auto t : arrTanks) {
        t->Draw( Canvas ); // ������ ������ ����� ���� �� ����
      }
      for (auto b : lstBullets) {
        b->Draw( Canvas ); // ������ ������ ����� ���� �� ����
      }
      // 5 �������� ��������� ������ � ������ ==> IsGameOver
      // 6 �������� ������ �� ����� �� ����
      // 7 ������� ���� ���� �� ����� ��������
      Canvas.Draw();
    }
  } // void Logic()

  void Settings() {}
  void Load() {}
  void Save() {}
  void TopShow() {}
  void Statistica() {}
  void About() {}
}; // class Game;
