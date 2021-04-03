#include <bits/stdc++.h>

int lcp[1000001];

int main(void)
{
    std::string s;
    std::cin>>s;
    int n = (int)s.size();
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
    int a1 = lcp[n-1];
    if(a1)
    {
        bool ok1 = 0;
        for(int i=a1;i<n-1;i++)
        {
            if(lcp[i] == a1)
            {
                ok1 = 1;
                break;
            }
        }
        if(ok1)
        std::cout<<s.substr(0, a1)<<"\n";
        else
        {
            int a2 = lcp[a1-1];
            if(a2)
            std::cout<<s.substr(0, a2)<<"\n";
            else std::cout<<"Just a legend\n";
        }
    }
    else std::cout<<"Just a legend\n";
    return 0;
}
