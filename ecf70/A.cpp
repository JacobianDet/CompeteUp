#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
    	std::string x,y;
    	std::cin>>x>>y;
    	int n1 = x.size();
    	int n2 = y.size();
    	std::reverse(x.begin(), x.end());
    	std::reverse(y.begin(), y.end());
    	int f1 = 0;
    	for(int i=0;i<n2;i++)
    	{
    		if(y[i] == '1')
    		{
    			f1 = i;
    			break;
    		}	
    	}
    	int pos = f1;
    	for(pos=f1;pos<n1;pos++)
    	{
    		if(x[pos] == '0')
    		continue;
    		else break;	
    	}	
    	std::cout<<(pos-f1)<<"\n";
    }
    return 0;
}