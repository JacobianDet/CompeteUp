#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> ans[1001];

int main(void)
{
    std::string s;
    std::cin>>s;
    int n = (int)s.size();
    std::stack<int> Z;
    for(int i=0;i<n;i++)
    {
        if(Z.empty())
        Z.push(i);
        else
        {
            if(s[Z.top()] == s[i])
            {
                if(s[i] == '0')
                {
                    ans[i] = mp(3, 1);
                    ans[Z.top()] = mp(1, 1);
                }
                else
                {
                    ans[i] = mp(4, 1);
                    ans[Z.top()] = mp(4, 3);
                }
                Z.pop();
            }
            else
            {
                if(Z.size() == 1)
                {
                    Z.push(i);
                    continue;
                }
                int a = Z.top();
                Z.pop();
                int b = Z.top();
                Z.pop();
                if(s[b] == s[i])
                {
                    if(s[i] == '0')
                    {
                        ans[i] = mp(3, 1);
                        ans[b] = mp(1, 1);
                    }
                    else
                    {
                        ans[i] = mp(4, 1);
                        ans[b] = mp(4, 3);
                    }
                    Z.push(a);
                }
            }
        }
    }
    while(!Z.empty())
    {
        if(s[Z.top()] == '0')
        ans[Z.top()] = mp(1, 1);
        else ans[Z.top()] = mp(4, 3);
        Z.pop();
    }
    for(int i=0;i<n;i++)
    std::cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
}