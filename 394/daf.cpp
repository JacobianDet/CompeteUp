#include <bits/stdc++.h>

int at[51], bt[51], df[51];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,L;
	std::cin>>n>>L;
	for(int i=0;i<n;i++)
	std::cin>>at[i];
	for(int i=0;i<n;i++)
	std::cin>>bt[i];
	for(int i=1;i<n;i++)
	df[i] = (at[i] - at[i-1]);
	df[0] = (L - at[n-1] + at[0]);
	bool tot = 0;
	for(int i=0;i<n;i++)
	{
		int st = bt[0];
		bool ok = 1;
		int pos = 0;
		for(int j=i+1;j<n;j++)
		{
			if(st + df[j] != bt[pos+1])
			{
				ok = 0;
				break;
			}
			else 
			{
				st = bt[pos+1];
				pos++;
			}	
		}	
		if(ok)
		{	
			for(int j=0;j<i;j++)
			{
				if(st + df[j] != bt[pos+1])
				{
					ok = 0;
					break;
				}	
				else 
				{
					st = bt[pos+1];
					pos++;
				}
			}
		}
		if(ok)
		{	
			tot = 1;
			break;
		}			
	}
	if(tot)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}