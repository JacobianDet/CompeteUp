#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 2000002
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

int ar1[MV], ar2[MV];
ll arr[MV];
bool use[MV];

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	int ct = 0;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		ar1[ct++] = i*m + j;
	}	
	ct = 0;
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		ar2[ct++] = i*m + j;	
	}	
	for(int x=1;x<=n*m;x++)
	{
		int ct = 0;
		for(int i=0;i<n*m;i+=x)
		{	
			if(!use[ar1[i]])
			{
				use[ar1[i]] = 1;
				ct++;
			}
			if(!use[ar2[i]])
			{
				use[ar2[i]] = 1;
				ct++;
			}			
		}
		for(int i=0;i<n*m;i+=x)
		{
			use[ar1[i]] = 0;
			use[ar2[i]] = 0;
		}
		std::cout<<ct<<" ";	
	}
	std::cout<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}