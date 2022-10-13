#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[] = {1,2,3,4,5,6,6,7,8};
int main()
{
  //frühest mögliches einfügen
  printf("%d ",lower_bound(arr, arr+9,6)-arr);
  //spätest mögliches einfügen
  printf("%d ",upper_bound(arr, arr+9,6)-arr);
}