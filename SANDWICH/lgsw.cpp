#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 2000001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define ins insert
#define sz size
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

ll arr[MV], lo[MV], phi[MV];
VL px;

ll modexp(ll a, ll n, ll p)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%p) * (a%p))%p;
		a = ((a%p) * (a%p))%p;
		n >>= 1;	
	}
	return res;
}

ll fexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}
	return res;
}

void siever(void)
{
	lo[1] = 1;
	for(int i=2;i<MV;i++)
	{
		if(!lo[i])
		{
			lo[i] = i;
			px.pb(i);
		}	
		for(int j=0;((j<(int)px.sz()) && (px[j]<=lo[i]) && ((i*px[j])<MV));j++)
		lo[i*px[j]] = px[j];	
	}	
	phi[1] = 1;
	for(ll i=2;i<MV;i++)
	{
		if(lo[i/lo[i]] == lo[i])
		phi[i] = lo[i] * phi[i/lo[i]];
		else phi[i] = (lo[i] - 1) * phi[i/lo[i]];	
	}
	return;	
}

void solve(int T)
{
	ll n,k,m;
	cin>>n>>k>>m;
	if(n <= k)
	{
		cout<<"1 1\n";
		return;
	}		
	vector<PLL> vp;
	ll ty = m;
	while(ty > 1)
	{
		ll ct = 0, p = lo[ty];
		while(!(ty % p))
		{
			ct++;
			ty /= p;
		}	
		vp.eb(p, ct);
	}	
	ll crs = 0;
	for(auto &&u : vp)
	{
		ll N = (k+1) * ((n+k-1)/k) - n - 1;
		ll R = ((n+k-1)/k) - 1;
		if(u.ss == 1)
		{
			arr[0] = 1;
			for(ll i=1;i<u.ff;i++)
			arr[i] = ((arr[i-1]%u.ff) * (i%u.ff))%u.ff;
			VL dN(62), dR(62);
			for(int i=0;i<62;i++)
			{
				dN[i] = N%u.ff;
				N /= u.ff;
				dR[i] = R%u.ff;
				R /= u.ff;
			}	
			ll fx = 1;
			for(int i=0;i<62;i++)
			{
				if(dN[i] < dR[i])
				{
					fx = 0;
					break;
				}
				ll fc = arr[dN[i]];
				ll iv1 = modexp(arr[dR[i]], phi[u.ff]-1, u.ff)%u.ff;
				ll iv2 = modexp(arr[dN[i]-dR[i]], phi[u.ff]-1, u.ff)%u.ff;
				fx = ((fx%u.ff) * (((fc%u.ff) * (((iv1%u.ff) * (iv2%u.ff))%u.ff))%u.ff))%u.ff;	
			}
			crs = ((crs%m) + (((fx%m) * ((((m/u.ff)%m) * (modexp((m/u.ff), phi[u.ff]-1, u.ff)%m))%m))%m))%m;
		}
		else
		{
			ll yt = fexp(u.ff, u.ss);
			arr[0] = 1;
			for(ll i=1;i<yt;i++)
			{
				ll uy = i;
				if(!(uy % u.ff))
				uy = 1;
				arr[i] = ((arr[i-1]%yt) * (uy%yt))%yt;	
			}
			ll tN = N, tR = R, tNR = N-R, tu = 0;
			ll fc = 1, iv1 = 1, iv2 = 1, fx = 1;
			while(tN)
			{
				fc = ((fc%yt) * (((modexp(arr[yt-1], (tN/yt), yt)%yt) * (arr[tN%yt]%yt))%yt))%yt;
				tu += (tN/u.ff);
				tN /= u.ff;
			}
			while(tR)
			{
				iv1 = ((iv1%yt) * (((modexp(arr[yt-1], (tR/yt), yt)%yt) * (arr[tR%yt]%yt))%yt))%yt;
				tu -= (tR/u.ff);
				tR /= u.ff;
			}
			while(tNR)
			{
				iv2 = ((iv2%yt) * (((modexp(arr[yt-1], (tNR/yt), yt)%yt) * (arr[tNR%yt]%yt))%yt))%yt;
				tu -= (tNR/u.ff);
				tNR /= u.ff;
			}
			if(tu >= u.ss)
			fx = 0;
			else fx = ((((fc%yt) * (((modexp(iv1, phi[yt]-1, yt)%yt) * (modexp(iv2, phi[yt]-1, yt)%yt))%yt))%yt) * (modexp(u.ff, tu, yt)%yt))%yt;
			crs = ((crs%m) + (((fx%m) * ((((m/yt)%m) * (modexp((m/yt), phi[yt]-1, yt)%m))%m))%m))%m;
		}
	}
	ll cx = (n+k-1)/k;
	cout<<cx<<" "<<crs<<"\n";
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

	siever();
	cin>>T;
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