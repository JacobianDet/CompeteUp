#include <bits/stdc++.h>
#define CHOR 10000001

typedef long long ll;

ll lo[CHOR];

void siever(void)
{
    for(ll i=1;i<CHOR;i++)
    lo[i] = i;
    for(ll i=2;i*i<CHOR;i++)
    {
        if(lo[i] == i)
        {
            for(ll p=i*i;p<CHOR;p+=i)
            {
                if(lo[p] == p)
                lo[p] = i;
            }
        }
    }
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    siever();
    int n;
    while(std::cin>>n)
    {
        ll t = n;
        std::cout<<"1";
        if(t > 1)
        std::cout<<" x ";
        while(t > 1)
        {
            ll p = lo[t];
            ll ct = 0;
            while(!(t % p))
            {
                ct++;
                t /= p;
            }
            for(int i=0;i<ct-1;i++)
            std::cout<<p<<" x ";
            if(ct)
            {
                std::cout<<p;
                if(t > 1)
                std::cout<<" x ";
            }    
        }
        std::cout<<"\n";
    }    
    return 0;
}