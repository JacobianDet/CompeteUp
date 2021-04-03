#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
#define mp make_pair
#define ins insert
#define sz size

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];
int memo[MV][3];
string s;
int n;

int xd(int ix, int st)
{
    if(ix == n)
    return 0;    
    if(memo[ix][st] != -1)
    return memo[ix][st];
    int ans = MOD;
    if(!st)
    {
        int chg =  0;
        if(s[ix] != 'a')
        chg++; 
        ans = min(ans, chg + xd(ix+1, st));
        ans = min(ans, xd(ix, st+1));
    }
    else if(st == 1)
    {
        int chg =  0;
        if(s[ix] != 'b')
        chg++; 
        ans = min(ans, chg + xd(ix+1, st));
        ans = min(ans, xd(ix, st+1));   
    }
    else
    {
        int chg =  0;
        if(s[ix] != 'a')
        chg++; 
        ans = min(ans, chg + xd(ix+1, st));
    }
    memo[ix][st] = ans;
    return ans;
}

void solve(int T)
{
    memset(memo, -1, sizeof(memo));
    cin>>s;
    n = (int)s.size();
    int res = xd(0, 0);
    cout<<n-res<<"\n";
    return;
}

int main(void)
{
    FLASH();
    int T;
    T = 1;

#ifndef ONLINE_JUDGE
    time_t time_t1, time_t2;
    time_t1 = clock();
#endif

    while(T--)
    solve(T);

#ifndef ONLINE_JUDGE
    time_t2 = clock();
    SETF();
    cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
    UNSETF();
#endif

    return 0;
}