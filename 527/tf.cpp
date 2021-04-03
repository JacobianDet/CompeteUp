#include <bits/stdc++.h>

int arr[101];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    std::sort(arr, arr+n);
    int ans = 0;
    for(int i=0;i<n;i+=2)
    ans += (arr[i+1] - arr[i]);
    std::cout<<ans<<"\n";
    return 0;
}