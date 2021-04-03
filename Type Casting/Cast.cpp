#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  system("cls");
  int x,y,t;
  float z,w;
  cout<<"Enter values of x,t,z and y\n";
  cin>>x>>t>>z>>y;
  cout<<(char)98<<endl<<static_cast<float>(x)/y<<endl<<(float)(x*x)/y<<endl;
  w=z/t;
  cout<<w<<endl;
  system("pause");
  return 0;
}
