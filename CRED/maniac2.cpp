#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll G[101][101], res[101][101];

void MATMUL(ll A[101][101], ll B[101][101], ll n)
{
	ll C[101][101];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		C[i][j] = 0;	
	}	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			ll sx = 0;
			for(ll k=1;k<=n;k++)
			sx = ((sx%MOD) + (((A[i][k]%MOD) * (B[k][j]%MOD))%MOD))%MOD;
			C[i][j] = sx;	
		}	
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		A[i][j] = C[i][j];	
	}
	return;
}

void modexp(ll n, ll k)
{
	for(int i=1;i<=n;i++)
	res[i][i] = 1;
	while(k)
	{
		if(k & 1)
		MATMUL(res, G, n);
		MATMUL(G, G, n);
		k >>= 1;	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		G[i][j] = res[i][j];	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,q,m,k;
	std::cin>>n>>q>>k>>m;
	for(ll i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s][d] = 1;
	}	
	modexp(n, k);
	while(q--)
	{
		int s,d;
		std::cin>>s>>d;
		std::cout<<G[s][d]<<"\n";
	}	
	return 0;
}