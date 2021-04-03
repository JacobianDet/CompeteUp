#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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

int ar[MV], vis[3][102];
PPII sx[26];
bool memo[3][102];
std::string G[3];
ll arr[MV];
int n,k;

bool BALLIA(int r, int c, int T)
{
	if(c == n)
	return 1;
	if(vis[r][c] == T)
	return memo[r][c];
	bool ans = 0, ok = 1;
	for(int i=0;i<26;i++)
	{
		int t1r = sx[i].ff.ff;
		int t1c = sx[i].ff.ss;
		int len = sx[i].ss;
		t1c -= 2*(c - 1);
		if((t1r == r) && (t1c <= c) && (t1c + len > c))
		{
			ok = 0;
			break;
		}	
		if((t1r == r) && (t1c <= c+1) && (t1c + len > c+1))
		{
			ok = 0;
			break;
		}	
	}		
	if(ok)	
	{
		bool l1 = 1, l2 = 1;
		for(int i=0;i<26;i++)
		{
			int t1r = sx[i].ff.ff;
			int t1c = sx[i].ff.ss;
			int len = sx[i].ss;
			t1c -= 2*(c - 1);
			if((t1r == r-1) && (t1c <= c+1) && (t1c + len > c+1))
			l1 = 0;
			if((t1r == r+1) && (t1c <= c+1) && (t1c + len > c+1))
			l2 = 0;	
		}	
		if(r-1 < 0)
		l1 = 0;
		if(r+1 > 2)
		l2 = 0;	
		ans |= BALLIA(r, c+1, T);
		if(l1)
		ans |= BALLIA(r-1, c+1, T);
		if(l2)
		ans |= BALLIA(r+1, c+1, T);	
	}
	vis[r][c] = T;
	memo[r][c] = ans;
	return ans;
}

void solve(int T)
{
	std::cin>>n>>k;
	for(int i=0;i<3;i++)
	std::cin>>G[i];
	int pr = -1;	
	for(int i=0;i<26;i++)
	sx[i] = mp(mp(-1, -1), -1);	
	for(int i=0;i<3;i++)
	{
		int ctl = 0, us = -1;
		for(int j=0;j<n;j++)
		{
			if(G[i][j] >= 'A' && G[i][j] <= 'Z')
			{
				if(sx[G[i][j] - 'A'].ff == mp(-1, -1))
				{	
					sx[G[i][j] - 'A'].ff.ff = i;
					sx[G[i][j] - 'A'].ff.ss = j+1;
				}
				if(G[i][j] - 'A' == us)	
				ctl++;
				else ctl = 1;
				sx[G[i][j] - 'A'].ss = ctl;
				us = G[i][j] - 'A';
			}	
			else if(G[i][j] == 's')
			{	
				ctl = 0;
				us = -1;
				pr = i;
			}	
			else 
			{
				us = -1;
				ctl = 0;
			}		
		}
	}	
	bool res = BALLIA(pr, 1, T);
	if(res)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return;	
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T+1);
	return 0;
}