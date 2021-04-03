#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 5000001
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

void solve(int T)
{
	string s;
	cin>>s;
	int n = s.sz();
	for(int i=0,l=0,r=-1;i<n;i++)
	{
		int k = ((i > r) ? 1 : min(d1[l+r-i], r-i+1));
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
		int k = ((i > r) ? 0 : min(d2[l+r-i+1], r-i+1));
		while((i-k-1 >= 0) && (i+k < n) && (s[i-k-1] == s[i+k]))
		k++;
		d2[i] = k--;
		if(i + k > r)
		{
			l = i-k-1;
			r = i+k;
		}	
	}
	ar[0] = 1;
	for(int i=1;i<n;i++)
	{
		int lx = i+1;
		if(lx & 1)
		{
			if(d1[lx/2] == (lx/2)+1)
			ar[i] = (1 + ar[lx/2-1]);	
		}	
		else
		{
			if(d2[lx/2] == (lx/2))
			ar[i] = (1 + ar[lx/2-1]);
		}
	}
	ll ans = 0;	
	for(int i=0;i<n;i++)
	ans += 1LL*ar[i];	
	cout<<ans<<"\n";
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