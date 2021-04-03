#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

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

ll arr[1000001];
ll arrv[1000001];

int main(void)
{	
	//freopen("input.in","r",stdin);
	//freopen("output.txt","w",stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	for(ll t=1;t<=T;t++)
	{
		memset(arr,0,sizeof(arr));
		memset(arrv,0,sizeof(arrv));
		ll n,k,x,y,c,d,e1,e2,f;
		std::cin>>n>>k>>x>>y>>c>>d>>e1>>e2>>f;
		for(ll i=1;i<=n;i++)
		{
			arr[i] = ((x%f) + (y%f))%f;
			ll px = x;
			ll py = y;
			x = ((((c%f) * (px%f))%f) + (((d%f) * (py%f))%f) + (e1%f))%f;
			y = ((((d%f) * (px%f))%f) + (((c%f) * (py%f))%f) + (e2%f))%f;
		}
		for(ll i=1;i<=n;i++)
		{
			if(i == 1)
			arrv[i] = ((arrv[i-1]%MOD) + (k%MOD))%MOD;
			else arrv[i] = ((arrv[i-1]%MOD) + ((((modexp(i, k+1)%MOD) - (i%MOD) + MOD)%MOD) * ((modexp(i-1, MOD-2)%MOD))%MOD)%MOD);
		}
		ll sum = 0;
		for(ll i=1;i<=n;i++)
		sum = ((sum%MOD) + (((((n%MOD - (i-1)%MOD + MOD)%MOD) * (arrv[i]%MOD))%MOD) * (arr[i]%MOD))%MOD)%MOD;
		std::cout<<"Case #"<<t<<": "<<sum<<"\n";
	}	
	return 0;
}