#ifndef SRC_CUBE_H
#define SRC_CUBE_H

class cube {
  using face = char[3][3];

public:
private:
  face c[6];
  face *mRight = c + 0;
  face *mUp = c + 1;
  face *mFront = c + 2;
  face *mLeft = c + 3;
  face *mDown = c + 4;
  face *mBack = c + 5;
};

#endif
