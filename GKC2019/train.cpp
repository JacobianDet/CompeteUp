#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

ll skl[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,p;
		std::cin>>n>>p;
		for(int i=0;i<n;i++)
		std::cin>>skl[i];
		std::sort(skl, skl+n);
		ll minv = 100000000000000, lxv = 0;
		for(int i=0;i<p;i++)
		lxv += (skl[p-1] - skl[i]);
		minv = std::min(minv, lxv);
		for(int i=0;i<n-p;i++)
		{
			lxv -= (skl[p-1+i] - skl[i]);
			lxv += (p-1)*(skl[p+i] - skl[p-1+i]);
			lxv += (skl[p+i] - skl[p+i]);
			minv = std::min(minv, lxv);
		}	
		std::cout<<"Case #"<<t<<": "<<minv<<"\n";
	}
	return 0;
}