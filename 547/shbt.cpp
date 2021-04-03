#include <bits/stdc++.h>

typedef long long ll;

ll pref[200001];

ll bs1(ll H, ll pv, ll sv)
{
	ll lo = 1;
	ll hi = 10000000000001;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(H + mid * pv + sv <= 0)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll H;
	int n;
	std::cin>>H>>n;
	int vx = 0;
	for(int i=1;i<=n;i++)
	{
		std::cin>>pref[i];
		pref[i] += pref[i-1];
		if(!vx && (pref[i] < 0) && (H + pref[i] <= 0))
		vx = i;	
	}	
	if(!vx && (pref[n] >= 0))
	std::cout<<"-1\n";
	else if(vx)
	std::cout<<vx<<"\n";
	else
	{
		ll mvx = LONG_LONG_MAX;
		for(int i=1;i<=n;i++)
		{
			if(pref[i] < 0)
			{
				ll azx = abs(H + pref[i])/abs(pref[n]);
				if((abs(H + pref[i]) % abs(pref[n])))
				azx++;
				mvx = std::min(mvx, azx * n + 1LL*i);	
			}
		}
		std::cout<<mvx<<"\n";	
	}	
	return 0;
}