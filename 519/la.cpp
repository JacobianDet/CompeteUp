#include <bits/stdc++.h>
#define pb push_back

int arr[1001], xar[1001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=1;i<=n;i++)
	xar[i-1] = arr[i] - arr[i-1];
	std::vector<int> res;
	for(int i=1;i<=n;i++)
	{
		bool ok = 1;
		for(int j=0;j<n-i;j++)
		{
			if(xar[j] != xar[j+i])
			{
				ok = 0;
				break;
			}	
		}	
		if(ok)
		res.pb(i);	
	}	
	std::cout<<(int)res.size()<<"\n";
	for(int i=0,j=(int)res.size();i<j;i++)
	std::cout<<res[i]<<" ";
	std::cout<<"\n";
	return 0;	
}