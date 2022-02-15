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

// прототип внешней глобальной переменной
extern vector<string> menuItems;

class Game {
private:
  // экранные коордитаны главного меню игры
  int menuRow;
  int menuCol;
  // 
  int cntHardTank;    // кол-во тяж. танков
  int cntMiddleTank;  // кол-во сред. танков
  int cntLightTank;   // кол-во легких танков
  int cntPlayerTank;  // кол-во танков игроков
  // массив танков - участников игры
  vector<BaseTank*> arrTanks;
  // список пулек на поле
  list<BaseBullet*> lstBullets;
  //
  bool IsGameOver; // игра окончена
  bool IsGame; // игра запущена или нет
  //
  CPole Canvas; // холст для прорисовки кадра игрового поля

public:
  Game():menuRow(4),menuCol(9),IsGame(false),IsGameOver(false)
  {
    Init();
  }

  // иниц-ция класса Game для старта нового партии игры
  void Init()
  {
    cntHardTank   = 1; // по умолчанию один тяж. танк
    cntMiddleTank = 2;
    cntLightTank  = 4;
    cntPlayerTank = 1; // по умолчанию один игрок
    // удаление танков из массива
    for (auto t : arrTanks) { delete t; }
    arrTanks.clear();  // очистка вектора
    // добавление в массив танчиков игроков
    for (int i = 0; i < cntPlayerTank; i++) {
      arrTanks.push_back( new PlayerTank );
    }
    // добавление в массив тяж. танчиков
    for (int i = 0; i < cntHardTank; i++) {
      arrTanks.push_back( new HardTank );
    }
    // добавление в массив средних танчиков
    for (int i = 0; i < cntMiddleTank; i++) {
      arrTanks.push_back( new MiddleTank );
    }
    for (int i = 0; i < cntLightTank; i++) {
      arrTanks.push_back( new LightTank );
    }
    // удаляем старые пульки
    for (auto b : lstBullets) { delete b; }
    lstBullets.clear();
    // Очистить поле игры
    Canvas.Clear();
    Canvas.LoadLevel(); // по умолчанию загружаем первый уровень игры
  }

  // главный метод программы игры BattleCity
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
        //return; - грубый вариант выхода
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
  // метод описания логики игрового процесса
  void Logic() {

    while( !IsGameOver ) // while(IsGameOver == false)
    {
      // 1
      for (auto t : arrTanks) { // for(BaseTank * t : arrTanks)
        t->Move( Canvas ); // каждый танчик может переместиться на поле
      }
      // 2
      for (auto t : arrTanks) {
        BaseBullet * pBullet = t->Shoot( Canvas );
        if (pBullet != nullptr) {
          lstBullets.push_back( pBullet );
        }
      }
      // 3 - перемещение пулек на поле
      for(auto b : lstBullets){
        b->Move( Canvas ); // перемещение пулек на поле
      }
      // 4 - прорисовка объектов на поле
      for (auto t : arrTanks) {
        t->Draw( Canvas ); // каждый танчик рисут себя на поле
      }
      for (auto b : lstBullets) {
        b->Draw( Canvas ); // каждая пулька рисут себя на поле
      }
      // 5 проверка попадания пульки в танчик ==> IsGameOver
      // 6 проверка пульки на выход за поле
      // 7 вывести кадр поля на экран монитора
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
