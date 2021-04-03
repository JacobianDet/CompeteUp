#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::set<ll> tun;
std::vector<ll> df;
ll sx[100001];

ll bs2(ll xl)
{
	ll lo = 0;
	ll hi = (int)df.size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(df[mid] > xl)
		hi = mid-1;
		else lo = mid;	
	}
	if(lo > hi)
	return -1;	
	else return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	{	
		ll c;
		std::cin>>c;
		tun.insert(c);
	}
	std::vector<ll> Z(tun.begin(), tun.end());
	for(ll i=0,j=(ll)Z.size();i<j-1;i++)
	df.pb(Z[i+1] - Z[i]);
	std::sort(df.begin(), df.end());
	n = (ll)df.size();
	for(ll i=0,j=(ll)df.size();i<j;i++)
	{
		if(!i)
		sx[i] = df[i];
		else sx[i] = sx[i-1] + df[i];	
	}	
	ll q;
	std::cin>>q;
	while(q--)
	{
		ll l,r;
		std::cin>>l>>r;
		ll sz = bs2(r-l+1);
		if(sz == -1)
		std::cout<<r-l+1<<" ";	
		else if(df[sz] > r-l+1)
		std::cout<<(n+1)*(r-l+1)<<" ";
		else std::cout<<(sx[sz] + (n-sz)*(r-l+1))<<" ";	
	}	
	std::cout<<"\n";
	return 0;
}