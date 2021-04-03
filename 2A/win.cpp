#include <bits/stdc++.h>
#define pb push_back

std::map <std::string, int> msi1, msi2;

int main(void)
{
    int n;
    std::cin>>n;
    std::vector<std::string> Z1;
    std::vector<int> Z2;
    for(int i=0;i<n;i++)
    {
        std::string s;
        int c;
        std::cin>>s>>c;
        Z1.pb(s);
        Z2.pb(c);
        msi1[s] += c;
    }
    int ans = 0;
    for(std::map<std::string, int>::iterator it = msi1.begin();it != msi1.end();it++)
    {
        if(ans < it->second)
        ans = it->second;
    }
    for(int i=0;i<n;i++)
    {
        msi2[Z1[i]] += Z2[i];
        if(msi2[Z1[i]] >= ans && msi1[Z1[i]] == ans)
        {
            std::cout<<Z1[i]<<"\n";
            break;
        }
    }
    return 0;
}