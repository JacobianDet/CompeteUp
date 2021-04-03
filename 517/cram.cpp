#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

ll bs2(ll val)
{
	ll lo = 0;
	ll hi = val;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(((mid * (mid + 1))/2) <= val)
		lo = mid;
		else hi = mid - 1;	
	}
	return lo;
}

int main(void)
{
	ll a,b;
	std::cin>>a>>b;
	ll vx = bs2(a+b);
	std::vector<ll> ax, bx;
	for(ll i=vx;i>0;i--)
	{
		if(b >= i)
		{	
			bx.pb(i);
			b -= i;
		}	
		else 
		{
			ax.pb(i);
			a -= i;
		}		
	}
	std::cout<<(int)ax.size()<<"\n";
	for(int i=0,j=(int)ax.size();i<j;i++)
	std::cout<<ax[i]<<" ";
	std::cout<<"\n"<<(int)bx.size()<<"\n";
	for(int i=0,j=(int)bx.size();i<j;i++)
	std::cout<<bx[i]<<" ";
	std::cout<<"\n";
	return 0;	
}