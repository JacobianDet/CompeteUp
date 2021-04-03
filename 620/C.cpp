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
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV];
ll arr[MV];

struct t3
{
	ll t,l,h;
}cx[101];

void solve(int T)
{
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>cx[i].t>>cx[i].l>>cx[i].h;
	vector<t3> VT;
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		if((int)VT.sz() == 0)
		VT.pb(cx[i]);
		else
		{
			int cn = (int)VT.sz() - 1;
			if(VT[cn].t == cx[i].t)
			{
				VT[cn].l = max(VT[cn].l, cx[i].l);
				VT[cn].h = min(VT[cn].h, cx[i].h);
				if(VT[cn].l > VT[cn].h)
				{
					ok = 0;
					break;
				}
			}
			else VT.pb(cx[i]);
		}	
	}
	if(!ok)
	{
		cout<<"NO\n";
		return;
	}	
	ll cl = m, cr = m, pt = 0;
	for(auto u : VT)
	{
		cl -= (u.t - pt);
		cr += (u.t - pt);
		pt = u.t;
		cl = max(cl, u.l);
		cr = min(cr, u.h);
		// cout<<cl<<" "<<cr<<"\n";
		if(cl > cr)
		{
			ok = 0;
			break;
		}
	}
	if(ok)
	cout<<"YES\n";
	else cout<<"NO\n";
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

	cin>>T;
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