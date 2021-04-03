#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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

int trie[1501*1501][26];
ll arr[MV];
std::string s,gbd;
int k;

void ins(std::string z, int &tot)
{
	int nxt = 0;
	for(auto u : z)
	{
		if(trie[nxt][u-'a'] == -1)
		trie[nxt][u-'a'] = ++tot;
		nxt = trie[nxt][u-'a'];	
	}	
	return;
}

int dfs_visit(int nxt, int kc)
{
	int ans = (nxt ? 1 : 0);
	for(int i=0;i<26;i++)
	{
		if((trie[nxt][i] != -1) && (kc + (gbd[i] == '0') <= k))
		ans += dfs_visit(trie[nxt][i], kc + (gbd[i] == '0'));	
	}	
	return ans;
}

void solve(int T)
{
	memset(trie, -1, sizeof(trie));
	std::cin>>s>>gbd>>k;
	int tot = 0;
	for(int i=0;i<s.sz();i++)
	ins(s.substr(i, s.sz()-i), tot);
	int ans = dfs_visit(0, 0);
	std::cout<<ans<<"\n";
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