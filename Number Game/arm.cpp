#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

char* arm(int n)
{
  system("cls");
  int u,t,a,i=0;
  double b;
  u=n;
  while(u!=0)
  {
    i++;
    u/=10;
  }
  for(u=n,b=0;u!=0;u/=10)
  {
    t=u%10;
    b+=pow(t,i);
  }
  a=b;
  if(a==n)
  return "Number is armstrong number\n";
  else return "Number is not armstrong number\n";
}
