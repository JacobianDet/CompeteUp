#include <bits/stdc++.h>

std::string s[1000];
bool rw[1000], cw[1000];

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,m;
        std::cin>>n>>m;
        for(int i=0;i<n;i++)
        std::cin>>s[i];
        for(int i=0;i<n;i++)
        rw[i] = 0;
        for(int i=0;i<m;i++)
        cw[i] = 0;
        bool oc = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j] == '1')
                {
                    oc = 1;
                    break;
                }
            }
        }
        if(!oc)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                std::cout<<"-1 ";
                std::cout<<"\n";
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(s[i][j] == '1')
                    rw[i] = 1;
                }
            }  
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(s[j][i] == '1')
                    cw[i] = 1;
                }
            } 
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(s[i][j] == '1')
                    std::cout<<"0 ";
                    else if(rw[i] || cw[j])
                    std::cout<<"1 ";
                    else std::cout<<"2 ";
                }
                std::cout<<"\n";
            } 
        }
    }
    return 0;
}