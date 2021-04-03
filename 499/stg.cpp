#include <bits/stdc++.h>

bool cmp(char a, char b)
{
    return (a < b);
}

int main(void)
{
    int n,k;
    std::cin>>n>>k;
    std::string s;
    std::cin>>s;
    std::sort(s.begin(), s.end(), cmp);
    char pc = s[0];
    int ct = 1, wt = (pc - 'a' + 1);
    for(int i=1;i<n;i++)
    {
        if(ct == k)
        break;
        if((int)(s[i] - pc) >= 2)
        {
            ct++;
            pc = s[i];
            wt += (pc - 'a' + 1);
        }
    }
    if(ct < k)
    std::cout<<"-1\n";
    else std::cout<<wt<<"\n";
    return 0;
}