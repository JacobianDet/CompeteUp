#include <bits/stdc++.h>

int A[1001], B[1001];

int main(void)
{
	int n,s;
	std::cin>>n>>s;
	for(int i=1;i<=n;i++)
	std::cin>>A[i];
	for(int i=1;i<=n;i++)
	std::cin>>B[i];
	if(!A[1] || (!A[s] && !B[s]))
	std::cout<<"NO\n";
	else
	{
		if(!A[s] && B[s])
		{
			bool ok = 0;
			for(int i=s+1;i<=n;i++)
			{
				if(A[i] && B[i])
				{
					ok = 1;
					break;
				}	
			}	
			if(!ok)
			std::cout<<"NO\n";
			else std::cout<<"YES\n";	
		}	
		else std::cout<<"YES\n";
	}
	return 0;
}