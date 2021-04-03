#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
 
std::pair<int, int> NE[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
 
int arr[2000][2000];
int vis[2000][2000];
std::vector<std::pair<int, int> > Z[4000001];
std::vector<int> amma;
std::set<std::pair<int, int> > TAX;
int n,m;
 
int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
 
int dfs_visit(int a, int b, int x, int y, int inc)
{
	vis[a][b] = inc;
	int ctr = 1;
	for(int t=0;t<4;t++)
	{
		int ca = a + NE[t].first;
		int cb = b + NE[t].second;
		if(0 <= ca && ca < n && 0 <= cb && cb < m && ((arr[ca][cb] == x) || (arr[ca][cb] == y)) && vis[ca][cb] != inc)
		ctr += dfs_visit(ca, cb, x, y, inc);
	}	
	return ctr;
}
 
int main(void)
{
	n = readInt();
	m = readInt();
	int ct = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	
			arr[i][j] = readInt();
			if((int)Z[arr[i][j]].size() == 0)
			{	
				ct++;
				amma.pb(arr[i][j]);
			}	
			Z[arr[i][j]].pb(mp(i, j));	
		}	
	}	
	if(ct == 1 || ct == 2)
	printf("%d\n", n*m);
	else if(ct == n*m)
	printf("2\n");
	else
	{	
		for(int i=0,a=(int)amma.size();i<a;i++)
		{
			for(int j=0,k=(int)Z[amma[i]].size();j<k;j++)
			{
				for(int t=0;t<4;t++)
				{
					int cx = Z[amma[i]][j].first + NE[t].first;
					int cy = Z[amma[i]][j].second + NE[t].second;
					if(0 <= cx && cx < n && 0 <= cy && cy < m && (arr[cx][cy] > amma[i]))
					TAX.insert(mp(amma[i], arr[cx][cy]));		
				}	
			}	
		}
		int ctr = 0, inc = 0;
		for(std::set<std::pair<int, int> >::iterator it=TAX.begin();it != TAX.end();it++)
		{
			int x = it->first;
			int y = it->second;
			if((int)Z[x].size() > (int)Z[y].size())
			{
				int tmp = x;
				x = y;
				y = tmp;
			}	
			inc++;
			for(int i=0,j=(int)Z[x].size();i<j;i++)
			{
				int a = Z[x][i].first;
				int b = Z[x][i].second;
				if(vis[a][b] != inc)
				ctr = std::max(ctr, dfs_visit(a, b, x, y, inc));	
				if(2*ctr >= n*m)
				break;	
			}		
			if(2*ctr >= n*m)
			break;	
		}
		printf("%d\n", ctr);
	}		
	return 0;
} 