#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        long long n;
        std::cin>>n;
        if(n & 1)
        {
            for(long long j=1;j<=n-2;j++)
            {
                if(j & 1)
                std::cout<<j+1<<" ";
                else std::cout<<j-1<<" ";
            }
            std::cout<<n<<" "<<n-2<<std::endl;
        }
        else
        {
            for(long long j=1;j<=n;j++)
            {
                if(j & 1)
                std::cout<<j+1<<" ";
                else std::cout<<j-1<<" ";
            }
            std::cout<<std::endl;
        }
    }
    return 0;
}
