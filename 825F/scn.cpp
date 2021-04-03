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
int prd[8001][8001], memo[8001], par[8001];

int xd(int idx, int n)
{
	if(idx == n)
	return 0;
	if(memo[idx] != -1)
	return memo[idx];
	int ans = 100000000;
	for(int i=idx;i<n;i++)
	{
		int cnt = 0;
		int val1 = prd[idx][i], val2 = (i-idx+1)/val1;
		cnt += val1;
		while(val2)
		{
			cnt++;
			val2 /= 10;
		}
		if(cnt + xd(i+1, n) < ans)
		{
			par[idx] = i+1;  
			ans = min(ans, cnt + xd(i+1, n));
		}	
	}
	memo[idx] = ans;
	return ans;
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	string s;
	cin>>s;
	int n = (int)s.sz();
	for(int i=0;i<n;i++)
	{
		VI lcp(n-i);
		for(int j=i;j<n;j++)
		{
			if(i != j)
			{	
				int k = lcp[j-1-i];
				while(k && (s[i+k] != s[j]))
				k = lcp[k-1];
				if(s[i+k] == s[j])
				k++;
				lcp[j-i] = k;
			}
			prd[i][j] = (!((j-i+1) % ((j-i+1) - lcp[j-i])) ? ((j-i+1) - lcp[j-i]) : (j-i+1));
		}	
	}
	int ans = xd(0, n);
	cout<<ans<<"\n";
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