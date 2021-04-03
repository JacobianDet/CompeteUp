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
VI emp[50001];

void solve(int T)
{	
	int n,s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		for(int j=0;j<c;j++)
		{
			int sk;
			cin>>sk;
			emp[i].pb(sk);
		}
	}
	for(int i=0;i<n;i++)
	sort(emp[i].begin(), emp[i].end());
	ll ct = 0;
	for(int i=0;i<n;i++)
	{
		MII m1;
		for(int k=0;k<emp[i].sz();k++)
		m1[emp[i][k]] = 1;
		for(int j=i+1;j<n;j++)
		{
			bool ok1 = 1, ok2 = 1;
			MII m2;
			for(int k=0;k<emp[j].sz();k++)
			m2[emp[j][k]] = 1;
			for(auto u : m1)
			{
				if(!m2[u.ff])
				{	
					m2.erase(u.ff);
					ok1 = 0;
					break;
				}		
			}	
			for(auto u : m2)
			{
				if(!m1[u.ff])
				{
					m1.erase(u.ff);
					ok2 = 0;
					break;
				}
			}
			//cout<<i<<" "<<j<<" "<<ok1<<" "<<ok2<<"\n";
			if(!ok1)
			ct++;
			if(!ok2)
			ct++;	
		}
	}
	cout<<"Case #"<<T<<": "<<ct<<"\n";
	for(int i=0;i<n;i++)
	emp[i].clear();	
	return;	
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
/*
#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif
*/
	for(int _=1;_<=T;_++)
	solve(_);
/*
#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif
*/
	return 0;
}