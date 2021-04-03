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

void solve(int T)
{
	int x;
	string s;
	cin>>x>>s;
	ll ln = ((ll)s.size() % MOD);
	int px = 0;
	while(ln < x)
	{
		string z = s.substr(px+1);
		if(s[px] == '2')
		{
			s += z;
			ln = (ln + (ll)z.sz())%MOD;
		}	
		else if(s[px] == '3')
		{
			s += (z + z);
			ln = (ln + (ll)z.sz() * 2)%MOD;
		}
		px++;		
	}
	for(int i=px;i<x;i++)
	{
		if(s[i] == '2')
		ln = ((((2%MOD) * (ln%MOD))%MOD) - ((1LL*i + 1)%MOD) + MOD)%MOD;
		else if(s[i] == '3')
		ln = ((((3%MOD) * (ln%MOD))%MOD) - (((2%MOD) * (1LL*i + 1)%MOD)%MOD) + MOD)%MOD;	
	}	
	cout<<ln<<"\n";
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