#include <bits/stdc++.h>

std::map<int, int> ctz;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
    	ctz.clear();
    	int n;
    	std::cin>>n;
    	for(int i=0;i<4*n;i++)
    	{
    		int x;
    		std::cin>>x;
    		ctz[x]++;
    	}	
    	bool ok = 1;
    	for(auto u : ctz)
    	{
    		if(u.second & 1)
    		{
    			ok = 0;
    			break;
    		}	
    	}
    	if(ctz.size() == 1)
    	std::cout<<"YES\n";
    	else
    	{	
	    	auto it1 = ctz.begin();
	    	auto it2 = ctz.rbegin();
	    	int ar = it1->first * it2->first;
	    	while(it1->first <= it2->first)
	    	{
	    		if(it1->first * it2->first == ar)
	    		{
	    			if(it1->second == it2->second)
	    			{
	    				it1++;
	    				it2++;
	    			}	
	    			else if(it1->second < it2->second)
	    			{
	    				it2->second -= it1->second;
	    				it1++;
	    			}	
	    			else if(it1->second > it2->second)
	    			{
	    				it1->second -= it2->second;
	    				it2++;
	    			}
	    		}
	    		else 
	    		{
	    			ok = 0;
	    			break;
	    		}	
	    	}
	    	if(ok)
	    	std::cout<<"YES\n";
	    	else std::cout<<"NO\n";	
	    }		
    }
    return 0;
}    