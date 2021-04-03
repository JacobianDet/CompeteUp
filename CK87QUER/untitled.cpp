#include <bits/stdc++.h>

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long y;
        std::cin>>y;
        long long c=0;
        for(long long b=1;b<=700;b++)
        if(y-b > 0)
        c += (long long)sqrt(y-b);
        else c += 0;
        std::cout<<c<<"\n";
    }
    return 0;
}
