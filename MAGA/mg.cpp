#include <bits/stdc++.h>
#define CHOR 100002
#define INF 1000000000

/* 1 = NS
   2 = S*/

typedef long long ll;

ll a[CHOR],n;
ll memo[CHOR][3][2];

ll maga(ll i, ll st, ll t)
{
	if(i+1 == ceil((double)(n+1)/2))
	{
		if(n & 1)
		{
			if(!t)
			{
				if((i & 1) && (a[i] < a[i+1]) && (a[n-i+1] < a[i+1]))
				return 0;	
				else if((!(i & 1)) && (a[i] > a[i+1]) && (a[n-i+1] > a[i+1]))
				return 0;
				else return INF;	
			}	
			else 
			{
				if((i & 1) && (a[i] > a[i+1]) && (a[n-i+1] > a[i+1]))
				return 0;	
				else if((!(i & 1)) && (a[i] < a[i+1]) && (a[n-i+1] < a[i+1]))
				return 0;
				else return INF;	
			}	
		}
		else
		{
			if(!t)
			{
				if(i & 1)
				{
					if((st == 0 || st == 1) && (a[i] < a[i+1]))
					return 0;
					else if(st == 2 && (a[i+1] < a[i]))
					return 0;
					else return INF;	
				}		
				else if(!(i & 1))
				{
					if((st == 0 || st == 1) && (a[i] > a[i+1]))
					return 0;
					else if(st == 2 && (a[i+1] > a[i]))
					return 0;
					else return INF;
				}	
				else return INF;	
			}	
			else
			{
				if(i & 1)
				{
					if((st == 0 || st == 1) && (a[i] > a[i+1]))
					return 0;
					else if(st == 2 && (a[i+1] > a[i]))
					return 0;
					else return INF;	
				}		
				else if(!(i & 1))
				{
					if((st == 0 || st == 1) && (a[i] < a[i+1]))
					return 0;
					else if(st == 2 && (a[i+1] < a[i]))
					return 0;
					else return INF;
				}	
				else return INF;	
			}	
		}	
	}
	if(memo[i][st][t] != -1)
	return memo[i][st][t];
	ll ans = INF;
	if(!t)
	{	
		if(i == 1)
		{
			if(n & 1)
			{
				if((a[i] < a[i+1]) && (a[n-i+1] < a[n-i]))
				ans = std::min(ans, maga(i+1, 1, t));
				if((a[n-i+1] < a[i+1]) && (a[i] < a[n-i]))
				ans = std::min(ans, 1+maga(i+1, 1, t));
				if((a[i] < a[n-i]) && (a[n-i+1] < a[i+1]))
				ans = std::min(ans, 1+maga(i+1, 2, t));	
			}	
			else
			{
				if((a[i] < a[i+1]) && (a[n-i+1] > a[n-i]))
				ans = std::min(ans, maga(i+1, 1, t));
				if((a[n-i+1] < a[i+1]) && (a[i] > a[n-i]))
				ans = std::min(ans, 1+maga(i+1, 1, t));
				if((a[i] < a[n-i]) && (a[n-i+1] > a[i+1]))
				ans = std::min(ans, 1+maga(i+1, 2, t));
				if((a[n-i+1] < a[n-1]) && (a[i] > a[i+1]))
				ans = std::min(ans, 2+maga(i+1, 2, t));	
			}	
		}
		else
		{
			if(n & 1)
			{
				if(st == 1)
				{
					if(i & 1)
					{
						if((a[i] < a[i+1]) && (a[n-i+1] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] < a[n-i]) && (a[n-i+1] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}
					else
					{
						if((a[i] > a[i+1]) && (a[n-i+1] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] > a[n-i]) && (a[n-i+1] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}
				else
				{
					if(i & 1)
					{
						if((a[n-i+1] < a[i+1]) && (a[i] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] < a[n-i]) && (a[i] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
					else
					{
						if((a[n-i+1] > a[i+1]) && (a[i] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] > a[n-i]) && (a[i] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}	
			}
			else
			{
				if(st == 1)
				{
					if(i & 1)
					{
						if((a[i] < a[i+1]) && (a[n-i+1] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] < a[n-i]) && (a[n-i+1] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}
					else
					{
						if((a[i] > a[i+1]) && (a[n-i+1] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] > a[n-i]) && (a[n-i+1] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}
				else
				{
					if(i & 1)
					{
						if((a[n-i+1] < a[i+1]) && (a[i] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] < a[n-i]) && (a[i] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
					else
					{
						if((a[n-i+1] > a[i+1]) && (a[i] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] > a[n-i]) && (a[i] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}	
			}	
		}	
	}
	else
	{
		if(i == 1)
		{
			if(n & 1)
			{
				if((a[i] > a[i+1]) && (a[n-i+1] > a[n-i]))
				ans = std::min(ans, maga(i+1, 1, t));
				if((a[n-i+1] > a[i+1]) && (a[i] > a[n-i]))
				ans = std::min(ans, 1+maga(i+1, 1, t));
				if((a[i] > a[n-i]) && (a[n-i+1] > a[i+1]))
				ans = std::min(ans, 1+maga(i+1, 2, t));	
			}	
			else
			{
				if((a[i] > a[i+1]) && (a[n-i+1] < a[n-i]))
				ans = std::min(ans, maga(i+1, 1, t));
				if((a[n-i+1] > a[i+1]) && (a[i] < a[n-i]))
				ans = std::min(ans, 1+maga(i+1, 1, t));
				if((a[i] > a[n-i]) && (a[n-i+1] < a[i+1]))
				ans = std::min(ans, 1+maga(i+1, 2, t));
				if((a[n-i+1] > a[n-1]) && (a[i] < a[i+1]))
				ans = std::min(ans, 2+maga(i+1, 2, t));	
			}	
		}
		else
		{
			if(n & 1)
			{
				if(st == 1)
				{
					if(i & 1)
					{
						if((a[i] > a[i+1]) && (a[n-i+1] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] > a[n-i]) && (a[n-i+1] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}
					else
					{
						if((a[i] < a[i+1]) && (a[n-i+1] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] < a[n-i]) && (a[n-i+1] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}
				else
				{
					if(i & 1)
					{
						if((a[n-i+1] > a[i+1]) && (a[i] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] > a[n-i]) && (a[i] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
					else
					{
						if((a[n-i+1] < a[i+1]) && (a[i] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] < a[n-i]) && (a[i] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}	
			}
			else
			{
				if(st == 1)
				{
					if(i & 1)
					{
						if((a[i] > a[i+1]) && (a[n-i+1] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] > a[n-i]) && (a[n-i+1] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}
					else
					{
						if((a[i] < a[i+1]) && (a[n-i+1] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[i] < a[n-i]) && (a[n-i+1] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}
				else
				{
					if(i & 1)
					{
						if((a[n-i+1] > a[i+1]) && (a[i] < a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] > a[n-i]) && (a[i] < a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
					else
					{
						if((a[n-i+1] < a[i+1]) && (a[i] > a[n-i]))
						ans = std::min(ans, maga(i+1, 1, t));
						if((a[n-i+1] < a[n-i]) && (a[i] > a[i+1]))
						ans = std::min(ans, 1+maga(i+1, 2, t));	
					}	
				}	
			}	
		}	
	}
	memo[i][st][t] = ans;	
	return ans;
}

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		memset(memo,-1,sizeof(memo));
		std::cin>>n;
		for(ll i=1;i<=n;i++)
		std::cin>>a[i];
		ll ans = 0;
		if(n == 1)
		ans = 0;	
		else ans = std::min(maga(1, 0, 0), maga(1, 0, 1));
		if(ans == INF)
		ans = -1;	
		std::cout<<ans<<"\n";	
	}	
	return 0;
}