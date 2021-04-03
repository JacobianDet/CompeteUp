#include <bits/stdc++.h>

typedef long long ll;

int lo[1000001], mu[1000001];

void mob_sling(void)
{
    for(int i=1;i<1000001;i++)
    {
        lo[i] = i;
        mu[i] = 1;
    }    
    for(int p=2;p*p<1000001;p++)
    {
        if(lo[p] == p)
        {
            for(int i=p*p;i<1000001;i+=p)
            {
                if(lo[i] == i)
                lo[i] = p;
            }
        }
    }
    for(int i=2;i<1000001;i++)
    {
        int j = i;
        while(lo[j/lo[j]] != lo[j])
        j /= lo[j];
        if(j != 1)
        mu[i] = 0;
        else mu[i] = -1*mu[i/lo[i]];
    }
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    mob_sling();
    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,m;
        std::cin>>n>>m;
        if(!m && !n)
        std::cout<<"Case "<<t<<": 0\n";
        else if(!n || !m)
        std::cout<<"Case "<<t<<": 1\n";
        else
        {
            if(m > n)
            {
                int tmp = m;
                m = n;
                n = tmp;
            }
            ll ans = 0;
            for(int i=1;i<=m;i++)
            {
                if(mu[i] != 0)
                ans += mu[i] * (1LL*n/i) * (1LL*m/i);
            }
            ans += 2;
            std::cout<<"Case "<<t<<": "<<ans<<"\n";
        }
    }
    return 0;
}
