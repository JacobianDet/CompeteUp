#include <bits/stdc++.h>
#define pb push_back

int lcp[10000001];

int main(void)
{
    int n;
    while(std::cin>>n)
    {
        std::string s;
        std::cin>>s;
        lcp[0] = 0;
        for(int i=1;i<n;i++)
        {
            int j = lcp[i-1];
            while(j && (s[i] != s[j]))
            j = lcp[j-1];
            if(s[i] == s[j])
            j++;
            lcp[i] = j;
        }
        std::cin.ignore();
        char c;
        std::vector<int> zex;
        int plcp = 0;
        int x = 0;
        c = getchar_unlocked();
        while(true)
        {
            if(c < 'a' || c > 'z')
            break;
            int j = plcp;
            while(j && (c != s[j]))
            j = lcp[j-1];
            if(c == s[j])
            j++;
            plcp = j;
            if(plcp == n)
            zex.pb(x-n+1);
            x++;
            c = getchar_unlocked();
        }
        if((int)zex.size() > 0)
        {
            for(int i=0,j=(int)zex.size();i<j;i++)
            std::cout<<zex[i]<<"\n";
        }
        else std::cout<<"\n";
    } 
    return 0;
}