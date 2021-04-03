#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

std::string L[101];
std::string F[101];

int btab[101];
std::pair<int, int> X[101];

bool cmpx(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.first < b.first);
}

int main(void)
{
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m,p;
		std::cin>>n>>m>>p;
		for(int i=0;i<n;i++)
		std::cin>>L[i];
		for(int i=0;i<m;i++)
		std::cin>>F[i];
		for(int i=0;i<p;i++)
		{
			int c1 = 0;
			for(int j=0;j<n;j++)
			{
				if(L[j][i] == '1')
				c1++;	
			}
			btab[i] = c1;
		}
		std::multiset<int> Z;
		for(int i=0;i<m;i++)
		{
			int cx = 0;
			for(int j=0;j<p;j++)
			{
				if(F[i][j] == '1')
				cx += (n - btab[j]);	
				else cx += btab[j];
			}	
			Z.insert(cx);
		}
		for(int i=0;i<p;i++)
		{
			int x = n - btab[i];
			int y = btab[i];
			if(x > y)
			{
				int tmp = x;
				x = y;
				y = tmp;
			}
			X[i] = mp(x, y);
		}
		std::sort(X, X+p, cmpx);
		int mx = 0;
		for(int i=0;i<p;i++)
		mx += X[i].first;
		std::vector<int> R;
		R.pb(mx);
		for(int i=p-1;i>=0;i--)
		{
			
		}

	}
	return 0;
}