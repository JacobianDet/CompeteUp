#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 100001

std::vector<std::pair<int, int> > G[CHOR];
int ed[CHOR], par[CHOR], lvl[CHOR];
int P[CHOR][20], mxe[CHOR][20], mne[CHOR][20];

void dfs_visit(int s, int p)
{
	if(p != -1)
	{
		par[s] = p;
		lvl[s] = 1 + lvl[p];
	}	
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		int u = G[s][i].first;
		int w = G[s][i].second;
		if(u != p)
		{
			ed[u] = w;
			dfs_visit(u, s);
		}	
	}
	return;	
}

void ST_build(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n;j++)
		{
			P[i][j] = -1;
			mxe[i][j] = 0;
			mne[i][j] = 1000001;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		P[i][0] = par[i];
		mxe[i][0] = ed[i];
		mne[i][0] = ed[i];
	}	
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			{
				P[i][j] = P[P[i][j-1]][j-1];
				mxe[i][j] = std::max(mxe[i][j-1], mxe[P[i][j-1]][j-1]);
				mne[i][j] = std::min(mne[i][j-1], mne[P[i][j-1]][j-1]);
			}	
		}	
	}
	return;	
}

std::pair<int, int> LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
	}	
	int lx = 0;
	int mx = 0, mn = 1000001;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		{
			mx = std::max(mx, mxe[p][i]);
			mn = std::min(mn, mne[p][i]);
			p = P[p][i];
		}	
	}
	if(p == q)
	return mp(mn, mx);	
	for(int i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			mx = std::max(mx, mxe[p][i]);
			mx = std::max(mx, mxe[q][i]);
			mn = std::min(mn, mne[p][i]);
			mn = std::min(mn, mne[q][i]);
			p = P[p][i];
			q = P[q][i];
		}	
	}
	mx = std::max(mx, mxe[p][0]);
	mx = std::max(mx, mxe[q][0]);
	mn = std::min(mn, mne[p][0]);
	mn = std::min(mn, mne[q][0]);
	return mp(mn, mx);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d,w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, w));
		G[d].pb(mp(s, w));
	}	
	dfs_visit(1, -1);
	ST_build(n);
	int q;
	std::cin>>q;
	while(q--)
	{
		int l,r;
		std::cin>>l>>r;
		std::pair<int, int> Z = LCA_find(l, r);
		std::cout<<Z.first<<" "<<Z.second<<"\n";
	}	
	return 0;
}