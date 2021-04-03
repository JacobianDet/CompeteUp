#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::vector<int> Z;
	for(int i=1;i<((1<<n)-1);i++)
	{
		int gs = 0, as = 0;
		for(int j=0;j<n;j++)
		{
			if(i & (1<<j))
			gs += arr[j];
			else as += arr[j];	
		}
		if(gs != as)
		{
			for(int j=0;j<n;j++)
			{
				if(i & (1<<j))
				Z.pb(j+1);	
			}
			break;	
		}	
	}
	if((int)Z.size() == 0)
	std::cout<<"-1\n";
	else
	{
		std::cout<<(int)Z.size()<<"\n";
		for(int i=0,j=(int)Z.size();i<j;i++)
		std::cout<<Z[i]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}