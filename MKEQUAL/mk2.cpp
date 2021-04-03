#include <bits/stdc++.h>
#define MOD 100000007

typedef long long ll;

ll arr[1001];

ll modexp(ll n)
{
	ll a = 2;
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

int main(void)
{
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		std::cin>>n;
		ll sum = 0;
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
			sum = ((sum%MOD) + (arr[i]%MOD))%MOD;
		}	
		sum = ((sum%MOD) * (modexp(n-1)%MOD))%MOD;
		std::cout<<"Case "<<t<<": "<<sum<<"\n";
	}
	return 0;
}