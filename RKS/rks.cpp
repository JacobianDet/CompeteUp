#include <bits/stdc++.h>

bool compare(std::pair<int,std::pair<int,int>>,std::pair<int,std::pair<int,int>>);

int main(void)
{
    int n,c;
    std::cin>>n>>c;
    std::map<int,std::pair<int,int>> mx;
    typedef std::vector<std::pair<int,std::pair<int,int>>>::iterator It;
    int temp,j=0;
    for(int i=0;i<n;i++)
    {
        std::cin>>temp;
        if(mx[temp].second == 0)
        {
            mx[temp].first = j;
            j++;
        }
        mx[temp].second++;
    }
    std::vector<std::pair<int,std::pair<int,int>>> x(mx.begin(),mx.end());
    std::sort(x.begin(),x.end(),compare);
    for(It it=x.begin();it!=x.end();it++)
    {
        while((it->second).second != 0)
        {
            std::cout<<it->first<<" ";
            (it->second).second --;
        }
    }
    return 0;
}

bool compare(std::pair<int,std::pair<int,int>> a,std::pair<int,std::pair<int,int>> b)
{
    if(a.second.second > b.second.second)
    return true;
    else if(a.second.second == b.second.second)
    {
        if(a.second.first < b.second.first)
        return true;
        else return false;
    }
    else return false;
}
