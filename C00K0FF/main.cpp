#include <bits/stdc++.h>

bool bins(std::string x,std::string s[],long long beg,long long las)
{
    while(beg <= las)
    {
        long long mid = (beg + las)/2;
        if(s[mid] == x)
        return true;
        else if(s[mid] > x)
        las = mid - 1;
        else beg = mid + 1;
    }
    return false;
}

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long n;
        std::cin>>n;
        std::string s[n];
        for(long long j=0;j<n;j++)
        std::cin>>s[j];
        if(n < 5)
        {
            std::cout<<"No"<<std::endl;
            continue;
        }
        std::sort(s,s+n);
        bool v[7];
        v[0] = bins("cakewalk",s,0,n-1);
        v[1] = bins("simple",s,0,n-1);
        v[2] = bins("easy",s,0,n-1);
        v[3] = bins("easy-medium",s,0,n-1);
        v[4] = bins("medium",s,0,n-1);
        v[5] = bins("medium-hard",s,0,n-1);
        v[6] = bins("hard",s,0,n-1);
        if(v[0] == true && v[1] == true && v[2] == true && (v[3] == true ||  v[4] == true) && (v[5] == true || v[6] == true))
        std::cout<<"Yes"<<std::endl;
        else std::cout<<"No"<<std::endl;
    }
    return 0;
}
