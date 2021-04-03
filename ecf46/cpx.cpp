#include <bits/stdc++.h>

typedef long long ll;

std::map<ll, ll> rupq;
ll ctr[200001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll l,r;
		std::cin>>l>>r;
		rupq[l]++;
		rupq[r+1]--;
	}		
	ll x = 0;
	ll l = 0;
	for(std::map<ll, ll>::iterator it = rupq.begin(); it != rupq.end(); it++)
	{
		ll a = it->first;
		ll b = it->second;
		ctr[x] += (a-l);
		x += b;
		l = a;
	}
	for(int i=1;i<=n;i++)
	std::cout<<ctr[i]<<" ";
	std::cout<<"\n";	
	return 0;
}