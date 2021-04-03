#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	std::vector<int> v;
	for(int i=0;i<n;i++)
	{	
		int z;
		std::cin>>z;
		v.pb(z);
	}	
	bool flag = 0;
	for(int k=0;k<n;k++)
	{
		for(int i=0,j=(int)v.size();i<j-1;i++)
		{
			if(abs(v[i]-v[i+1]) >= 2)
			{
				flag =1;
				break;
			}
		}
		if(flag)
		break;
		int pos = 0;
		for(int i=0,j=(int)v.size();i<j;i++)
		{
			if(v[i] > v[pos])
			pos = i;	
		}	
		v.erase(v.begin()+pos);
	}
	if(flag)
	std::cout<<"NO\n";
	else std::cout<<"YES\n";
	return 0;	
}