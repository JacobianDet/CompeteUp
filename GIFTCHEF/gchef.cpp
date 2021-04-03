#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 600005
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

int ar[MV], lcp[MV];
ll arr[MV], memo[MV][2];
int m,n;

ll xd(int idx, bool st)
{
	if(idx == m)
	return (st ? 1 : 0);
	if(memo[idx][st] != -1)
	return memo[idx][st];
	ll ans = 0;
	if(lcp[idx] == m)
	ans = ((ans%MOD) + (xd(idx - m, st | 1)%MOD))%MOD;
	ans = ((ans%MOD) + (xd(idx-1, st)%MOD))%MOD;
	memo[idx][st] = ans;
	return ans;	
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	string s,f;
	std::cin>>s>>f;
	m = (int)f.sz();
	n = (int)s.sz();
	string z = f + '#' + s;
	for(int i=1;i<z.sz();i++)
	{
		int j = lcp[i-1];
		while(j && (z[i] != z[j]))
		j = lcp[j-1];
		if(z[i] == z[j])
		j++;
		lcp[i] = j;	
	}	
	ll ans = xd(m+n, 0)%MOD;
	std::cout<<ans<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}