#include <bits/stdc++.h>

int arr[1000001];

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int m,n;
        std::cin>>m>>n;
        for(int i=0;i<n;i++)
        std::cin>>arr[i];
        std::sort(arr, arr+n);
        int nx = 0;
        if(m > 1)
        {
            for(int i=0;i<n-1;i++)
            {
                int x = arr[i]%m;
                int y = arr[i+1]%m;
                if(abs(x - y) == 1)
                continue;
                else
                {
                    if(x > y)
                    {
                        if((arr[i+1] - arr[i]) >= ((1LL*(x - y - 1))*m))
                        nx += (x - y - 1);
                        else
                        {
                            nx = -1;
                            break;
                        }
                    }
                    else if(y > x)
                    {
                        if((arr[i+1] - arr[i]) >= (y - x - 1))
                        nx += (y - x - 1);
                        else 
                        {
                            nx = -1;
                            break;
                        }
                    }
                    else
                    {
                        if((arr[i+1] - arr[i]) >= 1)
                        nx += 1;
                        else 
                        {
                            nx = -1;
                            break;
                        }
                    }
                }
            }
        }
        else nx = -1;
        std::cout<<nx<<"\n";    
    }
    return 0;
}