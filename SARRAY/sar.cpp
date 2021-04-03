#include <bits/stdc++.h>
#define mp std::make_pair
#define MV 100001
#define LM 20

struct trip
{
	int x, y, id;
}L[MV];

bool cmp(trip a, trip b)
{
	return (a.x == b.x) ? ((a.y < b.y) ? 1 : 0) : ((a.x < b.x) ? 1 : 0);
}

std::map<char, int> cord;
std::set<char> Z;
std::string s;
int SA[LM][MV];
int x;

class SAX
{
	public: void SA_build(int n);
			int LCP_find(int x, int y);
};

void SAX::SA_build(int n)
{
	for(int i=0;i<n;i++)
	SA[0][i] = cord[s[i]];
	for(int i=1;i<=x;i++)
	{
		for(int j=0;j<n;j++)
		{
			L[j].x = SA[i-1][j];
			L[j].y = (j + (1<<(i-1))) < n ? SA[i-1][j + (1<<(i-1))] : -1;
			L[j].id = j;
		}	
		std::sort(L, L+n, cmp);
		int u = 0;
		for(int j=0;j<n;j++)
		SA[i][L[j].id] = (j && (L[j].x == L[j-1].x) && (L[j].y == L[j-1].y)) ? SA[i][L[j-1].id] : u++;
	}	
	return;
}

int SAX::LCP_find(int x, int y)
{
	int ans = 0;
	for(int k=x;k>=0;k--)
	{
		if(SA[k][x] == SA[k][y])
		{
			ans += (1<<k);
			x += (1<<k);
			y += (1<<k);
		}	
	}
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin>>s;
	int n = (int)s.size();
	for(int i=0;i<n;i++)
	Z.insert(s[i]);
	int u = 0;	
	for(std::set<char>::iterator it = Z.begin();it != Z.end();it++)
	cord[*it] = u++;
	for(x=0;(1<<x)<=n;x++);
	SAX T;
	T.SA_build(n);
	std::set<std::pair<int, int> > V;
	for(int i=0;i<n;i++)
	V.insert(mp(SA[x][i], i));
	for(std::set<std::pair<int, int> >::iterator it = V.begin();it != V.end();it++)
	std::cout<<it->second<<"\n";
	return 0;
}