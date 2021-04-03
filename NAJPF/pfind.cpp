#include <bits/stdc++.h>
#define pb push_back

int lcp[2000002];
std::string z;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(lcp, 0, sizeof(lcp));
		std::string a,b;
		std::cin>>a>>b;
		z = b + '#' + a;
		lcp[0] = 0;
		for(int i=1,v=(int)z.size();i<v;i++)
		{
			int j = lcp[i-1];
			while(j && (z[i] != z[j]))
			j = lcp[j-1];
			if(z[i] == z[j])
			j++;
			lcp[i] = j;	
		}	
		int ctx = 0;
		std::vector<int> res;
		int n = (int)b.size();
		for(int i=n+1,j=(int)z.size();i<j;i++)
		{
			if(lcp[i] == n)
			{
				ctx++;
				res.pb(i-2*n+1);
			}	
		}
		if(ctx)
		{	
			std::cout<<ctx<<"\n";
			for(int i=0,j=(int)res.size();i<j;i++)
			std::cout<<res[i]<<" ";
			std::cout<<"\n";
		}	
		else std::cout<<"Not Found\n";	
	}	
	return 0;
}