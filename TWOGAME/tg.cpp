#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        ll a, b;
        std::cin>>a>>b;
        ll gcx = std::__gcd(a, b);
        if(!(gcx & (gcx - 1)))
        std::cout<<"Y\n";
        else std::cout<<"N\n";
    }
    return 0;
}