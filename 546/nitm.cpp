#include <bits/stdc++.h>

int A[501][501], B[501][501];
std::multiset<int> res[1005];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		std::cin>>A[i][j];	
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		std::cin>>B[i][j];	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		res[i+j].insert(A[i][j]);
	}	
	bool ok = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			auto it = res[i+j].find(B[i][j]);
			if(it == res[i+j].end())
			{
				ok = 0;
				break;
			}
			else res[i+j].erase(it);	
		}	
		if(!ok)
		break;	
	}	
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}