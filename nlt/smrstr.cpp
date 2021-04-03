#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,q;
		std::cin>>n>>q;
		std::vector<int> arr;
		for(int i=0;i<n;i++)
		{
			int t;
			std::cin>>t;
			if(t != 1)
			arr.pb(t);	
		}
		n = arr.size();
		while(q--)
		{
			int x;
			std::cin>>x;
			int z = std::min(32, n);
			for(int i=0;i<z;i++)
			x = x/arr[i];
			std::cout<<x<<" ";
		}	
		std::cout<<"\n";
	}	
	return 0;
}