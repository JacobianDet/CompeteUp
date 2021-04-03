#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(arr, 0, sizeof(arr));
		int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		{
			std::cin>>arr[i];
			arr[i] += arr[i-1];
		}	
		ll tot = arr[1];
		int dy = 0;
		ll id = 1;
		for(dy=1;dy<=n;dy++)
		{
			if((id + tot) >= n)
			break;
			else
			{
				id += tot;
				tot = arr[id];
			}	
		}
		std::cout<<dy<<"\n";	
	}
	return 0;
}