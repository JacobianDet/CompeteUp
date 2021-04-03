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
ll arr[MV], ldc[MV], rdc[MV], sldc[MV], srdc[MV];

struct fx1
{
	int idx;

	bool operator < (const fx1& wx) const
	{
		return (idx + d1[idx] - 1 <= wx.idx + d1[wx.idx] - 1);
	}
};

struct fx2
{
	int idx;

	bool operator < (const fx2& wx) const
	{
		return (idx + d2[idx] - 1 <= wx.idx + d2[wx.idx] - 1); 
	}
};

struct fx3
{
	int idx;

	bool operator < (const fx3& wx) const
	{
		return (idx - d1[idx] + 1 >= wx.idx - d1[wx.idx] + 1);
	}
};

struct fx4
{
	int idx;

	bool operator < (const fx4& wx) const
	{
		return (idx - d2[idx] >= wx.idx - d2[wx.idx]); 
	}
};

void solve(int T)
{
	std::string s;
	std::cin>>s;
	int n = s.sz();
	for(int i=0,l=0,r=-1;i<n;i++)
	{
		int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
		while((i-k >= 0) && (i+k < n) && (s[i-k] == s[i+k]))
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
	std::set<fx1> D1;
	std::set<fx2> D2;
	std::set<fx3> D3;
	std::set<fx4> D4;
	for(int i=0;i<n;i++)
	{
		D1.ins({i});
		if(d2[i] > 0)
		D2.ins({i});
		ldc[i] = (D1.sz() + D2.sz());
		while(!D1.empty() && (((*D1.begin()).idx + d1[(*D1.begin()).idx] - 1) == i))
		D1.erase(D1.begin());
		while(!D2.empty() && (((*D2.begin()).idx + d2[(*D2.begin()).idx] - 1) == i))
		D2.erase(D2.begin());	
		sldc[i] = ((i > 0) ? sldc[i-1] : 0) + ldc[i];
 	}
	ll ans = 0;
	for(int i=n-1;i>=0;i--)
	{
		D3.ins({i});
		if((i < n-1) && (d2[i+1] > 0))
		D4.ins({i+1});
		rdc[i] = (D3.sz() + D4.sz());
		if(i > 0)
		ans += (sldc[i-1] * rdc[i]);
		while(!D3.empty() && (((*D3.begin()).idx - d1[(*D3.begin()).idx] + 1) == i))
		D3.erase(D3.begin());
		while(!D4.empty() && (((*D4.begin()).idx - d2[(*D4.begin()).idx]) == i))
		D4.erase(D4.begin());	
	}
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