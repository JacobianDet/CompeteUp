#include <bits/stdc++.h>

int binc(std::string s, int ind)
{
    int n = s.size();
    int lo = ind;
    int hi = n-1;
    while(lo < hi)
    {
        int mid = lo + (hi - lo)/2;
        if(s[ind] == s[mid])
        hi = mid;
        else lo = mid + 1;
    }
    if(s[lo] != s[ind])
    lo = ind;
    return lo;
}

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        std::string s,t;
        std::cin>>s;
        int c = 0;
        for(int j=0,k=s.size();j<k-1; )
        {
            int x = binc(s, j);
            if(x-j == 0)
            {
                j++;
                continue;
            }
            else if(x-j == 1)
            {
                c += (x-j);
                int y = binc(s, x);
                while(y-x == 1)
                {
                    c += (y-j);
                    x = y;
                    y = binc(s, x);
                }
                j = x;
            }
            else if(x-j > 1)
            {
                t = s.substr(j+1, x-j-1);
                x = 0;
                int y = binc(t, x);
                while(y-x == 1)
                {
                    x = y;
                    y = binc(t, x);
                }
                if(x == (int)t.size()-1)
                c++;
                j++;
            }
        }
        std::cout<<c<<"\n";
    }
    return 0;
}
