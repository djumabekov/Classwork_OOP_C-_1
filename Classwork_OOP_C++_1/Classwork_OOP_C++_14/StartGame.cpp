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
#include "Game.h" // class Game;
#include "BaseTank.h"
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

// внешний вид танка по умолчанию
char defTankImage[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL+1] = {
  { // Direct = 0 - up
    " | ", //+'\0'
    "###",
    "#@#",
  },
  { // Direct = 1 - right
    "## ",
    "@#-",
    "## ",
  },
  { // Direct = 2 - down
    "#@#",
    "###",
    " | ",
  },
  { // Direct = 3 - left
    " ##", //+ '\0'
    "-#@",
    " ##",
  },
};

void StartGame()
{
  Game game;
  game.Start(); // запустить программу "Игра BattleCity"
}
