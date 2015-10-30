#include <gtest/gtest.h>
#include "../src/cube.h"

class TestCube : public cube {
public:
  TestCube() {
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          char value = i << 4;
          value |= j << 2;
          value |= k;
          SetPosition(static_cast<Face>(i), j, k, value);
        }
      }
    }
  }
  using cube::SetPosition;
};

int ComputeValue(Face face, int row, int column) {
  return static_cast<int>(face) << 4 | row << 2 | column;
}

TEST(CubeTests, RightCW) {
  TestCube target;
  target.SetPosition(Face::Front, 0, 2, ComputeValue(Face::Down, 0, 2));
  target.SetPosition(Face::Front, 1, 2, ComputeValue(Face::Down, 1, 2));
  target.SetPosition(Face::Front, 2, 2, ComputeValue(Face::Down, 2, 2));
  target.SetPosition(Face::Down, 0, 2, ComputeValue(Face::Back, 2, 0));
  target.SetPosition(Face::Down, 1, 2, ComputeValue(Face::Back, 1, 0));
  target.SetPosition(Face::Down, 2, 2, ComputeValue(Face::Back, 0, 0));
  target.SetPosition(Face::Back, 0, 0, ComputeValue(Face::Up, 2, 2));
  target.SetPosition(Face::Back, 1, 0, ComputeValue(Face::Up, 1, 2));
  target.SetPosition(Face::Back, 2, 0, ComputeValue(Face::Up, 0, 2));
  target.SetPosition(Face::Up, 0, 2, ComputeValue(Face::Front, 0, 2));
  target.SetPosition(Face::Up, 1, 2, ComputeValue(Face::Front, 1, 2));
  target.SetPosition(Face::Up, 2, 2, ComputeValue(Face::Front, 2, 2));
  target.SetPosition(Face::Right, 0, 0, ComputeValue(Face::Right, 2, 0));
  target.SetPosition(Face::Right, 0, 1, ComputeValue(Face::Right, 1, 0));
  target.SetPosition(Face::Right, 0, 2, ComputeValue(Face::Right, 0, 0));
  target.SetPosition(Face::Right, 1, 0, ComputeValue(Face::Right, 2, 1));
  target.SetPosition(Face::Right, 1, 2, ComputeValue(Face::Right, 0, 1));
  target.SetPosition(Face::Right, 2, 0, ComputeValue(Face::Right, 2, 2));
  target.SetPosition(Face::Right, 2, 1, ComputeValue(Face::Right, 1, 2));
  target.SetPosition(Face::Right, 2, 2, ComputeValue(Face::Right, 0, 2));

  TestCube test;
  test.RightCW();

  EXPECT_EQ(target, test);
}

TEST(CubeTests, RightCCW) {
  TestCube target;
  target.SetPosition(Face::Front, 0, 2, ComputeValue(Face::Up, 0, 2));
  target.SetPosition(Face::Front, 1, 2, ComputeValue(Face::Up, 1, 2));
  target.SetPosition(Face::Front, 2, 2, ComputeValue(Face::Up, 2, 2));
  target.SetPosition(Face::Down, 0, 2, ComputeValue(Face::Front, 0, 2));
  target.SetPosition(Face::Down, 1, 2, ComputeValue(Face::Front, 1, 2));
  target.SetPosition(Face::Down, 2, 2, ComputeValue(Face::Front, 2, 2));
  target.SetPosition(Face::Back, 0, 0, ComputeValue(Face::Down, 2, 2));
  target.SetPosition(Face::Back, 1, 0, ComputeValue(Face::Down, 1, 2));
  target.SetPosition(Face::Back, 2, 0, ComputeValue(Face::Down, 0, 2));
  target.SetPosition(Face::Up, 0, 2, ComputeValue(Face::Back, 2, 0));
  target.SetPosition(Face::Up, 1, 2, ComputeValue(Face::Back, 1, 0));
  target.SetPosition(Face::Up, 2, 2, ComputeValue(Face::Back, 0, 0));
  target.SetPosition(Face::Right, 0, 0, ComputeValue(Face::Right, 0, 2));
  target.SetPosition(Face::Right, 0, 1, ComputeValue(Face::Right, 1, 2));
  target.SetPosition(Face::Right, 0, 2, ComputeValue(Face::Right, 2, 2));
  target.SetPosition(Face::Right, 1, 0, ComputeValue(Face::Right, 0, 1));
  target.SetPosition(Face::Right, 1, 2, ComputeValue(Face::Right, 2, 1));
  target.SetPosition(Face::Right, 2, 0, ComputeValue(Face::Right, 0, 0));
  target.SetPosition(Face::Right, 2, 1, ComputeValue(Face::Right, 1, 0));
  target.SetPosition(Face::Right, 2, 2, ComputeValue(Face::Right, 2, 0));

  TestCube test;
  test.RightCCW();

  EXPECT_EQ(target, test);
}

