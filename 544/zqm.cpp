#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

ll a[200001], b[200001];
std::map<std::pair<ll, ll>, int> ZF;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>a[i];
	for(int i=1;i<=n;i++)
	std::cin>>b[i];
	int zc = 0;
	for(int i=1;i<=n;i++)
	{
		ll gx = std::__gcd(a[i], b[i]);
		if(a[i] != 0)
		ZF[mp(b[i]/gx, a[i]/gx)]++;
		else if(!gx)
		zc++;
	}	
	int ct = 0;
	for(std::map<std::pair<ll, ll>, int>::iterator it = ZF.begin();it != ZF.end();it++)
	{	
		if(((it->first).second) || (!((it->first).first) && !((it->first).second)))
		ct = std::max(ct, it->second);
	}
	ct += zc;
	std::cout<<ct<<"\n";
	return 0;
}