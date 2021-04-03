#include <bits/stdc++.h>

int arr[50001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	int tot = 0;
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
		tot += arr[i];
	}	
	std::sort(arr, arr+n);
	int mn = arr[0], mtot = tot;
	for(int i=0;i<n;i++)
	{
		for(int p=1;p*p<=arr[i];p++)
		{
			if(!(arr[i] % p))
			{
				if(p*p == arr[i])
				mtot = std::min(mtot, tot - arr[i] - mn + arr[i]/p + p*mn);
				else mtot = std::min(mtot, std::min(tot - arr[i] - mn + arr[i]/p + p*mn, tot - arr[i] - mn + p + (arr[i]/p) * mn));
			}
		}
	}
	std::cout<<mtot<<"\n";
	return 0;	
}