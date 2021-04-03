#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define INF 100000000000000001

typedef long long ll;

ll memo[100005][205];
std::pair<ll, int> pre[100005];
int n;

struct q4
{
	int s, t, d, pin;
	ll w;

	bool operator < (const q4& wx) const
	{
		return ((w > wx.w) || ((w == wx.w) && (d > wx.d)));
	}

};

std::vector<q4> Q[100005];
std::multiset<q4> X;

ll BALLIA(int z, int m)
{
	if(m < 0)
	return INF;	
	else if(z > n)
	return 0;
	if(memo[z][m] != -1)
	return memo[z][m];
	ll ans = INF;
	if(pre[z] != mp(0LL, 0))
	ans = std::min(pre[z].first + BALLIA(pre[z].second + 1, m), BALLIA(z + 1, m - 1));
	else ans = BALLIA(z + 1, m);
	memo[z][m] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int m,k;
	std::cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	pre[i] = mp(0LL, 0);
	for(int i=1;i<=k;i++)
	{
		int s, t, d;
		ll w;
		std::cin>>s>>t>>d>>w;
		Q[s].pb({s, t, d, 1, w});
		Q[t+1].pb({s, t, d, -1, w});
	}
	for(int i=1;i<=n;i++)
	{
		for(auto u : Q[i])
		{	
			if(u.pin == 1)
			X.insert(u);
			else X.erase(X.find({u.s, u.t, u.d, 1, u.w}));
		}
		if(!X.empty())
		pre[i] = mp((*X.begin()).w, (*X.begin()).d);
		else pre[i] = mp(0LL, 0);	
	}
	ll ans = BALLIA(1, m);
	std::cout<<ans<<"\n";
	return 0;
}