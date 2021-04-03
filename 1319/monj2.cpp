#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
 
double const EPS=3e-8;
using namespace std;
 
 
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
 
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
 
/* **************************************  My code start here ****************************************** */
typedef long long ll ;
ll size , a[20] , n[20];
pair < ll , ll > extended_gcd(ll a , ll b )
{
    if ( b == 0 ) return mp(1,0);
    pair <ll , ll > t = extended_gcd(b,a%b);
    return mp(t.second , t.first - ( a/b) * t.second);
}
ll modInverse(ll a , ll m)
{
    return (extended_gcd(a,m).first%m+m)%m;
}
ll chinese_remainder(ll *a,ll *n,int size)
{
    if(size==1) return *a;
    ll tmp = modinverse(n[0],n[1]);
    ll tmp2 = ( tmp* (a[1]-a[0])%n[1] + n[1])%n[1];
    ll ora = a[1];
    ll tgcd = gcd(n[0],n[1]);
    a[1] = a[0] + (n[0]/tgcd)*tmp2;
    n[1] *= (n[0]/tgcd);
    ll ret = chinese_remainder(a+1,n+1,size-1);
    n[1] /= n[0]/tgcd;
    a[1] = ora;
    return ret;
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int cs , t ;
     read(t);
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         int i ;
         read(size);
         rep(i,size)
         {
             read(n[i]) , read(a[i]);
         }
         printf("Case %d: %lld\n",cs,chinese_remainder(a,n,size));
     }
   return 0;
}