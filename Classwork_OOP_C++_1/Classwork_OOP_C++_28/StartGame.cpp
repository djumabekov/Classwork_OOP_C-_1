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
using namespace std;   // std::string, std::cout

/*void StartGame()
{
  Menu menu;
  menu.Set({ "���� BattleSity",
    "���� Tetris",
    "���� Tetris2",
    "���� ������",
    "�����" });
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
// ������ ������� �������� ���� � ���� ������� �����
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

void StartGame()
{
  Game game;
  game.Start(); // ��������� ��������� "���� BattleCity"
}
