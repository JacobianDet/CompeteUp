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

int ar[MV], vis[MV];
ll arr[MV];

struct t3
{
	int a,b,c;
}rx[MV];

vector<pair<t3, int> > Z[MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n-2;i++)
	cin>>rx[i].a>>rx[i].b>>rx[i].c;
	for(int i=1;i<=n-2;i++)
	{
		Z[rx[i].a].pb({rx[i], i});
		Z[rx[i].b].pb({rx[i], i});
		Z[rx[i].c].pb({rx[i], i});
		ar[rx[i].a]++;
		ar[rx[i].b]++;
		ar[rx[i].c]++;
	}	
	int pt = -1;
	for(int i=1;i<=n;i++)
	{
		if(ar[i] == 1)
		{
			pt = i;
			break;
		}	
	}	
	queue<PII> Q;
	VI res;
	Q.push({pt, -1});
	while(!Q.empty())
	{
		PII tx = Q.front();
		Q.pop();
		pair<t3, int> use;
		for(auto &u : Z[tx.ff])
		{
			if(!vis[u.ss])
			{
				use = u;
				break;
			}	
		}	
		VI ux;
		vis[use.ss] = 1;
		ux.pb(use.ff.a);
		ux.pb(use.ff.b);
		ux.pb(use.ff.c);
		ar[tx.ff]--;
		sort(ux.begin(), ux.end(), [tx](int A, int B){ return ((ar[A] < ar[B]) || ((ar[A] == ar[B]) && (A == tx.ss))); });
		ar[ux[1]]--;
		ar[ux[2]]--;
		if(ar[ux[1]] != 0)
		{
			res.pb(ux[0]);	
			Q.push({ux[1], ux[2]});
		}
		else
		{
			res.pb(ux[0]);
			res.pb(ux[1]);
			res.pb(ux[2]);
		}	
	} 
	for(auto u : res)
	cout<<u<<" ";
	cout<<"\n";
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