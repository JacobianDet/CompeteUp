#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int q;
    std::cin>>q;
    while(q--)
    {
        ll l,r,d;
        std::cin>>l>>r>>d;
        if(d < l)
        std::cout<<d<<"\n";
        else
        {
            ll x = (r/d);
            std::cout<<(x+1)*d<<"\n";
        }
    }
    return 0;
}