#include <iostream>
#include <vector>

using namespace std;

vector<int> v[5005];
int dp[5005][2005];

int recursiveSolution(int n, int V)
{
  if (n == 0)
  {
    return 0;
  }
  else
  {
    int s1 = -1;
    if (V - v[n - 1].front() >= 0)
    {
      s1 = recursiveSolution(n - 1, V - v[n - 1].front()) + v[n - 1].back();
    }
    return max(s1, recursiveSolution(n - 1, V));
  }
}

int dpSolution(int n, int V)
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
      s1 = dpSolution(n - 1, V - v[n - 1].front()) + v[n - 1].back();
    }
    return max(s1, dpSolution(n - 1, V));
  }
}

int main()
{
  int n, V;
  scanf("%d %d", &V, &n);
  for (int i = 0; i < n; i++)
  {
    int vi, wi;
    scanf("%d %d", &vi, &wi);
    v[i].push_back(vi);
    v[i].push_back(wi);
  }

  //printf("%d",recursiveSolution(n,V));
  printf("%d",dpSolution(n,V));
}