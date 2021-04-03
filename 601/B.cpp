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
PII ax[MV];

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	if((m < n) || (n == 2))
	cout<<"-1\n";
	else
	{
		int lc = MOD;
		PII hp;
		for(int i=0;i<n;i++)
		{
			ax[i] = {ar[i], i};
			for(int j=i+1;j<n;j++)
			{
				if(lc > (ar[i] + ar[j]))
				{	
					hp = {i, j};
					lc = (ar[i] + ar[j]);
				}		
			}	
		}
		sort(ax, ax+n, [](PII A, PII B){return (A.ff < B.ff);});
		vector<PII> Z;
		for(int i=0;i<n/2;i++)
		{
			Z.pb({ax[i].ss, ax[n-i-1].ss});
			if(i+1 < n/2)
			Z.pb({ax[n-i-1].ss, ax[i+1].ss});	
		}	
		if(n & 1)
		Z.pb({ax[n-n/2].ss, ax[n/2].ss});
		Z.pb({ax[n/2].ss, ax[0].ss});
		for(int i=0;i<(m-n);i++)
		Z.pb(hp);
		int ct = 0;
		for(auto u : Z)
		ct += (ar[u.ff] + ar[u.ss]);
		cout<<ct<<"\n";
		for(auto u : Z)
		cout<<u.ff+1<<" "<<u.ss+1<<"\n";	
	}	
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;

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