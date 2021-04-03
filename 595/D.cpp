#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200005
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

int ar[MV], vl[MV];
ll arr[MV];
PII lz[MV];
VI szx[MV];

void solve(int T)
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{	
		cin>>lz[i].ff>>lz[i].ss;
		szx[lz[i].ff].pb(i+1);
		szx[lz[i].ss+1].pb(-i-1);
		ar[lz[i].ff]++;
		ar[lz[i].ss+1]--;
	}	
	for(int i=1;i<MV;i++)
	ar[i] += ar[i-1];
	set<PII> Z;
	int cx = 0;
	VI res;
	for(int i=0;i<MV;i++)
	{
		cx += vl[i];
		for(auto u : szx[i])
		{
			if(u > 0)
			Z.insert(mp(lz[u-1].ss, u-1));
			else 
			{
				auto it = Z.find(mp(lz[-u-1].ss, -u-1));
				if(it != Z.end())
				Z.erase(it);
			}	
		}
		while(ar[i] - cx > k)
		{
			if(!Z.empty())
			{
				PII vfx = *Z.rbegin();
				Z.erase(Z.find(vfx));
				cx++;
				vl[vfx.ff+1]--;
				res.pb(vfx.ss);
			}
		}
	}
	cout<<(int)res.sz()<<"\n";
	for(auto u : res)
	cout<<u+1<<" ";
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