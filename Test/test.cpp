#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  system("cls");
  int n,a1,a2,i,sum=1;
  cout<<"Enter number of terms for fibonacci series\n";
  cin>>n;
  if(n==0)
  {
    cout<<"No term of series shown\nSum= 0\n";
    return 0;
  }
  if(n==1)
  {
    cout<<"Fibonacci series= 1+---\nSum= 1\n";
    return 0;
  }
  cout<<"Fibonacci series= 1+";
  for(i=1,a1=a2=1;i<n;i++)
  {
    cout<<a2<<"+";
    sum+=a2;
    a2=a1+a2;
    a1=a2-a1;
  }
  cout<<"---\nSum of series= "<<sum<<endl;
  system("pause");
  return 0;
}
