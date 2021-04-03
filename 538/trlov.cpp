#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

bool isP[10000001];
std::vector<ll> px;

void siever(void)
{
	memset(isP, 1, sizeof(isP));
	isP[0] = 0;
	isP[1] = 0;
	for(ll p=2;p*p<10000001;p++)
	{
		if(isP[p])
		{
			for(ll i=p*p;i<10000001;i+=p)
			isP[i] = 0;	
		}
	}	
	for(ll i=2;i<10000001;i++)
	{
		if(isP[i])
		px.pb(i);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	ll n,b;
	std::cin>>n>>b;
	ll oxt = 1000000000000000000, bt = b;
	for(int i=0,j=(int)px.size();i<j;i++)
	{
		if(!(bt % px[i]))
		{
			ll nt = n;
			ll ict = 0, hp = 0;
			while(!(bt % px[i]))
			{	
				hp++;
				bt /= px[i];
			}	
			while(nt >= px[i])
			{
				ict += (nt/px[i]);
				nt /= px[i];
			}	
			oxt = std::min(oxt, ict/hp);
		}	
	}
	if(bt > 1)
	{	
		ll ict = 0, nt = n;
		while(nt >= bt)
		{
			ict += (nt/bt);
			nt /= bt;
		}		
		oxt = std::min(oxt, ict);
	}	
	std::cout<<oxt<<"\n";
	return 0;
}