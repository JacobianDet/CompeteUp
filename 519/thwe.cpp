#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

struct trp
{
	ll x,y,ind;
}arr[300001];

ll prx[300001], pry[300001];
ll ans[300001];

bool cmpx(trp a, trp b)
{
	return ((a.x - a.y) == (b.x - b.y)) ? (a.x < b.x) : ((a.x - a.y) < (b.x - b.y));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ll x,y;
		std::cin>>x>>y;
		arr[i] = {x, y, i};
	}	
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		ll mn = 1000000000000;
		mn = std::min(arr[s].x + arr[d].y, arr[s].y + arr[d].x);
		ans[s] -= mn;
		ans[d] -= mn;
	}	
	std::sort(arr+1, arr+n+1, cmpx);
	for(int i=1;i<=n;i++)
	{
		prx[i] = prx[i-1] + arr[i].x;
		pry[i] = pry[i-1] + arr[i].y;
	}	
	for(int i=1;i<=n;i++)
	ans[arr[i].ind] += ((pry[n] - pry[i]) + prx[i-1] + ((i-1) * arr[i].y) + ((n-i) * arr[i].x));
	for(int i=1;i<=n;i++)
	std::cout<<ans[i]<<" ";
	std::cout<<"\n";
	return 0;	
 }