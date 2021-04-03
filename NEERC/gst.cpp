#include <bits/stdc++.h>

typedef long long ll;

int arr[7];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int k;
		std::cin>>k;
		for(int i=0;i<7;i++)
		std::cin>>arr[i];
		int ctr = 0;
		for(int i=0;i<7;i++)
		{
			if(arr[i])
			ctr++;	
		}	
		ll zx = 0;
		bool cz = 0;
		if(!(k % ctr))
		zx = (k/ctr);
		else 
		{
			zx = (k/ctr) + 1;
			cz = 1;
		}	
		ll tw = zx * 7;
		int dc = 0;
		int isn = 0, ifn = 0;
		for(int i=0;i<7;i++)
		{
			if(arr[i])
			{
				isn = i;
				tw -= dc;
				dc = 0;
				break;
			}	
			else dc++;
		}	
		for(int i=6;i>=0;i--)
		{
			if(arr[i])
			{
				ifn = i;
				tw -= dc;
				dc = 0;
				break;
			}	
			else dc++;
		}
		if(!cz)
		std::cout<<tw<<"\n";
		else
		{
			ll rz = (k % ctr);
			for(int t1=0;t1<=rz;t1++)
			{
		        int idc1 = 0, idc2 = 0;
		        int oc = 0;
				for(int i=isn;i<=ifn;i++)
				{	
					idc1++;
					if(arr[i])
					{	
						oc++;
						if(oc == t1 + 1)
						{
							idc1--;
							oc = 0;
							break;
						}	
					}	
				}
				for(int i=ifn;i>=isn;i--)
			    {
			    	idc2++;
			    	if(arr[i])
			    	{
			    		oc++;
			    		if(oc == rz - t1 + 1)
			    		{
			    			idc2--;
			    			oc = 0;
			    			break;
			    		}	
			    	}	
			    }
			    dc = std::max(dc, idc1 + idc2);
			}
			tw -= dc;
			std::cout<<tw<<"\n";	
		}	
	}
	return 0;
}