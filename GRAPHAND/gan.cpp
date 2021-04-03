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
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];

struct xf
{
	int d;
	ll c,v;
};

vector<xf> G[MV];
ll dist[MV];

void dijkstra_find(int sr, int dr, int n, ll k)
{
	for(int i=1;i<=n;i++)
	dist[i] = INF;	
	dist[sr] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL> > P;
	P.push({dist[sr], sr});
	while(!P.empty())
	{
		PLL xz = P.top();
		P.pop();
		if(xz.ss == dr)
		continue;
		for(auto u : G[xz.ss])
		{
			if((dist[u.d] > dist[xz.ss] + u.c) && ((u.v & k) == k))
			{
				dist[u.d] = dist[xz.ss] + u.c;
				P.push({dist[u.d], u.d});
			}	
		}	
	}
	return;
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		ll c,v;
		cin>>s>>d>>c>>v;
		G[s].pb({d,c,v});
		G[d].pb({s,c,v});
	}	
	int sr,dr;
	ll k;
	cin>>sr>>dr>>k;
	ll res = INF;
	ll x = 0;
	for(ll i=30;i>=0;i--)
	{
		if(k & (1LL<<i))
		x |= (1LL<<i);
		else 
		{
			dijkstra_find(sr, dr, n, x | (1LL<<i));
			res = min(res, dist[dr]);
		}	
	}
	dijkstra_find(sr, dr, n, k);
	res = min(res, dist[dr]);
	if(res == INF)
	cout<<"-1\n";	
	else cout<<res<<"\n";
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