#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        std::string s;
        std::cin>>s;
        for(int i=0;i<n;i+=2)
        {
            if(i+1 < n)
            std::swap(s[i], s[i+1]);
        }
        for(int i=0;i<n;i++)
        s[i] = ('z' - s[i] + 'a');
        std::cout<<s<<"\n";
    }
    return 0;
}