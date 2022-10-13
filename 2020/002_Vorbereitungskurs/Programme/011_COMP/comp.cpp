#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;

int f(int n)
{
  if(visited[n])
  {
    return 0;
  }
  else
  {
    visited[n] = true;
    for(int i = 0;i<v[n].size();i++)
    {
      f(v[n][i]);
    }
  }
  
}

int main()
{
  //n = Knote, m = Kanten
  int n, m, count = 0;
  scanf("%d %d", &n, &m);
  v.resize(n);
  for (int i = 0; i < m; i++)
  {
    int to, from;
    scanf("%d %d", &to, &from);
    v[to-1].push_back(from-1);
    v[from-1].push_back(to-1);
  }

  for (int i = 0; i < n; i++)
  {
    visited.push_back(false);
  }

  for (int i = 0; i < n; i++)
  {
    if(!visited[i])
    {
      count++;
      f(i);
    }
  }
  printf("%d",count);
}