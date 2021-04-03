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

int ar[MV], rr[MV], cr[MV];
ll arr[MV];
int gd[1001][1001];

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

void solve(int T)
{
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++)
	cin>>rr[i];
	for(int i=0;i<w;i++)
	cin>>cr[i];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		gd[i][j] = 2;	
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<rr[i];j++)
		gd[i][j] = 1;
		if(rr[i] < w)
		gd[i][rr[i]] = 0;	
	}	
	bool ok = 1;
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<cr[i];j++)
		{
			if(gd[j][i] == 0)
			{
				ok = 0;
				break;
			}
			else gd[j][i] = 1;
		}
		if(!ok)
		break;	
		if(cr[i] < h)
		{
			if(gd[cr[i]][i] == 1)
			{
				ok = 0;
				break;
			}	
			else gd[cr[i]][i] = 0;
		}	
	}
	if(!ok)
	cout<<"0\n";	
	else
	{
		ll ct = 0;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(gd[i][j] == 2)
				ct++;	
			}
		}
		std::cout<<(modexp(2, ct)%MOD)<<"\n";
	}	
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