#include <bits/stdc++.h>

int main(void)
{
    int n,k;
    std::cin>>n>>k;
    std::string s;
    std::cin>>s;
    int ca = 0, cb = 0;
    int p1 = 0, p2 = 0;
    int ans = 0;
    while(p2 < n)
    {
        while((p1 < p2) && (ca > k && cb > k))
        {
            if(s[p1] == 'a')
            ca--;
            else cb--;
            p1++;
        }
        if(ca <= k || cb <= k)
        {
            ans = std::max(ans, ca+cb);
            if(s[p2] == 'a')
            ca++;
            else cb++;
            p2++;
        }
    }
    if(ca <= k || cb <= k)
    ans = std::max(ans, ca+cb);
    std::cout<<ans<<"\n";
    return 0;
}
