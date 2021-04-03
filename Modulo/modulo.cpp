#include <iostream>
#include <cstdlib>
int modularExponentiation(int x,int n,int M);
int main(void)
{
    system("cls");
    std::cout<<"Enter x,n and m"<<std::endl;
    int x,n,m;
    std::cin>>x>>n>>m;
    int ans= modularExponentiation(x,n,m);
    std::cout<<ans<<std::endl;
    system("pause");
    return 0;
}

int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0) //n is even
        return modularExponentiation((x*x)%M,n/2,M)%M;
    else //n is odd
        return ((x%M)*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
