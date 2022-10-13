#include "hanoi.h"
#include "grader.cpp"
#include <iostream>
#include <time.h>

using namespace std;

void moveTower(int startPos, int endPos, int n, int freePos)
{
  if (n == 1)
  {
    move(startPos, endPos);
  }
  else
  {
    moveTower(startPos, freePos, n - 1, endPos);
    move(startPos, endPos);
    moveTower(freePos, endPos, n - 1, startPos);
  }
}

void hanoi(int n)
{
  moveTower(1, 2, n, 3);
}
