#include <bits/stdc++.h>

typedef long long ll;

ll a[200001], b[200001];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=(n>>(1LL));i++)
    std::cin>>b[i];
    for(int i=1;i<=(n>>1);i++)
    {
        if(i == 1)
        {
            a[i] = 0;
            a[n-i+1] = b[i];
        }
        else
        {
            a[i] = a[i-1];
            a[n-i+1] = a[n-i+2];
            if(a[i] + a[n-i+1] < b[i])
            a[i] += (b[i] - a[n-i+1] - a[i]);
            else if(a[i] + a[n-i+1] > b[i])
            a[n-i+1] -= (a[i] + a[n-i+1] - b[i]);
        }
    }
    for(int i=1;i<=n;i++)
    std::cout<<a[i]<<" ";
    std::cout<<"\n";
    return 0;
}