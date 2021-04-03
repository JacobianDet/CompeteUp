#include <iostream>
#include <cstdlib>
#include <cstring>
#include "arm.h"
#include "pall.h"
#include "perf.h"

using namespace std;

char* arm(int);
char* pall(int);
char* perf(int);

int main()
{
  system("cls");
  int n,x;
  char ch,str[80];
  do
  {
    system("cls");
    cout<<"Welcome to Number Game.Please enter your number and the desired operation you want on it.\n1.Checking for armstrong number\n2.Checking for pallindrome number\n3.Checking for perfect number\n4.Exit\n";
    cin>>n>>x;
    switch(x)
    {
      case 1: strcpy(str,arm(n));
              cout<<str<<endl;
              break;
      case 2: strcpy(str,pall(n));
              cout<<str<<endl;
              break;
      case 3: strcpy(str,perf(n));
              cout<<str<<endl;
              break;
      case 4: return 0;
    }
    cout<<"Do you wish to continue(Y/y)\n";
    cin>>ch;
  }while(ch=='y'||ch=='Y');
  system("pause");
  return 0;
}
