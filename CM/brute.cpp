#include <bits/stdc++.h>
#define MOD 490019

typedef long long ll;

ll sml[MOD+1], lml[MOD+1];

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,k;
	std::cin>>n>>k;
	if(n <= MOD)
	{
		for(ll i=1;i<=n;i++)
		{
			sml[i] = i;
			lml[i] = i;
		}	
	}	
	else
	{	
		ll mx = n%MOD;
		if(!mx)
		mx = MOD;	
		ll cx = mx;
		lml[mx] = n;
		sml[mx] = mx;
		cx = (cx - 1 + MOD)%MOD;
		if(!cx)
		cx = MOD;	
		ll fx = 1;
		while(cx != mx)
		{
			lml[cx] = n - fx;
			sml[cx] = cx;
			fx++;
			cx = (cx - 1 + MOD)%MOD;
			if(!cx)
			cx = MOD;
		}
	}	
	ll ax = 0;
	for(ll i=1;i<=std::min(n, 1LL*MOD);i++)
	{
		ll dx = (lml[i] - sml[i])/MOD + 1;
		ax = ((ax%MOD) + (((dx%MOD) * ((((i%MOD) * (i%MOD))%MOD))%MOD)))%MOD;
	}	
	ax = ((((ax%MOD) * (k%MOD))%MOD) * (modexp(n, k-1)%MOD))%MOD;
	std::cout<<ax<<"\n";
	return 0;
}