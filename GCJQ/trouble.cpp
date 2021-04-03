#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{	
		int n;
		std::cin>>n;
		std::vector<int> a(n);
		for(int i=0;i<n;i++)
		std::cin>>a[i];
		std::vector<int> odds;
		std::vector<int> evns;
		for(int i=0;i<n;i++)
		{
			if(i & 1)
			odds.pb(a[i]);
			else evns.pb(a[i]);	
		}	
		std::sort(odds.begin(), odds.end());
		std::sort(evns.begin(), evns.end());
		std::vector<int> ans;
		int io = 0;
		int ie = 0;
		for(int i=0;i<n;i++)
		{
			if(i & 1)
			{
				ans.pb(odds[io]);
				io++;
			}	
			else
			{
				ans.pb(evns[ie]);
				ie++;
			}	
		}	
		bool flag = 1;
		int pos = -1;
		for(int i=0;i<n-1;i++)
		{
			if(ans[i] > ans[i+1])
			{
				flag = 0;
				pos = i;
				break;
			}	
		}	
		if(!flag)
		std::cout<<"Case #"<<t<<": "<<pos<<"\n";
		else std::cout<<"Case #"<<t<<": "<<"OK\n";	
	}	
	return 0;
}