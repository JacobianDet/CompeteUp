#include <bits/stdc++.h>

int main(void)
{
    int n,k;
    std::cin>>n>>k;
    int arr[n];
    int sm = 0;
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
        sm += arr[i];
    }
    std::cout<<std::max(0, 2*k*n - n - 2*sm)<<"\n";
    return 0;    
}