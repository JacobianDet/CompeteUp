#include <bits/stdc++.h>

int main(void)
{
    int n;
    std::cin>>n;
    if(!((n + 3)%4) || !((n + 2)%4))
    std::cout<<"1\n";
    else std::cout<<"0\n";
    return 0;
}