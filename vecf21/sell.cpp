#include <bits/stdc++.h>

typedef long long ll;

struct tv
{
	ll w,c;
}arr[100001];

bool cmpx(tv a, tv b)
{
	return (a.c * b.w) > (b.c * a.w);
}

int main(void)
{
	ll n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>arr[i].w>>arr[i].c;
	std::sort(arr, arr+n, cmpx);
	ll ct = 0;	
	for(int i=0;i<n;i++)
	{
		if(m - arr[i].w >= 0)
		{
			m -= arr[i].w;
			ct += arr[i].c;
		}		
	}	
	std::cout<<ct<<"\n";
	return 0;
}