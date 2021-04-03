#include <bits/stdc++.h>

long long binc(std::string s1, std::string s2, std::vector<long long> ar)
{
    long long n = s1.size(),m = s2.size();
    long long lo = -1;
    long long hi = n-1;
    while(lo < hi)
    {
        long long mid = lo + (hi-lo+1)/2;
        std::string temp = s1;
        long long c=0,j=0;
        for(long long i=0;i<=mid;i++)
        temp[ar[i]-1] = '1';
        for(long long i=0;i<n;i++)
        {
            if(temp[i] == s2[j])
            {
                c++;
                j++;
            }
            if(j == m)
            break;
        }
        if(c < m)
        hi = mid-1;
        else lo = mid;
    }
    return lo;
}

int main(void)
{
    std::string t,p;
    std::cin>>t>>p;
    long long n = t.size();
    std::vector<long long> ar(n);
    for(long long i=0;i<n;i++)
    std::cin>>ar[i];
    long long ans = binc(t,p,ar);
    std::cout<<ans+1<<"\n";
    return 0;
}
