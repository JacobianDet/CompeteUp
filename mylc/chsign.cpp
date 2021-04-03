#include <bits/stdc++.h>

typedef long long ll;

struct cfcx
{
    int i, sgn1, sgn2;
};

int n;
ll arr[100001];
ll memo[100001][3][3];
cfcx par[100001][3][3];

ll medium(int i, int sgn1, int sgn2, int t)
{
    if(i == n)
    return 0;
    if(memo[i][sgn1][sgn2] != -1)
    return memo[i][sgn1][sgn2];
    ll ans = 0;
    int nsgn = 0;
    if(!sgn1 || (sgn1 == 2))
    {
        int sx1 = 1;
        int sx2 = 1;
        if(i)
        {
            if(!sgn2 || (sgn2 == 2))
            {
                if((arr[i-1] - arr[i]) < 1)
                sx1 = 0;
                else sx1 = 1;
            }
            else
            {
                if((arr[i-1] - arr[i] - arr[i-2]) < 1)
                sx1 = 0;
                else sx1 = 1;
            }    
        }
        if(i < n-1)
        {
            if((arr[i+1] - arr[i]) < 1)
            sx2 = 0;
            else sx2 = 1;
        }
        nsgn = (sx1 & sx2);
    }
    if(nsgn)
    {
        if((arr[i] + medium(i+1, 0, sgn1, t)) < (-arr[i] + medium(i+1, nsgn, sgn1, t)))
        {
            ans = std::min(arr[i] + medium(i+1, 0, sgn1, t), -arr[i] + medium(i+1, nsgn, sgn1, t));
            par[i][sgn1][sgn2] = {i+1, 0, sgn1};
        }
        else if((arr[i] + medium(i+1, 0, sgn1, t)) >= (-arr[i] + medium(i+1, nsgn, sgn1, t)))
        {
            ans = std::min(arr[i] + medium(i+1, 0, sgn1, t), -arr[i] + medium(i+1, nsgn, sgn1, t));
            par[i][sgn1][sgn2] = {i+1, nsgn, sgn1};
        }
    }        
    else 
    {
        ans = arr[i] + medium(i+1, nsgn, sgn1, t);
        par[i][sgn1][sgn2] = {i+1, nsgn, sgn1};
    }  
    memo[i][sgn1][sgn2] = ans;
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++)
    {
        std::cin>>n;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    par[i][j][k] = {i, j, k};
                    memo[i][j][k] = -1;
                }    
            }
        }
        for(int i=0;i<n;i++)
        std::cin>>arr[i];
        ll ans = medium(0, 2, 2, t);
        //std::cout<<ans<<"\n";
        int id = 0, sgn1 = 2, sgn2 = 2;
        while(id != n)
        {
            cfcx p = par[id][sgn1][sgn2];
            id = p.i;
            sgn1 = p.sgn1;
            sgn2 = p.sgn2;
            if(sgn1)
            std::cout<<-arr[id-1]<<" ";
            else std::cout<<arr[id-1]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}