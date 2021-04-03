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

int ar1[MV], ar2[MV], id1[MV], id2[MV], lcp[MV];
ll arr[MV];
vector<PII> G1[MV], G2[MV];
VI s1, s2;

void dfs_vis1(int s, int p)
{
	bool ok = 0;
	s1.pb(ar1[s]);
	for(auto u : G1[s])
	{
		if(u.ff != p)
		{
			if(!ok)
			ok = 1;
			else s1.pb(ar1[s]);
			s1.pb(u.ss);
			dfs_vis1(u.ff, s);
		}	
	}
	if(!ok)
	s1.pb(103);	
	return;
}

void dfs_vis2(int s, int p)
{
	bool ok = 0;
	s2.pb(ar2[s]);
	for(auto u : G2[s])
	{
		if(u.ff != p)
		{
			if(!ok)
			ok = 1;
			else s2.pb(ar2[s]);
			s2.pb(u.ss);
			dfs_vis2(u.ff, s);
		}	
	}
	if(!ok)
	s2.pb(103);	
	return;
}

bool cmpx(PII A, PII B)
{
	return (A.ss < B.ss);
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ar1[i];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		char c;
		cin>>s>>d>>c;
		id1[d]++;
		int x = (c == 'M') ? 101 : 102;
		G1[d].pb(mp(s, x));
		G1[s].pb(mp(d, x));
	}	
	for(int i=1;i<=n;i++)
	sort(G1[i].begin(), G1[i].end(), cmpx);	
	int nd = -1;
	for(int i=1;i<=n;i++)
	{
		if(!id1[i])
		{
			nd = i;
			break;
		}	
	}	
	dfs_vis1(nd, -1);
	int q;
	cin>>q;
	while(q--)
	{
		int m;
		cin>>m;
		for(int i=1;i<=m;i++)
		cin>>ar2[i];
		for(int i=0;i<m-1;i++)
		{
			int s,d;
			char c;
			cin>>s>>d>>c;
			id2[d]++;
			int x = (c == 'M') ? 101 : 102;
			G2[d].pb(mp(s, x));
			G2[s].pb(mp(d, x));
		}	
		for(int i=1;i<=m;i++)
		sort(G2[i].begin(), G2[i].end(), cmpx);	
		int yx = -1;
		for(int i=1;i<=m;i++)
		{
			if(!id2[i])
			{
				yx = i;
				break;
			}	
		}	
		dfs_vis2(yx, -1);
		for(int i=1;i<s2.sz();i++)
		{
			int j = lcp[i-1];
			while(j && (s2[i] != s2[j]))
			j = lcp[j-1];
			if(s2[i] == s2[j])
			j++;
			lcp[i] = j;	
		}	
		int u = s2.sz();
		int lc = 0, ct = 0;
		for(int i=0;i<s1.sz();i++)
		{
			int j = lc;
			while(j && (s1[i] != s2[j]))
			j = lcp[j-1];
			if(s1[i] == s2[j])
			j++;
			lc = j;
			if(lc == s2.sz())
			{		
				ct++;
				//std::cout<<"f "<<ct<<" "<<lc<<" "<<i<<"\n";
				lc = lcp[lc-1];
			}	
		}
		if(ct > 0)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";
		for(int i=1;i<=m;i++)
		{	
			id2[i] = 0;
			G2[i].clear();
		}	
		s2.clear();		
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