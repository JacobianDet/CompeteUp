#include <bits/stdc++.h>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string s;
    std::cin>>s;
    int n = (int)s.size();
    int p1 = -1, p2 = -1, p3 = -1, p4 = -1;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '[')
        {
            p1 = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == ']')
        {
            p2 = i;
            break;
        }
    }
    bool ok = 1;
    int ctx = 0;
    if((p1 == -1) || (p2 == -1) || (p1 >= p2))
    ok = 0;
    else
    {
        for(int i=p1;i<=p2;i++)
        {
            if(s[i] == ':')
            {
                p3 = i;
                break;
            }
        }
        for(int i=p2;i>=p1;i--)
        {
            if(s[i] == ':')
            {
                p4 = i;
                break;
            }
        }
        if((p3 == -1) || (p4 == -1) || (p3 >= p4))
        ok = 0;
        else
        {
            ctx = 4;
            for(int i=p3+1;i<p4;i++)
            {
                if(s[i] == '|')
                ctx++;
            }
        }
    }
    if(!ok)
    std::cout<<"-1\n";
    else std::cout<<ctx<<"\n";
    return 0;
}