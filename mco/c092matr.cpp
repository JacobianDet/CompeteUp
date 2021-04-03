#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll A[100][100];
		memset(A,0,sizeof(A));
		ll n,m;
		std::cin>>n>>m;
		std::vector<std::pair<ll, ll> > Z;
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{	
				std::cin>>A[i][j];
				if(A[i][j] == -1)
				Z.pb(mp(i, j));
			}		
		}
		bool z = 0;
		for(ll i=0,j=(ll)Z.size();i<j;i++)
		{
			ll u = Z[i].first;
			ll v = Z[i].second;
			ll rv[2],cv[2];
			rv[0] = 1;
			rv[1] = 2000000000;
			cv[0] = 1;
			cv[1] = 2000000000;
			for(ll k=u-1;k>=0;k--)
			{
				if(A[k][v] != -1)
				{	
					cv[0] = A[k][v];
					break;
				}		
			}
			for(ll k=u+1;k<n;k++)
			{
				if(A[k][v] != -1)
				{	
					cv[1] = A[k][v];
					break;
				}		
			}
			for(ll k=v-1;k>=0;k--)
			{
				if(A[u][k] != -1)
				{	
					rv[0] = A[u][k];
					break;
				}			
			}
			for(ll k=v+1;k<m;k++)
			{
				if(A[u][k] != -1)
				{	
					rv[1] = A[u][k];
					break;
				}		
			}
			if((rv[0] <= rv[1]) && (cv[0] <= cv[1]))
			{
				ll mini = std::max(rv[0], cv[0]);
				ll maxi = std::min(rv[1], cv[1]);
				if(mini <= maxi)
				A[u][v] = mini;
				else
				{	
					z = 1;
					break;
				}	
			}
			else
			{
				z = 1;
				break;
			}	
		}
		if(z)
		{	
			std::cout<<"-1\n";
			continue;
		}
		for(ll i=0;i<n;i++)
		{
			ll p = 1;
			for(ll j=0;j<m;j++)
			{
				if(p <= A[i][j])
				p = A[i][j];
				else 
				{
					z = 1;
					break;
				}	
			}
			if(z)
			break;	
		}	
		for(ll i=0;i<m;i++)
		{
			ll p = 1;
			for(ll j=0;j<n;j++)
			{
				if(p <= A[j][i])
				p = A[j][i];
				else 
				{
					z = 1;
					break;
				}	
			}
			if(z)
			break;	
		}	
		if(z)
		{	
			std::cout<<"-1\n";
			continue;
		}
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			std::cout<<A[i][j]<<" ";
			std::cout<<"\n";	
		}		
	}	
	return 0;
}