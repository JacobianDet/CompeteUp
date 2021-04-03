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

int ar[MV];
ll arr[MV];
string s[MV][2];
PII D[MV];

bool cmpx(pair<string, int> A, pair<string, int> B)
{
	return (A.ff < B.ff);
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>s[i][0]>>s[i][1];
	for(int i=0;i<n;i++)
	cin>>ar[i];
	vector<pair<string, int> > Z;
	for(int i=0;i<n;i++)
	{
		Z.pb(mp(s[i][0], i+1));
		Z.pb(mp(s[i][1], i+1));
	}	
	sort(Z.begin(), Z.end(), cmpx);
	for(int i=1;i<=n;i++)
	{
		D[i].ff = -1; D[i].ss = -1;
	}	
	for(int i=0;i<2*n;i++)
	{	
		if(D[Z[i].ss].ff == -1)
		D[Z[i].ss].ff = i;
		else if(D[Z[i].ss].ss == -1)
		D[Z[i].ss].ss = i;	
	}
	int pz = -1;
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		if(D[ar[i]].ff > pz)
		pz = D[ar[i]].ff;
		else if(D[ar[i]].ss > pz)
		pz = D[ar[i]].ss;
		else 
		{
			ok = 0;
			break;
		}	
	}	
	if(!ok)
	cout<<"NO\n";
	else std::cout<<"YES\n";
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