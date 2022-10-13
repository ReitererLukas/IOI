#include "hanoi.h"
#include "grader.cpp"
#include <stdio.h>

using namespace std;

void moveTower(int startPos, int targetPos, int freePos, int n)
{
  if(n == 1)
  {
    move(startPos, targetPos);
  }
  else
  { 
    moveTower(startPos,freePos,targetPos,n-1);
    move(startPos,targetPos);
    moveTower(freePos,targetPos,startPos,n-1);
  }
}

void hanoi(int n)
{
  moveTower(1,2,3,n);
}