#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()
#define whoami(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); whi(_it, args); }

void whi(istream_iterator<string> it) { cerr<<"\n"; }

template<typename T, typename... Args>
void whi(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<" "<<a<<" "; whi(++it, args...); }

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed); cerr.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed); cerr.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;

const int MOD = 1000000007;
const ll INF = 4e18;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct h_llint {
    static uint64_t splitmix64(uint64_t x) {    // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
}
};

struct h_pair{
    size_t operator()(const PLL&x)const{
        return hash<ll>()(((ll)x.ff)^(((ll)x.ss)<<32));
    }
};

typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;
//ordered_set = order_of_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV];
ll arr[MV];
PLL axf[MV], rz[MV];
ll mat[3][3], trx[3][3];

void TRANSMAT(ll xc, ll yc)
{
    mat[0][1] = mat[1][0] = mat[2][0] = mat[2][1] = 0;
    mat[0][0] = mat[1][1] = mat[2][2] = 1;
    mat[0][2] = xc;
    mat[1][2] = yc;
    return;
}

void REFMAT(ll xc, ll yc)
{
    mat[0][1] = mat[0][2] = mat[1][0] = mat[1][2] = mat[2][0] = mat[2][1] = 0;
    mat[2][2] = 1;
    mat[0][0] = xc;
    mat[1][1] = yc;
    return;
}

void ROTMAT(ll xc, ll yc)
{
    mat[0][0] = mat[0][2] = mat[1][1] = mat[1][2] = mat[2][0] = mat[2][1] = 0;
    mat[2][2] = 1;
    mat[0][1] = xc;
    mat[1][0] = yc;
    return;
}

void MATMUL(void)
{
    ll tp[3][3];
    memset(tp, 0, sizeof(tp));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            tp[i][j] += mat[i][k] * trx[k][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        trx[i][j] = tp[i][j];
    }
    return;
}

struct qry
{
    ll t1, t2, t3, t4;
};

void solve(int T)
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>axf[i].ff>>axf[i].ss;
    int m;
    cin>>m;
    vector<qry> Q;
    for(int i=1;i<=m;i++)
    {
        ll t;
        cin>>t;
        if(t < 3)
        Q.pb({0, i, t, -1});
        else
        {
            ll p;
            cin>>p;
            Q.pb({0, i, t, p});
        }
    }  
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        ll a,b;
        cin>>a>>b;
        Q.pb({1, a, b, i});
    }
    sort(begin(Q), end(Q), [](qry A, qry B){ return ((A.t2 < B.t2) || ((A.t2 == B.t2) && (A.t1 < B.t1))); });
    memset(trx, 0, sizeof(trx));
    trx[0][0] = trx[1][1] = trx[2][2] = 1;
    for(auto &&u : Q)
    {
        // whoami(u.t1, u.t2, u.t3, u.t4);
        if(u.t1)
        {
            ll x = trx[0][0] * axf[u.t3].ff + trx[0][1] * axf[u.t3].ss + trx[0][2];
            ll y = trx[1][0] * axf[u.t3].ff + trx[1][1] * axf[u.t3].ss + trx[1][2];
            rz[u.t4] = {x, y};
        }
        else
        {
            if(u.t3 < 3)
            {
                ll xp = ((u.t3 == 1) ? 1 : -1);
                ll yp = ((u.t3 == 1) ? -1 : 1);
                ROTMAT(xp, yp);
                MATMUL();
                // for(int i=0;i<3;i++)
                // {
                //     for(int j=0;j<3;j++)
                //     whoami(i, j, mat[i][j]);
                // }
            }
            else
            {
                ll xp = ((u.t3 == 3) ? u.t4 : 0);
                ll yp = ((u.t3 == 3) ? 0 : u.t4);
                TRANSMAT(-xp, -yp);
                MATMUL();
                REFMAT(((u.t3 == 3) ? -1 : 1), ((u.t3 == 3) ? 1 : -1));
                MATMUL();
                TRANSMAT(xp, yp);
                MATMUL();
            }
        }
    }
    for(int i=0;i<q;i++)
    cout<<rz[i].ff<<" "<<rz[i].ss<<"\n";
    return;
}

int main(void)
{
    FLASH();
    //freopen("cowjog.in", "r", stdin);
    //freopen("cowjog.out", "w", stdout);
    int T;
    T = 1;

#ifndef ONLINE_JUDGE
    time_t time_t1, time_t2;
    time_t1 = clock();
#endif

    //cin>>T;
    while(T--)
    solve(T);

#ifndef ONLINE_JUDGE
    time_t2 = clock();
    SETF();
    cerr<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
    UNSETF();
#endif

    return 0;
}