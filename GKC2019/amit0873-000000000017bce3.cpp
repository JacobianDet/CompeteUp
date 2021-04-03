#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define Pi 3.14159265358979323846264338
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define mp make_pair
#define pb push_back
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define x first
#define y second
#define maxn 400001
typedef long long int ll;
typedef vector<vector<ll> > mat;
//********************* mat *********************
mat matMul(mat A,mat B,ll m)
{int r1=A.size(),r2=B.size(),c1=A[0].size(),c2=B[0].size();mat ans(r1);for(int i=0;i<r1;i++)
for(int j=0;j<c2;j++)
{ll mul=0;for(int k=0;k<c1;k++)
mul=(mul+A[i][k]*B[k][j])%m;ans[i].pb(mul);}
return ans;}
mat matPow(mat x,ll n,ll m)
{int r=x.size(),c=x[0].size();mat result(r);forn(i,r)
forn(j,c)
{if(i==j)
result[i].pb(1);else
result[i].pb(0);}
while(n>0)
{if(n%2==1)
result=matMul(result,x,m);x=matMul(x,x,m);n=n/2;}
return result;}
//******************** mat **********************
ll mod=1e9+7;
ll pow1(ll x,ll n,ll m)  {  ll result=1; while(n>0) {  x%=m; if(n % 2 ==1) result=(result * x)%m; x=(x*x)%m; n=n/2; } return result; } 
ll pow2(ll x,ll n)  {  ll result=1; while(n>0) {   if(n % 2 ==1) result=(result * x); x=(x*x); n=n/2; } return result; }
ll modInverse(ll A,ll M) { return pow1(A,M-2,M); }
ll f[1000001];
void fact() { f[0]=f[1]=1; for(int i=2;i<=1e6;i++) f[i]=(f[i-1]*i)%mod;} 
ll gcd(ll a,ll b) { if(b==0) return a; else return gcd(b,a%b); }
const int size=1e6+1;  
//------------------------------------------------------------------------------------------------------------------------------------//
ll a[size],b[size],n,sa[size],sb[size],m,X,Y;
pair<ll,pair<ll,ll> > A[size],B[size];


bool comp(pair<ll,pair<ll,ll> > p1,pair<ll,pair<ll,ll> > p2)
{
	return (p1.y.x*p2.x>p2.y.x*p1.x);
}

double fun1(int z)
{
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(sa[mid]>=z)
		r=mid;
		else
		l=mid+1;
	}
	//cout<<"**"<<l<<"\n";
	int id=l;
	double ans;
	if(sa[id]==z)
	{
		
		ans= (double)sb[id];
		//cout<<"#"<<ans<<"\n";
		return ans;
	}
	ans = id>0 ? (double)sb[id-1]:0;
	double mul=((double)A[id].y.x)/((double)A[id].x);
	double q=id>0?sa[id-1]:0;
	q=z-q;
	mul*=q;
	ans+=mul;
	return ans;
}

int main()
{
    //fast;
    int t; cin>>t;
	for(int Test=1;Test<=t;Test++)
    {
    	X=Y=0;
        cin>>m>>n;
        forn(i,n){
        	cin>>a[i]>>b[i];
        	A[i]=mp(a[i],mp(b[i],i));
        	B[i]=mp(b[i],mp(a[i],i));
        	X+=a[i];
        	Y+=b[i];
        	
		}
		
		sort(A,A+n,comp);
        for(int i=0;i<n;i++)
        {
        	int id=A[i].y.y;
        	if(i==0)
        	{
        		sa[i]=a[id];
        		sb[i]=b[id];
			}
			else
			{
				sa[i]=a[id]+sa[i-1];
        		sb[i]=b[id]+sb[i-1];
			}
			//cout<<sa[i]<<" ";
		}
		string ans="";
		for(int i=0;i<m;i++)
		{
			
			int l,r; cin>>l>>r;
			if(l>X or r>Y)
			{
				ans+="N";
				continue;
			}
			double d=fun1(X-l);
			//cout<<d<<"\n";
			if(d>=(double)r)
			ans+="Y";
			else
			ans+="N";
		}
        cout<<"Case #"<<Test<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}

