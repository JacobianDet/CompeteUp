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

int pt[MV][3];

int rec(vector<int> idx, int k)
{
	if(k == 3)
	return idx[0];
	//cout<<"A\n";
	map<int, VI> mp;
	for(auto u : idx)
	{	
		//cout<<u<<" ";
		mp[pt[u][k]].pb(u);
	}	
	VI a;
	for(auto u : mp)
	{
		int cx = rec(u.ss, k+1);
		if(cx != -1)
		a.pb(cx);	
	}	
	for(int i=0,j=(int)a.sz();i<j-1;i+=2)
	cout<<a[i]+1<<" "<<a[i+1]+1<<"\n";
	return (((int)a.sz() & 1) ? a.back() : -1);	
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int d=0;d<3;d++)
		cin>>pt[i][d];	
	}	
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	int x = rec(idx, 0);
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