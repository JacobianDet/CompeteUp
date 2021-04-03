#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::string G[1001], H[1001];
int l[1001][1001], r[1001][1001], u[1001][1001], d[1001][1001], h[1001][1001], v[1001][1001];
std::vector<std::pair<std::pair<int, int>, int> > res;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<n;i++)
    std::cin>>G[i];
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(G[i][j] == '.')
			{
				l[i][j] = 0;
				u[i][j] = 0;
			}	
			else
			{
				if(i-1 >= 0)
				u[i][j] = 1 + u[i-1][j];
				else u[i][j] = 1;
				if(j-1 >= 0)
				l[i][j] = 1 + l[i][j-1];
				else l[i][j] = 1;	
			}
		}
	}	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(G[i][j] == '.')
			{
				r[i][j] = 0;
				d[i][j] = 0;
			}	
			else
			{
				if(i+1 < n)
				d[i][j] = 1 + d[i+1][j];
				else d[i][j] = 1;
				if(j+1 < m)
				r[i][j] = 1 + r[i][j+1];
				else r[i][j] = 1;	
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(G[i][j] == '*')
			{
				int len = std::min(l[i][j], std::min(r[i][j], std::min(u[i][j], d[i][j]))) - 1;
				if(len != 0)
				res.pb(mp(mp(i, j), len));	
			}	
		}
	}
	for(auto u : res)
	{
		v[u.first.first-u.second][u.first.second]++;
		if(u.first.first+u.second+1 < n)
		v[u.first.first+u.second+1][u.first.second]--;
		h[u.first.first][u.first.second-u.second]++;
		if(u.first.second+u.second+1 < m)
		h[u.first.first][u.first.second+u.second+1]--;	
	}
	for(int i=0;i<n;i++)
	{
		H[i].resize(m);
		for(int j=0;j<m;j++)
		{
			if(i-1 >= 0)
			v[i][j] += v[i-1][j];
			if(j-1 >= 0)
			h[i][j] += h[i][j-1];
			if(h[i][j] > 0 || v[i][j] > 0)
			H[i][j] = '*';
			else H[i][j] = '.';
		}
	}
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		if(G[i] != H[i])
		{
			ok = 0;
			break;
		}	
	}
	if(!ok)
	std::cout<<"-1\n";
	else
	{
		std::cout<<res.size()<<"\n";
		for(auto u : res)
		std::cout<<u.first.first+1<<" "<<u.first.second+1<<" "<<u.second<<"\n";	
	}	
	return 0;
}