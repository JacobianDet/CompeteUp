#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
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
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];

void solve(int T)
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int bc = 0, wc = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'B')
		bc++;
		else wc++;	
	}
	if((bc & 1) && (wc & 1))
	cout<<"-1\n";
	else
	{
		int ct = 0;
		VI dz;
		for(int i=0;i<n-1;i++)
		{
			if(s[i] == 'B')
			{
				ct++;
				dz.pb(i+1);
				s[i] = 'W';
				s[i+1] = ((s[i+1] == 'W') ? 'B' : 'W');
			}	
		}
		if(s[n-1] == 'B')
		{
			for(int i=0;i<n-1;i+=2)
			{
				ct++;
				dz.pb(i+1);
			}
		}
		cout<<ct<<"\n";
		if(ct > 0)
		{
			for(auto u : dz)
			cout<<u<<" ";
			cout<<"\n";	
		}
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