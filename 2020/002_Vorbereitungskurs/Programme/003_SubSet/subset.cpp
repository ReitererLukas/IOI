#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


vector<int> v;

void printVec(vector<int> &v)
{
  for(int num:v)
  {
    printf("%d ",num);
  }
  printf("\n");
}

void f(int n, int num, vector<int> &v)
{
  if(n+1 == num)
  {
    printVec(v);
  }
  else
  {
    v.push_back(num);
    f(n,num+1,v);
    v.pop_back();
    f(n,num+1,v);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  
  f(n,1,v);
}