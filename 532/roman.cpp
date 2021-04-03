#include <bits/stdc++.h>

int arr[101];
bool cl[101];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,k;
    std::cin>>n>>k;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=k)
        cl[j] = 1;
        for(int j=i;j>0;j-=k)
        cl[j] = 1;
        int e = 0, s = 0;
        for(int i=1;i<=n;i++)
        {
            if(!cl[i])
            {
                if(arr[i] == 1)
                e++;
                else s++;
            }
        }
        ans = std::max(ans, abs(e-s));
        memset(cl, 0, sizeof(cl));
    }
    std::cout<<ans<<"\n";
    return 0;
}