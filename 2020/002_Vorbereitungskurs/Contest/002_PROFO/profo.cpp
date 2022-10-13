#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tmp;
vector<vector<bool>> ob;
pair<int, int> goal;
int n, m, k, r;

void findObs()
{
  ob.resize(m);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ob[i].push_back(false);
    }
  }

  for (int i = 0; i < tmp.size(); i++)
  {
    ob[tmp[i][0] - 1][tmp[i][1] - 1] = true;
    ob[tmp[i][2] - 1][tmp[i][3] - 1] = true;
  }
}

bool hitsOb(int x, int y)
{
  if (x >= m || y >= n)
  {
    return false;
  }
  return ob[x - 1][y - 1];
}

//prev: 0 = aufi, 1 = rechts
int f(int x, int y, int prev, int hops)
{
  if (x > m || y > n)
  {
    return 0;
  }
  if (hops == k)
  {
    int s = 1;
    if (prev == 1)
    {
      if (!hitsOb(x, y + 1) && y < n)
      {
        s = f(x, y + 1, 0, 1);
      }
    }
    else
    {
      if (!hitsOb(x + 1, y) && x < m)
      {
        s = f(x + 1, y, 1, 1);
      }
    }
    //printf("S: %d\n", s);
    return s;
  }
  else
  {
    int s1 = 0, s2 = 0;
    bool b1 = true, b2 = true;
    if (prev == 0)
    {
      if (!hitsOb(x, y + 1) && y < n)
      {
        s1 = f(x, y + 1, prev, hops + 1);
        b1 = false;
      }
      if (!hitsOb(x + 1, y) && x < m)
      {
        s2 = f(x + 1, y, 1, 1);
        b2 = false;
      }
    }
    else //prev == 1
    {
      if (!hitsOb(x + 1, y) && x < m)
      {
        s1 = f(x + 1, y, prev, hops + 1);
        b1 = false;
      }
      if (!hitsOb(x, y + 1) & y < n)
      {
        s2 = f(x, y + 1, 0, 1);
        b2 = false;
      }
    }
    if (b1 && b2)
    {
      return 1;
    }
    else
    {
      return s1 + s2;
    }
  }
}

int main()
{
  scanf("%d %d %d %d", &n, &m, &k, &r);
  goal = {m, n};
  tmp.resize(r);
  for (int i = 0; i < r; i++)
  {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    tmp[i].push_back(b);
    tmp[i].push_back(a);
    tmp[i].push_back(d);
    tmp[i].push_back(c);
  }
  //printf("%d %d\n", n, m);
  findObs();
  printf("%d\n", f(1, 1, 0, 0));
  /*for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < m; j++)
    {
      if (ob[j][i])
      {
        printf("1 ");
      }
      else
      {
        printf("0 ");
      }
    }
    printf("\n");
  }*/
}