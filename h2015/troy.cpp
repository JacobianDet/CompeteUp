#include <bits/stdc++.h>
#define MOD 1000000007
#define CHOR 100100

typedef long long ll;

ll xt[CHOR], p[CHOR], f[CHOR];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,q;
	std::cin>>n>>q;
	ll x,y;
	std::cin>>x>>y;
	ll a,b;
	std::cin>>a>>b;
	for(ll i=1;i<=n;i++)
	std::cin>>xt[i];
	for(ll i=1;i<=n;i++)
	{
		if(i == 1)
		f[i] = x%MOD;
		else if(i == 2)
		f[i] = y%MOD;
		else f[i] = ((a%MOD * f[i-2]%MOD)%MOD + (b%MOD * f[i-1]%MOD)%MOD)%MOD;	
	}	
	while(q--)
	{
		ll l,r;
		std::cin>>l>>r;
		if(l < r)
		{
			p[l] = (p[l]%MOD + f[1]%MOD)%MOD;
			p[l+1] = (p[l+1]%MOD + f[2]%MOD)%MOD;
			p[l+1] = (p[l+1]%MOD + MOD - (b%MOD * f[1])%MOD)%MOD;
			p[r+1] = (p[r+1]%MOD + MOD - f[r-l+2]%MOD)%MOD;
			p[r+2] = (p[r+2]%MOD + MOD - (a%MOD * f[r-l+1]%MOD)%MOD)%MOD;	
		}	
		else 
		{
			p[l] = (p[l]%MOD + f[1]%MOD)%MOD;
			p[r+1] = (p[r+1]%MOD + MOD - (b%MOD * f[1]%MOD)%MOD)%MOD;
			p[r+2] = (p[r+2]%MOD + MOD - (a%MOD * f[1]%MOD)%MOD)%MOD;	
		}	
	}	
	for(ll i=1;i<=n;i++)
	{
		if(i > 2)
		p[i] = (p[i]%MOD + (a%MOD * p[i-2]%MOD)%MOD)%MOD;
		if(i > 1)
		p[i] = (p[i]%MOD + (b%MOD * p[i-1]%MOD)%MOD)%MOD;
	}	
	for(ll i=1;i<=n;i++)
	{
		xt[i] = (xt[i]%MOD + p[i]%MOD)%MOD;
		std::cout<<xt[i]<<" ";
	}
	std::cout<<"\n";
	return 0;	
}