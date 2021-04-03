#include <bits/stdc++.h>

typedef long long ll;

ll arr[500001];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    bool op = 0, on = 0;
    ll mnx = 1000000005, sx = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < 0)
        {
            on = 1;
            sx += (-arr[i]);
            if(mnx > (-arr[i]))
            mnx = (-arr[i]);
        }
        else
        {
            op = 1;
            sx += arr[i];
            if(mnx > arr[i])
            mnx = arr[i];   
        }  
    }
    if(on && op)
    std::cout<<sx<<"\n";
    else 
    {
        if(n == 1)
        std::cout<<arr[0]<<"\n";
        else std::cout<<sx - (mnx<<1)<<"\n";
    }    
    return 0;
}