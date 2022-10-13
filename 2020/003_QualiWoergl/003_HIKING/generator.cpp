#include <stdio.h>
#include <vector>

#define MAX_N 1000000;
#define MAX_H 10000000;

using namespace std;

vector<int> v;

void generateSub2()
{

}

int main()
{
  int n;
  scanf("%d",&n);

  if(n == 2)
  {
    generateSub2();
  }

  for(int n:v)
  {
    printf("%d\n",n);
  }
}