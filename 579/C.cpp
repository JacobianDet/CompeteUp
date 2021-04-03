#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

bool px[1000001];
std::vector<ll> pt;

void siever(void)
{
	memset(px, 1, sizeof(px));
	px[0] = 0;
	px[1] = 0;
	for(int p=2;p*p<1000001;p++)
	{
		if(px[p])
		{	
			for(int i=p*p;i<1000001;i+=p)
			px[i] = 0;
		}		
	}
	for(int i=1;i<1000001;i++)
	{
		if(px[i])
		pt.pb(i);
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
    std::cin>>n;
    ll gx = 0;
    for(int i=0;i<n;i++)
    {
    	ll x;
    	std::cin>>x;
    	gx = std::__gcd(gx, x);
    }
    ll res = 1;
    for(auto u : pt)
    {
    	if(!(gx % u))
    	{
    		ll vx = u;
    		ll ct = 0;
    		while(!(gx % vx))
    		{
    			gx /= vx;
    			ct++;
    		}
    		res *= (ct + 1);
    	}	
    }
    if(gx > 1)
    res *= 2;
    std::cout<<res<<"\n";
    return 0;	
}    