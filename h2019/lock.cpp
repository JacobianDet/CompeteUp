#include <bits/stdc++.h>

int arr[16];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	bool ok = 0;
	for(int i=0;i<(1<<n);i++)
	{
		int os = 0, es = 0;
		for(int j=0;j<n;j++)
		{
			if(i & (1<<j))
			os += arr[j];	
			else es += arr[j];
		}
		if(!((abs(os - es)) % 360))
		{
			ok = 1;
			break;
		}	
	}	
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}