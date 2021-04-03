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

int ar[MV], d1[MV], d2[MV];
ll arr[MV];
int memo[5001][5001];

int xd(int s, int d)
{
	if(s == d)
	return 1;
	if(memo[s][d] != -1)
	return memo[s][d];
	int ans = 0;
	if((d-s+1) & 1)
	{
		if(2*d1[(s+d)/2] - 1 >= (d-s+1))
		ans = 1 + min(xd(s, (s+d)/2 - 1), xd((s+d)/2 + 1, d));	
	}	
	else
	{
		if(2*d2[(s+d)/2 + 1] >= (d-s+1))
		ans = 1 + min(xd(s, (s+d)/2), xd((s+d)/2 + 1, d));	
	}
	memo[s][d] = ans;
	return ans;
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	string s;
	cin>>s;
	int n = (int)s.sz();
	for(int i=0,l=0,r=-1;i<n;i++)
	{
		int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
		while((i-k >= 0) && (i+k < n) && (s[i+k] == s[i-k]))
		k++;
		d1[i] = k--;
		if(i + k > r)
		{
			l = i-k;
			r = i+k;
		}
	}
	for(int i=0,l=0,r=-1;i<n;i++)
	{
		int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
		while((i-k-1 >= 0) && (i+k < n) && (s[i-k-1] == s[i+k]))
		k++;
		d2[i] = k--;
		if(i + k > r)
		{
			l = i-k-1;
			r = i+k;
		}	
	}
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>=i;j--)
		{
			memo[i][j] = xd(i, j);
			if(memo[i][j])
			{
				ar[1]++;
				ar[memo[i][j]+1]--;
			}	
		}	
	}
	for(int i=1;i<=n;i++)
	{
		ar[i] += ar[i-1];
		cout<<ar[i]<<" ";
	}
	cout<<"\n";
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