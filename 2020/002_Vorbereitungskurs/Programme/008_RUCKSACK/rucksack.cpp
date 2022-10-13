#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int, int);
int dp[5005][2005];
vector<int> v[5005];

int f(int n, int V)
{
  if (dp[n][V] != 0)
  {
    return dp[n][V];
  }
  if (n == 0)
  {
    return 0;
  }
  else
  {
    int s1 = -1;
    if (V - v[n - 1].front() >= 0)
    {
      s1 = f(n - 1, V - v[n - 1].front()) + v[n - 1].back();
    }
    int s2 = f(n - 1, V);
    return dp[n][V] = max(s1, s2);
  }
}

int main()
{
  int V, n;
  scanf("%d %d", &V, &n);
  for (int i = 0; i < n; i++)
  {
    int wi, vi;
    scanf("%d %d", &vi, &wi);
    v[i].push_back(vi);
    v[i].push_back(wi);
  }
  printf("%d\n", f(n, V));
}