#include <set>
#include <stdio.h>

using namespace std;

int arr[] = {1,2,3,4,5};

int main()
{
  //arr[5] == arr.end()
  for(int* i = arr;i != arr + 5;i++)
  {
    printf("%d ", *i);
  }
  printf("\n");

  set<int> s;
  s.insert(8);
  s.insert(3);
  s.insert(6);
  s.insert(1);
  s.insert(2);
  s.insert(22);
  s.insert(5);

  for(set<int>::iterator i = s.begin(); i!= s.end();i++)
  {
    printf("%d ", *i);
  }
  printf("\n");

  for(auto  i = s.begin(); i != s.end(); i++)
  {
    printf("%d ", *i);
  }
  printf("\n");

  for(int i:s)
  {
    printf("%d ", i);
  }
  printf("\n");
}