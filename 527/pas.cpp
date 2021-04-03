#include <bits/stdc++.h>

std::string X[205];
bool plen[101];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<2*n-2;i++)
    std::cin>>X[i];
    std::string s1, s2;
    for(int i=0;i<2*n-2;i++)
    {
        if((int)X[i].size() == n-1)
        {
            if(s1 == "")
            s1 = X[i];
            else s2 = X[i];
        }
    }
    bool ok1 = 1, ok2 = 1;
    for(int i=1;i<n-1;i++)
    {
        if(s1[i] != s2[i-1])
        {
            ok1 = 0;
            break;
        }
    }
    for(int i=1;i<n-1;i++)
    {
        if(s2[i] != s1[i-1])
        {
            ok2 = 0;
            break;
        }
    }
    if(ok1)
    {
        memset(plen, 0, sizeof(plen));
        std::string sz = s1 + s2[n-2];
        //std::cout<<sz<<"\n";
        int pc = 0, sc = 0;
        for(int i=0;i<2*n-2;i++)
        {
            bool ok = 1;
            for(int j=0,k=(int)X[i].size();j<k;j++)
            {
                if(sz[j] != X[i][j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok && !plen[(int)X[i].size()])
            plen[(int)X[i].size()] = 1;
            else ok = 0;
            if(ok && (pc < n-1))
            pc++; 
            else sc++;
        }
        if(pc == sc)
        {
            memset(plen, 0, sizeof(plen));
            pc = 0, sc = 0;
            for(int i=0;i<2*n-2;i++)
            {
                bool ok = 1;
                for(int j=0,k=(int)X[i].size();j<k;j++)
                {
                    if(sz[j] != X[i][j])
                    {
                        ok = 0;
                        break;
                    }
                }
                if(ok && !plen[(int)X[i].size()])
                plen[(int)X[i].size()] = 1;
                else ok = 0;
                if(ok && (pc < n-1))
                {
                    std::cout<<"P";
                    pc++; 
                }    
                else
                {
                     std::cout<<"S";
                     sc++;
                }     
            }
            std::cout<<"\n";
            return 0;
        }    
    }
    if(ok2)
    {
        memset(plen, 0, sizeof(plen));
        std::string sz = s2 + s1[n-2];
        //std::cout<<sz<<"\n";
        int pc = 0, sc = 0;
        for(int i=0;i<2*n-2;i++)
        {
            bool ok = 1;
            for(int j=0,k=(int)X[i].size();j<k;j++)
            {
                if(sz[j] != X[i][j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok && !plen[(int)X[i].size()])
            plen[(int)X[i].size()] = 1;
            else ok = 0;
            if(ok && (pc < n-1))
            pc++; 
            else sc++;
        }
        if(pc == sc)
        {
            memset(plen, 0, sizeof(plen));
            pc = 0, sc = 0;
            for(int i=0;i<2*n-2;i++)
            {
                bool ok = 1;
                for(int j=0,k=(int)X[i].size();j<k;j++)
                {
                    if(sz[j] != X[i][j])
                    {
                        ok = 0;
                        break;
                    }
                }
                if(ok && !plen[(int)X[i].size()])
                plen[(int)X[i].size()] = 1;
                else ok = 0;
                if(ok && (pc < n-1))
                {
                    std::cout<<"P";
                    pc++; 
                }    
                else
                {
                     std::cout<<"S";
                     sc++;
                }     
            }
            std::cout<<"\n";
            return 0;
        }   
    }
    return 0;
}