#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll factx[1001], invf[1001];

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

void factup(void)
{
	factx[0] = 1;
	invf[0] = 1;
	for(ll i=1;i<1001;i++)
	{
		factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
		invf[i] = modexp(factx[i], MOD-2)%MOD;
	}
	return;
}

ll ct[1001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    factup();
    int k;
    std::cin>>k;
    for(int i=1;i<=k;i++)
    std::cin>>ct[i];
    ll tot = 0, ax = 1;
    for(int i=1;i<=k;i++)
    {
    	ll fx = ((factx[tot + ct[i] - 1]%MOD) * (((invf[tot]%MOD) * (invf[ct[i] - 1]%MOD))%MOD))%MOD;
    	tot += ct[i];
    	ax = ((ax%MOD) * (fx%MOD))%MOD;
    }	
    std::cout<<ax<<"\n";
    return 0;
}