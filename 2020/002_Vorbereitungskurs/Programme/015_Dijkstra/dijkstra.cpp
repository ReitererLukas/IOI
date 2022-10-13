#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
  int w;
  int n;
};

struct Node
{
  int w;
  int n;
  vector<int> p;
};

vector<vector<Edge>> v;

bool operator>(const Node &a, const Node &b)
{
  return a.w > b.w;
}

bool operator<(const Node &a, const Node &b)
{
  return a.w < b.w;
}

void printSol(int w, vector<int> &p)
{
  printf("%d\n", w * -1);
  for (int num : p)
  {
    printf("%d ", num + 1);
  }
  printf("\n");
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  v.resize(n);

  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    v[a - 1].push_back({w, b - 1});
    v[b - 1].push_back({w, a - 1});
  }

  vector<bool> flag;

  for (int i = 0; i < n; i++)
  {
    flag.push_back(false);
  }

  priority_queue<Node> qu;
  qu.push({-0, 0, {0}});
  while (!qu.empty() && !flag[n])
  {
    Node node = qu.top();
    qu.pop();
    if (!flag[node.n])
    {
      for (int i = 0; i < v[node.n].size(); i++)
      {
        node.p.push_back(v[node.n][i].n);
        qu.push({((node.w * -1) + v[node.n][i].w) * -1, v[node.n][i].n, node.p});
        node.p.pop_back();
      }
      flag[node.n] = true;
      if (node.n == n - 1)
      {
        printSol(node.w, node.p);
      }
    }
  }
  if (!flag.back())
  {
    printf("-1\n");
  }
}