#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

int main(void)
{
	int n;
	std::cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	bool d3[n], m2[n];
	memset(d3,0,sizeof(d3));
	memset(m2,0,sizeof(m2));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j] == 2*arr[i])
			{	
				m2[i] = 1;
				break;
			}		
		}
		if(arr[i] % 3)
		d3[i] = 0;
		else
		{
			for(int j=0;j<n;j++)
			{
				if(arr[j] == arr[i]/3)
				{	
					d3[i] = 1;
					break;
				}		
			}	
		}	
	}
	std::vector<ll> res;
	int x = 0;
	while(x != n)
	{	
		for(int i=0;i<n;i++)
		{
			if(!d3[i] && !m2[i])
			{	
				d3[i] = 1;
				m2[i] = 1;
				res.pb(arr[i]);
				for(int j=0;j<n;j++)
				{	
					if(arr[i] == arr[j]*2)
					{	
						m2[j] = 0;
						break;
					}
					else if(arr[i]*3 == arr[j])
					{
						d3[j] = 0;
						break;
					}	
				}
				break;		
			}	
		}
		x++;
	}
	std::reverse(res.begin(), res.end());
	for(int i=0;i<n;i++)
	std::cout<<res[i]<<" ";
	std::cout<<"\n";
	return 0;	
}