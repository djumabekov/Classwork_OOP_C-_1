//
// StartGame.cpp
//
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Win10.h"
#include "Menu.h"
using namespace std;   // std::string, std::cout

/*void StartGame()
{
  Menu menu;
  menu.Set({ "Игра BattleSity",
    "Игра Tetris",
    "Игра Tetris2",
    "Игра Змейка",
    "Выход" });
  switch (menu.Show(5, 10)) {
    case 0: {
      GameBatleSity game;
      //game.Init(); - ???
      game.Start(); // game.Run();
      break;
    }
    case 1: {
      GameTetris game;
      game.Start();
      break;
    }
    case 2: {
      GameTetris2 game;
      game.Start();
      break;
    }
  }
}
*/
/*
string menuItems[] = {
  "Start new game",
  "Continue game",
};
*/
// массив пунктов главного меню в виде вектора строк
vector<string> menuItems({
  " Start new game ",
  "    Continue    ",
  "    Settings    ",
  "   Load game    ",
  "   Save game    ",
  "      Top       ",
  "   Statistica   ",
  "     About      ",
  "      Exit      ",  
  });

// экранные коордитаны главного меню игры
int menuRow = 3;
int menuCol = 8;

void StartGame()
{
  //Game game;
  CMenu menu; // Menu menu(menuRow, menuCol);
  menu.Set(menuItems);
  int choose = menu.Show(menuRow, menuCol);
  switch (choose) {
    case 0: // " Start new game "
      //game.StartNewGame();
      break;
    case 1: // "Continue"
      //game.ContinueGame();
      break;
    case 2: // Settings
    case 3: // Load game
    case 4: // Save game
    case 5: // Top       "
    case 6: // Statistica   "
    case 7: // About      "
    case 8: // Exit      "
    case -1:;
  }
}
