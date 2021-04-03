#include <bits/stdc++.h>

int arr[101], cnt[101];

int bs2(int n, int m)
{
    std::set<int> Z;
    for(int i=0;i<m;i++)
    Z.insert(arr[i]);
    std::vector<int> V(Z.begin(), Z.end());
    int lo = 0;
    int hi = m;
    while(lo < hi)
    {
        int mid = lo + (hi - lo + 1)/2;
        int tno = 0;
        for(int i=0,j=(int)V.size();i<j;i++)
        tno += cnt[V[i]]/mid;
        if(tno < n)
        hi = mid - 1;
        else lo = mid;
    }
    return lo;
}

int main(void)
{
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        std::cin>>arr[i];
        cnt[arr[i]]++;
    }    
    int ans = bs2(n, m);
    std::cout<<ans<<"\n";
    return 0;
}