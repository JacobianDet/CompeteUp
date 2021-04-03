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
        int n;
        std::cin>>n;
        if(n == 1)
        std::cout<<"1 1\n";
        else if(n == 2)
        std::cout<<"1 10\n";
        else
        {
            if(n & 1)
            {
                std::cout<<"1 1";
                for(int i=0;i<(n-1)/2;i++)
                std::cout<<"0";
                std::cout<<"\n";
            }
            else
            {
                std::cout<<"1 1";
                for(int i=0;i<n/2;i++)
                std::cout<<"0";
                std::cout<<"\n";
            }    
        }
    }
    return 0;
}