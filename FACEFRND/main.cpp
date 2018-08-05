#include <bits/stdc++.h>

int main(void)
{
    int n;
    std::cin>>n;
    std::set<std::string> s;
    std::string x[n];
    for(int i=0;i<n;i++)
    {
        std::map<std::string,std::string> mss;
        int m;
        std::cin>>x[i]>>m;
        std::map<std::string, std::map<int,std::string>> chor;
        for(int j=0;j<m;j++)
        std::cin>>chor[x[i]][j];
        for(int j=0;j<m;j++)
        s.insert(chor[x[i]][j]);
    }
    for(int i=0;i<n;i++)
    s.erase(x[i]);
    std::cout<<s.size()<<std::endl;
}
