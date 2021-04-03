#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> memo[100001];
bool vis[100001];
int arr[100001];

std::pair<int, int> kefx(int n)
{
	if(n == 1)
	return mp(1, 1);
	if(vis[n])
	return memo[n];
	int ansl = 0, ansg = 0;
	std::pair<int, int> p = kefx(n-1);
	if(arr[n-1] <= arr[n])
	ansl = 1 + p.second;
	else ansl = 1;
	ansg = std::max(ansl, p.first);
	vis[n] = 1;
	memo[n] = mp(ansg, ansl);
	return mp(ansg, ansl);	
}

int main(void)
{	
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	int ans = kefx(n).first;
	std::cout<<ans<<"\n";
	return 0;	
}