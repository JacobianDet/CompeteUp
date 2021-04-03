#include <bits/stdc++.h>

int main(void)
{
    std::string a,b;
    std::cin>>a>>b;
    bool ok = 0;
    if((int)a.size() != (int)b.size())
    ok = 1;
    else 
    {
        int n = (int)a.size();
        int a0 = 0, b0 = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == '0')
            a0++;
            if(b[i] == '0')
            b0++;
        }
        if(((a0 == n) && (b0 < n)) || ((a0 < n) && (b0 == n))) 
        ok = 1;        
    }
    if(ok)
    std::cout<<"NO\n";
    else std::cout<<"YES\n";
    return 0;
}