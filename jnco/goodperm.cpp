#include <bits/stdc++.h>

int arr[10];
int pzx[10];
bool mark[10];
int n,k;

void perm_find(int i, int& c)
{
	if(i == n+1)
	{
		int ct = 0;
		for(int j=1;j<=n-1;j++)
		{
			if(pzx[j] < pzx[j+1])
			ct++;	
		}	
		if(ct == k)
		c++;	
		return;
	}	
	if(arr[i])
	{	
		pzx[i] = arr[i];
		perm_find(i+1, c);
	}	
	else
	{
		for(int j=1;j<=n;j++)
		{
			if(!mark[j])
			{	
				pzx[i] = j;
				mark[j] = 1;
				perm_find(i+1, c);
				pzx[i] = 0;
				mark[j] = 0;
			}	
		}	
	}
	return;	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(arr, 0, sizeof(arr));
		memset(pzx, 0, sizeof(pzx));
		memset(mark, 0, sizeof(mark));
		std::cin>>n>>k;
		for(int i=1;i<=n;i++)
		{	
			std::cin>>arr[i];
			mark[arr[i]] = 1;
		}	
		int c = 0;
		perm_find(1, c);
		std::cout<<c<<"\n";	
	}	
	return 0;
}