#ifndef SRC_CUBE_H
#define SRC_CUBE_H

#include <stdexcept>
#include <utility>

enum class Face { Right, Up, Front, Left, Down, Back };

class cube {
  friend bool operator==(const cube &a, const cube &b);
  using face = char[3][3];

public:
  void RightCW() {
    face &right = Right();
    face &up = Up();
    face &front = Front();
    face &back = Back();
    face &down = Down();
    // Corners
    Cycle(right[0][0], right[0][2], right[2][2], right[2][0]);
    Cycle(up[0][2], back[2][0], down[0][2], front[0][2]);
    Cycle(up[2][2], back[0][0], down[2][2], front[2][2]);
    // Edges
    Cycle(right[0][1], right[1][2], right[2][1], right[1][0]);
    Cycle(up[1][2], back[1][0], down[1][2], front[1][2]);
  }
  void RightCCW() {
    RightCW();
    RightCW();
    RightCW();
  }
  face &GetFace(Face face) {
    switch (face) {
    case Face::Back:
      return Back();
    case Face::Down:
      return Down();
    case Face::Front:
      return Front();
    case Face::Left:
      return Left();
    case Face::Right:
      return Right();
    case Face::Up:
      return Up();
    }
    throw std::invalid_argument{"Must request a valid face"};
  }
  char GetPosition(Face face, std::size_t row, std::size_t column) {
    return GetFace(face)[row][column];
  }

protected:
  void SetPosition(Face face, std::size_t row, std::size_t column, char value) {
    GetFace(face)[row][column] = value;
  }

private:
  template <typename... Ts> void Cycle(Ts &... ts) { CycleImpl(ts...); }
  template <typename T1, typename... Ts> T1 &CycleImpl(T1 &t1, Ts &... ts) {
    std::swap(t1, CycleImpl(ts...));
    return t1;
  }
  template <typename T> T &CycleImpl(T &t) { return t; }
  void CycleImpl() {}

  face &Right() { return *mRight; }
  face &Up() { return *mUp; }
  face &Front() { return *mFront; }
  face &Left() { return *mLeft; }
  face &Down() { return *mDown; }
  face &Back() { return *mBack; }
  face const &Right() const { return *mRight; }
  face const &Up() const { return *mUp; }
  face const &Front() const { return *mFront; }
  face const &Left() const { return *mLeft; }
  face const &Down() const { return *mDown; }
  face const &Back() const { return *mBack; }
  face c[6];
  face *mRight = c + 0;
  face *mUp = c + 1;
  face *mFront = c + 2;
  face *mLeft = c + 3;
  face *mDown = c + 4;
  face *mBack = c + 5;
};

inline bool operator==(const cube &a, const cube &b) {
  bool equal = true;
  cube::face const &(cube::*faces[6])()
      const = {&cube::Right, &cube::Up,   &cube::Front,
               &cube::Left,  &cube::Down, &cube::Back};
  for (auto face : faces) {
    for (std::size_t i = 0; i < 3; ++i) {
      for (std::size_t j = 0; i < 3; ++i) {
        equal == equal && (a.*face)()[i][j] == (b.*face)()[i][j];
      }
    }
  }
  return equal;
}

#endif
