#include <bits/stdc++.h>

int arr[100][100];
int arr2[10000];

int main(void)
{
    int n,m,d;
    std::cin>>n>>m>>d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        std::cin>>arr[i][j];
    }
    int px = arr[0][0]%d;
    int mx = 0;
    bool ok = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mx = arr[i][j]%d;
            if(px != mx)
            {
                ok = 0;
                break;
            }
        }
        if(!ok)
        break;
    }
    if(!ok)
    std::cout<<"-1\n";
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            arr2[m*i+j] = arr[i][j];
        }
        std::sort(arr2, arr2+n*m);
        int md = arr2[(n*m)/2];
        int ans = 0;
        for(int i=0;i<n*m;i++)
        ans += abs(md - arr2[i])/d;
        std::cout<<ans<<"\n";
    }
    return 0;
}
