#include<bits/stdc++.h>
#define m 1000000007
    using namespace std;
    typedef long long ll;
     
    ll mpow(ll x,ll p)
    {
        ll ans = 1;
        ll z = x;
        while(p)
        {
            if(p&1)
            ans = ((ans%m)*(z%m))%m;
            z = (((z%m)*(z%m))%m);
            p>>=1;
        }
        return ans;
    }
     
     
    ll fun(ll n,ll t)
    {
        ll ans = 1;
        for(ll i = n+1;i<=t+n+1;i++)
            ans = ((ans%m)*(i%m))%m;
        return ans;
    }
     
    void bing(ll f[])
    {
        f[0] = 1;
        for(ll i=1;i<1002;i++)
            f[i] = ((f[i-1]%m)*i)%m;
    }
     
     
     
    int main()
    {
        ll q;
        cin>>q;
        ll f[1002];
        bing(f);
        while(q--)
        {
            ll n,t;
            cin>>n>>t;
            ll tinv = mpow(t+1,m-2);
            ll a = f[t+1];
            ll b = fun(n,t);
            ll ans = ((((b % m) - (a % m) + m)%m) * (tinv%m))%m;
            cout<<ans<<endl;
        }
        return 0;
    }
/*
result  = (T!(C(N+T+1,N)-1))%m
    = (T!((N+T+1)!/(N!*(T+1)!) - 1))%m
    = ((T+N+1)!/N!*(T+1) - T!)%m
    = (((T+N+1)*(T+N)....*(N+1)*(modiv(T+1))%m-(T!)%m)%m
    = (((b%m)*(tinv%m))%m-a%m+m)%m
    where b = (T+N+1).....(N+1)
    a = T!
    tinv = modinv(T+1)
*/
