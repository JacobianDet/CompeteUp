#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 4000001
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
	string s;
	cin>>s;
	while(s != "End")
	{
		int n = s.sz();
		std::cout<<lcp[0]<<" ";
		for(int i=1;i<n;i++)
		{
			int j = lcp[i-1];
			while(j && (s[i] != s[j]))
			j = lcp[j-1];
			if(s[i] == s[j])
			j++;
			lcp[i] = j;
			cout<<lcp[i]<<" ";	
		}
		cout<<"\n";
		cin>>s;
	}	
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