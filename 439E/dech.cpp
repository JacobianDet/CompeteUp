#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001
#define MOD 1000000007

typedef long long ll;

ll lo[CHOR], mu[CHOR], factx[CHOR], invf[CHOR];

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

void mob_sling(void)
{
	for(ll i=1;i<CHOR;i++)
	{
		lo[i] = i;
		mu[i] = 1;
	}
	for(ll p=2;p*p<CHOR;p++)
	{
		if(lo[p] == p)
		{
			for(ll i=p*p;i<CHOR;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}
		}
	}
	for(ll i=2;i<CHOR;i++)
	{
		ll j = i;
		while(lo[j/lo[j]] != lo[j])
		j /= lo[j];
		if(j != 1)
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];
	}
	return;
}

void factup(void)
{
	factx[0] = 1;
	invf[0] = 1;
	for(ll i=1;i<CHOR;i++)
	{
		factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
		invf[i] = modexp(factx[i], MOD-2);
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	factup();
	mob_sling();
	int q;
	std::cin>>q;
	while(q--)
	{
		ll n,f;
		ll ans = 0;
		std::cin>>n>>f;
		std::vector<ll> Z;
		ll t = n;
		while(t > 1)
		{
			ll ct = 0, p = lo[t];
			while(!(t % p))
			t /= p; 
			Z.pb(p);
		}
		int z = (int)Z.size();
		for(int i=0;i<(1<<z);i++)
		{
			ll fx = 1;
			for(int j=0;j<z;j++)
			{
				if(i & (1<<j))
				fx *= Z[j];	
			}
			if(n/fx >= f)
			{
				ll ax = ((factx[n/fx-1]%MOD) * (((invf[f-1]%MOD) * (invf[n/fx - f]%MOD))%MOD))%MOD;
				ans += (mu[fx] * ax);
				if(ans >= MOD)
				ans -= MOD;
				if(ans < 0)
				ans += MOD;	
			}
		}
		std::cout<<ans<<"\n";
	}
	return 0;
}
