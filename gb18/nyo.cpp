#include <bits/stdc++.h>

int main(void)
{
    int y,b,r;
    std::cin>>y>>b>>r;
    int x = std::min(y, std::min(b-1, r-2));
    std::cout<<(3*x + 3)<<"\n";
    return 0;
}