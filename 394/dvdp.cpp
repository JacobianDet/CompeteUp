#include <bits/stdc++.h>
#define INF 10000000000001

typedef long long ll;

ll a[100001], c[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	ll l,r;
	std::cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
	std::cin>>a[i];
	for(int i=1;i<=n;i++)
	std::cin>>c[i];
	ll L = -INF, R = INF;
	for(int i=1;i<=n;i++)
	{
		L = std::max(L, l-a[i]-c[i]);
		R = std::min(R, r-a[i]-c[i]);
	}	
	if(L > R)
	std::cout<<"-1\n";
	else
	{
		for(int i=1;i<=n;i++)
		std::cout<<(a[i] + c[i] + L)<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}