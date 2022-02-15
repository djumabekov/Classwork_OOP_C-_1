//
// BaseTank.h
//
#pragma once

enum Direct
{
  Left, Right, Up, Down,
  MAX_DIRECT,
};

#define TANK_SIZE_ROW  3
#define TANK_SIZE_COL  3

// класс для хранения изображения танка
class Image {
private:
  char    m_Img[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL];
  Direct  m_Dir;     // направление дула танка
public:
  Image() : m_Img(), m_Dir() {}
  Image(char img[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL])
    : Image()
  {
    SetImg(img);
  }

  Direct GetDir() const { return m_Dir; }
  void SetDir(Direct dir) { m_Dir = dir; }

  void SetImg(char img[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL]) {
    /*char* p1 = (char*)m_Img;
    char* p2 = (char*)img;
    int size = MAX_DIRECT * TANK_SIZE_ROW * TANK_SIZE_COL;
    for (int i = 0; i < size; i++) {
      p1[i] = p2[i];
    }
    */
    for (int i = 0; i < MAX_DIRECT; i++) {
      for (int j = 0; j < TANK_SIZE_ROW; j++) {
        for (int k = 0; k < TANK_SIZE_COL; k++) {
          m_Img[i][j][k] = img[i][j][k];
        }
      }
    }
  }
  void Draw(CPole Cnavas) {

  }
};

class BaseTank
{
protected:
  int     m_nRow, m_nCol; // относительные координаты танка на поле
  Image   m_Img;     // объект для хранения вида танка
  //Direct  m_Dir;     // направление дула танка
  int     m_nLifes;  // 100
  double  m_fSpeed;  // [0;1.0]
  // BaseBullet
public:
  BaseTank() : m_nRow(), m_nCol(), m_Dir(), // rand()
    m_nLifes(100), m_fSpeed(1.0),
    m_Img(defaultTankImage)
  {}

}; // class BaseTank
