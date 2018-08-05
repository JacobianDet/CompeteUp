#include <bits/stdc++.h>
#define MOD 1000000007
#define CHOR 100001
#define pb push_back

typedef long long ll;

ll lo[CHOR], mu[CHOR], f[CHOR], fn[CHOR];

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

void fun1(ll k)
{
	for(ll i=1;i<CHOR;i++)
	{
		lo[i] = i;
		mu[i] = 1;
	}	
	for(ll i=2;i<CHOR;i++)
	{
		if(lo[i] == i)
		{
			for(ll j=i*i;j<CHOR;j+=i)
			{
				if(lo[j] == j)
				lo[j] = i;	
			}	
		}	
	}
	for(ll i=2;i<CHOR;i++)
	{
		ll j=i;
		while(lo[j/lo[j]] != lo[j])
		j /= lo[j];
		if(j != 1)
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];
	}	
	for(ll i=1;i<CHOR;i++)
	{
		for(ll j=i;j<CHOR;j+=i)
		{
			if(mu[i] == 1)
			f[j] = (f[j]%MOD + ((modexp(j, k)%MOD) * (modexp(modexp(i, k), MOD-2)%MOD))%MOD)%MOD;
			else if(mu[i] == -1)
			f[j] = (f[j]%MOD - ((modexp(j, k)%MOD) * (modexp(modexp(i, k), MOD-2)%MOD))%MOD + MOD)%MOD;	
		}
	}	
	for(ll i=1;i<CHOR;i++)
	fn[i] = (fn[i-1]%MOD + f[i]%MOD)%MOD;	
	return;
}

int main(void)
{
	ll k;
	std::cin>>k;
	fun1(k);
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll l,r;
		std::cin>>l>>r;
		l--;
		ll G1 = 0, G2 = 0;
		std::vector<ll> zex1;
		std::vector<ll> zex2;
		for(ll i=1,lx=0;i<=r;i=lx+1)
		{
			zex1.pb(i);
			lx = r/(r/i);
		}	
		for(ll i=0,j=(ll)zex1.size();i<j;i++)
		{
			if(i != j-1)
			G1 = (G1%MOD + (((((r/zex1[i])%MOD) * (((r/zex1[i])%MOD + 1%MOD)%MOD) * (modexp(2, MOD-2)%MOD))%MOD) * ((fn[zex1[i+1]-1]%MOD - fn[zex1[i]-1]%MOD + MOD)%MOD))%MOD)%MOD;
			else G1 = (G1%MOD + (((((r/zex1[i])%MOD) * (((r/zex1[i])%MOD + 1%MOD)%MOD) * (modexp(2, MOD-2)%MOD))%MOD) * ((fn[r]%MOD - fn[zex1[i]-1]%MOD + MOD)%MOD))%MOD)%MOD; 
		}
		if(l)
		{	
			for(ll i=1,lx=0;i<=l;i=lx+1)
			{
				zex2.pb(i);
				lx = l/(l/i);
			}	
			for(ll i=0,j=(ll)zex2.size();i<j;i++)
			{
				if(i != j-1)
				G2 = (G2%MOD + (((((l/zex2[i])%MOD) * (((l/zex2[i])%MOD + 1%MOD)%MOD) * (modexp(2, MOD-2)%MOD))%MOD) * ((fn[zex2[i+1]-1]%MOD - fn[zex2[i]-1]%MOD + MOD))%MOD)%MOD)%MOD;
				else G2 = (G2%MOD + (((((l/zex2[i])%MOD) * (((l/zex2[i])%MOD + 1%MOD)%MOD) * (modexp(2, MOD-2)%MOD))%MOD) * ((fn[l]%MOD - fn[zex2[i]-1]%MOD + MOD)%MOD))%MOD)%MOD; 
			}
			G1 = (G1%MOD - G2%MOD + MOD)%MOD;
		}	
		std::cout<<G1<<"\n";		
	}	
	return 0;
}