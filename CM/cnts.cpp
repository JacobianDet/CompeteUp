#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

std::map<std::string, ll> MX;

ll factx[1000001], invf[1000001], inv[1000001];

void factup(void)
{
	factx[0] = 1;
	factx[1] = 1;
	inv[0] = 0;
	inv[1] = 1;
	for(ll i=2;i<1000001;i++)
	{
		factx[i] = (i * factx[i-1])%MOD;
		inv[i] = (MOD - ((MOD/i) * (inv[MOD % i]))%MOD)%MOD;
	}
	invf[0] = 1;
	for(ll i=1;i<1000001;i++)
	invf[i] = (inv[i] * invf[i-1])%MOD;	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	factup();
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		std::string s;
		std::cin>>s;
		MX[s]++;
	}	
	ll ax = 1;
	for(auto u : MX)
	ax = ((ax%MOD) * (invf[u.second]%MOD))%MOD;
	ll ans = ((factx[n]%MOD) * (ax%MOD))%MOD;
	std::cout<<ans<<"\n";
	MX.clear();
	return 0;
}