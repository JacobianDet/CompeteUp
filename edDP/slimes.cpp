#include <bits/stdc++.h>
#define mp std::make_pair
#define INF 10000000000000

typedef long long ll;

ll arr[401];
std::pair<ll, ll> memo[401][401];
bool vis[401][401];

std::pair<ll, ll> SLIME(int i, int j)
{
	if(i == j)
	return mp(0, arr[i]);	
	else if(i+1 == j)
	return mp((arr[i] + arr[j]), (arr[i] + arr[j]));
	if(vis[i][j])
	return memo[i][j];
	ll ans1 = INF, ans2 = INF;
	for(int k=i;k<j;k++)
	{
		std::pair<ll, ll> px1 = SLIME(i, k);
		std::pair<ll, ll> px2 = SLIME(k+1, j);
		if(ans1 > ((px1.second + px2.second) + px1.first + px2.first))
		{	
			ans1 = std::min(ans1, (px1.second + px2.second) + px1.first + px2.first);
			ans2 = (px1.second + px2.second);
		}	
	}
	vis[i][j] = 1;
	memo[i][j] = mp(ans1, ans2);
	return memo[i][j];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(vis, 0, sizeof(vis));
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	ll ans = SLIME(1, n).first;	
	std::cout<<ans<<"\n";
	return 0;
}