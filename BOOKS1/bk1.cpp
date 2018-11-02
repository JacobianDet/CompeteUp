#include <bits/stdc++.h>

typedef long long ll;

ll arr[501];
bool mark[501];

ll bs1(int m, int k)
{
	ll lo = *std::max_element(arr, arr+m);
	ll hi = std::accumulate(arr, arr+m, 0);
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		ll ct = 0;
		int px = 1;
		for(int i=0;i<m;i++)
		{
			if(ct + arr[i] <= mid)
			ct += arr[i];
			else
			{
				ct = arr[i];
				px++;
			}	
		}	
		if(px > k)
		lo = mid + 1;
		else hi = mid;	
	}	
	return lo;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(mark, 0, sizeof(mark));
		int m,k;
		std::cin>>m>>k;
		for(int i=0;i<m;i++)
		std::cin>>arr[i];
		ll az = bs1(m, k);
		ll ct = 0, px = 0;
		for(int i=m-1;i>=0;i--)
		{
			if(ct + arr[i] <= az)
			ct += arr[i];
			else
			{
				px++;
				mark[i] = 1;
				ct = arr[i];
			}	
		}	
		if(px < k-1)
		{
			for(int i=0;i<m;i++)
			{
				if(px == k-1)
				break;	
				if(!mark[i])
				{
					mark[i] = 1;
					px++;
				}
			}	
		}
		for(int i=0;i<m;i++)
		{
			std::cout<<arr[i]<<" ";
			if(mark[i])
			std::cout<<"/ ";	
		}	
		std::cout<<"\n";
	}
	return 0;
}