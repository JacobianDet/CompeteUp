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
map<string, int> sd1;
map<string, vector<ll> > sd2;

void solve(int T)
{
	int k,n;
	cin>>k>>n;
	for(int i=0;i<k;i++)
	{
		string s;
		ll v;
		std::cin>>s>>v;
		sd2[s].pb(v);
	}	
	for(auto it = sd2.begin();it != sd2.end();it++)
	sort(sd2[it->ff].rbegin(), sd2[it->ff].rend());
	ll ans = 0, zf1 = 0, zf2 = 0;
	for(auto u : sd2)
	{
		if(!sd1[u.ff])
		{	
			string x = u.ff;
			string y = x;
			reverse(y.begin(), y.end());
			if(x != y)
			{
				for(int i=0;i<min(sd2[x].sz(), sd2[y].sz());i++)
				{
					if((sd2[x][i] + sd2[y][i]) > 0)
					ans += (sd2[x][i] + sd2[y][i]);
					else break;	
				}	
				sd1[x] = 1;
				sd1[y] = 1;
			}	
		}	
	}
	for(auto u : sd2)
	{
		string x = u.ff;
		string y = x;
		reverse(y.begin(), y.end());
		if(x == y)
		{	
			int st = 0;
			for( ;st+1<sd2[x].sz();st+=2)
			{
				if((sd2[x][st] + sd2[x][st+1]) > 0)
				ans += (sd2[x][st] + sd2[x][st+1]);
				else break;	
			}
			sd1[x] = st;	
		}	
	}
	for(auto u : sd2)
	{
		string x = u.ff;
		string y = x;
		reverse(y.begin(), y.end());
		if(x == y)
		{	
			int st = sd1[x];
			if((st >= 0) && (st < sd2[x].sz()) && (sd2[x][st] > 0))
			zf1 = max(zf1, sd2[x][st]);
		}	
	}
	for(auto u : sd2)
	{
		string x = u.ff;
		string y = x;
		reverse(y.begin(), y.end());
		if(x == y)
		{	
			int st = sd1[x];
			if(st > 0)
			zf2 = min(zf2, sd2[x][st-1]);
		}	
	}
	ans += max(zf1, -zf2);	
	cout<<ans<<"\n";
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