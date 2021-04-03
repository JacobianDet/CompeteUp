#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        ll l,r;
        std::cin>>l>>r;
        std::cout<<((r*r) - ((l-1)*(l-1)))<<"\n";
    }
    return 0;
}