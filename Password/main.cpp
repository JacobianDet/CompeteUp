#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
  system("cls");
  char line[15];
  int count=3;
  while(count>0)
  {
  system("cls");
  cout<<"Enter password\n";
  cin.getline(line,11);
  if(strcmp(line,"usep4fordi")==0)
  {
   cout<<"\nPassword Accepted";
   break;
  }
  else
  {
    count--;
    cout<<"\nYou have "<<count<<" attempts remaining"<<endl;
  }
  system("pause");
  }
  return 0;
}
