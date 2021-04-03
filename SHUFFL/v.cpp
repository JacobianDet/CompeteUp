#include <bits/stdc++.h>
#define ll long long
#define pb push_back

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        ll m,x,y;
        std::cin>>m>>x>>y;
        std::vector<ll> z(m);
        for(ll j=0;j<m;j++)
        z[j] = j+1;
        while(m > 2)
        {
            std::vector<ll> a,b;
            for(ll j=0;j<m;j++)
            {
                if(j & 1)
                a.pb(z[j]);
                else b.pb(z[j]);
            }
            int s = m*x/y;
            a.erase(a.begin()+s);
            b.erase(b.begin()+s);
            z.clear();
            for(ll j=0;j<m-2;j++)
            {
                ll t = a.size();
                if(j < t)
                z.pb(a[j]);
                else z.pb(b[j-t]);
            }
            m = z.size();
        }
        std::cout<<(z[0] ^ z[1])<<"\n";
    }
    return 0;
}
