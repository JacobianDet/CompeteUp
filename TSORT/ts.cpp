#include <bits/stdc++.h>

int arr[1000001];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    std::sort(arr+1, arr+n+1);
    for(int i=1;i<=n;i++)
    std::cout<<arr[i]<<"\n";
    return 0;
}