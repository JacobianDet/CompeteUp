#include <bits/stdc++.h>
#define ll long long
#define inf (1LL<<57)
#define PII pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const long long mod = 1e9 + 7;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

vector<ll> b,S,T;

bool cm1(ll i,ll j)
{
    return b[i]>b[j];
}

bool cm2(ll i,ll j)
{
    return (S[i] * T[j] > S[j] * T[i]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    freopen("inp5.txt", "r", stdin);
    freopen("op5.txt", "w", stdout);
    
    ll B,L,D;
    cin>>B>>L>>D;
    
    b.clear();b.resize(B);
    for(ll i=0;i<B;i++)cin>>b[i];
    
    S.clear();S.resize(L);
    T.clear();T.resize(L);
    
    vector<ll> N(L),M(L);
    vector<vector<ll>> v;
    
    for(ll i=0;i<L;i++)
    {
        cin>>N[i]>>T[i]>>M[i];
        vector<ll> tmp(N[i]);
        
        ll sum=0;
        for(ll j=0;j<N[i];j++)
        {
            cin>>tmp[j];
            sum += b[tmp[j]];
        }
        S[i] = sum;
        sort(tmp.begin(),tmp.end(),cm1);
        v.pb(tmp);
    }
    
    //---------------------
    
    vector<ll> tmp;
    for(ll i=0;i<L;i++)
    {
        tmp.pb(i);
    }
    sort(tmp.begin(),tmp.end(),cm2);
    
    ll tim = D;
    unordered_map<ll,ll> used;
    vector<vector<ll>> ot;
    ll ct=0;
    for(int i=0;i<tmp.size();i++)
    {
        if(tim<T[tmp[i]])continue;
        
        tim -= T[tmp[i]];
        ll days = tim*M[tmp[i]];
        vector<ll> ans;
        
        if(tim<T[tmp[i]])continue;
        
        for(int j=0;j<v[tmp[i]].size();j++)
        {
            if(days > 0 && (used[ v[tmp[i]][j] ] == 0) )
            {
                ans.pb(v[tmp[i]][j]);
                used[ v[tmp[i]][j] ] = 1;
                days--;
            }
        }
        if(ans.size())
        {
            ct++;
            ot.pb({tmp[i],1LL* int(ans.size())});
            ot.pb(ans);
        }
        else tim += T[tmp[i]];
    }
    cout<<ct<<endl;
    for(auto it:ot)
    {
        for(auto i:it)cout<<i<<" ";cout<<endl;
    }
}