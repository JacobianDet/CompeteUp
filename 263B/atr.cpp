#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define CHOR 100001
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef double d;

std::vector<int> G[CHOR];
ll memo[CHOR][2];
int col[CHOR];

void dfs_visx(int s, int p)
{
	ll wv = 0, bv = 0;
	ll ans1 = 0, ans2 = 0;
	if(col[s])
	bv = 1;
	else wv = 1;
	for(int i=0,j=(int)G[s].size();i<j;i++)	
	{
		if(G[s][i] != p)
		{
			dfs_visx(G[s][i], s);
			ans1 = 0, ans2 = 0;
			ans1 = ((ans1%MOD) + (((((((memo[G[s][i]][0]%MOD) * (bv%MOD))%MOD) + (((memo[G[s][i]][1]%MOD) * (wv%MOD))%MOD))%MOD) + (((memo[G[s][i]][1]%MOD) * (bv%MOD))%MOD))%MOD))%MOD;
			ans2 = ((ans2%MOD) + (((((memo[G[s][i]][0]%MOD) * (wv%MOD))%MOD) + (((memo[G[s][i]][1]%MOD) * (wv%MOD))%MOD))%MOD))%MOD;
			bv = ans1;
			wv = ans2; 	
		}	
	}
	ans1 = bv;
	ans2 = wv;
	memo[s][1] = ans1;
	memo[s][0] = ans2;
	return;
}

int main(void)
{
	memset(memo, -1, sizeof(memo));
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int p;
		std::cin>>p;
		G[i+1].pb(p);
		G[p].pb(i+1);
	}	
	for(int i=0;i<n;i++)
	std::cin>>col[i];
	dfs_visx(0, -1);
	std::cout<<memo[0][1]<<"\n";
	return 0;
}