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

int ar[MV];
VL px, dv[MV];
ll arr[MV], factx[MV], inv[MV], invf[MV], lo[MV], mu[MV], cnt[MV];
bitset<MV> sxc;

void factup(void)
{
	factx[0] = 1; factx[1] = 1;
	inv[1] = 1;
	invf[0] = 1; invf[1] = 1;
	for(ll i=2;i<MV;i++)
	{
		factx[i] = ((1LL*i%MOD) * (1LL*factx[i-1]%MOD))%MOD;
		inv[i] = ((1LL*(MOD - (MOD/i))%MOD) * (1LL*inv[MOD%i]%MOD))%MOD;
		invf[i] = ((1LL*inv[i]%MOD) * (1LL*invf[i-1]%MOD))%MOD;
	}
	return;
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
	mu[1] = 1;
	for(ll i=2;i<MV;i++)
	{
		if(lo[i/lo[i]] == lo[i])
		mu[i] = 0;
		else mu[i] = -1 * mu[i/lo[i]];	
	}
	for(int i=1;i<MV;i++)
	{
		if(mu[i] != 0)
		{
			for(int j=i;j<MV;j+=i)
			dv[j].pb(i);
		}
	}	
	return;
}

struct sq
{
	int l,r,k,id;
}Q[MV];

class mo
{
	public: void add(int x)
			{
				for(auto &&u : dv[x])
				{
					sxc[u] = 1;	
					cnt[u]++;
				}	
				return;
			}

			void remove(int x)
			{
				for(auto &&u : dv[x])
				{
					cnt[u]--;
					if(!cnt[u])
					sxc[u] = 0;		
				}
				return;
			}
};

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	const int Z = (int)floor(sqrt(n));
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>Q[i].l>>Q[i].r>>Q[i].k;
		Q[i].id = i;
	}	
	mo D;
	sort(Q, Q+q, [Z](sq A, sq B){ return (((A.l/Z) < (B.l/Z)) || (((A.l/Z) == (B.l/Z)) && (((A.l/Z) & 1) ? (A.r < B.r) : (A.r > B.r)))); });		
	int mo_l = 1, mo_r = 0;
	for(int i=0;i<q;i++)
	{
		int l = Q[i].l;
		int r = Q[i].r;
		int k = Q[i].k;
		// whoami(l, r, k);
		while(mo_l > l)
		{
			mo_l--;
			D.add(ar[mo_l]);
		}
		while(mo_r < r)
		{
			mo_r++;
			D.add(ar[mo_r]);
		}	
		while(mo_l < l)
		{
			D.remove(ar[mo_l]);
			mo_l++;
		}
		while(mo_r > r)
		{
			D.remove(ar[mo_r]);
			mo_r--;
		}
		ll ct = 0;
		for(int u = sxc._Find_first();u<MV;u=sxc._Find_next(u))
		{
			// whoami(u, cnt[u]);
			if(cnt[u] < k)
			continue;
			ct = ((ct%MOD) + ((((MOD + mu[u])%MOD) * (((factx[cnt[u]]%MOD) * (((invf[k]%MOD) * (invf[cnt[u]-k]%MOD))%MOD))%MOD))%MOD))%MOD;
		}
		ar[Q[i].id] = ct;
	}
	for(int i=0;i<q;i++)
	cout<<ar[i]<<"\n";
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

	factup();
	siever();
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