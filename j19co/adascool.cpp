#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,m;
        std::cin>>n>>m;
        if(!(n & 1) || !(m & 1))
        std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
    return 0;
}