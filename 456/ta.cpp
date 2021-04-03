#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll a,b;
	std::cin>>a>>b;
	ll x,y,z;
	std::cin>>x>>y>>z;
	ll c=0,d=0;
	if(x)
	c += 2*x;	
	if(y)
	{
		c += y;
		d += y;
	}	
	if(z)
	d += 3*z;
	ll ans = 0;
	if(a > c)
	ans += 0;
	else ans += (c-a);
	if(b > d)
	ans += 0;
	else ans += (d-b);
	std::cout<<ans<<"\n";	
	return 0;
}