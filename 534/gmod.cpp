#include <bits/stdc++.h>

int bs1(void)
{
    int lo = 0;
    int hi = 2000000000;
    for(int i=0;i<29;i++)
    {
        int mid = lo + (hi - lo)/2;
        std::cout<<"? "<<lo<<" "<<mid<<std::endl;
        char ch;
        std::cin>>ch;
        if(ch == 'x')
        hi = mid;
        else lo = mid + 1;
        if(lo >= hi)
        break;
    }
    return lo;
}

int bs2(void)
{
    int lo = 0;
    int hi = 2000000000;
    for(int i=0;i<29;i++)
    {
        int mid = lo + (hi - lo + 1)/2;
        std::cout<<"? "<<lo<<" "<<mid<<std::endl;
        char ch;
        std::cin>>ch;
        if(ch == 'x')
        hi = mid - 1;
        else lo = mid;
        if(lo >= hi)
        break;
    }
    return lo;
}

int main(void)
{
    std::string s;
    std::cin>>s;
    while(1)
    {
        int ans1 = bs1();
        int ans2 = bs2();
        std::cout<<"? "<<ans1<<" "<<ans2<<std::endl;
        char ch;
        std::cin>>ch;
        if(ch == 'x')
        ans2 = (ans1 + ans2)/2;
        else ans1 = (ans1 + ans2)/2;
        std::cout<<"? "<<ans1<<" "<<ans2<<std::endl;
        std::cin>>ch;
        if(ch == 'x')
        ans2 = (ans1 + ans2)/2;
        else ans1 = (ans1 + ans2)/2;
        std::cout<<"! "<<ans1<<std::endl;
        std::cin>>s;
        if(s != "start")
        break;
    }
    return 0;
}