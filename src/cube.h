#ifndef SRC_CUBE_H
#define SRC_CUBE_H

#include <utility>

class cube {
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

private:
  template <typename... Ts> void Cycle(Ts &... ts) { CycleImpl(ts...); }
  template <typename T1, typename T2, typename... Ts>
  void CycleImpl(T1 &t1, T2 &t2, Ts &... ts) {
    std::swap(t1, t2);
    CycleImpl(t2, ts...);
  }
  template <typename T> void CycleImpl(T &t) {}
  void CycleImpl() {}

  face &Right() { return *mRight; }
  face &Up() { return *mUp; }
  face &Front() { return *mFront; }
  face &Left() { return *mLeft; }
  face &Down() { return *mDown; }
  face &Back() { return *mBack; }
  face c[6];
  face *mRight = c + 0;
  face *mUp = c + 1;
  face *mFront = c + 2;
  face *mLeft = c + 3;
  face *mDown = c + 4;
  face *mBack = c + 5;
};

#endif
