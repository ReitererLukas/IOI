#include <iostream>
#include <vector>
#include <math.h>
#define MOD 1000000007

using namespace std;

int f(int, int);
int dp[1005][1005];

int f(int n, int k)
{
  if(dp[n][k] != 0)
  {
    return dp[n][k];
  }
  if (n == 0)
  {
    return 1;
  }
  if (k > n)
  {
    return 0;
  }
  else
  {
    int count = 0;
    for (int i = k; i <= n; i++)
    {
      count = ((f(n - i, i) % MOD) + (count % MOD)) % MOD;
    }
    return dp[n][k] = count;
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("%d", f(n, 1));
}