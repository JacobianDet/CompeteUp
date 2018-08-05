#include <bits/stdc++.h>
#define CHOR 10000002
#define pb push_back
#define mp std::make_pair
#define ll long long
 
ll arr[CHOR];
ll end[CHOR];
ll sze[CHOR];
 
class dsu
{
	public: int root(int x)
			{
				while(x != arr[x])
				x = arr[arr[x]];
				return x;	
			}
 
			void find_union(int x, int y)
			{
				int rx = root(x);
				int ry = root(y);
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
	ll t;
	scanf("%lld", &t);
	for(ll y=1;y<=t;y++)
	{
		ll n;
		scanf("%lld", &n);
		for(ll i=1;i<=CHOR;i++)
		{
			arr[i] = i;
			end[i] = i;
			sze[i] = 1;
		}
		dsu T;
		std::vector<std::pair<ll, ll> > Z;
		for(ll i=0;i<n;i++)
		{
			ll s,d;
			scanf("%lld %lld", &s, &d);
			Z.pb(mp(s, d));
		}	
		ll ctr = 0;
		for(ll i=n-1;i>=0;i--)
		{
			ll l = Z[i].first;
			ll r = Z[i].second;
			ll c=0;
			for(ll j=end[T.root(l)]; j<=r; j=end[T.root(j)])
			{	
				c++;
				end[T.root(j)] = end[T.root(j+1)];
				T.find_union(j, j+1);	
			}	
			if(c > 0)
			ctr++;	
		}
		printf("%lld\n", ctr);	
	}	
	return 0;
} 