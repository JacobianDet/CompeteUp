#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	if(n < k || __builtin_popcount(n) > k)
	std::cout<<"NO\n";
	else
	{
		std::cout<<"YES\n";
		int fx = __builtin_popcount(n);
		std::vector<int> Z;
		while(n)
		{
			int x = n & (-n);
			Z.pb(x);
			n &= (n-1);
		}
		std::reverse(Z.begin(), Z.end());
		int pos = -1;
		for(int i=0;i<fx;i++)
		{
			if(Z[i] + (fx - i - 1) >= k)
			{
				pos = i;
				break;
			}	
			else 
			{
				for(int j=0;j<Z[i];j++)
				std::cout<<"1 ";	
				k -= Z[i];
			}
		}
		if(pos != -1)
		{
			int t = Z[pos];
			for(int i=pos+1;i<fx;i++)
			{	
				std::cout<<Z[i]<<" ";
				k--;
			}	
			while(k > 1)
			{
				if(k <= (t>>1))
				{
					std::cout<<(t>>1)<<" ";
					k--;
				}
				else
				{
					for(int i=0;i<(t>>1);i++)
					std::cout<<"1 ";
					k -= (t>>1);	
				}
				t >>= 1;
			}
			std::cout<<t<<"\n";
		}	
		else std::cout<<"\n";	
	}	
	return 0;
}