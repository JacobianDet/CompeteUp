#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

bool isP[10000001];
std::vector<ll> px;

void siever(void)
{
	memset(isP, 1, sizeof(isP));
	isP[0] = 0;
	isP[1] = 0;
	for(ll p=2;p*p<10000001;p++)
	{
		if(isP[p])
		{	
			for(ll i=p*p;i<10000001;i+=p)
			isP[i] = 0;
		}		
	}
	for(ll i=2;i<10000001;i++)
	{
		if(isP[i])
		px.pb(i);	
	}
	return;
}

ll fexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}
	return res;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	ll n,p;
	std::cin>>n>>p;
	ll ag = 1;
	for(int i=0,j=(int)px.size();i<j;i++)
	{
		ll xd = px[i], ct = 0;
		while(!(p % xd))
		{
			p /= xd;
			ct++;
		}
		if(ct/n)
		ag *= fexp(xd, (ct/n));
	}
	if(p > 1)
	{
		if(n == 1)
		ag *= p;	
	}
	std::cout<<ag<<"\n";
	return 0;
}