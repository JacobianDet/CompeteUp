#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int a,b,c,x,y;
        std::cin>>a>>b>>c>>x>>y;
        if((x + y == a + b + c) && (((x <= a + b) || (x <= a + c) || (x <= b + c)) && ((y <= a + b) || (y <= a + c) || (y <= b + c))))
        std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
    return 0;
}