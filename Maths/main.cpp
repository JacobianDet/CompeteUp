#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
  system("cls");
  int z,i;
  double u,v;
  float t=132.88;
  cout<<"Enter value of z\n";
  cin>>z;
  u=pow(z,4.0);
  i=pow(z,3.0);
  v=sqrt(z);
  cout.setf(ios_base::fixed);
  cout<<setprecision(9)<<u<<endl<<setprecision(11)<<v<<endl<<102.667<<endl;
  cout.unsetf(ios_base::fixed);
  cout<<setprecision(4)<<16.87886666655<<endl;
  cout<<setprecision(4)<<10248.887<<endl;
  cout<<i<<endl;
  cout.precision();
  cout<<t<<endl;
  system("pause");
  return 0;
}
