#include <bits/stdc++.h>
#define MV 100001
#define LMV 20

typedef long long ll;

int skl[MV][2], SB[MV][LMV][2];

class ST
{
	public: void build(int n, int ty);
			int query(int qs, int qd, int ty); 
};

void ST::build(int n, int ty)
{
	for(int i=1;i<=n;i++)
	SB[i][0][ty] = skl[i][ty];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<n;i++)
		{	
			if(i + (1<<(j-1)) <= n)
			SB[i][j][ty] = std::max(SB[i][j-1][ty], SB[i+(1<<(j-1))][j-1][ty]);
		}		
	}	
	return;
}

int ST::query(int qs, int qd, int ty)
{
	int lx = 0;
	for(lx=0;(1<<lx)<=(qd-qs+1);lx++);
	lx--;	
	int mx = std::max(SB[qs][lx][ty], SB[qd-(1<<lx)+1][lx][ty]);
	return mx;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,k;
		std::cin>>n>>k;
		for(int i=1;i<=n;i++)
		std::cin>>skl[i][0];
		for(int i=1;i<=n;i++)
		std::cin>>skl[i][1];
		ST Z;
		Z.build(n, 0);
		Z.build(n, 1);
		ll ct = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int m1 = Z.query(i, j, 0);
				int m2 = Z.query(i, j, 1);
				if(abs(m1 - m2) <= k)
				ct++;
			}	
		}
		std::cout<<"Case #"<<t<<": "<<ct<<"\n";	
	}
	return 0;
}