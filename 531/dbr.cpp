#include <bits/stdc++.h>

int arr[101];

int main(void)
{
    int n,x,y;
    std::cin>>n>>x>>y;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    if(x <= y)
    {
        int ctl = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] <= x)
            ctl++;
        }
        if(ctl & 1)
        std::cout<<((ctl>>1) + 1)<<"\n";
        else std::cout<<(ctl>>1)<<"\n";
    }
    else std::cout<<n<<"\n";
    return 0;
}