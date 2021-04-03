#include <bits/stdc++.h>

int A[1051][1051], B[1051][1051], C[1051][1051], D[1051][1051];

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                std::cin>>A[i][j];
                C[i][j] = A[i][j];
                D[i][j] = A[i][j];
            }    
        }
        bool ok = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            std::cin>>B[i][j];
        }
        for(int i=0;i<n;i++)
        {
            if(A[i][i] != B[i][i])
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            bool ok1 = 1, ok2 = 1;
            for(int i=0;i<n;i++)
            {
                int sw = 0;
                for(int j=i-1;j>=0;j--)
                {
                    if(C[i][j] != B[i][j])
                    sw++;
                }
                //std::cout<<sw<<"\n";
                if(sw > 0 && sw < i)
                {
                    ok1 = 0;
                    break;
                }
                if(sw)
                {
                    for(int j=0;j<n;j++)
                    std::swap(C[i][j], C[j][i]);
                }
                sw = 0;
                for(int j=i-1;j>=0;j--)
                {
                    if(C[i][j] != B[i][j])
                    sw++;
                }
                if(sw)
                {
                    ok1 = 0;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--)
            {
                int sw = 0;
                for(int j=i+1;j<n;j++)
                {
                    if(D[i][j] != B[i][j])
                    sw++;
                }
                if(sw > 0 && sw < (n - i - 1))
                {
                    ok2 = 0;
                    break;
                }
                if(sw)
                {
                    for(int j=0;j<n;j++)
                    std::swap(D[i][j], D[j][i]);
                }
                sw = 0;
                for(int j=i+1;j<n;j++)
                {
                    if(D[i][j] != B[i][j])
                    sw++;
                }
                if(sw)
                {
                    ok2 = 0;
                    break;
                }
            }
            ok = (ok1 | ok2);
        }
        if(ok)
        std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
    return 0;
}