#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

ll fx[18], lo[100002];

void fibx(void)
{
    fx[0] = 1;
    for(int i=1;i<18;i++)
    fx[i] = (1LL * i) * fx[i-1];  
    return;
}

void siever(void)
{
    for(ll i=1;i<=100000;i++)
    lo[i] = i;
    for(ll i=2;i*i<=100000;i++)
    {
        if(lo[i] == i)
        {
            for(ll p=i*i;p<=100000;p+=i)
            {
                if(lo[p] == p)
                lo[p] = i;    
            }    
        }    
    }   
    return;
}

int main() {
    fibx();
    int T;
    std::cin>>T;
    while(T--)
    {
        ll n;
        std::cin>>n;
        ll sx = 0;
        ll t = n;
        std::vector<ll> Z;
        while(t > 1)
        {
            ll p = lo[t];
            ll ct = 0;
            while(lo[t] == p)
            {
                ct++;
                t /= p;
            }    
            Z.pb(ct);
            sx += ct;
        }    
        ll ax = fx[sx];
        for(int i=0,j=(int)Z.size();i<j;i++)
        ax /= fx[Z[i]];
        std::cout<<ax<<"\n";
    }
    return 0;
}