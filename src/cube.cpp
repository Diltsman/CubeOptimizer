#include "cube.h"

void cube::R() {
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

void cube::R_() {
  face &right = Right();
  face &up = Up();
  face &front = Front();
  face &back = Back();
  face &down = Down();
  // Corners
  Cycle(right[2][0], right[2][2], right[0][2], right[0][0]);
  Cycle(front[0][2], down[0][2], back[2][0], up[0][2]);
  Cycle(front[2][2], down[2][2], back[0][0], up[2][2]);
  // Edges
  Cycle(right[1][0], right[2][1], right[1][2], right[0][1]);
  Cycle(front[1][2], down[1][2], back[1][0], up[1][2]);
}

void cube::L() {
  face &left = Left();
  face &up = Up();
  face &front = Front();
  face &back = Back();
  face &down = Down();
  // Corners
  Cycle(left[0][0], left[0][2], left[2][2], left[2][0]);
  Cycle(up[0][0], front[0][0], down[0][0], back[2][2]);
  Cycle(up[2][0], front[2][0], down[2][0], back[0][2]);
  // Edges
  Cycle(left[0][1], left[1][2], left[2][1], left[1][0]);
  Cycle(up[1][0], front[1][0], down[1][0], back[1][2]);
}

void cube::L_() {
  face &left = Left();
  face &up = Up();
  face &front = Front();
  face &back = Back();
  face &down = Down();
  // Corners
  Cycle(left[2][0], left[2][2], left[0][2], left[0][0]);
  Cycle(up[0][0], back[2][2], down[0][0], front[0][0]);
  Cycle(up[2][0], back[0][2], down[2][0], front[2][0]);
  // Edges
  Cycle(left[0][1], left[1][0], left[2][1], left[1][2]);
  Cycle(up[1][0], back[1][2], down[1][0], front[1][0]);
}

cube::face &cube::GetFace(Face face) {
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

struct Value {
  Value(int i, int j, int k) : i(static_cast<Face>(i)), j(j), k(k) {}
  Face i;
  int j;
  int k;
  Value(char c) : i(static_cast<Face>(c >> 4)), j((c >> 2) & 0x3), k(c & 0x3) {}
  operator char() const {
    char value = static_cast<int>(i) << 4;
    value |= j << 2;
    value |= k;
    return value;
  }
};

bool operator==(const cube &a, const cube &b) {
  bool equal = true;
  cube::face const &(cube::*faces[6])()
      const = {&cube::Right, &cube::Up,   &cube::Front,
               &cube::Left,  &cube::Down, &cube::Back};
  for (auto face : faces) {
    for (std::size_t i = 0; i < 3; ++i) {
      for (std::size_t j = 0; j < 3; ++j) {
        equal = equal && (a.*face)()[i][j] == (b.*face)()[i][j];
      }
    }
  }
  return equal;
}
