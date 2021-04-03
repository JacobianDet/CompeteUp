#include <bits/stdc++.h>

int arr[201];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
    	int n;
    	std::cin>>n;
    	for(int i=0;i<n;i++)
    	std::cin>>arr[i];
    	int ok = 0;
    	for(int i=0;i<n-1;i++)
    	{
    		if(!i)
    		{	
	    		if(arr[i+1] == (((arr[i] + 1)%n) ? (arr[i] + 1)%n : n))
	    		ok = 1;
	    		else if(arr[i+1] == (((arr[i] - 1 + n)%n) ? ((arr[i] - 1 + n)%n) : n))
	    		ok = 2;
	    		else break;	
	    	}
	    	else
	    	{
	    		if(ok == 1)
	    		{
	    			if(arr[i+1] != (((arr[i] + 1)%n) ? (arr[i] + 1)%n : n))
	    			{	
	    				ok = 0;
	    				break;
	    			}		
	    			else continue;
	    		}
	    		else if(ok == 2)
	    		{
	    			if(arr[i+1] != (((arr[i] - 1 + n)%n) ? ((arr[i] - 1 + n)%n) : n))
	    			{
	    				ok = 0;
	    				break;
	    			}
	    			else continue;	
	    		}	
	    	}	
    	}
    	if(ok == 1 || ok == 2 || n == 1)
    	std::cout<<"YES\n";
    	else std::cout<<"NO\n";	
    }
    return 0;
}    