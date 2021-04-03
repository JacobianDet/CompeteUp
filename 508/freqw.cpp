#include <bits/stdc++.h>

int ctx[26];

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	std::string s;
	std::cin>>s;
	for(int i=0;i<n;i++)
	ctx[s[i] - 'A']++;
	int minn = 10000000;
	for(int i=0;i<k;i++)
	minn = std::min(minn, ctx[i]);
	std::cout<<k*minn<<"\n";
	return 0;
}