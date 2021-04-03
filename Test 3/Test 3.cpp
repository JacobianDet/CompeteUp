#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
  system("cls");
  std::string a;
  std::size_t i,j,k;
  std::cout<<"Enter value of string\n";
  getline(std::cin,a);
  for(i=0;i<a.length();i++)
  {
    if(a[i]>='a'&&a[i]<='z')
    a[i]-=32;
  }
  if(a[0]=='A'||a[0]=='E'||a[0]=='I'||a[0]=='O'||a[0]=='U')
  a+="WAY";
  else
  {
    for(i=1;i<a.length();i++)
    {
      if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
      {
       for(j=i;j<a.length();j++)
       {
         for(k=j;k>j-i;k--)
         {
          a[k-1]+=a[k];
          a[k]=a[k-1]-a[k];
          a[k-1]-=a[k];
         }
       }
       break;
      }
    }
    a+="AY";
  }
  std::cout<<"Piglatin form= "<<a<<std::endl;
  system("pause");
  return 0;
}
