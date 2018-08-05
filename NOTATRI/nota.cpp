#include <bits/stdc++.h>

int binc(std::vector<int> &len, int elem)
{
    int n = len.size();
    int lo = 0;
    int hi = n-1;
    while(lo < hi)
    {
        int mid = lo + (hi-lo)/2;
        if(len[mid] > elem)
        hi = mid;
        else lo = mid + 1;
    }
    if(len[lo] <= elem)
    lo = n;
    return lo;
}

int main(void)
{
    int n;
    std::cin>>n;
    while(n != 0)
    {
        std::vector<int> len(n);
        for(int i=0;i<n;i++)
        std::cin>>len[i];
        std::sort(len.begin(), len.end());
        int c=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int e = len[i]+len[j];
                int ans = binc(len, e);
                c += n-ans;
            }
        }
        std::cout<<c<<"\n";
        std::cin>>n;
    }
    return 0;
}
