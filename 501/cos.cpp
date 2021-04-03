#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

struct trx
{
	ll a,b,diff;
}arr[100001];

bool cmp(trx u, trx v)
{
	return (u.diff > v.diff);
}

int main(void)
{
	int n;
	ll m;
	std::cin>>n>>m;
	ll sx1 = 0, sx2 = 0;
	for(int i=0;i<n;i++)
	{	
		ll a,b;
		std::cin>>a>>b;
		arr[i] = {a, b, a-b};
		sx1 += b;
		sx2 += a;
	}
	if(sx1 > m)
	std::cout<<"-1\n";
	else
	{
		std::sort(arr, arr+n, cmp);
		int ct = 0;
		for(ct=0;ct<n;ct++)
		{
			if(sx2 <= m)
			break;
			else sx2 -= arr[ct].diff;
		}	
		std::cout<<ct<<"\n";
	}		
	return 0;
}