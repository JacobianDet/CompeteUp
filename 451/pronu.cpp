#include <bits/stdc++.h>
#define p std::pair<ll, ll>
#define mp std::make_pair
#define ll long long

p egcd(ll a, ll b)
{
	ll x = 0,y = 0;
	if(!b)
	{
		x = 1;
		y = 0;
	}	
	else 
	{
		p ans = egcd(b, a%b);
		x = ans.first;
		y = ans.second;
		ll temp = x;
		x = y;
		y = temp - floor((float)a/b)*y;
	}	
	return mp(x,y);
}

int main(void)
{
	ll n,a,b;
	std::cin>>n>>a>>b;
	ll u = (ll)a/std::__gcd(a,b);
	ll v = (ll)b/std::__gcd(a,b);
	ll z = (ll)n/std::__gcd(a,b);
	p ans = egcd(a,b);
	ll x = ans.first;
	ll y = ans.second;
	if((floor((float)y*z/u) < ceil((float)z*(-x)/v)) || (n % std::__gcd(a,b)))
	std::cout<<"NO\n";
	else 
	{
		std::cout<<"YES\n"<<(ll)x*z + (ll)floor((float)y*z/u)*v<<" "<<(ll)y*z - (ll)floor((float)y*z/u)*u<<"\n";
	}	
	return 0;
}