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

int ar[MV], lcp[MV];
ll arr[MV];

void solve(int T)
{
	std::string s;
	std::cin>>s;
	int n = s.sz();
	for(int i=1;i<n;i++)
	{
		int j = lcp[i-1];
		while(j && (s[i] != s[j]))
		j = lcp[j-1];
		if(s[i] == s[j])
		j++;
		lcp[i] = j;	
	}	
	for(int i=0;i<n;i++)
	ar[lcp[i]]++;
	for(int i=n-1;i>0;i--)
	ar[lcp[i-1]] += ar[i];
	for(int i=1;i<=n;i++)
	ar[i]++;
	int x = n;
	VI res;
	while(x)
	{
		res.pb(x);
		x = lcp[x-1];
	}	
	std::reverse(res.begin(), res.end());
	std::cout<<res.sz()<<"\n";
	for(auto u : res)
	std::cout<<u<<" "<<ar[u]<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}