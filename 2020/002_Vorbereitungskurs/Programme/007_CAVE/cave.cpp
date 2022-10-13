#include <iostream>
#include "cave.h"
//#include "grader.cpp"

using namespace std;

void exploreCave(int N)
{
  int S[N] = {};
  int D[N];

  int firstClosed = tryCombination(S);
  while (firstClosed != -1)
  {
    for (int i = firstClosed; i < N; i++)
    {
      S[i] = (S[i] + 1) % 2;
    }
    firstClosed = tryCombination(S);
  }
  
  answer(S, D);
}
