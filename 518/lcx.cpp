#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

bool isP[100001];
std::vector<ll> px;

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
		px.pb(i);	
	}	
	return;
}

int main(void)
{
	siever();
	ll n;
	std::cin>>n;
	ll prod = 1;
	for(int i=0,j=(int)px.size();i<j;i++)
	{
		if(!(n % px[i]))
		{
			ll ctx = 0;
			while(!(n % px[i]))
			{
				n /= px[i];
				ctx++;
			}	
			prod *= (ctx + 1);
		}
	}
	if(n > 1)
	prod <<= 1;	
	std::cout<<prod<<"\n";
	return 0;
}