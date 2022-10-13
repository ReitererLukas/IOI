#include <stdio.h>
#include <vector>

using namespace std;

void f(int n, vector<int> &v)
{
  if (n == 0)
  {
    for (int num:v)
    {
      printf("%d ", num);
    }
    printf("\n");
  }
  else
  {
    f(n - 1, v);
    v.push_back(n);
    f(n - 1, v);
    v.pop_back();
  }
}

void f1(int n, int num, vector<int> &v)
{
  if (n == num)
  {
    for (int num:v)
    {
      printf("%d ", num);
    }
    printf("\n");
  }
  else
  {
    f1(n + 1, num, v);
    v.push_back(n);
    f1(n + 1, num, v);
    v.pop_back();
  }
}

int main()
{
  vector<int> v;
  int n;
  scanf("%d", &n);
  f(n - 1, v);
  v.push_back(n);
  f(n - 1, v);
  v.pop_back();
  printf("\n");
  f1(1, n, v);
  v.push_back(n);
  f1(1, n, v);
  v.pop_back();
}