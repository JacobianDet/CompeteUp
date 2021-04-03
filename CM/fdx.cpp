#include <bits/stdc++.h>
#define pb push_back
#define MOD 1000000007

typedef long long ll;

std::vector<ll> px;
bool isP[30000001];

void siever(void)
{
	memset(isP, 1, sizeof(isP));
	isP[0] = 0;
	isP[1] = 0;
	for(ll p=2;p*p<30000001;p++)
	{
		if(isP[p])
		{
			for(ll i=p*p;i<30000001;i+=p)
			isP[i] = 0;	
		}	
	}	
	for(ll p=2;p<30000001;p++)
	{
		if(isP[p])
		px.pb(p);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	ll n;
	std::cin>>n;
	ll dx = 1;
	for(int i=0,j=(int)px.size();i<j;i++)
	{
		ll p = px[i], z = n, cx = 0;
		while(z)
		{
			cx += (z/p);
			z /= p;
		}	
		dx = ((dx%MOD) * ((cx + 1)%MOD))%MOD;
	}	
	std::cout<<dx<<"\n";
	return 0;
}