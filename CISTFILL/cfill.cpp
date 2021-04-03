#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back

struct cistern
{
	ll b,h,w,d;
};

cistern cis[50000];

ld cfill(ll n, ld v)
{
	ld lo = 0;
	ld hi = 0;
	for(ll i=0;i<n;i++)
	hi = std::max((ll)hi, (ll)(cis[i].b + cis[i].h));
	for(int t=0;t<100;t++)
	{
		ld mid = lo + (hi-lo)/2;
		ld res = 0;
		for(ll i=0;i<n;i++)
		{
			if(cis[i].b + cis[i].h <= mid)
			res += (cis[i].h*cis[i].w*cis[i].d);
			else if(cis[i].b + cis[i].h > mid && cis[i].b <= mid)
			res += ((mid - cis[i].b)*cis[i].w*cis[i].d); 
			else continue;
		}
		if(res < v)
		lo = mid;
		else hi = mid;	
	}
	return lo;	
}

int main(void)
{
	int k;
	std::cin>>k;
	while(k--)
	{
		ll n;
		ld v = 0,vol = 0;
		std::cin>>n;
		for(ll i=0;i<n;i++)
		{	
			std::cin>>cis[i].b>>cis[i].h>>cis[i].w>>cis[i].d;
			vol += (cis[i].h*cis[i].w*cis[i].d);
		}	
		std::cin>>v; 
		if(vol < v)
		{
			std::cout<<"OVERFLOW\n";
			continue;
		}	
		ld res = cfill(n,v);
		printf("%.2Lf\n", res);
	}	
	return 0;
}

