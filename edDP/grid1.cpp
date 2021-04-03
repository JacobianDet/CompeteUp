#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll memo[1001][1001];
std::string grid[1001];

ll GRID(int h, int w)
{
	if((h <= 0) || (w <= 0) || (grid[h-1][w-1] == '#'))
	return 0;	
	else if((h == 1) && (w == 1))
	return 1;
	if(memo[h][w] != -1)
	return memo[h][w];
	ll ans = ((GRID(h-1, w)%MOD) + (GRID(h, w-1)%MOD))%MOD;
	memo[h][w] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int h,w;
	std::cin>>h>>w;
	for(int i=0;i<h;i++)
	std::cin>>grid[i];
	ll ans = GRID(h, w)%MOD;
	std::cout<<ans<<"\n";
	return 0;
}