#include <bits/stdc++.h>
#define mp std::make_pair
#define MV 1001
#define LM 15

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
			int LCP_find(int a, int b);
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

int SAX::LCP_find(int a, int b)
{
	int ans = 0;
	for(int k=x;k>=0;k--)
	{
		if(SA[k][a] == SA[k][b])
		{
			ans += (1<<k);
			a += (1<<k);
			b += (1<<k);
		}	
	}
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{	
		memset(SA, -1, sizeof(SA));
		std::cin>>s;
		int n = (int)s.size();
		for(int i=0;i<n;i++)
		Z.insert(s[i]);
		int u = 0;	
		for(std::set<char>::iterator it = Z.begin();it != Z.end();it++)
		cord[*it] = u++;
		for(x=0;(1<<x)<=n;x++);
		SAX D;
		D.SA_build(n);
		std::set<std::pair<int, int> > V;
		for(int i=0;i<n;i++)
		V.insert(mp(SA[x][i], i));
		std::vector<std::pair<int, int> > VT(V.begin(), V.end());
		int lcp = 0;
		for(int i=0,j=(int)VT.size();i<j;i++)
		{
			if(i)
			lcp += D.LCP_find(VT[i].second, VT[i-1].second);
		}	
		int ans = (n*n + n)/2 - lcp;
		std::cout<<ans<<"\n";
	}		
	return 0;
}