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

const ll MOD = 1000000007;
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

ll dist[MV];
vector<PLL> G[MV];
PPLL edg[MV];

void dijkstra_find(ll n, ll a, ll b, ll w, ll ti = MV)
{
	for(int i=1;i<=n;i++)
	dist[i] = INF;
	dist[a] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL> > P;
	P.push({0, a});
	while(!P.empty())
	{
		PLL px = P.top();
		P.pop();
		// whoami(px.ff, px.ss);
		if(px.ss == b)
		break;	
		for(auto u : G[px.ss])
		{
			ll fw = MOD;
			if(u.ss <= ti)
			fw = (!edg[u.ss].ss ? w : edg[u.ss].ss);
			else fw = (!edg[u.ss].ss ? MOD : edg[u.ss].ss);
			if(dist[u.ff] > dist[px.ss] + fw)
			{
				dist[u.ff] = dist[px.ss] + fw;	
				P.push({dist[u.ff], u.ff});
			}	
		}
	}
	return;
}

ll bs1(ll n, ll a, ll b, ll l, ll m)
{
	ll lo = 0;
	ll hi = m-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		dijkstra_find(n, a, b, 1, mid);
		if(dist[b] > l)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

void solve(int T)
{
	ll n,m,l,a,b;
	cin>>n>>m>>l>>a>>b;
	a++;
	b++;
	for(int i=0;i<m;i++)
	{
		ll s,d,w;
		cin>>s>>d>>w;
		s++, d++;
		edg[i] = {{s, d}, w};
		G[s].pb({d, i});
		G[d].pb({s, i});
	}	
	dijkstra_find(n, a, b, MOD);
	if(dist[b] < l)
	{
		cout<<"NO\n";
		return;
	}
	dijkstra_find(n, a, b, 1);
	// cout<<dist[b]<<"\n";
	if(dist[b] > l)
	{
		cout<<"NO\n";
		return;
	}
	ll idx = bs1(n, a, b, l, m);	
	dijkstra_find(n, a, b, 1, idx);
	ll df = (l - dist[b]);
	// whoami(df, idx, dist[b]);
	for(int i=0;i<idx;i++)
	edg[i].ss = (!edg[i].ss ? 1 : edg[i].ss);
	edg[idx].ss = (!edg[idx].ss ? 1 + df : edg[idx].ss);
	for(int i=idx+1;i<m;i++)
	edg[i].ss = (!edg[i].ss ? MOD : edg[i].ss);
	cout<<"YES\n";
	for(int i=0;i<m;i++)	
	cout<<edg[i].ff.ff-1<<" "<<edg[i].ff.ss-1<<" "<<edg[i].ss<<"\n";
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