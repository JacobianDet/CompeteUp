#include <bits/stdc++.h>

int arr[400], ctr[1001], res[400];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n*n;i++)
	{	
		std::cin>>arr[i];
		ctr[arr[i]]++;
	}
	int oc = 0, tc = 0;
	for(int i=0;i<1001;i++)	
	{
		if(ctr[i] & 1)
		oc++;	
		if((ctr[i] % 4) == 2)
		tc++;	
	}	
	if(((n & 1) && ((oc > 1) || (tc > ((n>>1)<<1)))) || ((!(n & 1)) && ((oc > 0) || (tc > 0))))
	std::cout<<"NO\n";
	else
	{
		std::cout<<"YES\n";
		int pz = 0;
		for(int i=0;i<1001;i++)
		{
			if(ctr[i] & 1)
			{
				res[(n>>1)*n + (n>>1)] = i;
				ctr[i]--;
				break;
			}	
		}	
		int j = 0, k = 0;
		for(int i=0;i<1001;i++)
		{
			int x = (ctr[i]/4)*4;
			int ox = x;
			if(x)
			{	
				for( ;j<(n>>1); )
				{
					for( ;k<(n>>1);k++)
					{
						if(!x)
						break;
						res[j*n + k] = i;
						res[j*n + n - 1 - k] = i;
						res[n*n - 1 - (j*n + k)] = i;
						res[n*n - 1 - (j*n + n - 1 - k)] = i;
						x -= 4;	
					}
					if(k == (n>>1))	
					{	
						k = 0;
						j++;
					}		
					if(!x)
					break;
				}	
			}
			if(ox != x)
			ctr[i] = x + (ctr[i]%4);	
		}	
		j = 0, k = 0;
		for(int i=0;i<1001;i++)
		{
			if(ctr[i] && !(ctr[i] % 2))
			{	
				for( ;j<(n>>1);j++)
				{
					if(!ctr[i])
					break;
					res[(n>>1)*n + j] = i;
					res[(n>>1)*n + n - 1 - j] = i;
					ctr[i] -= 2;	
				}
				if(j == (n>>1))
				{
					for( ;k<(n>>1);k++)
					{
						if(!ctr[i])
						break;	
						res[k*n + (n>>1)] = i;
						res[n*n - 1 - (k*n + (n>>1))] = i;
						ctr[i] -= 2;
					}	
				}	
			}		
		}	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			std::cout<<res[i*n + j]<<" ";
			std::cout<<"\n";
		}	
	}	
	return 0;
}