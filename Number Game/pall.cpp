#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

char* pall(int n)
{
  system("cls");
  int i,p=0,u;
  u=n;
  while(u!=0)
  {
    i=u%10;
    p=10*p+i;
    u/=10;
  }
  if(p==n)
  return "Number is a pallindrome number\n";
  else return "Number is not a pallindrome number\n";
}
