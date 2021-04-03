#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define INF 1000000000000000

typedef long long ll;

ll memo1[513], memo2[513];
std::vector<int> val[513];
std::pair<ll, int> PZ[100001];

bool cmpx(int A, int B)
{
	return (PZ[A].first < PZ[B].first);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for(int i=0;i<512;i++)
	{	
		memo1[i] = 0;
		memo2[i] = INF;
	}		
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int r;
		std::cin>>r;
		int mask = 0;
		for(int j=0;j<r;j++)
		{
			int c;
			std::cin>>c;
			mask |= (1<<(c-1));
		}
		memo1[mask]++;
	}	
	for(int i=0;i<m;i++)
	{
		std::cin>>PZ[i].first;
		int r;
		std::cin>>r;
		int mask = 0;
		for(int j=0;j<r;j++)
		{
			int c;
			std::cin>>c;
			mask |= (1<<(c-1));
		}	
		PZ[i].second = mask;
		val[mask].pb(i);
		memo2[mask] = std::min(memo2[mask], PZ[i].first);	
	}	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<512;j++)
		{	
			if(j & (1<<i))
			memo1[j] += memo1[j ^ (1<<i)];	
		}		
	}
	for(int i=0;i<512;i++)
	std::sort(val[i].begin(), val[i].end(), cmpx);	
	ll mzx = 0, czx = INF;
	int v1 = 0, v2 = 0;
	for(int i=0;i<512;i++)
	{
		for(int j=0;j<512;j++)
		{
			if(i != j)
			{	
				if(memo2[i] != INF && memo2[j] != INF)
				{	
					if(memo1[i | j] == mzx && czx > memo2[i] + memo2[j])
					{
						mzx = memo1[i | j];
						czx = std::min(czx, memo2[i] + memo2[j]);
						v1 = val[i][0];
						v2 = val[j][0];
					}	
					else if(memo1[i | j] > mzx)
					{
						mzx = memo1[i | j];
						czx = memo2[i] + memo2[j];
						v1 = val[i][0];
						v2 = val[j][0];
					}
				}
			}
			else
			{
				if(memo2[i] != INF && val[i].size() >= 2)
				{
					if(memo1[i] == mzx && czx > PZ[val[i][0]].first + PZ[val[i][1]].first)
					{
						mzx = memo1[i];
						czx = std::min(czx, PZ[val[i][0]].first + PZ[val[i][1]].first);
						v1 = val[i][0];
						v2 = val[i][1];
					}	
					else if(memo1[i] > mzx)
					{
						mzx = memo1[i];
						czx = PZ[val[i][0]].first + PZ[val[i][1]].first;
						v1 = val[i][0];
						v2 = val[i][1];
					}
				}
			}			
		}	
	}
	std::cout<<v1+1<<" "<<v2+1<<"\n";
	return 0;	
}