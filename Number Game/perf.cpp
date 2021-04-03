#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

char* perf(int n)
{
  system("cls");
  int i,perf=1;
  for(i=2;i<n;i++)
  {
    if(n%i==0)
    perf+=i;
  }
  if(perf==n)
  return "Number is a perfect number\n";
  else return "Number is not a perfect number\n";
}
