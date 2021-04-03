#include<bits/stdc++.h>
using namespace std;


// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#define ll long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define S second
#define F first
#define die() return 0;

#define md         1000000007
#define M           1000011
#define N 			24

ll gcd(ll a,ll b){
	if(b==0)return a;
	if(a==0)return b;
	return gcd(b,a%b);
}
ll exp(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)
			r=r*a%md,r%=md;
		a=a*a%md;a%=md;
		b/=2;
	}
	return r%md;
}
int solve(){
		ll n,i,j,k,m;
		ll a,b,c,g;
		cin>>a>>b>>c>>g;
		ll aa=a,bb=b,cc=c;
		a/=g;b/=g;c/=g;

		vector<int> mu(M,1),pr(M,1);
		mu[0]=0;mu[1]=1;
		for(i=2;i<M;++i){
			if(!pr[i])continue;
			pr[i]=1;
			for(j=i;j<M;j+=i){
				pr[j]=0;
				mu[j]*=-1;
				if((j/i)%i==0)mu[j]=0;
			}
		}
		ll ans=0;
		for(i=1;i<=1e6;++i){
			ll k=a/i;
			k=k*(b/i)*(c/i);
			k=k%md;
			k=k*mu[i];k=(k+md)%md;
			ans=ans+k;
			if(ans>md)ans-=md;
		}
		cout<<ans<<"\n";

		die();
}


int main(){



    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j;
    t=1;
    // cin>>t;
    while(t--){
    	solve();
    }





    die();
}
