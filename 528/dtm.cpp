#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll n,k;
    std::cin>>n>>k;
    for(ll i=k-1;i>0;i--)
    {
        if(!(n % i))
        {
            std::cout<<((n/i)*k + i)<<"\n";
            break;
        }
    }
    return 0;
}