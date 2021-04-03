#include <bits/stdc++.h>

int main(void)
{
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(arr[i] & 1)
        std::cout<<arr[i]<<" ";
        else std::cout<<arr[i]-1<<" ";
    }
    std::cout<<"\n";
    return 0;
}