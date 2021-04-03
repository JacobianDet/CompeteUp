#include <bits/stdc++.h>
#define CHOR 100001
typedef long long ll;

std::vector<ll> in(CHOR);
std::vector<ll> sk(CHOR);
std::vector<ll> ch(CHOR);
std::vector<ll> par(CHOR);
void update(ll s, ll d)
{
    if(s==1){
        ch[1]-=(sk[s]-d);
        sk[1]=d;
        return;
    }
    ll i=par[s];
    while(par[i]!=i){
        ch[i]-=(sk[s]-d);
        i=par[i];
    }
    ch[1]-=(sk[s]-d);
    ch[s]-=(sk[s]-d);
    sk[s]=d;
}
int main(void)
{
    par[1] = 1;
    ll n,m,s,d;
    scanf("%lld %lld", &n, &m);
    for(ll i=1;i<=n;i++){
        scanf("%lld", &in[i]);
    }
    for(ll i=0;i<n-1;i++)
    {
        scanf("%lld %lld", &s, &d);
        par[d] = s;
    }
    for(ll i=1;i<=n;i++){
        update(i,in[i]);
    }
    //this
    //for(ll i=1;i<=n;i++){
        //printf("%lld\n",ch[i]);
    //}
    //this
    for(ll i=0;i<m;i++)
    {
        char x;
        scanf("%c", &x);
        if(x == 'U')
        {
            scanf("%lld %lld", &s, &d);
            update(s, d);
        }
        else{
                scanf("%lld", &s);
                printf("%lld\n",ch[s]);
        }
    }
}
