#include <iostream>
int main()
{
  unsigned long long N,R,G;
  std::cin>>N>>R;
  if(N>0&&R>0)
  {
    for(G=1;G<=R;G++)
    {
      if(G!=1)
      std::cout<<" ";
      N=2*N-1;
      std::cout<<N;
    }
  }
  return 0;
}
