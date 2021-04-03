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

int ar[(1<<20)];
ll arr[MV];
bool mez[(1<<20)];

void solve(int T)
{
	int n;
	string s;
	cin>>s;
	n = s.sz();
	mez[0] = 1;
	for(int i=0;i<n;i++)
	{
		int mask = 0;
		for(int j=i;j>max(i-20, -1);j--)
		{
			if(!(mask & (1<<(s[j]-'a'))))
			{
				mask |= (1<<(s[j]-'a'));
				mez[mask] = 1;
			}
			else break;
		}	
	}	
	for(int i=0;i<(1<<20);i++)
	{
		if(mez[i])
		ar[i] = __builtin_popcount(i);
		else ar[i] = 0;	
	}	
	for(int i=0;i<20;i++)
	{
		for(int mask=0;mask<(1<<20);mask++)
		{
			if(mask & (1<<i))
			ar[mask] = max(ar[mask], ar[mask ^ (1<<i)]);
		}		
	}	
	int mct = 0;
	for(int mask=0;mask<(1<<20);mask++)
	mct = max(mct, ar[mask] + ar[(1<<20)-1-mask]);
	cout<<mct<<"\n";
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