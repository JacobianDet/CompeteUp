#include <bits/stdc++.h>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        std::string s;
        std::cin>>s;
        int n = (int)s.size();
        int ctr[26];
        memset(ctr, 0, sizeof(ctr));
        for(int i=0;i<n;i++)
        ctr[s[i] - 97]++;
        bool ok = 0;
        for(int i=0;i<26;i++)
        {
            if(ctr[i] == n)
            {
                ok = 1;
                break;
            }
        }
        if(ok)
        std::cout<<"-1\n";
        else
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<ctr[i];j++)
                std::cout<<(char)(i + 97);
            }
            std::cout<<"\n";
        }
    }
    return 0;
}