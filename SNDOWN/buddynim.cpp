#include <bits/stdc++.h>

typedef long long ll;

ll A[101], B[101];

bool cmpx(ll a, ll b)
{
	return (a > b);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,m;
		std::cin>>n>>m;
		ll ta = 0, tb = 0;
		for(int i=0;i<n;i++)
		{
			ll x;
			std::cin>>x;
			A[i] = x;
			ta += x;
		}	
		for(int i=0;i<m;i++)
		{
			ll x;
			std::cin>>x;
			B[i] = x;
			tb += x;
		}
		std::sort(A, A+n, cmpx);
		std::sort(B, B+m, cmpx);
		if(ta != tb)
		std::cout<<"Alice\n";
		else
		{
			int mn = std::min(n, m);
			bool ok = 0;
			for(int i=0;i<mn;i++)
			{
				if(A[i] != B[i])
				{
					ok = 1;
					break;
				}	
			}
			if(!ok)
			{	
				if(n > m)
				{	
					if(A[mn])
					ok = 1;
				}
				else if(n < m)
				{
					if(B[mn])
					ok = 1;	
				}	
			}	
			if(ok)
			std::cout<<"Alice\n";
			else std::cout<<"Bob\n";	
		}	
	}
	return 0;
}