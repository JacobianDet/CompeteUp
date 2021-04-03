#include <bits/stdc++.h>

bool compare(std::pair<std::string, std::string> a, std::pair<std::string, std::string> b)
{
   if(a.second == b.first)
   return true;
   else if(a.first == b.second)
   return false;
   if(a.first < b.first)
   return true;
   else return false;
}

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        std::cin>>n;
        std::vector<std::pair<std::string, std::string>> Z;
        std::string s,d;
        for(int j=0;j<n;j++)
        {
            std::cin>>s>>d;
            Z.push_back(std::make_pair(s,d));
        }
        std::sort(Z.begin(),Z.end(),compare);
        for(std::vector<std::pair<std::string, std::string>>::iterator it = Z.begin();it != Z.end();it++)
        std::cout<<it->first<<"-"<<it->second<<" ";
        std::cout<<std::endl;
    }
    return 0;
}
