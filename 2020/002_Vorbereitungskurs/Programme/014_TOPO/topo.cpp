#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ahead;

void f(int n, vector<bool> &visited)
{
  if (visited[n])
  {
    return;
  }
  else
  {
    visited[n] = true;
    for (int i = 0; i < ahead[n].size(); i++)
    {
      f(ahead[n][i], visited);
    }
    printf("%d ", n + 1);
  }
}

int main()
{
  int m, n;
  scanf("%d %d", &n, &m);

  ahead.resize(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    ahead[b - 1].push_back(a - 1);
  }

  vector<bool> visited;
  for (int i = 0; i < n; i++)
  {
    visited.push_back(false);
  }

  for(int i= 0;i<visited.size();i++)
  {
    if(!visited[i])
    {
      f(i, visited);
    }
  }
  printf("\n");
}