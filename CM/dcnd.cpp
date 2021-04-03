#include <bits/stdc++.h>
#define MOD 998244353

typedef long long ll;

std::set<int> dpc;

ll factx[100001], invf[100001], inv[100001];
int prm[100001];

void factup(void)
{
	factx[0] = 1;
	factx[1] = 1;
	inv[0] = 0;
	inv[1] = 1;
	for(ll i=2;i<100001;i++)
	{
		factx[i] = (i * factx[i-1])%MOD;
		inv[i] = (MOD - ((MOD/i) * (inv[MOD % i]))%MOD)%MOD;
	}
	invf[0] = 1;
	for(ll i=1;i<100001;i++)
	invf[i] = (inv[i] * invf[i-1])%MOD;	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	factup();
	ll n,c;
	std::cin>>n>>c;
	for(int i=1;i<=c;i++)
	{
		int t;
		std::cin>>t;
		dpc.insert(t);
	}
	for(int i=0;i<n;i++)
	std::cin>>prm[i];	
	int nx = dpc.size();
	ll ax = 0;
	for(int i=1;i<=nx;i++)
	{
		ll fx = ((factx[nx]%MOD) * (((invf[i]%MOD) * (invf[nx-i]%MOD))%MOD))%MOD;
		if(i & 1)
		ax = ((ax%MOD) + (((fx%MOD) * (factx[n-i]%MOD))%MOD))%MOD;
		else ax = ((ax%MOD) - (((fx%MOD) * (factx[n-i]%MOD))%MOD) + MOD)%MOD;	
	}
	std::cout<<ax<<"\n";
	return 0;	
}