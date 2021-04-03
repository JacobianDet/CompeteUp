#include <bits/stdc++.h>

typedef long long ll;

int V[20];
int memo[21][21][21][21];

int pall(int i, int st, int lo, int hi)
{
    if(i == st + (20-st+1)/2)
    {
        if(lo <= hi)
        return 1;
        else return 0;
    }
    if(memo[i][st][lo][hi] != -1)
    return memo[i][st][lo][hi];
    int ans = 0, nlo = lo, nhi = hi;
    for(int j=0;j<=9;j++)
    {
        if(j && (st == 20))
        {
            if(j < V[i])
            nlo = std::min(nlo, i);
            if(j < V[19-i+i])
            nlo = std::min(nlo, 19-i+i);
            if(j > V[i])
            nhi = std::min(nhi, i);
            if(j > V[19-i+i])
            nhi = std::min(nhi, 19-i+i);
            ans += pall(i+1, i, nlo, nhi);
        }
        else if(st)
        {
            if(j < V[i])
            nlo = std::min(nlo, i);
            if(j < V[19-i+st])
            nlo = std::min(nlo, 19-i+st);
            if(j > V[i])
            nhi = std::min(nhi, i);
            if(j > V[19-i+st])
            nhi = std::min(nhi, 19-i+st);
            ans += pall(i+1, st, nlo, nhi);
        }
        else ans += pall(i+1, st, lo, hi);
        nlo = lo;
        nhi = hi;
    }
    memo[i][st][lo][hi] = ans;
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
        memset(V, 0, sizeof(V));
        memset(memo, -1, sizeof(memo));
        ll a,b,temp;
        std::cin>>a>>b;
        if(a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }    
        temp = b;
        int x = 19;
        while(temp)
        {
            V[x--] = (temp%10);
            temp /= 10;
        }
        int ans = pall(1, 20, 20, 20);
        if(a)
        {
            memset(V, 0, sizeof(V));
            memset(memo, -1, sizeof(memo));
            x = 19;
            temp = a-1;
            while(temp)
            {
                V[x--] = (temp%10);
                temp /= 10;
            }
            ans -= pall(1, 20, 20, 20);
        }    
        std::cout<<"Case "<<t<<": ";
        std::cout<<ans<<"\n";
    }
    return 0;
}