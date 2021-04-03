#include <bits/stdc++.h>

typedef long long ll;

ll fct[20];

void factup(void)
{
    fct[0] = 1;
    for(int i=1;i<20;i++)
    fct[i] = i * fct[i-1];
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    factup();
    int T;
    std::cin>>T;
    while(T--)
    {
        std::string s;
        ll n;
        std::cin>>s>>n;
        std::set<char> Z;
        std::string t;
        for(int i=0,j=(int)s.size();i<j;i++)
        Z.insert(s[i]);
        ll ax = 0;
        for(int i=0,j=(int)s.size();i<j;i++)
        {
            int z = (int)Z.size();
            for(std::set<char>::iterator it = Z.begin();it != Z.end();it++)
            {
                if(s[i] != (*it))
                ax += fct[z-1];
                else
                {
                    Z.erase(it);
                    break;
                }
            }
        }
        ax++;
        n += ax;
        ax = 0;
        for(int i=0,j=(int)s.size();i<j;i++)
        Z.insert(s[i]);
        while(ax < n)
        {
            int z = (int)Z.size();
            if(!z)
            break;
            for(std::set<char>::iterator it = Z.begin();it != Z.end();it++)
            {
                if(ax + fct[z-1] < n)
                ax += fct[z-1];
                else
                {
                    t += (*it);
                    Z.erase(it);
                    break;
                }
            }
        }
        std::cout<<t<<"\n";
    }
    return 0;
}