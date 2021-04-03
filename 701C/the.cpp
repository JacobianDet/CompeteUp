#include <bits/stdc++.h>

int main(void)
{
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    int ctx[52];
    memset(ctx, 0, sizeof(ctx));
    for(int i=0;i<n;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        ctx[s[i] - 'a' + 26]++;
        else ctx[s[i] - 'A']++;
    }
    int ctv = 0;
    for(int i=0;i<52;i++)
    {
        if(ctx[i])
        ctv++;
    }
    int p1 = 0, p2 = 0;
    int rex = 0, ans = n;
    memset(ctx, 0, sizeof(ctx));
    while(p2 < n)
    {
        while((p1 < p2) && (rex == ctv))
        {
            ans = std::min(ans, (p2-p1));
            if(s[p1] >= 'a' && s[p1] <= 'z')
            {
                ctx[s[p1] - 'a' + 26]--;
                if(!ctx[s[p1] - 'a' + 26])
                rex--;
            }
            else
            {
                ctx[s[p1] - 'A']--;
                if(!ctx[s[p1] - 'A'])
                rex--; 
            }    
            p1++;
        }
        if(rex < ctv)
        {
            if(s[p2] >= 'a' && s[p2] <= 'z')
            {
                ctx[s[p2] - 'a' + 26]++;
                if(!(ctx[s[p2] - 'a' + 26] - 1))
                rex++;
            }
            else
            {
                ctx[s[p2] - 'A']++;
                if(!(ctx[s[p2] - 'A'] - 1))
                rex++; 
            }   
            p2++;
        }
    }
    while(p1 < n)
    {
        if(rex == ctv)
        ans = std::min(ans, p2-p1);
        if(s[p1] >= 'a' && s[p1] <= 'z')
        {
            ctx[s[p1] - 'a' + 26]--;
            if(!ctx[s[p1] - 'a' + 26])
            rex--;
        }
        else
        {
            ctx[s[p1] - 'A']--;
            if(!ctx[s[p1] - 'A'])
            rex--; 
        }    
        p1++;
    }
    std::cout<<ans<<"\n";
}