#include <bits/stdc++.h>

int arr[1001][1001], mxr[1001][1001], mxc[1001][1001], zxr[1001][1001], zxc[1001][1001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		std::cin>>arr[i][j];	
	}	
	for(int i=0;i<n;i++)
	{
		std::set<int> Z;
		for(int j=0;j<m;j++)
		Z.insert(arr[i][j]);
		std::map<int, int> Y;
		int val = 0;
		for(auto u : Z)
		{	
			Y[u] = val+1;
			val++;
		}		
		for(int j=0;j<m;j++)
		{	
			zxr[i][j] = Y[arr[i][j]];
			mxr[i][j] = val;
		}
		Z.clear();		
	}	
	for(int i=0;i<m;i++)
	{
		std::set<int> Z;
		for(int j=0;j<n;j++)
		Z.insert(arr[j][i]);
		std::map<int, int> Y;
		int val = 0;
		for(auto u : Z)
		{	
			Y[u] = val+1;
			val++;
		}		
		for(int j=0;j<n;j++)
		{	
			zxc[j][i] = Y[arr[j][i]];
			mxc[j][i] = val;
		}
		Z.clear();	
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(zxr[i][j] >= zxc[i][j])
			std::cout<<std::max(mxr[i][j], mxc[i][j] + (zxr[i][j] - zxc[i][j]))<<" ";
			else std::cout<<std::max(mxc[i][j], mxr[i][j] + (zxc[i][j] - zxr[i][j]))<<" ";
		}
		std::cout<<"\n";	
	}	
	return 0;
}