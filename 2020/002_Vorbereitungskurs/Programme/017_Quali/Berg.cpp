#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX_N 10000005

int n, v[MAX_N];

int main()
{
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf(" %d", v + i);
  }

  stack<int> st;
  int rs = 0;
  st.push(v[0]);
  bool isOver = false;
  for(int i = 1;i < n;i++)
  {
    isOver = false;
    while(!st.empty() && !isOver)
    {
      int num = st.top();
      if(v[i] > num)
      {
        printf("Pop: %d\n",num);
        st.pop();
        if(st.empty())
        {
          printf("Push: %d\n",v[i]);
          st.push(v[i]);
          isOver = true;
        }
      }
      else if(num == v[i])
      {
        printf("%d %d %d\n",num,v[i],i);
        printf("Push: %d\n",v[i]);
        st.push(v[i]);
        rs += 2;
        isOver = true;
      }
      else
      {
        printf("Push: %d\n",v[i]);
        st.push(v[i]);
        isOver = true;
      }
    }
  }
  printf("%d\n",rs);
}