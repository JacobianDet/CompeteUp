#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll n;
    std::cin>>n;
    std::set<ll> Z;
    for(ll i=1;i*i<=n;i++)
    {
        if(!(n % i))
        {
            if(i*i == n)
            Z.insert((n * (2 + n - i))/(2*i));
            else
            {
                Z.insert((n * (2 + n - i))/(2*i));
                Z.insert((n * (2 + n - n/i))/(2*(n/i)));
            }
        }    
    }
    for(std::set<ll>::iterator it = Z.begin();it != Z.end();it++)
    std::cout<<*it<<" ";
    std::cout<<"\n";
    return 0;
}