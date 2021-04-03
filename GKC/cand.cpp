#include <bits/stdc++.h>
#define pb push_back
#define pof pop_front 
#define CHOR 500005
#define NINF -10000000000000000

typedef long long ll;

ll xval[CHOR];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,o;
		ll d;
		std::cin>>n>>o>>d;
		ll x1,x2,a,b,c,m,l;
		std::cin>>x1>>x2>>a>>b>>c>>m>>l;
		xval[1] = x1;
		xval[2] = x2;
		for(int i=3;i<=n;i++)
		xval[i] = ((((((a%m) * (xval[i-1]%m))%m) + (((b%m) * (xval[i-2]%m))%m))%m) + (c%m))%m;
		ll dsum = 0, dodd = 0;
		std::deque<ll> D;
		ll ans = NINF;
		for(int i=1;i<=n;i++)
		{
			ll av = xval[i] + l;
			if(av < 0)
			av = -av;	
			while(!D.empty() && ((dsum + xval[i] + l > d) || ((av & 1) && (dodd + 1 > o))))
			{
				ll u = D.front();
				D.pof();
				dsum -= u;
				if(u < 0)
				u = -u;	
				if(u & 1)
				dodd--;
			}
			if((dsum + xval[i] + l > d) || ((av & 1) && (dodd + 1 > o)))
			continue;
			else
			{
				D.pb(xval[i] + l);
				dsum += (xval[i] + l);
				if(av & 1)
				dodd++;	
				ans = std::max(ans, dsum);
			}	
		}
		std::cout<<"Case #"<<t<<": ";
		if(ans == NINF)
		std::cout<<"IMPOSSIBLE\n";
		else std::cout<<ans<<"\n";	
	}
	return 0;
}