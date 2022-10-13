#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int main()
{
  map<int, string> m;

  m.insert({6, "Robin"});
  m[3] = "Lukas";

  if(m[0] == "")
  {
    printf("Leer\n");
  }
}