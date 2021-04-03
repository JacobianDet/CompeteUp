#include <bits/stdc++.h>

int A[1000001], B[1000001];

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=1;i<=n;i++)
        std::cin>>A[i];
        for(int i=1;i<=n;i++)
        std::cin>>B[i];
        bool ok = 1;
        if((A[1] || B[n]) || (A[n] != B[1]))
        ok = 0;
        for(int i=1;i<=n;i++)
        {
            if(A[i] + B[i] < A[n])
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
    return 0;
}