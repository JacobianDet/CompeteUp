#include <bits/stdc++.h>

int main(void)
{
    std::string s,t;
    std::cin>>s;
    int c=0;
    for(int i=1,l=s.size();i<=l;i++)
    {
        for(int j=0;j<=l-i;j++)
        {
            t = s.substr(j, i);
            if(t == "Danil"||t == "Olya"||t == "Slava"||t == "Ann"||t == "Nikita")
            c++;
        }
    }
    if(c == 1)
    std::cout<<"YES\n";
    else std::cout<<"NO\n";
    return 0;
}
