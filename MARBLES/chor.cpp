#include <bits/stdc++.h>

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long n,k;
        std::cin>>n>>k;
        long long ans=1;
        long long chor = std::min(n-k,k-1);
        for(long long j=1;j<=chor;j++)
        {
            ans = ans*(n-j)/j;
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}
