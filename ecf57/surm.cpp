#include <bits/stdc++.h>
#define MOD 998244353

typedef long long ll;

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD));
		n >>= 1;	
	}
	return res;
}

int ctr[26];

int main(void)
{
	ll n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	ll px = 1, sx = 1;
	for(int i=0;i<n;i++)
	ctr[s[i] - 'a']++;
	bool ok = 1;	
	for(int i=0;i<26;i++)
	{
		if(ctr[i] > 0 && ctr[i] < n)
		{
			ok = 0;
			break;
		}	
	}	
	if(ok)
	{
		ll ans = ((((n%MOD) * ((n+1)%MOD))%MOD) * (modexp(2, MOD-2)%MOD))%MOD;
		std::cout<<ans<<"\n";
	}	
	else
	{
		int pos=1;
		while(s[pos] == s[pos-1])
		{	
			px++;
			pos++;
		}	
		pos=n-2;
		while(s[pos] == s[pos+1])
		{	
			sx++;
			pos--;
		}
		ll ans = 0;
		if(s[0] == s[n-1])
		ans = (((px+1)%MOD) * ((sx+1)%MOD))%MOD;
		else ans = ((((px%MOD) + (sx%MOD))%MOD) + 1)%MOD;
		std::cout<<ans<<"\n";		
	}
	return 0;
}