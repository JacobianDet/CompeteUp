#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

int sz[100001];
ll pos[100001];

ll bs2(int n, ll B)
{
	ll lo = 0;
	ll hi = 1000000000000000000;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		std::set<std::pair<int, int> > Z;
		
	}
}

int main(void)
{
	int n;
	ll B;
	std::cin>>n>>B;
	for(int i=0;i<n;i++)
	std::cin>>sz[i];
	for(int i=0;i<n;i++)
	std::cin>>pos[i];
	ll ans = bs2(n, B);
	std::cout<<ans<<"\n";
	return 0;	
}