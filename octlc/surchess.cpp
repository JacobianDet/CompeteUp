#include <bits/stdc++.h>
#define INF 100000000

/* 0 = BLACK
   1 = WHITE*/

std::string G[201];
int rw[2][201][201], cw[2][201][201];
int dist[201];

int bs2(int n, int val)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(dist[mid] <= val)
		lo = mid;
		else hi = mid - 1;	
	}
	return lo;
}

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
			if(!(i & 1))
			{
				if(!(j & 1))
				{	
					if(G[i][j] == '0')
					rw[1][i][j] = 1;
					else rw[0][i][j] = 1;
				}
				else
				{
					if(G[i][j] == '0')
					rw[0][i][j] = 1;
					else rw[1][i][j] = 1;	
				}	 	
			}
			else
			{
				if(!(j & 1))
				{
					if(G[i][j] == '0')
					rw[0][i][j] = 1;
					else rw[1][i][j] = 1; 	
				}	
				else
				{
					if(G[i][j] == '0')
					rw[1][i][j] = 1;
					else rw[0][i][j] = 1;
				}
			}
		}	
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(!(j & 1))
			{
				if(!(i & 1))
				{	
					if(G[i][j] == '0')
					cw[1][i][j] = 1;
					else cw[0][i][j] = 1;
				}
				else
				{
					if(G[i][j] == '0')
					cw[0][i][j] = 1;
					else cw[1][i][j] = 1;	
				}	 	
			}
			else
			{
				if(!(i & 1))
				{
					if(G[i][j] == '0')
					cw[0][i][j] = 1;
					else cw[1][i][j] = 1; 	
				}	
				else
				{
					if(G[i][j] == '0')
					cw[1][i][j] = 1;
					else cw[0][i][j] = 1;
				}
			}
		}
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			rw[0][i][j] += rw[0][i][j-1];
			rw[1][i][j] += rw[1][i][j-1];
		}	
	}
	for(int j=0;j<m;j++)
	{
		for(int i=1;i<n;i++)
		{
			cw[0][i][j] += cw[0][i-1][j];
			cw[1][i][j] += cw[1][i-1][j];
		}	
	}
	int mx = std::min(n, m);
	for(int i=1;i<=mx;i++)
	dist[i] = INF;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int ct1 = 0, ct2 = 0;
			for(int k=1,z=std::max(i, j);k<=mx-z;k++)
			{
				if(!i && !j)
				{	
					ct1 += (rw[0][i+k-1][j+k-1]);
					ct2 += (rw[1][i+k-1][j+k-1]);
					if(k > 1)
					{
						ct1 += (cw[0][i+k-2][j+k-1]);
						ct2 += (cw[1][i+k-2][j+k-1]);
					}	
				}
				else if(!i)
				{
					ct1 += (rw[0][i+k-1][j+k-1] - rw[0][i+k-1][j-1]);
					ct2 += (rw[1][i+k-1][j+k-1] - rw[1][i+k-1][j-1]);
					if(k > 1)
					{
						ct1 += (cw[0][i+k-2][j+k-1]);
						ct2 += (cw[1][i+k-2][j+k-1]);
					}
				}
				else if(!j)
				{
					ct1 += (rw[0][i+k-1][j+k-1]);
					ct2 += (rw[1][i+k-1][j+k-1]);
					if(k > 1)
					{
						ct1 += (cw[0][i+k-2][j+k-1] - cw[0][i-1][j+k-1]);
						ct2 += (cw[1][i+k-2][j+k-1] - cw[1][i-1][j+k-1]);
					}	
				}	
				else
				{
					ct1 += (rw[0][i+k-1][j+k-1] - rw[0][i+k-1][j-1]);
					ct2 += (rw[1][i+k-1][j+k-1] - rw[1][i+k-1][j-1]);
					if(k > 1)
					{
						ct1 += (cw[0][i+k-2][j+k-1] - cw[0][i-1][j+k-1]);
						ct2 += (cw[1][i+k-2][j+k-1] - cw[1][i-1][j+k-1]);
					}		
				}
				dist[k] = std::min(dist[k], std::min(ct1, ct2));
			}	
		}	
	}
	int q;
	std::cin>>q;
	while(q--)
	{
		int x;
		std::cin>>x;
		int pos = bs2(mx, x);
		std::cout<<pos<<"\n";
	}	
	return 0;
}