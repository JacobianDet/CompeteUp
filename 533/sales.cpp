#include <bits/stdc++.h>

int arr[1001];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    int mv = 1000000000, ps = -1;
    for(int i=1;i<=100;i++)
    {
        int imv = 0;
        for(int j=0;j<n;j++)
        {
            if(i != arr[j])
            imv += abs(i - arr[j]) - 1;
        }
        if(imv < mv)
        {
            mv = imv;
            ps = i;
        }
    }
    std::cout<<ps<<" "<<mv<<"\n";
    return 0;
}