#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	ll ct = 0;
	for(int i=0;i<n;i++)
	{
		if(!((s[i] - '0') & 1))
		ct += (1LL*(i+1));	
	}
	std::cout<<ct<<"\n";
	return 0;
}