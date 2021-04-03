#include <bits/stdc++.h>

typedef long long ll;

ll memo[2][3001][3001];
bool vis[2][3001][3001];
ll arr[3001];

ll DEQUE(int bx, int i, int j)
{
	if(i == j)
	{
		if(!bx)
		return arr[i];	
		else return -arr[i];
	}	
	if(vis[bx][i][j])
	return memo[bx][i][j];
	ll ans = 0;
	if(!bx)
	ans = std::max(arr[i] + DEQUE(bx ^ 1, i+1, j), arr[j] + DEQUE(bx ^ 1, i, j-1));
	else ans = std::min(-arr[i] + DEQUE(bx ^ 1, i+1, j), -arr[j] + DEQUE(bx ^ 1, i, j-1));
	vis[bx][i][j] = 1;
	memo[bx][i][j] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	memset(vis, 0, sizeof(vis));
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	ll ans = DEQUE(0, 1, n);	
	std::cout<<ans<<"\n";
	return 0;
}