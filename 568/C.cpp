#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	ll M;
	std::cin>>n>>M;
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
		if(i)
		arr[i] += arr[i-1];	
	}
	ll ctr[101];
	memset(ctr, 0, sizeof(ctr));
	for(int i=0;i<n;i++)
	{
		ll req = 0, ctx = 0;
		if(arr[i] > M)
		{	
			for(ll j=100;j>0;j--)
			{
				if(arr[i] - ctx - j*ctr[j] <= M)
				{	
					req += (arr[i] - ctx - M + (j - 1))/j;
					break;
				}	
				else 
				{
					ctx += j*ctr[j];
					req += ctr[j]; 
				}	
			}
		}
		std::cout<<req<<" ";
		if(!i)
		ctr[arr[i]]++;
		else ctr[arr[i] - arr[i-1]]++;	
	}
	std::cout<<"\n";
	return 0;
}