#include <bits/stdc++.h>

typedef long long ll;

ll res[10][10], dxv[10][10], oxc[10][10][10], dx0[10];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string s;
    std::cin>>s;
    for(int i=0;i<10;i++)
    {
    	dx0[i] = 100000;
    	for(int j=0;j<10;j++)
    	dxv[i][j] = 100000;	
    }	
    for(int i=0;i<10;i++)
    {
    	for(int j=0;j<10;j++)
    	dxv[i][(j * i)%10] = std::min(dxv[i][(j * i)%10], 1LL*j);
    }
    for(int i=0;i<10;i++)
    {
    	for(int j=1;j<=10;j++)
    	{	
    		if(!((j * i)%10))
    		dx0[i] = std::min(dx0[i], 1LL*j);
    	}		
    }	
    for(int i=0;i<10;i++)
    {
    	for(int j=0;j<10;j++)
    	{
    		for(int k=0;k<10;k++)
    		oxc[i][j][k] = 100000;	
    	}
    }
    for(int i=0;i<10;i++)
    {
    	for(int j=0;j<10;j++)
    	{
    		for(int k=0;k<10;k++)
    		{
    			for(int l=0;l<10;l++)
    			{
    				for(int m=0;m<10;m++)
    				{
    					if((l + m)%10 == k)
    					{	
    						if(!l && !m)
    						oxc[i][j][k] = std::min(oxc[i][j][k], std::min(dx0[i], dx0[j]));
    						else oxc[i][j][k] = std::min(oxc[i][j][k], dxv[i][l] + dxv[j][m]);
    					}
    				}	
    			}	
    		}
    	}
    }
    for(int i=0;i<10;i++)
    {
    	for(int j=0;j<10;j++)
    	{
    		ll tot = 0;
    		for(int k=1;k<s.size();k++)
    		{
    			int d1 = s[k] - '0', d2 = s[k-1] - '0';
    			int df = (d1 - d2 + 10)%10;
    			//std::cout<<d1<<" "<<d2<<" "<<df<<"\n";
    			ll fx = oxc[i][j][df];
    			if(fx >= 100000)
    			{
    				tot = -1;
    				break;
    			}	
    			else tot += (fx-1);
    		}
    		res[i][j] = tot;
    	}
    }
    for(int i=0;i<10;i++)
    {
    	for(int j=0;j<10;j++)
    	std::cout<<res[i][j]<<" ";
    	std::cout<<"\n";	
    }
    return 0;
}