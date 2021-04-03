#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

struct Point
{
	ll x, y;
};

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

ll getCount(Point p, Point q)
{
	ll d1 = abs(p.x - q.x);
	ll d2 = abs(p.y - q.y);
    return (std::__gcd(d1, d2) - 1);
}

int main(void)
{
 	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	ll sm = modexp(6, MOD-2)%MOD;
	while(T--)
	{
		Point p[3];
		for(int i=0;i<3;i++)
		std::cin>>p[i].x>>p[i].y;
		ll md1 = getCount(p[0], p[1]);
		ll md2 = getCount(p[1], p[2]);
		ll md3 = getCount(p[2], p[0]);

		ll mx1 = ((((((md1%MOD) + (md2%MOD))%MOD) + (md3%MOD))%MOD) + (3%MOD))%MOD;
		ll mx2 = ((((((md1%MOD) + (md2%MOD))%MOD) + (md3%MOD))%MOD) + (2%MOD))%MOD;
		ll mx3 = ((((((md1%MOD) + (md2%MOD))%MOD) + (md3%MOD))%MOD) + (1%MOD))%MOD;
		ll sum = ((((((mx1%MOD) * (mx2%MOD))%MOD) * (mx3%MOD))%MOD) * (sm%MOD))%MOD;
		if(md1 > 0)
		{	
			ll mx4 = ((md1%MOD) + (2%MOD))%MOD;
			ll mx5 = ((md1%MOD) + (1%MOD))%MOD;
			ll mx6 = (md1%MOD);
			sum = ((sum%MOD) - (((((((mx4%MOD) * (mx5%MOD))%MOD) * (mx6%MOD))%MOD) * (sm%MOD))%MOD));
			while(sum < 0)
			sum += MOD;	
		}	
		if(md2 > 0)
		{
			ll mx7 = ((md2%MOD) + (2%MOD))%MOD;
			ll mx8 = ((md2%MOD) + (1%MOD))%MOD;
			ll mx9 = (md2%MOD);
			sum = ((sum%MOD) - (((((((mx7%MOD) * (mx8%MOD))%MOD) * (mx9%MOD))%MOD) * (sm%MOD))%MOD));
			while(sum < 0)
			sum += MOD;
		}
		if(md3 > 0)
		{	
			ll mx10 = ((md3%MOD) + (2%MOD))%MOD;
			ll mx11 = ((md3%MOD) + (1%MOD))%MOD;
			ll mx12 = (md3%MOD);
			sum = ((sum%MOD) - (((((((mx10%MOD) * (mx11%MOD))%MOD) * (mx12%MOD))%MOD) * (sm%MOD))%MOD));
			while(sum < 0)
			sum += MOD;
		}		
		std::cout<<sum<<"\n";
	}
	return 0;
}