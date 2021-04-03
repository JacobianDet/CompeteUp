#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	if(n == 1 || n == 2)
	std::cout<<"No\n";
	else
	{
		std::cout<<"Yes\n";
		std::vector<int> v1, v2;
		int mk = 0;
		if(n & 1)
		mk = n;
		else mk = (n>>1);	
		for(int i=1;i<=n;i++)
		{
			if(i != mk)
			v2.pb(i);
			else v1.pb(i);	
		}	
		std::cout<<(int)v1.size()<<" ";
		for(int i=0,j=(int)v1.size();i<j;i++)
		std::cout<<v1[i]<<" ";
		std::cout<<"\n";	
		std::cout<<(int)v2.size()<<" ";
		for(int i=0,j=(int)v2.size();i<j;i++)
		std::cout<<v2[i]<<" ";
		std::cout<<"\n";
	}	
	return 0;
}