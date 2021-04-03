#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
    std::string s;
    std::cin>>s;
    ll ao = 0, ae = 0, bo = 0, be = 0;
    ll to = 0, te = 0;
    for(int i=0,j=(int)s.size();i<j;i++)
    {
        if(i & 1)
        {
            if(s[i] == 'a')
            {
                ae++;
                to += ae;
                te += ao;
            }
            else
            {
                be++;
                to += be;
                te += bo;
            }
        }
        else
        {
            if(s[i] == 'a')
            {
                ao++;
                to += ao;
                te += ae;
            }
            else
            {
                bo++;
                to += bo;
                te += be;
            }
        }
    }
    std::cout<<te<<" "<<to<<"\n";
    return 0;
}
