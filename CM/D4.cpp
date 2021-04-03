#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
#define MV 1000005
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

int ar[MV], d1[MV], d2[MV];
ll arr[MV];

// PII xd(int l, int r)
// {
// 	if(l > r)
// 	return {0, 0};	
// 	else if(l == r)
// 	return {1, 0};
// 	string z = s.substr(l, r-l+1);
// 	PII zxd;
// 	if(s[l] == s[r])
// 	{
// 		zxd = xd(l+1, r-1);
// 		zxd.ff++;
// 		zxd.ss++;
// 	}	
// 	int n = (int)z.sz();
// 	for(int i=0;i<n;i++)
// 	{
// 		d1[i] = 0;
// 		d2[i] = 0;
// 	}	
// 	for(int i=0,l=0,r=-1;i<n;i++)
// 	{
// 		int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
// 		while((0 <= i-k) && (i+k < n) && (z[i-k] == z[i+k]))
// 		k++;
// 		d1[i] = k--;
// 		if(i+k > r)
// 		{
// 			l = i-k;
// 			r = i+k;
// 		}	
// 	}
// 	for(int i=0,l=0,r=-1;i<n;i++)
// 	{
// 		int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
// 		while((0 <= i-k-1) && (i+k < n) && (z[i-k-1] == z[i+k]))
// 		k++;
// 		d2[i] = k--;
// 		if(i+k > r)
// 		{
// 			l = i-k-1;
// 			r = i+k;
// 		}	
// 	}
// 	int mvp = 0, mvs = 0;
// 	for(int i=0;i<n;i++)
// 	{
// 		int lx = 2*d1[i] - 1;
// 		if(i-d1[i]+1 == 0)
// 		mvp = max({mvp, lx});
// 		if(i+d1[i]-1 == n-1)
// 		mvs = max({mvs, lx});	
// 	}	
// 	for(int i=0;i<n;i++)
// 	{
// 		int lx = 2*d2[i];
// 		if(i-d2[i] == 0)
// 		mvp = max({mvp, lx});
// 		if(i+d2[i]-1 == n-1)
// 		mvs = max({mvs, lx});	
// 	}
// 	int uy = max({zxd.ff + zxd.ss, mvp, mvs});
// 	if((zxd.ff + zxd.ss) == uy)
// 	return zxd;
// 	else if(mvp == uy)
// 	{
// 		zxd.ff = mvp;
// 		zxd.ss = 0;
// 		return zxd;
// 	}	
// 	else
// 	{
// 		zxd.ff = 0;
// 		zxd.ss = mvs;
// 		return zxd;
// 	}
// }

void solve(int T)
{
	string s;
	cin>>s;
	int n = (int)s.sz();
	int p1 = 0, p2 = n-1;
	while(p1 < p2)
	{
		if(s[p1] == s[p2])
		{
			p1++;
			p2--;
		}	
		else break;
	}
	if(p1 >= p2)
	cout<<s+s<<"\n";
	else
	{
		string z = s.substr(0, p1);
		string rz = z;
		reverse(begin(rz), end(rz));
		string sx1 = s.substr(p1);
		n = (int)sx1.sz();
		for(int i=0;i<n;i++)
		{
			d1[i] = 0;
			d2[i] = 0;
		}	
		for(int i=0,l=0,r=-1;i<n;i++)
		{
			int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
			while((0 <= i-k) && (i+k < n) && (sx1[i-k] == sx1[i+k]))
			k++;
			d1[i] = k--;
			if(i+k > r)
			{
				l = i-k;
				r = i+k;
			}	
		}
		for(int i=0,l=0,r=-1;i<n;i++)
		{
			int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
			while((0 <= i-k-1) && (i+k < n) && (sx1[i-k-1] == sx1[i+k]))
			k++;
			d2[i] = k--;
			if(i+k > r)
			{
				l = i-k-1;
				r = i+k;
			}	
		}
		int mvp = 0, mvs = 0;
		for(int i=0;i<n;i++)
		{
			int lx = 2*d1[i] - 1;
			if(i-d1[i]+1 == 0)
			mvp = max({mvp, lx});
			if(i+d1[i]-1 == n-1)
			mvs = max({mvs, lx});	
		}	
		for(int i=0;i<n;i++)
		{
			int lx = 2*d2[i];
			if(i-d2[i] == 0)
			mvp = max({mvp, lx});
			if(i+d2[i]-1 == n-1)
			mvs = max({mvs, lx});	
		}
		string s1 = z + sx1.substr(0, mvp) + rz;
		string sx2 = s.substr(0, p2+1);
		n = (int)sx2.sz();
		for(int i=0;i<n;i++)
		{
			d1[i] = 0;
			d2[i] = 0;
		}	
		for(int i=0,l=0,r=-1;i<n;i++)
		{
			int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
			while((0 <= i-k) && (i+k < n) && (sx2[i-k] == sx2[i+k]))
			k++;
			d1[i] = k--;
			if(i+k > r)
			{
				l = i-k;
				r = i+k;
			}	
		}
		for(int i=0,l=0,r=-1;i<n;i++)
		{
			int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
			while((0 <= i-k-1) && (i+k < n) && (sx2[i-k-1] == sx2[i+k]))
			k++;
			d2[i] = k--;
			if(i+k > r)
			{
				l = i-k-1;
				r = i+k;
			}	
		}
		mvp = 0, mvs = 0;
		for(int i=0;i<n;i++)
		{
			int lx = 2*d1[i] - 1;
			if(i-d1[i]+1 == 0)
			mvp = max({mvp, lx});
			if(i+d1[i]-1 == n-1)
			mvs = max({mvs, lx});	
		}	
		for(int i=0;i<n;i++)
		{
			int lx = 2*d2[i];
			if(i-d2[i] == 0)
			mvp = max({mvp, lx});
			if(i+d2[i]-1 == n-1)
			mvs = max({mvs, lx});	
		}
		string s2 = z + sx2.substr(n-mvs, mvs) + rz;
		if((int)s1.sz() > (int)s2.sz())
		cout<<s1<<"\n";
		else cout<<s2<<"\n";	
	}	
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