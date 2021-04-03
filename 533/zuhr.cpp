#include <bits/stdc++.h>
#define pb push_back

std::vector<int> jan[26];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,k;
    std::string s;
    std::cin>>n>>k>>s;
    int ctr = 1;
    for(int i=0;i<n;i++)
    {
        if(i < n-1)
        {
            if(s[i] != s[i+1])
            {
                jan[s[i] - 'a'].pb(ctr);
                ctr = 1;
            }
            else ctr++;
        }
        else jan[s[i] - 'a'].pb(ctr);
    }
    int xz = 0;
    for(int i=0;i<26;i++)
    {
        int ixz = 0;
        for(int j=0,sz=(int)jan[i].size();j<sz;j++)
        ixz += jan[i][j]/k;
        xz = std::max(xz, ixz);
    }
    std::cout<<xz<<"\n";
    return 0;
}