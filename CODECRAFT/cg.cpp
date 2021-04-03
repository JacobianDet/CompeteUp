#include <bits/stdc++.h>

int freq[100001];

int main(void)
{
	memset(freq,0,sizeof(freq));
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		freq[t]++;
	}
	bool flag = 0;
	for(int i=1e5;i>0;i--)
	{
		if(freq[i] & 1)
		{	
			flag = 1;
			break;
		}		
	}	
	if(flag)
	std::cout<<"Conan\n";
	else std::cout<<"Agasa\n";	
	return 0;	
}