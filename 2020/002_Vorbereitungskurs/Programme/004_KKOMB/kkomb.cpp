#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void f(int, int, std::vector<int> &, int, int);
void g(int, int, std::vector<int> &, int, int);
void printVec(std::vector<int> &);

void printVec(vector<int> &v)
{
  for (int num : v)
  {
    printf("%d ", num);
  }
  printf("\n");
}

//true = kommt dazu
void f(int n, int num, vector<int> &v, int k, int skipped)
{
  if (n + 1 == num)
  {
    printVec(v);
  }
  else
  {
    if (num - skipped <= k)
    {
      v.push_back(num);
      f(n, num + 1, v, k, skipped);
      v.pop_back();
    }
    if (skipped < n - k)
    {
      g(n, num + 1, v, k, skipped + 1);
    }
  }
}

//false = kommt nicht dazu
void g(int n, int num, vector<int> &v, int k, int skipped)
{
  if (n + 1 == num)
  {
    printVec(v);
  }
  else
  {
    if (num - skipped <= k)
    {
      v.push_back(num);
      f(n, num + 1, v, k, skipped);
      v.pop_back();
    }
    if (skipped < n - k)
    {
      g(n, num + 1, v, k, skipped + 1);
    }
  }
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> v;

  f(n, 1, v, k, 0);
}