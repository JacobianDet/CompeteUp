#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

int prime[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

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

ll ctx[71], bxv[71];
ll oc[71], ec[71];
int memo[72][(1<<19)];

/*ll sqzd(int i, int mask)
{
	if(i == 71)
	{
		if(!mask)
		return 1*1LL;
		else return 0*1LL;	
	}	
	if(memo[i][mask] != -1)
	return memo[i][mask];	
	ll ans = 0;
	if(ctx[i])
	ans = ((((1LL*oc[i]%MOD) * (1LL*sqzd(i+1, mask ^ bxv[i])%MOD))%MOD) + (((1LL*ec[i]%MOD) * (1LL*sqzd(i+1, mask)%MOD))%MOD))%MOD;
	else ans = (1LL*sqzd(i+1, mask))%MOD;
	memo[i][mask] = ans;
	return ans;
}*/

int main(void)
{
	memset(memo, -1, sizeof(memo));
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		ctx[t]++;
	}	
	for(int i=1;i<=70;i++)
	{
		if(ctx[i])
		{
			oc[i] = modexp(2, ctx[i]-1)%MOD;
			ec[i] = modexp(2, ctx[i]-1)%MOD;
		}	
	}
	for(int i=1;i<=70;i++)	
	{
		int t = i;
		for(int j=0;j<19;j++)
		{
			int p = prime[j];
			int ct = 0;
			while((t > 1) && !(t%p))
			{
				t /= p;
				ct++;
			}
			if(ct & 1)
			bxv[i] ^= (1<<j);	
		}	
	}
	//ll ans = sqzd(1, 0);
	memo[71][0] = 1*1LL;
	for(int j=((1<<19)-1);j>0;j--)
	memo[71][j] = 0*1LL;	
	for(int i=70;i>0;i--)
	{
		for(int j=((1<<19)-1);j>=0;j--)
		{
			if(ctx[i])
			memo[i][j] = ((((1LL*oc[i]%MOD) * (1LL*memo[i+1][j ^ bxv[i]]%MOD))%MOD) + (((1LL*ec[i]%MOD) * (1LL*memo[i+1][j]%MOD))%MOD))%MOD;
			else memo[i][j] = (1LL*memo[i+1][j])%MOD;
		}	
	}	
	std::cout<<(((1LL*memo[1][0]%MOD) - (1%MOD) + MOD)%MOD)<<"\n";
	//std::cout<<((ans%MOD) - (1%MOD) + MOD)%MOD<<"\n";
	return 0;	
}