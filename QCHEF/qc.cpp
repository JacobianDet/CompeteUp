#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

struct sfx
{
	ll linb[CHOR];
	ll bans[CHOR];
}block[350];

ll arr[CHOR], next[CHOR], prev[CHOR], last[CHOR];
ll Z,B,n;
ll indx[CHOR], found[CHOR], te;

class LazyMap
{
	public: LazyMap()
			{
				memset(indx,0,sizeof(indx));
				memset(found,0,sizeof(found));
				te = 0;
			}
			void clear(void)
			{
				te++;
				return;
			}
			bool KF(ll i)
			{
				return (found[i] == te);
			}
			void setter(ll i, ll val)
			{
				found[i] = te;
				indx[i] = val;
				return;
			}
			ll getter(ll i)
			{
				return indx[i];
			}
}axe;

class sqrtdec
{
	public: void build(void);
			ll query(ll l, ll r);
};

void sqrtdec::build(void)
{
	for(ll i=1;i<=n;i++)
	{	
		prev[i] =  0;
		next[i] = n+1;
		last[i] = 0;
	}	
	for(ll i=1;i<=n;i++)
	{
		ll j = last[arr[i]];
		if(j)
		{
			next[j] = i;
			prev[i] = j;
		}	
		last[arr[i]] = i;
	}	
	for(ll b=1;b<=B;b++)
	{
		ll l = b*Z - Z + 1;
		ll r = std::min(b*Z, n);
		for(ll i=l;i<=r;i++)
		{
			if(next[i] > r)
			{
				ll x = i;
				while(x)
				{
					block[b].linb[x] = i;
					x = prev[x];
				}
			}	
		}	
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll b=2;b<=B;b++)
		{
			if(!block[b].linb[i])
			block[b].linb[i] = block[b-1].linb[i];	
		}	
	}
	ll anx = 0;
	for(ll b=1;b<=B;b++)
	{
		axe.clear();
		ll c_l = b*Z - Z + 1;
		anx = 0;
		for(ll i=c_l;i<=n;i++)
		{
			if(!axe.KF(arr[i]))	
			axe.setter(arr[i], i);
			anx = std::max(anx, i - indx[arr[i]]);
			block[b].bans[i] = anx;
		}	
	}	
	return;
}

ll sqrtdec::query(ll l, ll r)
{
	ll b_l = (l + Z - 1)/Z;
	ll b_r = r/Z;
	if(b_l >= b_r)
	{
		axe.clear();
		ll anx = 0;
		for(ll i=l;i<=r;i++)
		{
			if(!axe.KF(arr[i]))
			axe.setter(arr[i], i);
			anx = std::max(anx, i - indx[arr[i]]);
		}	
		return anx;
	}	
	else
	{
		ll e_l = b_l*Z;
		ll anx = block[b_l+1].bans[r];
		for(ll i=l;i<=e_l;i++)
		{
			if(prev[i] < l)
			{
				ll y = block[r/Z].linb[i];
				while(next[y] <= r)
				y = next[y];
				anx = std::max(anx, y - i);	
			}	
		}
		return anx;	
	}	
}

int main(void)
{
	ll m,k;
	std::cin>>n>>m>>k;
	Z = floor(sqrt(n));
	B = ceil((double)n/Z);
	for(ll i=1;i<=n;i++)
	std::cin>>arr[i];
	sqrtdec T;
	T.build();
	for(ll i=0;i<k;i++)
	{
		ll l,r;
		std::cin>>l>>r;
		std::cout<<T.query(l, r)<<"\n";
	}	
	return 0;
}