#include <iostream>
#include <string>
#include <cstdlib>
//Here I am only learning about class string in <string>
//input in string class variable as getline(cin,str,del)
//Stop using namespace std regularly

int main()
{
  system("cls");
  std::string s1,s2,s5("Chor hai tu");
  int l;
  char c1,c2;
  std::cout<<"Enter value in string\n";
  getline(std::cin,s1);
  s2=s1+" "+s5;
  s2+="anda";
  l=s2.length();
  c1=s2.front();
  c2=s2.back();
  std::string s3=s2.substr(5,12);
  std::size_t f,y;
  f=s2.find(s3,2);
  y=s2.find("hello everyone",0,5);
  if(f!=std::string::npos)
  std::cout<<"String found at position= "<<f<<"\n";
  if(y!=std::string::npos)
  std::cout<<"String found at position= "<<y<<"\n";
  std::cout<<s5<<std::endl<<s1<<std::endl<<s2<<std::endl<<l<<" "<<c1<<" "<<c2<<std::endl<<s3<<std::endl;
  system("pause");
  return 0;
}
