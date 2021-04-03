#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

ll arr[CHOR];
ll ld[CHOR];
ll sze[CHOR];
std::map<std::string, ll> msl;
 
class dsu
{
	public: ll root(ll x)
			{
				while(x != arr[x])
				x = arr[arr[x]];
				return x;	
			}
 
			void find_union(ll x, ll y)
			{
				ll rx = root(x);
				ll ry = root(y);
				if(rx == ry)
				return;
				if(sze[rx] > sze[ry])
				{
					arr[ry] = rx;
					sze[rx] += sze[ry];
				}	
				else
				{
					arr[rx] = ry;
					sze[ry] += sze[rx];
				}	
				return;
			}
};

int main(void)
{
	for(ll i=1;i<CHOR;i++)
	{
		arr[i] = i;
		sze[i] = 1;
		ld[i] = i;
	}	
	dsu T;
	ll n,k,m;
	std::cin>>n>>k>>m;
	ll az[n+1];
	for(ll i=1;i<=n;i++)
	{
		std::string s;
		std::cin>>s;
		msl[s] = i;
	}
	for(ll i=1;i<=n;i++)
	std::cin>>az[i];
	for(ll i=0;i<k;i++)
	{
		ll x;
		std::cin>>x;
		ll q1,q;
		std::cin>>q;
		for(ll j=1;j<x;j++)
		{
			std::cin>>q1;
			ll rt = ld[T.root(q)];
			T.find_union(q, q1);
			if(az[q1] < az[rt])
			ld[T.root(q)] = q1;
			else ld[T.root(q)] = rt;	
		}	
	}	
	ll tc = 0;
	for(ll i=0;i<m;i++)
	{
		std::string s;
		std::cin>>s;
		tc += az[ld[T.root(msl[s])]];
	}	
	std::cout<<tc<<"\n";
	return 0;
}