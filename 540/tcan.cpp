#include <bits/stdc++.h>

typedef long long ll;

ll arr[200005], opref[200005], epref[200005], osuff[200005], esuff[200005];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=1;i<=n;i++)
	{
		if(i & 1)
		{
			opref[i] = opref[i-1] + arr[i];
			epref[i] = epref[i-1];
		}	
		else
		{
			opref[i] = opref[i-1];
			epref[i] = epref[i-1] + arr[i];
		}
	}	
	for(int i=n;i>0;i--)
	{
		if(i & 1)
		{
			osuff[i] = osuff[i+1] + arr[i];
			esuff[i] = esuff[i+1];
		}	
		else
		{
			osuff[i] = osuff[i+1];
			esuff[i] = esuff[i+1] + arr[i];
		}
	}
	int ctr = 0;
	for(int i=1;i<=n;i++)
	{
		if(opref[i-1] + esuff[i+1] == osuff[i+1] + epref[i-1])
		ctr++;	
	}	
	std::cout<<ctr<<"\n";
	return 0;
}