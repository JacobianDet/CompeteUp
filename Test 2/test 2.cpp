#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  system("cls");
  char a[80],b[30];
  int i,j,count=0;
  cout<<"Enter string and substring to be found\n";
  cin.getline(a,80);
  cin.getline(b,30);
  for(i=0;a[i]!='\0';i++)
  {
    if(a[i]==b[0])
    {
      for(j=1;(a[i+j]!='\0')&&(b[j]!='\0');j++)
      {
        if(a[i+j]!=b[j])
        break;
      }
      if(b[j]=='\0')
      count++;
    }
  }
  if(count==0)
  cout<<"Substring not found\n";
  else cout<<"Substring found "<<count<<" times\n";
  system("pause");
  return 0;
}
