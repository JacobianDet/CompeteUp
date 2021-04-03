#include <bits/stdc++.h>

typedef std::vector<std::pair<char,int>>::iterator It;
bool compx(std::pair<char,int>,std::pair<char,int>);

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        std::string x;
        int k;
        std::cin>>x>>k;
        std::map<char,int> freq;
        for(size_t j=0,k = x.size();j<k;j++)
        freq[x[j]]++;
        std::vector<std::pair<char,int>> v(freq.begin(),freq.end());
        std::sort(v.begin(),v.end(),compx);
        int ans = 1000000;
        for(It it = v.begin();it != v.end();it++)
        {
            int flag=0;
            for(It jt = v.begin();jt != v.end();jt++)
            {
                if(jt->second < it->second)
                flag += jt->second;
                else flag += std::max(0,(jt->second)-(it->second)-k);
            }
            ans = std::min(flag,ans);
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}

bool compx(std::pair<char,int> a,std::pair<char,int> b)
{
    if(a.second < b.second)
    return true;
    else return false;
}
