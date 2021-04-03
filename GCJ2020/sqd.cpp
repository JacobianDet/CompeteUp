#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

int ar[MV];
ll arr[MV];
vector<VL> val, lf, rf, uf, df, vis;

void solve(int T)
{
	int r,c;
	cin>>r>>c;
	val.resize(r, VL(c));
	lf.resize(r, VL(c));
	rf.resize(r, VL(c));
	uf.resize(r, VL(c));
	df.resize(r, VL(c));
	vis.resize(r, VL(c));
	for(auto &&u1 : val)
	{
		for(auto &&u2 : u1)
		cin>>u2;	
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			lf[i][j] = j-1;
			rf[i][j] = j+1;
			uf[i][j] = i-1;
			df[i][j] = i+1;
			vis[i][j] = MOD;
		}	
	}
	queue<PII> Q;
	ll rtot = 0, tot = 0, qxf = 0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			tot += val[i][j];
			ll sx = 0, nn = 0;
			if(lf[i][j] != -1)
			{
				sx += val[i][lf[i][j]];
				nn++;
			}
			if(rf[i][j] != c)
			{
				sx += val[i][rf[i][j]];
				nn++;
			}
			if(uf[i][j] != -1)
			{
				sx += val[uf[i][j]][j];
				nn++;
			}
			if(df[i][j] != r)
			{
				sx += val[df[i][j]][j];
				nn++;
			}
			if(nn * val[i][j] < sx)
			{
				vis[i][j] = 1;
				Q.push({i, j});
			}
		}
	}
	int lvl = 1;
	while(!Q.empty())
	{
		lvl++;
		rtot += (tot - qxf);
		// cout<<rtot<<"\n";
		int sx = (int)Q.sz();
		for(int j=0;j<sx;j++)
		{
			PII u = Q.front();
			Q.pop();
			if(lf[u.ff][u.ss] != -1)
			rf[u.ff][lf[u.ff][u.ss]] = rf[u.ff][u.ss];
			if(rf[u.ff][u.ss] != c)
			lf[u.ff][rf[u.ff][u.ss]] = lf[u.ff][u.ss];
			if(uf[u.ff][u.ss] != -1)
			df[uf[u.ff][u.ss]][u.ss] = df[u.ff][u.ss];
			if(df[u.ff][u.ss] != r)
			uf[df[u.ff][u.ss]][u.ss] = uf[u.ff][u.ss];
			Q.push(u);
		}	
		for(int j=0;j<sx;j++)
		{
			PII u = Q.front();
			Q.pop();
			if(lf[u.ff][u.ss] != -1)
			{
				int x = u.ff;
				int y = lf[u.ff][u.ss];
				if(vis[x][y] > lvl)
				{
					ll sx = 0, nn = 0;
					if(lf[x][y] != -1)
					{
						sx += val[x][lf[x][y]];
						nn++;
					}
					if(rf[x][y] != c)
					{
						sx += val[x][rf[x][y]];
						nn++;
					}
					if(uf[x][y] != -1)
					{
						sx += val[uf[x][y]][y];
						nn++;
					}
					if(df[x][y] != r)
					{
						sx += val[df[x][y]][y];
						nn++;
					}
					if(nn * val[x][y] < sx)
					{
						vis[x][y] = lvl;
						Q.push({x, y});
					}
				}	
			}
			if(rf[u.ff][u.ss] != c)
			{
				int x = u.ff;
				int y = rf[u.ff][u.ss];
				if(vis[x][y] > lvl)
				{
					ll sx = 0, nn = 0;
					if(lf[x][y] != -1)
					{
						sx += val[x][lf[x][y]];
						nn++;
					}
					if(rf[x][y] != c)
					{
						sx += val[x][rf[x][y]];
						nn++;
					}
					if(uf[x][y] != -1)
					{
						sx += val[uf[x][y]][y];
						nn++;
					}
					if(df[x][y] != r)
					{
						sx += val[df[x][y]][y];
						nn++;
					}
					if(nn * val[x][y] < sx)
					{
						vis[x][y] = lvl;
						Q.push({x, y});
					}
				}	
			}
			if(uf[u.ff][u.ss] != -1)
			{
				int x = uf[u.ff][u.ss];
				int y = u.ss;
				if(vis[x][y] > lvl)
				{
					ll sx = 0, nn = 0;
					if(lf[x][y] != -1)
					{
						sx += val[x][lf[x][y]];
						nn++;
					}
					if(rf[x][y] != c)
					{
						sx += val[x][rf[x][y]];
						nn++;
					}
					if(uf[x][y] != -1)
					{
						sx += val[uf[x][y]][y];
						nn++;
					}
					if(df[x][y] != r)
					{
						sx += val[df[x][y]][y];
						nn++;
					}
					if(nn * val[x][y] < sx)
					{
						vis[x][y] = lvl;
						Q.push({x, y});
					}
				}		
			}
			if(df[u.ff][u.ss] != r)
			{
				int x = df[u.ff][u.ss];
				int y = u.ss;
				if(vis[x][y] > lvl)
				{
					ll sx = 0, nn = 0;
					if(lf[x][y] != -1)
					{
						sx += val[x][lf[x][y]];
						nn++;
					}
					if(rf[x][y] != c)
					{
						sx += val[x][rf[x][y]];
						nn++;
					}
					if(uf[x][y] != -1)
					{
						sx += val[uf[x][y]][y];
						nn++;
					}
					if(df[x][y] != r)
					{
						sx += val[df[x][y]][y];
						nn++;
					}
					if(nn * val[x][y] < sx)
					{
						vis[x][y] = lvl;
						Q.push({x, y});
					}
				}		
			}
			qxf += val[u.ff][u.ss];		
		}	
	}
	rtot += (tot - qxf);
	cout<<"Case #"<<T<<": "<<rtot<<"\n";
	val.clear();
	lf.clear();
	rf.clear();
	uf.clear();
	df.clear();
	vis.clear();
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	cin>>T;
	for(auto _=1;_<=T;_++)
	solve(_);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}