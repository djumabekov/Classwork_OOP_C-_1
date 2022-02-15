//
// BaseTank.h
//
#pragma once

enum Direct
{
  Up, Right, Down, Left,
  MAX_DIRECT,
};

#define TANK_SIZE_ROW  3
#define TANK_SIZE_COL  3

extern char defTankImage[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL + 1];

// ����� ��� �������� ����������� �����
class Image {
private:
  char    m_Img[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL + 1];
  Direct  m_Dir;     // ����������� ���� �����
public:
  Image() : m_Img(), m_Dir() {}
  Image(char img[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL + 1])
    : Image()
  {
    SetImg(img);
  }

  Direct GetDir() const { return m_Dir; }
  void SetDir(Direct dir) { m_Dir = dir; }

  void SetImg(char img[MAX_DIRECT][TANK_SIZE_ROW][TANK_SIZE_COL + 1]) {
    /*char* p1 = (char*)m_Img;
    char* p2 = (char*)img;
    int size = MAX_DIRECT * TANK_SIZE_ROW * TANK_SIZE_COL;
    for (int i = 0; i < size; i++) {
      p1[i] = p2[i];
    }
    */
    for (int i = 0; i < MAX_DIRECT; i++) {
      for (int j = 0; j < TANK_SIZE_ROW; j++) {
        for (int k = 0; k < TANK_SIZE_COL + 1; k++) {
          m_Img[i][j][k] = img[i][j][k];
        }
      }
    }
  }
  // ���������� ����� �� ������ �������� ����
  void Draw(CPole& Canvas, int row, int col) {
    for (int i = 0; i < TANK_SIZE_ROW; i++) {
      for (int j = 0; j < TANK_SIZE_COL; j++) {
        Canvas[row+i][col+j] = m_Img[m_Dir][i][j];
      }
    }
  }
  // ������� ����������� ������� ����� �� ������
  void Clear(CPole& Canvas, int row, int col) {
    for (int i = 0; i < TANK_SIZE_ROW; i++) {
      for (int j = 0; j < TANK_SIZE_COL; j++) {
        Canvas[row+i][col+j] = ' ';
      }
    }
  }
  // ����� ��� ������������� �����
  void SetSymbol(int row, int col, char sym) {
    m_Img[Direct::Up   ][row][col] = sym;
    m_Img[Direct::Down ][row][col] = sym;
    m_Img[Direct::Left ][row][col] = sym;
    m_Img[Direct::Right][row][col] = sym;
  }

}; // class Image;

class BaseTank {
protected:
  int     m_nRow, m_nCol; // ������������� ���������� ����� �� ����
  int     m_nRowOld, m_nColOld; // ������, ���������� ���������� ����� �� ����
  Image   m_Img;     // ������ ��� �������� ���� �����
  //Direct  m_Dir;     // ����������� ���� �����
  int     m_nLifes;  // 100
  double  m_fSpeed;  // [0;1.0]
  int     m_nStep;   // ���-�� ����� ��� �����-����
  // BaseBullet
public:
  BaseTank() : m_nRow(), m_nCol(), /*m_Dir(),*/ // rand()
    m_nRowOld(), m_nColOld(),
    m_nLifes(100), m_fSpeed(1.0),
    m_Img(defTankImage), m_nStep(0)
  {}
  // ����� ����������� � ����������� �����
  // ���������� false, ���� ����� �������� ����
  virtual bool Move(CPole& Canvas)
  {
    if (m_nStep == 0) {
      m_nStep = rand() % 6 + 2; // [2;7]
      int dir = rand() % MAX_DIRECT;
      m_Img.SetDir((Direct)dir);
    }
    else { m_nStep--; }
    DoOneStep(Canvas); // ������� ���� ��� � ������� �����������
    return true; // ���� ������ ��� �����
  }
  // 
  virtual void DoOneStep(CPole& Canvas) {
    Direct dir = m_Img.GetDir();
    switch (dir)
    {
    case Up:
      if (m_nRow > 0) { m_nRow--; }
      // ������� �� �����������
      for (int i = 0; i < TANK_SIZE_COL; i++) {
        if (Canvas[m_nRow][m_nCol + i] != ' ') {
          m_nRow++; break;
        }
      }
      break;
    case Right:
      if (m_nCol < Canvas.GetWidth() - TANK_SIZE_COL - 1)
      { m_nCol++; }
      // ������� �� �����������
      break;
    case Down:
      if(m_nRow < Canvas.GetHeight() - TANK_SIZE_ROW - 1)
      { m_nRow++; }
      // ������� �� �����������
      break;
    case Left:
      if (m_nCol > 0) { m_nCol--; }
      // ������� �� �����������
      break;
    }
  }
  // ����� ��� ����������� ������� ������ �������
  virtual BaseBullet* Shoot(CPole& Canvas) {
    int temp = rand() % 10; // [0;9]
    if (temp == 2) {
      return new BaseBullet(*this); // ������� �����-����
      //return new Bullet1(*this);
    }
    return nullptr; // ���� �� ���������
  }

