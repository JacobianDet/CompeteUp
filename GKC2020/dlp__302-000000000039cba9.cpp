#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
// #define ll long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
#define f(i,j,l) for(i=j;i<l;i++)
#define smax(a,b) a=max(a,b)
// #if !defined(ONLINE_JUDGE)
// #include "debugging.h"
// #endif
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set

// int const mod = 7340033;
// int const mod = 998244353;
int const mod = 1e9+9;
int power(int a,int b,int m){
    int res = 1;
    while(b){
        if(b&1){
            // res = res*a;
            res = (res*a)%m;
        }
        a=(a*a)%m;
        // a%=m;
        b=b/2;
    }
    return res;
}
// ll mul(ll num1,ll num2,ll m){
//     ll x = (num1*num2)%m;
//     return x;
// }

// ll add(ll num1,ll num2,ll m){
//     ll x = ((num1%m)+(num2%m))%m;
//     return x;
// }

// ll sub(ll num1,ll num2,ll m){
//     ll x = (((num1%m)-(num2%m))%m + m)%m;
//     return x;
// }


int inverse(int x , int m){
    return power(x,m-2,m);
}

int const N = 5e5+5;
int const inf = 2e18;

vector<int> adj[N];
int depth[N];
int cnt;
vector<int> d[N];
int ca[N];
int cb[N];
int par[N][20];


void dfs(int in,int p){
    depth[in] = depth[p] +1;
    par[in][0] = p;
    for(int i=1;i<20;i++){
        par[in][i] = par[par[in][i-1]][i-1];
    }
    for(auto x:adj[in]){
        if(x == p) continue;
        dfs(x,in);
    }
}

int findpar(int x,int l){
    for(int i=19;i>=0;i--){
        if(l&(1LL<<i)){
            x = par[x][i];
        }
    }
    return x;
}



void solve(){  
    int i,j;
    int n , a,b;
    cin >> n >> a >> b;

    for(i=1;i<=n;i++){
        adj[i].clear();
        depth[i] = 0;
        d[i].clear();
        ca[i] = 0;
        cb[i] = 0;
    }

    for(i=2;i<=n;i++){
        int p; cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }

    depth[0] = 0;

    dfs(1,0);

    // for(i=1;i<=n;i++){
    //     for(j=0;j<3;j++) cout<<par[i][j]<<" "; cout<<endl;
    // }

    cnt = 0;
    int mx = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(i=1;i<=n;i++){
        cnt1 = cnt1 + (depth[i] + a-1)/a;
        cnt2 = cnt2 + (depth[i] + b-1)/b;
        d[depth[i]].pb(i);
        mx = max(depth[i] , mx);
    }
    cnt = (cnt1 + cnt2)*n;

    // cout<<cnt<<endl;

    for(i=mx;i>0;i--){
        for(auto x:d[i]){
            ca[x]++;
            if(i > a){ 
                int p = findpar(x,a);
                ca[p] += ca[x];
            }

            cb[x]++;
            if(i > b){
                int p = findpar(x,b);
                cb[p] += cb[x];
            }
        }
    }

    for(i=1;i<=n;i++){
        // cout<<ca[i]<<" "<<cb[i]<<endl;
        cnt = cnt - ca[i]*cb[i];
    }

    ld res = (ld)cnt;
    int z = n*n;
    res = res/(ld)z;

    cout<<fixed << setprecision(10) << res << endl;
}           

int32_t main(){
    IOS;
    int t;
    t = 1;
    // precompute();
    cin>>t;  
    for(int tt=1;tt<=t;tt++){
        cout << "Case #"<<tt<<": ";
        solve();
    }
    return 0;
}


/*

46




*/