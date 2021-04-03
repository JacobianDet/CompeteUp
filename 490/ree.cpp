#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	std::vector<int> di;
	for(int i=1;i*i<=n;i++)
	{
		if(!(n % i))
		{
			if(i*i == n)
			di.pb(i);
			else
			{	
				di.pb(i);
				di.pb(n/i);
			}	
		}	
	}
	std::sort(di.begin(), di.end());
	for(int i=0,j=(int)di.size();i<j;i++)
	{
		for(int k=0;k<di[i]/2;k++)
		std::swap(s[k], s[di[i]-k-1]);	
	}
	std::cout<<s<<"\n";
	return 0;
}