  virtual void Draw(CPole& Canvas) {
    m_Img.Clear(Canvas, m_nRowOld, m_nColOld);
    m_Img.Draw(Canvas, m_nRow, m_nCol);
    // ��������� ������ ����������
    m_nRowOld = m_nRow;
    m_nColOld = m_nCol;
  }
  // ����������� ���������� ��� �������� �����
  virtual ~BaseTank() {}
}; // class BaseTank

class HardTank : virtual public BaseTank
{
protected:
public:
  HardTank() {
    m_nLifes = 150; // 150%
    m_fSpeed = 0.5; // ��������� �������� �����
    m_Img.SetSymbol(1, 1, 'H');
  }
  virtual ~HardTank() {} // ����������� ����������
};

class MiddleTank : virtual public BaseTank
{
protected:
public:
  MiddleTank() {
    m_nLifes = 100; // 100%
    m_fSpeed = 0.75; // ��������� �������� �����
    m_Img.SetSymbol(1, 1, 'M');
  }
  virtual ~MiddleTank() {} // ����������� ����������
};

class LightTank : virtual public BaseTank
{
protected:
public:
  LightTank() {
    m_nLifes = 75;   // 75%
    m_fSpeed = 1.0; // ��������� ������� �����
    m_Img.SetSymbol(1, 1, 'L');
  }
  virtual ~LightTank() {} // ����������� ����������
};

// ���� ������
class PlayerTank : virtual public MiddleTank
{
protected:
  bool m_bIsShoot; // ��� �������� �����
public:
  PlayerTank() : m_bIsShoot(false) {
    m_Img.SetSymbol(1, 1, 'P');
  }
  virtual bool Move( CPole& Canvas ) override {
    if ( _kbhit() ) {
      int key = _getch();
      if (key == KEY::CURSOR1 || key == KEY::CURSOR2) {
        key = _getch(); // ��� ������� ������ ���������� ��������
      }
      while (_kbhit()) { _getch(); } // ����� ������ ����������
      // ��������� ������� ������� - ����� �����������
      switch (key) {
        case KEY::UP:     m_Img.SetDir(Direct::Up);    break;
        case KEY::DOWN:   m_Img.SetDir(Direct::Down);  break;
        case KEY::LEFT:   m_Img.SetDir(Direct::Left);  break;
        case KEY::RIGHT:  m_Img.SetDir(Direct::Right); break;
        case KEY::ENTER: case KEY::SPACE:
          m_bIsShoot = true;
          break;
        case KEY::ESC:
          return false; // ����� � ������� ���� - �����
      }
      DoOneStep(Canvas); // ���� ��� ������
    }
    return true;
  }
  virtual BaseBullet* Shoot(CPole& Canvas) override {
    if (m_bIsShoot == true) {
      m_bIsShoot = false;
      return new BaseBullet(*this); // ������� �����
    }
    return nullptr; // �������� �� ����
  }
}; // class PlayerTank;

