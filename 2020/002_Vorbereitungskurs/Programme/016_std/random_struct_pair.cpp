#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utility>
//#include <bits/stdc++.h> ==> fügt alle header ein

using namespace std;

struct node
{
  int value;
  int sum;
  node *left;
  node *right;

  bool operator<(node other)
  {
    return value < other.value;
  }
};

bool operator<(node a,node b)
{
  return a.value < b.value;
}

int main()
{
  pair<int, int> p = {3,5};
  pair<int, int> a = make_pair(3,6);
  if(p < a)
  {
    printf("wuhu\n");
  }

  node x;
  x.value = 3;
  x.sum = 4;
  x.left = &x;

  //seed random number generator
  srand(time(0));
  for(int i = 0;i<5;i++)
  {
    printf("%d ",rand());
  }
  printf("\n");

  for(int i = 0;i<15;i++)
  {
    //rand() % (OG - UG) + UG
    printf("%d ", rand() % (20 - 5) + 5);
  }
  printf("\n");
}