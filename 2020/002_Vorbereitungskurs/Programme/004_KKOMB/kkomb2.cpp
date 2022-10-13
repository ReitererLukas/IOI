#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;
int K;

void f(int n, int k)
{
  if (n == 0)
  {
    if (v.size() == K)
    {
      for (int num : v)
      {
        printf("%d ", num);
      }
      printf("\n");
    }
  }
  else
  {
    f(n - 1, k);
    if (k != 0)
    {
      v.push_back(n);
      f(n - 1, k - 1);
      v.pop_back();
    }
  }
}

void f1(int n, int num, int k)
{
  if (n == num)
  {
    if (v.size() == K)
    {
      for (int num : v)
      {
        printf("%d ", num);
      }
      printf("\n");
    }
  }
  else
  {
    f1(n + 1, num, k);
    if (k != 0)
    {
      v.push_back(n);
      f1(n + 1, num, k - 1);
      v.pop_back();
    }
  }
}

int main()
{
  int n;
  scanf("%d %d", &n, &K);

  f(n - 1, K);
  v.push_back(n);
  f(n - 1, K - 1);
  v.pop_back();
  printf("\n");
  f1(1, n, K);
  v.push_back(n);
  f1(1, n, K - 1);
  v.pop_back();
}