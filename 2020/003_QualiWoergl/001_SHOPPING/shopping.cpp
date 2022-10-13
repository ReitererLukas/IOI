#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int P, B, R;
vector<pair<int, int>> v;
vector<int> p;
vector<vector<vector<int>>> dp;

int f(int n, int bu, int nR)
{
  if (dp[n][bu][nR] != 0)
  {
    //printf("DP: %d\n",dp[n][bu][nR]);
    return dp[n][bu][nR];
  }
  if (bu == 0 || n == 0)
  {
    int va3 = 0, va1 = 0;
    if (nR > 0 && n > 0)
    {
      pair<int, int> product = v.back();
      v.pop_back();
      va1 = f(n - 1, bu, nR);

      int pr = product.first;
      int per = p.back();
      p.pop_back();
      pr -= (pr * (per / 100.0));
      if (pr == 0)
      {
        va3 = f(n - 1, bu, nR - 1) + product.second;
      }
      p.push_back(per);
      v.push_back(product);
    }
    return dp[n][bu][nR] = max(va1, va3);
  }
  else
  {
    pair<int, int> product = v.back();
    v.pop_back();
    int va1 = 0, va2 = 0, va3 = 0;
    va1 = f(n - 1, bu, nR);
    if (bu - product.first >= 0)
    {
      va2 = f(n - 1, bu - product.first, nR) + product.second;
    }
    if (nR > 0)
    {
      int pr = product.first;
      int per = p.back();
      p.pop_back();
      pr -= (pr * (per / 100.0));
      if (bu - pr >= 0)
      {
        va3 = f(n - 1, bu - pr, nR - 1) + product.second;
      }
      p.push_back(per);
    }
    v.push_back(product);
    return dp[n][bu][nR] = max(va1, max(va2, va3));
  }
}
int main()
{
  scanf("%d %d %d", &P, &B, &R);
  int n = 0;
  vector<vector<int>> tmp;
  tmp.resize(P);
  int maxV = 0;
  
  for (int i = 0; i < P; i++)
  {
    int e, vk, a;
    scanf("%d %d %d", &e, &vk, &a);
    n += a;
    tmp[i].push_back(e);
    tmp[i].push_back(vk);
    tmp[i].push_back(a);
    maxV = max(maxV,vk);
  }

  for (int i = 0; i < tmp.size(); i++)
  {
    int s = tmp[i].back();
    for (int j = 0; j < s; j++)
    {
      v.push_back({tmp[i][0], tmp[i][1]});
    }
  }
  
  for (int i = 0; i < R; i++)
  {
    int pro;
    scanf(" %d", &pro);
    p.push_back(pro);
  }
  //printf("%d %d %d\n",R,p.size(), v.size());

  dp.resize(n + 1);
  for (int i = 0; i < dp.size(); i++)
  {
    dp[i].resize(B + 1);
    for (int j = 0; j < dp[i].size(); j++)
    {
      dp[i][j].resize(R + 1);
    }
  }

  printf("%d\n", f(v.size(), B, R));
}