#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define ll long long

ll n,m;
ll G[1000][1000];
ll lvl[1000][1000];

std::pair<ll, ll> NE[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void bfs_visit(ll s, ll d)
{
	std::queue<std::pair<ll, ll> > Q;
	Q.push(mp(s, d));
	while(!Q.empty())
	{
		ll x = Q.front().first;
		ll y = Q.front().second;
		Q.pop();
		for(ll i=0;i<4;i++)
		{
			ll u = NE[i].first;
			ll v = NE[i].second;
			ll cx = x + u;
			ll cy = y + v;
			if(0 <= cx && cx < n && 0 <= cy && cy < m && G[cx][cy] != -1 && lvl[cx][cy] > lvl[x][y] + 1 && lvl[x][y] + 1 <= G[s][d])
			{
				lvl[cx][cy] = lvl[x][y] + 1;
				if(lvl[cx][cy] < G[s][d])
				Q.push(mp(cx, cy));	
			}	
		}	
	}
	return;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	while(T--)
	{
		std::cin>>n>>m;
		std::vector<std::pair<ll, ll> > Z;
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{	
				std::cin>>G[i][j];
				if(G[i][j] > 0)
				{	
					Z.pb(mp(i,j));
					lvl[i][j] = 0;
				}	
				else lvl[i][j] = 10000000;
			}		
		}	
		for(ll i=0,j=(ll)Z.size();i<j;i++)
		{
			ll x = Z[i].first;
			ll y = Z[i].second;
			bfs_visit(x, y);
		}	
		for(ll i=0;i<n;i++)
		{
			std::string s;
			for(ll j=0;j<m;j++)
			{
				if(G[i][j] == -1)
				s += 'B';
				else if(lvl[i][j] == 10000000)
				s += 'N';
				else s += 'Y';	
			}	
			std::cout<<s<<"\n";
		}	
	}
	return 0;	
}