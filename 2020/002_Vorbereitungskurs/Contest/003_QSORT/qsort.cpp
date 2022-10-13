#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int c, n,k;

template <class Iterator>
int quicksort(Iterator bgn, Iterator end, int count)
{
  c = max(c, count);
  if (bgn == end)
    return 0;
  int p = *bgn;
  auto mid = std::stable_partition(bgn, end, [p](int x) { return x < p; });
  return 1 + std::max(quicksort(bgn, mid, count +1 ), quicksort(mid + 1, end, count + 1));
}

int fak(int n)
{
  int sum = 1;
  for(int i = 2;i<=n;i++)
  {
    sum *=i;
  }
  return sum;
}

void printPer(vector<int> &v)
{
  for(int num:v)
  {
    printf("%d ",num);
  }
  printf("\n");
}

void calc()
{
  vector<int> v;

  for(int i = 1;i<=n;i++)
  {
    v.push_back(i);
  }

  
  int fakul = fak(n);
  for(int i = 0;i<fakul;i++)
  {
    c = 0;
    //printPer(v);
    vector<int> vec = v;
    quicksort(vec.begin(),vec.end(),1);
    if(c == k)
    {
      printPer(v);
      return;
    }
    next_permutation(v.begin(),v.end());
  }
}

int main()
{
  scanf("%d %d", &n, &k);

  calc();
  if(c != k)
  {
    printf("-1");
  }
}