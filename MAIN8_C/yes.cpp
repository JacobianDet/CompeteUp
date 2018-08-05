#include <bits/stdc++.h>

int arr[50000];

int bs2(int n, int k)
{
    int lo = 0;
    int hi = *std::max_element(arr, arr+n);
    while(lo < hi)
    {
        int mid = lo + (hi - lo + 1)/2;
        int ct = 0;
        for(int i=0;i<n;i++)
        ct += (arr[i]/mid);
        if(ct < k)
        hi = mid - 1;
        else lo = mid;
    }
    return lo;
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,k;
        std::cin>>n>>k;
        for(int i=0;i<n;i++)
        std::cin>>arr[i];
        int ans = bs2(n, k);
        std::cout<<ans<<"\n";
    }
    return 0;
}