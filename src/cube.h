#ifndef SRC_CUBE_H
#define SRC_CUBE_H

struct cube {
  char c[6][3][3];
  char (*right)[3][3] = &c[0];
  char (*up)[3][3] = &c[1];
  char (*front)[3][3] = &c[2];
  char (*left)[3][3] = &c[3];
  char (*down)[3][3] = &c[4];
  char (*back)[3][3] = &c[5];
};

#endif
