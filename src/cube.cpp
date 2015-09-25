#include "cube.h"

void cube::RightCW() {
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

void cube::RightCCW() {
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

void cube::LeftCW() {}

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
