#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

ll en[100000];

ld radio(ll n, ll u)
{
	ll lo = 0;
	ll hi = n;
	ld ans = -1;
	while(lo < hi)
	{
		ll mid = lo + (hi-lo)/2;
		ld z = (ld)(en[n] - en[mid+1])/(en[n] - en[mid]);
		if(en[n] - en[mid] <= u && n >= mid+2 && z > ans)
		{	
			ans = z;
			hi = mid;
		}	
		else lo = mid + 1;	
	}	
	if((en[n] - en[lo] > u) || (n < lo+2))
	return -1;
	else return ans;	
}

int main(void)
{
	ll n,u;
	std::cin>>n>>u;
	for(ll i=0;i<n;i++)
	std::cin>>en[i];
	ld ans = -1;
	for(int i=n-1;i>=0;i--)
	{	
		ld hpos = radio(i, u);	
		if(hpos > ans)
		ans = hpos;	
	}
	if(ans != -1)
	std::cout<<std::fixed<<std::setprecision(20)<<ans<<"\n";
	else std::cout<<"-1\n";
	return 0;	
}