#include <bits/stdc++.h>

int arr[101];
int n;
bool vis[2][100001], memo[2][100001];

bool STONE(int bx, int k) 
{
	if(k < 0)
	return 1;
	else if(k == 0)
	return 0;	
	if(vis[bx][k])
	return memo[bx][k];	
	bool ans = 0;
	for(int i=1;i<=n;i++)
	ans |= (1 ^ STONE(bx ^ 1, k - arr[i]));	
	vis[bx][k] = 1;
	memo[bx][k] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, 0, sizeof(memo));
	memset(vis, 0, sizeof(vis));
	int k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	bool ans = STONE(0, k);	
	if(ans)
	std::cout<<"First\n";
	else std::cout<<"Second\n";
	return 0;	
}