#include <bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

int main(void)
{
    std::string t;
    std::cin>>t;
    int n = (int)t.size();
    std::deque<char> D;
    for(int i=0;i<n;i++)
    D.pb(t[i]);
    t = "";
    while(!D.empty())
    {
        int sz = (int)D.size();
        if(sz & 1)
        {
            t += D.front();
            D.pof();
        }
        else
        {
            t += D.back();
            D.pob();
        }
    }
    std::reverse(t.begin(), t.end());
    std::cout<<t<<"\n";
    return 0;
}