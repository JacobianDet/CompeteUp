#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
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

const int MOD = 1000000007;

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

int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

bitset<57800> isP;

void siever(void)
{
	isP.set();
	isP[0] = 0, isP[1] = 0;
	for(int p=isP._Find_first();p*p<57800;p=isP._Find_next(p))
	{
		for(int i=p*p;i<57800;i+=p)
		isP[i] = 0;	
	}	
	return;
}

void solve(int T)
{
	vector<pair<string, int> > vin(T);
	vector<string> vou(T);
	int idx = 0;
	for(auto &&s : vin)
	{	
		char ch;
		ch = getchar_unlocked();
		while (true) {
			if (!(ch >= '0' && ch <= '9')) break;
			s.ff += ch;
			ch = getchar_unlocked();
		}
		s.ss = idx++;
	}	
	auto cmpx = [&](string A, string B)->bool{
		if((int)A.sz() > (int)B.sz())
		return 0;
		else if((int)A.sz() < (int)B.sz())	
		return 1;
		else
		{
			bool ok = 1;
			for(int i=0;i<(int)A.sz();i++)
			{
				if(A[i] < B[i])
				break;
				else if(A[i] > B[i])
				{	
					ok = 0;
					break;
				}	
				else continue;	
			}
			return ok;	
		}
	};
	auto stc = [&](pair<string, int> A, pair<string, int> B)->bool{
		string a1 = A.ff, a2 = B.ff;
		if((int)a1.sz() < (int)a2.sz())
		return 1;
		else if((int)a1.sz() > (int)a2.sz())
		return 0;
		else
		{
			bool ok = 0;
			for(int i=0;i<(int)a1.sz();i++)
			{
				if(a1[i] < a2[i])
				{
					ok = 1;
					break;
				}
				else if(a1[i] > a2[i])
				break;	
				else continue;	
			}
			return ok;
		}	
	};
	sort(begin(vin), end(vin), stc);
	string mt = to_string(1), pmt = to_string(1);
	int u = isP._Find_first();
	for(auto &&s : vin)
	{		
		while(cmpx(mt, s.ff))
		{	
			string xt = to_string(u);
			VI fd(((int)xt.sz() + (int)mt.sz()));
			int ia = 0, ib = 0;
			for(int i=(int)xt.sz()-1;i>=0;i--)
			{
				int cy = 0;
				ib = 0;
				for(int j=(int)mt.sz()-1;j>=0;j--)
				{
					int px = fd[ia+ib] + ((xt[i] - '0') * (mt[j] - '0')) + cy;
					cy = px/10;
					fd[ia+ib] = px%10;
					ib++;
				}
				if(cy > 0)
				fd[ia+ib] += cy;
				ia++;	
			}
			string zt = "";
			bool ok = 0;
			for(int i=(int)fd.sz()-1;i>=0;i--)
			{
				if(!fd[i] && !ok)
				continue;
				else
				{
					ok = 1;
					zt += (char)(fd[i] + 48);
				}	
			}
			pmt = mt;
			mt = zt;
			u = isP._Find_next(u);
		}
		vou[s.ss] = pmt;	
	}	
	for(auto &&s : vou)
	{	
		for(auto &&u : s)
		printf("%c", u);
		printf("\n");
	}			
	return;
}

int main(void)
{
	// FLASH();
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	siever();
	T = readInt();
	solve(T);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}