#include <bits/stdc++.h>

struct seg3
{
    int ind, l, r;
}arr[100001];

int ans[100001];

bool cmpx(seg3 A, seg3 B)
{
    if(A.l < B.l)
    return 1;
    else if((A.l == B.l) && (A.r < B.r))
    return 1;
    else return 0;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            std::cin>>arr[i].l>>arr[i].r;
            arr[i].ind = i;
            ans[i] = 0;
        }
        std::sort(arr, arr+n, cmpx);
        int rx = arr[0].r, pos = -1;
        ans[arr[0].ind] = 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i].l <= rx)
            {
                ans[arr[i].ind] = 1;
                rx = std::max(rx, arr[i].r);
            }
            else
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        std::cout<<"-1\n";
        else 
        {
            for(int i=pos;i<n;i++)
            ans[arr[i].ind] = 2;
            for(int i=0;i<n;i++)
            std::cout<<ans[i]<<" ";
            std::cout<<"\n";
        }
    }
    return 0;
}