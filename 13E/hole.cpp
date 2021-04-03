#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

struct SD
{
	ll next, count;
};

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,m;
	std::cin>>n>>m;
	ll pr[n+1];
	memset(pr,0,sizeof(pr));
	for(ll i=1;i<=n;i++)
	std::cin>>pr[i];
	ll Z = floor(sqrt(n));
	SD T[n+1];
	for(ll i=n;i>0;i--)
	{
		T[i].next = i;
		T[i].count = 0;
		ll a = i/Z, b = (i + pr[i])/Z;
		if(i + pr[i] > n)
		{
			T[i].next = CHOR;
			T[i].count = 1;
		}	
		else
		{
			if(a == b)
			{
				T[i].next = T[i + pr[i]].next;
				T[i].count = T[i + pr[i]].count + 1;
			}	
			else
			{
				T[i].next = i + pr[i];
				T[i].count = 1;
			}
		}
	}		
	for(ll i=0;i<m;i++)
	{
		ll x;
		std::cin>>x;
		if(!x)
		{
			ll l,r;
			std::cin>>l>>r;
			pr[l] = r;
			ll j = l;
			ll a = l/Z, b = (l + pr[l])/Z;
			if(l + pr[l] > n)
			{
				T[l].next = CHOR;
				T[l].count = 1;
			}
			else
			{	
				if(a == b)
				{
					T[l].next = T[l + pr[l]].next;
					T[l].count = T[l + pr[l]].count + 1;
				}	
				else
				{
					T[l].next = l + pr[l];
					T[l].count = 1;
				}
			}	
			for(j = l-1, b=j/Z; (a == b && j > 0); )
			{
				if(j + pr[j] <= l)
				{	
					T[j].next = T[j+pr[j]].next;
					T[j].count = T[j+pr[j]].count + 1;
				}
				j--;
				b = j/Z;
			}	
		}	
		else
		{
			ll u;
			std::cin>>u;
			ll ctr = 0;
			while(T[u].next != CHOR)
			{	
				ctr += T[u].count;
				u = T[u].next;
			}
			while(u + pr[u] <= n)
			{
				ctr++;
				u += pr[u];
			}	
			ctr++;
			std::cout<<u<<" "<<ctr<<"\n";
		}	
	}
	return 0;	
}