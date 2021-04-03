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
#define mpp make_pair
#define ins insert
#define sz size
#define endl '\n'

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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];
struct custom_hash {
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
unordered_map<int, PII, custom_hash> mp;
ll j, k;
ll cdiv(ll num, ll den){
	return num / den + (num % den != 0);
}
ll get(ll x, ll y, ll f){
	if(f % 2 == 0 or f == 1){
		return cdiv(x *  2 + y, f);
	}
	ll ret = 0;
	ll kk = f / 2;
	ll p = x / kk;
	ret = p;
	x -= (p * kk);
	y -= p;
	if(y <= 0){
		ret += (x > 0);
		return ret;
	}
	else{
		if(x > 0){
			ret++;
			y -= (f - (2 * x));
			if(y <= 0){
				return ret;
			}
			else{
				ret += cdiv(y, f);
			}
		}
		else{
			ret += cdiv(y, f);
		}
		return ret;
	}
}
bool pred(ll mid){
	ll ret = 0;
	for(auto &e:mp){
		ll pp = get(e.second.first, e.second.second, mid);
		ret += (cdiv(pp, k));
	}
	return ret <= j;
}
void solve(int T)
{
	ll n, k, j;
	cin >> n >> k >> j;
	::j = j;
	::k = k;
	mp.clear();
	bool is2 = 0;
	for(int i = 0;i < n;i++){
		int t, sz;
		cin >> t >> sz;
		if(sz == 1){
			mp[t].second++;
		}
		else{
			mp[t].first++;
			is2 = 1;
		}
	}
	ll l = 1 + is2, r = INF;
	while(l < r){
		ll mid = l + (r - l) / 2;
		if(pred(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l << endl;;
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
	cin >> T;
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