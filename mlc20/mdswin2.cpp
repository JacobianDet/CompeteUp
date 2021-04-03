#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds; 
#define INF (1LL<<57)
#define MOD 998244353
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
//ordered_set = order_by_key(.)
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
ll arr[MV], factx[MV], inv[MV], invf[MV], cnt[MV], cv[MV];
bitset<MV> xfd;
ll xd;

// int readInt (void) {
// 	bool minus = false;
// 	int result = 0;
// 	char ch;
// 	ch = getchar_unlocked();
// 	while (true) {
// 		if (ch == '-') break;
// 		if (ch >= '0' && ch <= '9') break;
// 		ch = getchar_unlocked();
// 	}
// 	if (ch == '-') minus = true; else result = ch-'0';
// 	while (true) {
// 		ch = getchar_unlocked();
// 		if (ch < '0' || ch > '9') break;
// 		result = result*10 + (ch - '0');
// 	}
// 	if (minus)
// 		return -result;
// 	else
// 		return result;
// }

struct sq
{
	int l,r,id;
}Q[MV];

class mo
{
	public: void ch_cnt(ll f, ll d)
			{
				xd ^= f;
				if(cv[f] == 0)
				{
					if(d == -1)
					return;
					xfd[f] = 1;
				}
				cv[f] += d;
				if(cv[f] == 0)
				{
					if(d == +1)
					return;	
					xfd[f] = 0;
				}
			}

			void add(int x)
			{
				ch_cnt(cnt[x], -1);
				cnt[x]++;
				ch_cnt(cnt[x], +1);
			}

			void remove(int x)
			{
				ch_cnt(cnt[x], -1);
				cnt[x]--;
				ch_cnt(cnt[x], +1);
			}
};

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

void solve(int T)
{
	memset(cnt, 0, sizeof(cnt));
	memset(cv, 0, sizeof(cv));	
	xfd.reset();
	// xfd[MV-1] = 1;
	// cout<<xfd<<"\n";
	// mkd.clear();
	int n;
	cin>>n;
	const int Z = (int)floor(sqrt(n));
	xd = 0;
	mo D;
	SI vza;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		vza.ins(ar[i]);
	}
	VI vzb(vza.begin(), vza.end());
	for(int i=1;i<=n;i++)
	ar[i] = (lower_bound(vzb.begin(), vzb.end(), ar[i]) - vzb.begin()) + 1;	
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
	}
	sort(Q, Q+q, [Z](sq A, sq B){ return (((A.l/Z) < (B.l/Z)) || (((A.l/Z) == (B.l/Z)) && (((A.l/Z) & 1) ? (A.r < B.r) : (A.r > B.r)))); });		
	int mo_l = 1, mo_r = 0;
	for(int i=0;i<q;i++)
	{
		int l = Q[i].l;
		int r = Q[i].r;
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
		if(!xd)
		arr[Q[i].id] = 0;
		else
		{
			ll ct = 0;
			// xfd |= (1<<0);
			for(ll u = xfd._Find_first();u<MV;u = xfd._Find_next(u))
			{
				// cout<<u<<"A ";
				xd ^= u;
				if(xd < u)
				ct = ((ct%MOD) + (((cv[u]%MOD) * (((factx[u]%MOD) * (((invf[xd]%MOD) * (invf[u-xd]%MOD))%MOD))%MOD))%MOD))%MOD;
				xd ^= u;
				// mkd[u] = 0;
			}
			// printf("%d\n", u);
			arr[Q[i].id] = ct;	
			// printf("\n");	
		}	
	}
	for(int i=0;i<q;i++)
	cout<<arr[i]<<"\n";
	// xfd.reset();	
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

	factup();
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