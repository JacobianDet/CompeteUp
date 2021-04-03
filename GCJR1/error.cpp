#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;
typedef long double ld;

struct vx
{
	int a,r;
};

std::vector<ll> Z;

ll bmx(ll lo, ll hi)
{
	std::vector<ll>::iterator it = std::lower_bound(Z.begin(), Z.end(), lo);
	if(it == Z.end())
	return -1;
	ll pos = it - Z.begin();
	if(Z[pos] > hi)
	return -1;
	else return pos;	
}

bool comp(vx x, vx y)
{
	return (x.r < y.r);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	for(ll t=1;t<=T;t++)
	{
		ll n,l;
		std::cin>>n>>l;
		vx arr[l];
		for(ll i=0;i<l;i++)
		std::cin>>arr[i].a;	
		for(ll i=1;i<=n;i++)
		{
			ll fz = floor((ld)i*100/n);
			ld ff = ((ld)i*100/n);
			if(ff - fz >= 0.5)	
			Z.pb(i);
		}	
		/*for(ll i=0,j=(ll)Z.size();i<j;i++)
		std::cout<<Z[i]<<" ";
		std::cout<<"\n";*/	
		ll perc = 0;
		ll ctr = 0;
		for(ll i=0;i<l;i++)
		ctr += arr[i].a;
		for(ll i=0;i<l;i++)
		{
			ll z = bmx(arr[i].a, arr[i].a+n-ctr);
			if(z != -1)
			arr[i].r = Z[z] - arr[i].a;
			else arr[i].r = 0;
		}	
		std::sort(arr,arr+l,comp);
		for(ll i=0;i<l;i++)
		{
			if(arr[i].r <= n-ctr)
			{	
				arr[i].a += arr[i].r;
				ctr += arr[i].r;
			}
			ll fz = floor((ld)(arr[i].a)*100/n);
			ld ff = ((ld)(arr[i].a)*100/n);
			ll cz = fz;
			if(ff - fz >= 0.5)
			cz++;
			perc += cz;	
		}	
		if(Z.size() != 0)
		{
			while(n-ctr >= Z[0])
			{
				ll fz = floor((ld)Z[0]*100/n);
				ld ff = ((ld)Z[0]*100/n);
				ll cz = fz;
				if(ff - fz >= 0.5)
				cz++;
				perc += cz;
				ctr += Z[0];	
			}		
		}	
		ll fz = floor((ld)(n-ctr)*100/n);
		ld ff = ((ld)(n-ctr)*100/n);
		perc += fz;
		std::cout<<"Case #"<<t<<": "<<perc<<"\n";
		Z.clear();
	}		
	return 0;
}