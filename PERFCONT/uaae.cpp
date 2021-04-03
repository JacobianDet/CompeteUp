#include <bits/stdc++.h>

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long n,p;
        std::cin>>n>>p;
        std::vector<long long> x(n);
        for(long long j=0;j<n;j++)
        std::cin>>x[j];
        long long C=0,H=0;
        for(long long j=0;j<n;j++)
        {
            if(x[j] <= p/10)
            H++;
            else if(x[j] >= p/2)
            C++;
        }
        if(H == 2 && C == 1)
        std::cout<<"yes"<<std::endl;
        else std::cout<<"no"<<std::endl;
    }
    return 0;
}
