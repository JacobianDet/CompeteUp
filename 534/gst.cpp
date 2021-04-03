#include <bits/stdc++.h>

int main(void)
{
    std::string s;
    std::cin>>s;
    int n = (int)s.size();
    std::stack<int> Z;
    int popc = 0;
    for(int i=0;i<n;i++)
    {
        if(Z.empty())
        Z.push(i);
        else 
        {
            if(s[i] == s[Z.top()])
            {
                popc++;
                Z.pop();
            }
            else Z.push(i);
        }
    }
    if(popc & 1)
    std::cout<<"Yes\n";
    else std::cout<<"No\n";
    return 0;
}