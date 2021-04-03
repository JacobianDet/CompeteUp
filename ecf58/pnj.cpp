#include <bits/stdc++.h>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    int mn = 0, mx = 0;
    while(T--)
    {
        char ch;
        int x,y;
        std::cin>>ch>>x>>y;
        if(x > y)
        {
            int tmp = x;
            x = y;
            y = tmp;
        }
        if(ch == '+')
        {
            mn = std::max(mn, x);
            mx = std::max(mx, y);
        }
        else
        {
            if((mx > y) || (mn > x))
            std::cout<<"NO\n";
            else std::cout<<"YES\n"; 
        }
    }
    return 0;
}