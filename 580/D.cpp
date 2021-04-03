#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ins insert
#define sz size

void FLASH() {std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;

int ar[MV];
ll arr[MV];
VI ax[64];
std::set<int> G[MV];
map<PII, int> MPII;
map<int, int> lvl, par;

int bfs_visit(int s)
{
	lvl.clear();
	par.clear();
	int cyc = 1000000;
	queue<int> Q;
	Q.push(s);
	lvl[s] = 1;
	par[s] = 0;
	while(!Q.empty())
	{
		int px = Q.front();
		Q.pop();
		for(auto u : G[px])
		{
			if(lvl[u] == 0)
			{
				lvl[u] = lvl[px] + 1;
				par[u] = px;
				Q.push(u);
			}
			else if(u != par[px])
			cyc = min(cyc, lvl[px] + lvl[u] - 1);	
		}
	}
	return cyc;
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i])
		{	
			for(int j=0;j<62;j++)
			{
				if(arr[i] & (1LL<<j))
				ax[j].pb(i);		
			}
		}	
	}
	int cyc = 1000000;
	bool ok = 0;
	for(int i=0;i<62;i++)
	{
		if(ax[i].size() >= 3)
		{	
			ok = 1;
			cyc = 3;
			break;
		}		
		else if(ax[i].size() == 2)
		{
			G[ax[i][0]].ins(ax[i][1]);
			G[ax[i][1]].ins(ax[i][0]);
		}	
	}
	if(!ok)
	{
		for(int i=1;i<=n;i++)
		{	
			cyc = std::min(cyc, bfs_visit(i));
			if(cyc == 3)
			{
				ok = 1;
				break;
			}	
		}	
	}	
	if(cyc >= 1000000)
	cout<<"-1\n";
	else cout<<cyc<<"\n";
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