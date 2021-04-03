#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

int B[20], ctr[10];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll a, b;
    std::cin>>a>>b;
    int n1 = 0, n2 = 0;
    ll t = a;
    while(t)
    {
    	n1++;
    	ctr[t%10]++;
    	t /= 10;
    }
    t = b;
    while(t)
    {
    	B[20-n2-1] = (t%10);
    	n2++;
    	t /= 10;
    }
    if(n1 < n2)
    {
    	for(int j=n1;j>0;j--)
    	{
	    	for(int i=9;i>=0;i--)
	    	{
	    		if(ctr[i])
	    		{	
	    			ctr[i]--;
	    			std::cout<<i;
	    			break;
	    		}		
	    	}
	    }	
    	std::cout<<"\n";	
    }	
    else
    {
    	std::vector<int> res;
    	bool ok = 0;
    	for(int i=0;i<n2;i++)
    	{
    		bool tc = 0;
    		for(int j=9;j>=0;j--)
    		{
    			if(ctr[j])
    			{
    				if(!ok)
    				{
	    				if(B[20-n2+i] < j)
	    				continue;
	    				else if(B[20-n2+i] > j)
	    				{
	    					tc = 1;
	    					ok = 1;
	    					res.pb(j);
	    					ctr[j]--;
	    					break;
	    				}	
	    				else
	    				{
	    					tc = 1;
	    					res.pb(j);
	    					ctr[j]--;
	    					break;
	    				}
	    			}
	    			else
	    			{
	    				ctr[j]--;
	    				res.pb(j);
	    				tc = 1;
	    				break;
	    			}	
    			}
    		}
    		if(!tc)
    		{
    			int pos = -1;
    			for(int j=res.size()-1;j>=0;j--)
    			{
    				ctr[res[j]]++;
    				for(int k=res[j]-1;k>=0;k--)
    				{
    					if(ctr[k])
    					{	
	    					pos = j;
	    					ctr[k]--;
	    					res[j] = k;
	    					tc = 1;
	    					ok = 1;
	    					break;
	    				}	
    				}
    				if(tc)
    				break;	
    			}
    			for(int j=pos+1;j<=i;j++)
    			{
    				for(int k=9;k>=0;k--)
    				{
    					if(ctr[k])
    					{	
    						ctr[k]--;
    						if(j != i)
    						res[j] = k;
    						else res.pb(k);
    						break;
    					}	
    				}	
    			}
    		}
    	}
    	for(auto u : res)
    	std::cout<<u;
    	std::cout<<"\n";		
    }
    return 0;
}