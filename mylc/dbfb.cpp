#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll fibn[100001];

void fx(void)
{
	fibn[0] = 0;
	fibn[1] = 1;
	for(ll i=2;i<100001;i++)
	fibn[i] = (fibn[i-1]%MOD + fibn[i-2]%MOD)%MOD;
	return;	
}

int main(void)
{
	fx();
	int T;
	std::cin>>T;
	while(T--)
	{
		ll m,n;
		std::cin>>m>>n;
		ll a[m],b[m];
		ll as = 0, bs = 0;
		for(ll i=0;i<m;i++)
		{	
			std::cin>>a[i];
			as = (as%MOD + a[i]%MOD)%MOD;
		}	
		for(ll i=0;i<m;i++)
		{	
			std::cin>>b[i];
			bs = (bs%MOD + b[i]%MOD)%MOD;
		}	
		ll res = 0;
		if(n > 2)
		res = (((((fibn[n-1]%MOD) * (bs%MOD))%MOD + ((fibn[n-2]%MOD) * (as%MOD))%MOD)%MOD) * ((m%MOD)%MOD))%MOD;
		else res = (((((fibn[1]%MOD) * (bs%MOD))%MOD + ((fibn[0]%MOD) * (as%MOD))%MOD)%MOD) * ((m%MOD)%MOD))%MOD;	
		std::cout<<res<<"\n";
	}	
	return 0;
}