#include <bits/stdc++.h>
#define CHOR 10000001

typedef long long ll;

ll ctx[CHOR], pref[CHOR];
bool isP[CHOR];

void difsver(void)
{
    memset(isP, 1, sizeof(isP));
    isP[0] = 0;
    isP[1] = 0;
    for(ll p=2;p*p<=CHOR;p++)
    {
        if(isP[p])
        {
            for(ll i=p*p;i<CHOR;i+=p)
            isP[i] = 0;
        }
    }
    for(ll p=2;p<CHOR;p++)
    {
        if(isP[p])
        {
            for(ll i=p;i<CHOR;i+=p)
            pref[p] += ctx[i];
        }
    }
    for(ll i=1;i<CHOR;i++)
    pref[i] += pref[i-1];
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        std::cin>>t;
        ctx[t]++;
    }
    difsver();
    int m;
    std::cin>>m;
    while(m--)
    {
        ll l,r;
        std::cin>>l>>r;
        if(l >= CHOR)
        std::cout<<"0\n";
        else if(l < CHOR && r >= CHOR)
        std::cout<<(pref[CHOR-1] - pref[l-1])<<"\n";
        else std::cout<<(pref[r] - pref[l-1])<<"\n";
    }
    return 0;
}