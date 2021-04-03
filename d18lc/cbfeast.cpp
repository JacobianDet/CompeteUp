#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp std::make_pair

typedef long long ll;

std::deque<std::pair<ll, ll> > D;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int Q;
    ll k;
    std::cin>>Q>>k;
    ll ans = 0;
    for(int q=0;q<Q;q++)
    {
        int x;
        ll c;
        std::cin>>x>>c;
        c ^= ans;
        if((x == 1) || (x == 2))
        {
            ll d;
            std::cin>>d;
            if(x == 1)
            D.pf(mp(c, d));
            else D.pb(mp(c, d));
        }
        else
        {
            ll ansx1 = 0, ansx2 = 0, gans = 0;          
            for(std::deque<std::pair<ll, ll> >::iterator it = D.begin();it != D.end();it++)
            {
                if(it == D.begin())
                {
                    if(it->first >= c-k && it->first <= c+k)
                    {
                        ansx2 += it->second;
                        gans = std::max(gans, ansx2);
                    }     
                }
                else
                {
                    ansx1 = std::min(ansx1, ansx2);
                    if(it->first >= c-k && it->first <= c+k)
                    {
                        ansx2 += it->second;
                        gans = std::max(gans, ansx2 - ansx1);
                    }
                }
            }
            std::cout<<gans<<"\n";
            ans = gans;
        }
    }
    return 0;
}