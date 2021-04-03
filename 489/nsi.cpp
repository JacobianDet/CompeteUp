#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

bool isP[100001];
std::vector<ll> pr;
std::vector<ll> prod;

void siever(void)
{
	memset(isP, 1, sizeof(isP));
	isP[0] = 0;
	isP[1] = 0;
	for(ll p=2;p*p<100001;p++)
	{
		if(isP[p])
		{
			for(ll i=p*p;i<100001;i+=p)
			isP[i] = 0;	
		}	
	}
	for(int i=2;i<100001;i++)
	{
		if(isP[i])
		pr.pb(i);	
	}	
	return;
}

//prod.size() doesn't exceed 15 here

/*void funcx(ll a, ll b, ll i)
{
	if(i == (int)prod.size())
	{
		if(a >= l && a <= r && b >= l && b <= r)
		ctr++;
		return;
	}	
	funcx(a*prod[i], b, i+1);
	funcx(a, b*prod[i], i+1);
	return;
}*/

int main(void)
{
	siever();
	ll l,r,x,y;
	std::cin>>l>>r>>x>>y;
	if(r < x || l > y || y%x)
	std::cout<<"0\n";
	else
	{
		ll ctr = 0;
		y /= x;
		for(int i=0,j=(int)pr.size();i<j;i++)
		{
			if(!(y % pr[i]))
			{
				ll p = pr[i];
				ll z = 1;
				while(!(y % p))
				{
					y /= p;
					z *= p;
				}
				prod.pb(z);	
			}	
		}
		if(y > 1)
		prod.pb(y);
		for(int i=0,j=(int)prod.size();i<(1<<j);i++)
		{
			ll a = x;
			ll b = x;
			for(int k=0;k<j;k++)
			{
				if(i & (1<<k))
				a *= prod[k];
				else b *= prod[k];	
			}	
			if(a >= l && a <= r && b >= l && b <= r) 
			ctr++;	
		}	
		std::cout<<ctr<<"\n";
	}	
	return 0;
}