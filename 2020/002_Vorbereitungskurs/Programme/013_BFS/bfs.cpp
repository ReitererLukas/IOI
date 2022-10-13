#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
int n, m;

struct node
{
  int value;
  int ep;
};

void f()
{
  queue<node> q;
  bool found = false;
  q.push({0, 0});
  while (!q.empty() && !found)
  {
    node v = q.front();
    q.pop();

    if (v.value == n - 1)
    {
      printf("%d", v.ep);
      found = true;
    }

    for (int i = 0; i < edges[v.value].size(); i++)
    {
      if (!visited[edges[v.value][i]])
      {
        q.push({edges[v.value][i], v.ep + 1});
        visited[edges[v.value][i]] = true;
      }
    }
  }
  if (!found)
  {
    printf("-1");
  }
}

int main()
{
  scanf("%d %d", &n, &m);
  edges.resize(n);
  for (int i = 0; i < m; i++)
  {
    int to, from;
    scanf("%d %d", &to, &from);
    edges[to - 1].push_back(from - 1);
    edges[from - 1].push_back(to - 1);
  }
  for (int i = 0; i < n; i++)
  {
    visited.push_back(false);
  }

  f();
}