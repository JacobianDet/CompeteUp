#include <bits/stdc++.h>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    int ctr[3];
    memset(ctr, 0, sizeof(ctr));
    std::set<int> Z[3];
    for(int i=0;i<n;i++)
    {
        if(s[i] == '0')
        {
            Z[0].insert(i);
            ctr[0]++;
        }    
        else if(s[i] == '1')
        {
            Z[1].insert(i);
            ctr[1]++;
        }    
        else 
        {
            Z[2].insert(i);
            ctr[2]++;
        }    
    }
    for(int i=0;i<3;i++)
    {
        if(ctr[i] > n/3)
        {
            for(int j=0;j<3;j++)
            {
                if(ctr[j] < n/3)
                {
                    if(j < i)
                    {
                        for(int k=0,x=std::min(ctr[i] - n/3, n/3 - ctr[j]);k<x;k++)
                        {
                            std::set<int>::iterator it = Z[i].begin();
                            s[*it] = (char)(j + '0');
                            Z[i].erase(*it);
                            ctr[j]++;
                        }
                    }
                }
            }
            for(int j=2;j>=0;j--)
            {
                if(ctr[j] < n/3)
                {
                    if(j > i)
                    {
                        for(int k=0,x=std::min(ctr[i] - n/3, n/3 - ctr[j]);k<x;k++)
                        {
                            std::set<int>::reverse_iterator rit = Z[i].rbegin();
                            s[*rit] = (char)(j + '0');
                            Z[i].erase(*rit);
                            ctr[j]++;
                        }
                    }
                }
            }  
            ctr[i] = n/3;
        }     
    }
    std::cout<<s<<"\n";
    return 0;
}