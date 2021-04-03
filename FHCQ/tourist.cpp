#include <bits/stdc++.h>

typedef long long ll;

std::string s[51];

int main(void)
{
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,k;
		ll v;
		std::cin>>n>>k>>v;
		std::set<int> S;
		for(int i=0;i<n;i++)
		std::cin>>s[i];
		std::cout<<"Case #"<<t<<": ";
		for(int i=0;i<k;i++)
		S.insert((((i%n) + ((((v-1)%n) * (k%n))%n))%n));
		for(std::set<int>::iterator it=S.begin();it != S.end();it++)
		std::cout<<s[*it]<<" ";	
		std::cout<<"\n";	
	}
	return 0;
}