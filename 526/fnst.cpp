#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
    ll n,k;
    std::string s,t;
    std::cin>>n>>k>>s>>t;
    ll xd = 1, ans = 0;
    int pos = -1;
    for(int i=0;i<n;i++)
    {
        xd <<= 1;
        if(s[i] == 'b')
        xd--;
        if(t[i] == 'a')
        xd--;
        if(xd >= k)
        {
            pos = i;
            break;
        }
        ans += std::min(xd, k);
    }
    if(pos != -1)
    ans += k*(n-pos);
    std::cout<<ans<<"\n";
    return 0;
}