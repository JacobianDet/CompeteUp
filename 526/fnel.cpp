#include <bits/stdc++.h>

int arr[101];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    int gtot = 10000000;
    for(int i=1;i<=n;i++)
    {
        int itot = 0;
        for(int j=1;j<=n;j++)
        itot += ((abs(i-j) + abs(j-1) + abs(1-i)) * arr[j]);
        gtot = std::min(gtot, 2*itot);
    }
    std::cout<<gtot<<"\n";
    return 0;
}