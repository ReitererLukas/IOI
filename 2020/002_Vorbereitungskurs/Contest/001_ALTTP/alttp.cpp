#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
vector<int> res;
vector<int> afterOverflow;
bool overflow = false;
bool unSolv = false;
int N;

void printVec()
{
  for (int num : res)
  {
    printf("%d ", num);
  }
  for (int i = afterOverflow.size() - 1; i >= 0; i--)
  {
    printf("%d ", afterOverflow[i]);
  }
  printf("\n");
}

bool contain(vector<int> o, int n)
{
  for(int i = 0;i<o.size();i++)
  {
    if(o[i] == n)
    {
      return true;
    }
  }
  return false;
}

void f(int n, int count)
{
  if (visited[n])
  {
    return;
  }
  if (count == N)
  {
    if (res.size() == 0)
    {
      unSolv = true;
    }
    overflow = true;
    return;
  }
  else
  {
    for (int i = 0; i < v[n].size(); i++)
    {
      f(v[n][i], count + 1);
    }
    if (overflow)
    {
      if(!contain(afterOverflow,n+1))
      {
        afterOverflow.push_back(n + 1);
      }
    }
    else
    {
      res.push_back(n + 1);
    }
    visited[n] = true;
  }
}

void shiftOverflow()
{
  for (int i = afterOverflow.size() - 1; i >= 0; i--)
  {
    res.push_back(afterOverflow[i]);
  }
  overflow = false;
  afterOverflow.clear();
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  N = n;
  v.resize(n);
  for (int j = 0; j < m; j++)
  {
    int i, k;
    scanf("%d %d", &i, &k);
    for (int x = 0; x < k; x++)
    {
      int a;
      scanf(" %d", &a);
      v[i - 1].push_back(a - 1);
    }
  }

  for (int i = 0; i < n; i++)
  {
    visited.push_back(false);
  }

  vector<int> first;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i].size() == 0)
    {
      first.push_back(i);
      res.push_back(i+1);
      visited[i] = true;
    }
  }
  if(first.size() > 0)
  {
    f(first[0], 1);
    shiftOverflow();
  }
  for (int i = 0; i < visited.size(); i++)
  {
    if (!visited[i])
    {
      f(i, 1);
      shiftOverflow();
    }
  }
  if (unSolv)
  {
    printf("-1\n");
  }
  else
  {
    printVec();
  }
}