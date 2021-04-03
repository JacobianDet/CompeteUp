#include <bits/stdc++.h>

typedef long long ll;

ll arr[50001];

int main(void)
{
	int n;
	std::cin>>n;
	ll sx = 0;
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i];
		sx += arr[i];
	}	
	sx /= n;
	ll mv = 0;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i] < sx)
		{
			arr[i+1] -= (sx - arr[i]);
			mv += (sx - arr[i]);
			arr[i] = sx;
		}	
		else
		{
			arr[i+1] += (arr[i] - sx);
			mv += (arr[i] - sx);
			arr[i] = sx;
		}
	}	
	std::cout<<mv<<"\n";
	return 0;
}