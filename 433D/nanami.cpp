#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

int ar[MV], pref[1005][1005], L[1005][1005], R[1005][1005], U[1005][1005], D[1005][1005], lf[1005], rf[1005];
ll arr[MV];

void solve(int T)
{
	int n,m,q;
	cin>>n>>m>>q;
	memset(pref, 0, sizeof(pref));
	memset(L, 0, sizeof(L));
	memset(R, 0, sizeof(R));
	memset(U, 0, sizeof(U));
	memset(D, 0, sizeof(D));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>pref[i][j];
			// pref[i][j] += (pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1]);
		}	
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(pref[i][j])
			U[i][j] = 1 + U[i-1][j];
			else U[i][j] = 0;	
		}
	}
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(pref[i][j])
			D[i][j] = 1 + D[i+1][j];
			else D[i][j] = 0;	
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(pref[j][i])
			L[j][i] = 1 + L[j][i-1];
			else L[j][i] = 0;	
		}	
	}
	for(int i=m;i>0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(pref[j][i])
			R[j][i] = 1 + R[j][i+1];
			else R[j][i] = 0;	
		}
	}
	while(q--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op == 1)
		{
			pref[x][y] ^= 1;
			for(int i=1;i<=n;i++)
			{
				if(pref[i][y])
				U[i][y] = 1 + U[i-1][y];
				else U[i][y] = 0;	
			}
			for(int i=n;i>0;i--)
			{
				if(pref[i][y])
				D[i][y] = 1 + D[i+1][y];
				else D[i][y] = 0;	
			}
			for(int i=1;i<=m;i++)
			{
				if(pref[x][i])
				L[x][i] = 1 + L[x][i-1];
				else L[x][i] = 0;	
			}
			for(int i=m;i>0;i--)
			{
				if(pref[x][i])
				R[x][i] = 1 + R[x][i+1];
				else R[x][i] = 0;	
			}
		}
		else
		{
			int mv = 0;
			stack<int> S;
			for(int i=1;i<=m;i++)
			{
				lf[i] = 0;
				rf[i] = m+1;
			}
			for(int i=1;i<=m;i++)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (U[x][S.top()] >= U[x][i]))
					S.pop();
					if(!S.empty())
					lf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=m;i>0;i--)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (U[x][S.top()] >= U[x][i]))
					S.pop();
					if(!S.empty())
					rf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=1;i<=m;i++)
			{
				if((lf[i] < y) && (y < rf[i]))
				mv = max({mv, (rf[i] - lf[i] - 1) * U[x][i]});	
			}
			for(int i=1;i<=m;i++)
			{
				lf[i] = 0;
				rf[i] = m+1;
			}
			for(int i=1;i<=m;i++)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (D[x][S.top()] >= D[x][i]))
					S.pop();
					if(!S.empty())
					lf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=m;i>0;i--)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (D[x][S.top()] >= D[x][i]))
					S.pop();
					if(!S.empty())
					rf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=1;i<=m;i++)
			{
				if((lf[i] < y) && (y < rf[i]))
				mv = max({mv, (rf[i] - lf[i] - 1) * D[x][i]});	
			}
			for(int i=1;i<=n;i++)
			{
				lf[i] = 0;
				rf[i] = n+1;
			}
			for(int i=1;i<=n;i++)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (L[S.top()][y] >= L[i][y]))
					S.pop();
					if(!S.empty())
					lf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=n;i>0;i--)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (L[S.top()][y] >= L[i][y]))
					S.pop();
					if(!S.empty())
					rf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=1;i<=n;i++)
			{
				if((lf[i] < x) && (x < rf[i]))
				mv = max({mv, (rf[i] - lf[i] - 1) * L[i][y]});	
			}
			for(int i=1;i<=n;i++)
			{
				lf[i] = 0;
				rf[i] = n+1;
			}
			for(int i=1;i<=n;i++)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (R[S.top()][y] >= R[i][y]))
					S.pop();
					if(!S.empty())
					lf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=n;i>0;i--)
			{
				if(S.empty())
				S.push(i);
				else
				{
					while((!S.empty()) && (R[S.top()][y] >= R[i][y]))
					S.pop();
					if(!S.empty())
					rf[i] = S.top();
					S.push(i);	
				}	
			}
			while(!S.empty())
			S.pop();
			for(int i=1;i<=n;i++)
			{
				if((lf[i] < x) && (x < rf[i]))
				mv = max({mv, (rf[i] - lf[i] - 1) * R[i][y]});	
			}
			cout<<mv<<"\n";
		} 
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