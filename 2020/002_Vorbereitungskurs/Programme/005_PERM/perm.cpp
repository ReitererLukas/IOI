#include <iostream>
#include <vector>

using namespace std;

void f(vector<int> &, vector<int> &);
void printVec(vector<int> &);

void f(vector<int> &v, vector<int> &result)
{
  if (v.size() == 0)
  {
    printVec(result);
  }
  else
  {
    //printf("%d ",num);
    for (int i = 0; i < v.size(); i++)
    {
      int num = v.front();
      v.erase(v.begin(), v.begin() + 1);
      result.push_back(num);
      f(v, result);
      result.pop_back();
      v.push_back(num);
    }
  }
}

void printVec(vector<int> &result)
{
  for (int num : result)
  {
    printf("%d ", num);
  }
  printf("\n");
}

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> v;
  vector<int> result;

  for (int i = 1; i <= n; i++)
  {
    v.push_back(i);
  }

  for (int i = 1; i <= n; i++)
  {
    int num = v.front();
    v.erase(v.begin(), v.begin() + 1);
    result.push_back(num);
    f(v, result);
    result.pop_back();
    v.push_back(num);
  }
}