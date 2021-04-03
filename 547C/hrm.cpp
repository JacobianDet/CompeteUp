#include <bits/stdc++.h>
using namespace std;
#define MV 15000001

typedef long long ll;

const int MOD = 1000000007;

int mu[MV], lo[MV], f[MV], inv[MV];

int readInt (void) {
 bool minus = false;
 int result = 0;
 char ch;
 ch = getchar_unlocked();
 while (true) {
     if (ch == '-') break;
     if (ch >= '0' && ch <= '9') break;
     ch = getchar_unlocked();
 }
 if (ch == '-') minus = true; else result = ch-'0';
 while (true) {
     ch = getchar_unlocked();
     if (ch < '0' || ch > '9') break;
     result = result*10 + (ch - '0');
 }
 if (minus)
     return -result;
 else
     return result;
}

int modexp(int a, ll n)
{
    int res = 1;
    while(n)
    {
        if(n & 1)
        res = (1LL*res * a)%MOD;
        a = (1LL*a * a)%MOD;
        n >>= 1;
    }
    return res;
}

int siever(int yt, int n, int m)
{
    for(int i=1;i<=yt;i++)
    {
        lo[i] = i;
        mu[i] = 1;
        f[i] = i;
        if(i == 1)
        inv[i] = 1;
        else inv[i] = ((1LL*MOD - (MOD/i)) * inv[MOD%i])%MOD;
    }     
    int rx = 1;
    for(int i=2;i<=yt;i++)
    {
        if(lo[i/lo[i]] == lo[i])
        mu[i] = 0;
        else mu[i] = -mu[i/lo[i]];    
        if(mu[i] != 0)
        {
            for(int j=2*i;j<=yt;j+=i)
            {
                if(lo[j] == j)
                lo[j] = i;    
                int fc = j/i;
                if(mu[i] == 1)
                f[j] = (1LL*f[j] * fc)%MOD; 
                else f[j] = (1LL*f[j] * inv[fc])%MOD;
            }    
        }
        rx = (1LL*rx * modexp(f[i], (1LL*(n/i) * (m/i))))%MOD;    
    }    
    return rx;    
}

void solve(int T)
{
    int n = readInt();
    int m = readInt();
    int mn = min(n,m);
    int rx = siever(mn, n, m);
    string wd = to_string(rx);
    for(auto &&u : wd)
    putchar_unlocked(u);
    putchar_unlocked('\n');    
    return;
}

int main(void)
{
    // FLASH();
    int T;
    T = 1;

// #ifndef ONLINE_JUDGE
//     time_t time_t1, time_t2;
//     time_t1 = clock();
// #endif

    //cin>>T;
    while(T--)
    solve(T);

// #ifndef ONLINE_JUDGE
//     time_t2 = clock();
//     SETF();
//     cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
//     UNSETF();
// #endif

    return 0;
}