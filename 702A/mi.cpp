#include <bits/stdc++.h>
#define mp std::make_pair

int arr[100001];
bool vis[100001];
std::pair<int, int> memo[100001];
int n;

std::pair<int, int> axd(int i)
{
	if(i == n)
	return mp(1, 1);
	if(vis[i])
	return memo[i];
	int ans1 = 0;
	int ans2 = 0;
	std::pair<int, int> z = axd(i+1);
	ans2 = z.second;
	if(arr[i] < arr[i+1])
	ans1 = 1 + z.first;
	else ans1 = 1;
	if(ans1 > ans2)
	ans2 = ans1;
	vis[i] = 1;
	memo[i] = mp(ans1, ans2);
	return mp(ans1, ans2);
}

int main(void)
{
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	int ans = axd(1).second;
	std::cout<<ans<<"\n";
	return 0;	
}