#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;

bool vis[MV];
int ar[MV];
ll arr[MV];
VI G[MV];

struct e3
{
	ll e12, e23, e31;
};

e3 dfs_visit(int s)
{
	vis[s] = 1;
	ll e12 = 0, e23 = 0, e31 = 0;
	for(auto u : G[s])
	{
		if(!vis[u])
		{
			//cout<<s<<" "<<u<<"\n";
			if((ar[s] == 1 && ar[u] == 2) || (ar[u] == 1 && ar[s] == 2))
			e12++;
			else if((ar[s] == 2 && ar[u] == 3) || (ar[u] == 2 && ar[s] == 3))
			e23++;
			else if((ar[s] == 3 && ar[u] == 1) || (ar[u] == 3 && ar[s] == 1))
			e31++;	
			e3 W = dfs_visit(u);
			e12 += W.e12;
			e23 += W.e23;
			e31 += W.e31;
		}	
		else
		{
			//cout<<s<<" "<<u<<"\n";
			if((ar[s] == 1 && ar[u] == 2) || (ar[u] == 1 && ar[s] == 2))
			e12++;
			else if((ar[s] == 2 && ar[u] == 3) || (ar[u] == 2 && ar[s] == 3))
			e23++;
			else if((ar[s] == 3 && ar[u] == 1) || (ar[u] == 3 && ar[s] == 1))
			e31++;
		}	
	}
	return {e12, e23, e31};
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	int e1 = 0, e2 = 0;
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		e1 = s;
		e2 = d;
	}
	if(!m)
	cout<<"-1\n";
	else
	{	
		set<int> X;
		for(int i=1;i<=n;i++)
		X.ins(i);
		for(auto u : G[e1])
		X.erase(u);
		for(auto u : X)
		ar[u] = 1;
		X.clear();
		for(int i=1;i<=n;i++)
		X.ins(i);
		for(auto u : G[e2])
		X.erase(u);
		bool ok = 1;
		for(auto u : X)
		{	
			if(ar[u])
			{	
				ok = 0;
				break;
			}	
			ar[u] = 2;
		}	
		X.clear();
		if(!ok)
		cout<<"-1\n";
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(!ar[i])
				ar[i] = 3;	
			}	
			ll c1 = 0, c2 = 0, c3 = 0, e12 = 0, e23 = 0, e31 = 0;
			for(int i=1;i<=n;i++)
			{
				if(ar[i] == 1)
				c1++;
				else if(ar[i] == 2)
				c2++;
				else c3++;	
			}
			for(int i=1;i<=n;i++)
			{	
				if(!vis[i])
				{	
					e3 X = dfs_visit(i);
					e12 += X.e12;
					e23 += X.e23;
					e31 += X.e31;
				}	
			}	
			e12 /= 2;
			e23 /= 2;
			e31 /= 2;
			//cout<<c1<<" "<<c2<<" "<<c3<<" "<<e12<<" "<<e23<<" "<<e31<<"\n";
			if(!c1 || !c2 || !c3 || (e12 != c1 * c2) || (e23 != c2 * c3) || (e31 != c3 * c1) || (e12 + e23 + e31 != m))
			ok = 0;	
			if(!ok)
			cout<<"-1\n";
			else
			{	
				for(int i=1;i<=n;i++)
				cout<<ar[i]<<" ";
				cout<<"\n";
			}		
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