#include <bits/stdc++.h>

typedef long long ll;

ll a[500001], b[500001];
std::map<ll, ll> sx;
std::set<ll, std::greater<ll> > X;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>a[i];
		ll mn = 1000000007;
		for(int i=0;i<n;i++)
		{
			std::cin>>b[i];
			mn = std::min(b[i]-1, mn);
		}	
		ll mtot = 0;
		for(int i=0;i<n;i++)
		{
			sx[a[i] % b[i]] += b[i];
			ll zx = a[i] % b[i];
			if(zx <= mn)
			mtot += (mn - zx);
			else mtot += ((b[i] - zx) + mn);	
		}	
		for(int i=0;i<n;i++)
		{
			if(a[i] % b[i] <= mn)
			X.insert(a[i] % b[i]);	
		}
		X.insert(0);
		ll itot = mtot, iv = mn;
		for(auto u : X)
		{
			itot -= n*(iv - u);
			mtot = std::min(mtot, itot);
			iv = u;
			itot += sx[u];
		}
		std::cout<<mtot<<"\n";
		X.clear();
		sx.clear();
	}
	return 0;
}
