#include <bits/stdc++.h>

bool compx(std::pair<long long,long long>,std::pair<long long,long long>);

int main(void)
{
    long long n,Hetero = 0;
    std::cin>>n;
    std::map<long long,long long> mii;
    typedef std::map<long long,long long>::iterator It;
    for(long long i=0;i<n;i++)
    {
        std::string x;
        long long y;
        std::cin>>x>>y;
        if(x[0] == 'i')
        {
        	mii[y]++;
        	if(mii[y] == 1)
        	Hetero++;
        	else if(mii[y] > 1)
        	Hetero--;
        }
        else if(x[0] == 'd')
        {
            mii[y]--;
            if(mii[y] == 1)
            Hetero++;
        	else if(mii[y] == 0)
        	Hetero--;
            if(mii[y] == 0 ||mii[y] == -1)
            mii.erase(y);
        }
        if(mii.empty())
        {
            std::cout<<"neither"<<std::endl;
            continue;
        }
        It it = mii.begin();
        if(mii.end() == ++it)
        {
            if(mii.begin()->second == 1)
            std::cout<<"neither"<<std::endl;
            else std::cout<<"homo"<<std::endl;
            continue;
        }
        if(Hetero == mii.size())
        std::cout<<"hetero"<<std::endl;
        else std::cout<<"both"<<std::endl;
    }
    return 0;
}


bool compx(std::pair<long long,long long>x,std::pair<long long,long long>y)
{
    if(x.second > y.second)
    return true;
    else return false;
}





