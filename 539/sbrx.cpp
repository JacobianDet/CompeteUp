#include <bits/stdc++.h>

typedef long long ll;

ll xoz[(1<<20)][2];
int pref[300001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		std::cin>>pref[i];
		pref[i] ^= pref[i-1];
	}	
	ll ct = 0;
	xoz[0][0]++;
	for(int i=1;i<=n;i++)
	{
		ct += xoz[pref[i]][i & 1];
		xoz[pref[i]][i & 1]++;
	}	
	std::cout<<ct<<"\n";
	return 0;
}