#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 1000001
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

int ar[MV], nxt[MV];
ll arr[MV];
std::string gx[101];
ll G[101][101];

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>gx[i];	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((i != j+1) && (gx[i][j] == '0')) 
			G[i][j+1] = MOD;	
			else G[i][j+1] = (gx[i][j] - '0');
		}	
	}
	int m;
	std::cin>>m;
	for(int i=1;i<=m;i++)
	std::cin>>ar[i];
	for(int i=1;i<m;i++)
	nxt[i] = i+1;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((G[i][k] != MOD) && (G[k][j] != MOD) && (i != j))
				G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);	
			}	
		}
	}
	if(m == 2)
	{
		std::cout<<m<<"\n";
		for(int i=1;i<=m;i++)
		std::cout<<ar[i]<<" ";
		std::cout<<"\n";	
	}	
	else
	{
		int p1 = 1, p2 = 3;
		while(p2 <= m)
		{
			if(G[ar[p1]][ar[p2]] < (p2 - p1))
			{
				p1 = nxt[p1];
				if(p2 - p1 < 2)
				p2++;
			}		
			else 
			{
				nxt[p1] = p2;
				p2++;
			}	
		}
		p1 = 1;
		int ct = 0;
		while(p1 != m)
		{
			ct++;
			p1 = nxt[p1];
		}	
		p1 = 1;
		ct++;
		std::cout<<ct<<"\n";
		while(p1 != m)
		{
			std::cout<<ar[p1]<<" ";
			p1 = nxt[p1];
		}
		std::cout<<ar[p1]<<"\n";
	}	
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