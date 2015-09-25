#ifndef SRC_CUBE_H
#define SRC_CUBE_H

#include <stdexcept>
#include <utility>

enum class Face { Right, Up, Front, Left, Down, Back };

class cube {
  friend bool operator==(const cube &a, const cube &b);
  using face = char[3][3];

public:
  void RightCW();
  void RightCCW();
  char GetPosition(Face face, std::size_t row, std::size_t column) {
    return GetFace(face)[row][column];
  }

protected:
  face &GetFace(Face face);
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

bool operator==(const cube &a, const cube &b);

#endif
