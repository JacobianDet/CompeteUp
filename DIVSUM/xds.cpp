#include <bits/stdc++.h>

int B[300];
int nb;

int NDIV(int a)
{
    int ans = 0;
    int temp = 0;
    int us = 0;
    while(temp < a)
    {
        temp = 10*temp + B[us];
        us++;
    }
    while(nb > us)
    {
        ans = 10*ans + (temp/a);
        temp = 10*(temp%a) + B[us];
        us++;
    }
    if(nb == us)
    {
        ans = 10*ans + (temp/a);
        temp %= a;
        return temp;
    }    
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int a;
        std::string b;
        std::cin>>a>>b;
        if(!a)
        std::cout<<b<<"\n";
        else
        {
            nb = 0;
            for(int i=0,j=(int)b.size();i<j;i++)
            B[i] = (b[i] - '0');
            nb = (int)b.size();
            int res = NDIV(a);
            std::cout<<std::__gcd(a, res)<<"\n";
        }    
    }    
    return 0;
}