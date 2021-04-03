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
int vis[2][MV][7];
bool memo[2][MV][7];
string s1,s2;
int n;

bool xd(int rx, int cx, int pt, int T)
{
	if((rx == 0) && (cx == n))
	return 0;	
	else if((rx == 1) && (cx == n))
	return 1;
	if(vis[rx][cx][pt] == T)
	return memo[rx][cx][pt];
	bool ans = 0;
	if(!rx)
	{
		if(s1[cx] == '1' || s1[cx] == '2')
		{
			if(!pt)
			ans |= xd(rx, cx+1, 2, T);	
			else if(pt == 2)
			ans |= xd(rx, cx+1, 2, T);
			else if(pt == 3)
			ans |= xd(rx, cx+1, 2, T);

		}
		else
		{
			if(!pt)
			ans |= xd(rx+1, cx, 4, T);	
			else if(pt == 2)
			ans |= xd(rx+1, cx, 4, T);
			else if(pt == 3)
			ans |= xd(rx+1, cx, 4, T);
			else if(pt == 5)
			ans |= xd(rx, cx+1, 3, T);	

		}
	}
	else 
	{
		if(s2[cx] == '1' || s2[cx] == '2')
		{
			if(pt == 2)
			ans |= xd(rx, cx+1, 2, T);
			else if(pt == 6)
			ans |= xd(rx, cx+1, 2, T);	
		}	
		else
		{
			if(pt == 2)
			ans |= xd(rx-1, cx, 5, T);
			else if(pt == 4)
			ans |= xd(rx, cx+1, 6, T);
			else if(pt == 6)
			ans |= xd(rx-1, cx, 5, T);	
		}
	}
	vis[rx][cx][pt] = T;
	memo[rx][cx][pt] = ans;
	return ans;	
}

void solve(int T)
{
	cin>>n;
	cin>>s1>>s2;
	bool ans = xd(0, 0, 0, T);
	cout<<(ans ? "YES" : "NO")<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<200001;j++)
		{	
			for(int k=0;k<7;k++)
			vis[i][j][k] = 100001;
		}		
	}	
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