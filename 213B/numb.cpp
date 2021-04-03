#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

int arr[10];
ll factx[101], invf[101];
ll memo[101][11][2];

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

void factup(void)
{
	factx[0] = 1;
	invf[0] = 1;
	for(ll i=1;i<101;i++)
	{	
		factx[i] = ((factx[i-1]%MOD) * (i%MOD))%MOD;
		invf[i] = modexp(factx[i], MOD-2)%MOD;
	}
	return;	
}

ll duakal(int sp, int i, int lz)
{
	if(sp < 0)
	return 0;
	else if(i == 10)
	{
		if(!sp)
		return 1;
		else return 0;	
	}
	if(memo[sp][i][lz] != -1)
	return memo[sp][i][lz];
	ll ans = 0;
	for(ll j=arr[i];j<=sp;j++)
	ans = ((ans%MOD) + (((duakal(sp-j, i+1, lz)%MOD) * (invf[j]%MOD))%MOD))%MOD;
	memo[sp][i][lz] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	factup();
	int n;
	std::cin>>n;
	for(int i=0;i<10;i++)
	std::cin>>arr[i];
	ll ans = 0;
	int cz = 0;
	for(int i=1;i<=n;i++)
	ans = ((ans%MOD) + (((factx[i]%MOD) * (duakal(i, 0, cz)%MOD))%MOD))%MOD;
	if(arr[0])
	{	
		cz = 1;
		arr[0]--;
	}	
	for(int i=n;i>=1;i--)
	ans = ((ans%MOD) - (((factx[i-1]%MOD) * (duakal(i-1, 0, cz)%MOD))%MOD) + MOD)%MOD;
	std::cout<<ans<<"\n";
	return 0;
}