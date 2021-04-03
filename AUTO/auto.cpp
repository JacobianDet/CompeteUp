#include <bits/stdc++.h>

long double binx(long double bal, long double pay, int nom)
{
    long double lo = 0;
    long double hi = 100;
    int x = 0;
    while(x <= 100)
    {
        long double mid = lo + (hi - lo)/2;
        long double t = bal;
        int y = nom;
        while(y > 0)
        {
            t = t*(1 + mid/1200) - pay;
            y--;
        }
        int l = t;
        if(l >= 1)
        hi = mid;
        else lo = mid;
        x++;
    }
    return lo;
}

int main(void)
{
    long double bal,pay;
    int nom;
    std::cin>>bal>>pay>>nom;
    long double res = binx(bal, pay, nom);
    std::cout<<res<<std::endl;
    return 0;
}
