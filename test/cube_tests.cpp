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
};

TEST(CubeTests, RightCW) {
  TestCube test;
  test.RightCW();
}
