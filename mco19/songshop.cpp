#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

struct ssn
{
	int a,p;
	ll v;
}ax[1001];

int bx[1001], lb[1001], rb[1001];
ll sbx[1001];
std::vector<int> albx[1001];
ll memo[1001][1001];
std::vector<int> cmb;
int n;

ll MR0X(int i, int p)
{
	if(p < 0)
	return -1000000000000;
	else if(i == n)
	return 0;
	if(memo[i][p] != -1)
	return memo[i][p];
	ll ans = std::max(MR0X(i+1, p), ax[cmb[i]].v + MR0X(i+1, p-ax[cmb[i]].p));
	if(i == lb[ax[cmb[i]].a])
	ans = std::max(ans, sbx[ax[cmb[i]].a] + MR0X(rb[ax[cmb[i]].a], p-bx[ax[cmb[i]].a]));
	memo[i][p] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int m,p;
	std::cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	std::cin>>ax[i].a>>ax[i].p>>ax[i].v;
	for(int i=1;i<=m;i++)
	std::cin>>bx[i];
	for(int i=1;i<=n;i++)
	{	
		albx[ax[i].a].pb(i);
		sbx[ax[i].a] += ax[i].v;
	}
	for(int i=1;i<=m;i++)
	{
		lb[i] = cmb.size();
		cmb.insert(cmb.end(), albx[i].begin(), albx[i].end());
		rb[i] = cmb.size();
	}	
	ll ans = MR0X(0, p);	
	std::cout<<ans<<"\n";
	return 0;	
}