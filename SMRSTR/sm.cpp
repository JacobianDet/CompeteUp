#include <bits/stdc++.h>
#define ll long long

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        ll n,q,tp;
        std::cin>>n>>q;
        std::vector<ll> d(n);
        for(ll j=0;j<n;j++)
        std::cin>>d[j];
        for(ll j=0;j<q;j++)
        {
            std::cin>>tp;
            for(ll k=0;k<n;k+=2)
            {
                if(k == n-1 && n & 1)
                tp /= d[k];
                else tp = (tp/d[k])/d[k+1];
            }
            std::cout<<tp<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}