TEST(CubeTests, LeftCW) {
  TestCube target;
  target.SetPosition(Face::Front, 0, 0, ComputeValue(Face::Up, 0, 0));
  target.SetPosition(Face::Front, 1, 0, ComputeValue(Face::Up, 1, 0));
  target.SetPosition(Face::Front, 2, 0, ComputeValue(Face::Up, 2, 0));
  target.SetPosition(Face::Down, 0, 0, ComputeValue(Face::Front, 0, 0));
  target.SetPosition(Face::Down, 1, 0, ComputeValue(Face::Front, 1, 0));
  target.SetPosition(Face::Down, 2, 0, ComputeValue(Face::Front, 2, 0));
  target.SetPosition(Face::Back, 0, 2, ComputeValue(Face::Down, 2, 0));
  target.SetPosition(Face::Back, 1, 2, ComputeValue(Face::Down, 1, 0));
  target.SetPosition(Face::Back, 2, 2, ComputeValue(Face::Down, 0, 0));
  target.SetPosition(Face::Up, 0, 0, ComputeValue(Face::Back, 2, 2));
  target.SetPosition(Face::Up, 1, 0, ComputeValue(Face::Back, 1, 2));
  target.SetPosition(Face::Up, 2, 0, ComputeValue(Face::Back, 0, 2));
  target.SetPosition(Face::Left, 0, 0, ComputeValue(Face::Left, 2, 0));
  target.SetPosition(Face::Left, 0, 1, ComputeValue(Face::Left, 1, 0));
  target.SetPosition(Face::Left, 0, 2, ComputeValue(Face::Left, 0, 0));
  target.SetPosition(Face::Left, 1, 0, ComputeValue(Face::Left, 2, 1));
  target.SetPosition(Face::Left, 1, 2, ComputeValue(Face::Left, 0, 1));
  target.SetPosition(Face::Left, 2, 0, ComputeValue(Face::Left, 2, 2));
  target.SetPosition(Face::Left, 2, 1, ComputeValue(Face::Left, 1, 2));
  target.SetPosition(Face::Left, 2, 2, ComputeValue(Face::Left, 0, 2));

  TestCube test;
  test.LeftCW();

  EXPECT_EQ(target, test);
}

TEST(CubeTests, LeftCCW) {
  TestCube target;
  target.SetPosition(Face::Front, 0, 0, ComputeValue(Face::Down, 0, 0));
  target.SetPosition(Face::Front, 1, 0, ComputeValue(Face::Down, 1, 0));
  target.SetPosition(Face::Front, 2, 0, ComputeValue(Face::Down, 2, 0));
  target.SetPosition(Face::Down, 0, 0, ComputeValue(Face::Back, 2, 2));
  target.SetPosition(Face::Down, 1, 0, ComputeValue(Face::Back, 1, 2));
  target.SetPosition(Face::Down, 2, 0, ComputeValue(Face::Back, 0, 2));
  target.SetPosition(Face::Back, 0, 2, ComputeValue(Face::Up, 2, 0));
  target.SetPosition(Face::Back, 1, 2, ComputeValue(Face::Up, 1, 0));
  target.SetPosition(Face::Back, 2, 2, ComputeValue(Face::Up, 0, 0));
  target.SetPosition(Face::Up, 0, 0, ComputeValue(Face::Front, 0, 0));
  target.SetPosition(Face::Up, 1, 0, ComputeValue(Face::Front, 1, 0));
  target.SetPosition(Face::Up, 2, 0, ComputeValue(Face::Front, 2, 0));
  target.SetPosition(Face::Left, 0, 0, ComputeValue(Face::Left, 0, 2));
  target.SetPosition(Face::Left, 0, 1, ComputeValue(Face::Left, 1, 2));
  target.SetPosition(Face::Left, 0, 2, ComputeValue(Face::Left, 2, 2));
  target.SetPosition(Face::Left, 1, 0, ComputeValue(Face::Left, 0, 1));
  target.SetPosition(Face::Left, 1, 2, ComputeValue(Face::Left, 2, 1));
  target.SetPosition(Face::Left, 2, 0, ComputeValue(Face::Left, 0, 0));
  target.SetPosition(Face::Left, 2, 1, ComputeValue(Face::Left, 1, 0));
  target.SetPosition(Face::Left, 2, 2, ComputeValue(Face::Left, 2, 0));

  TestCube test;
  test.LeftCCW();

  EXPECT_EQ(target, test);
}