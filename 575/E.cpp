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

void solve(int T)
{
	int b,w;
	cin>>b>>w;
	int sx = 200000, sy = 200000;
	bool col = 0;
	int mx = min(b, w);
	vector<PII> V, VX;
	for(int i=0;i<2*mx;i++)
	{
		if(!col) w--;
		else b--;
		V.pb(mp(sx, sy));
		sx++;
		col ^= 1;
	}	 	
	if((b > (2*(mx-1) + 3)) || (w > (2*(mx-1) + 3)))
	cout<<"NO\n";
	else
	{
		if(b)
		{
			for(int i=0;i<2*mx;i+=2)
			{
				int dx = V[i].ff;
				int dy = V[i].ss;
				if(!i)
				{
					VX.pb(mp(dx-1, dy));
					b--;
					if(!b)
					break;	
					VX.pb(mp(dx, dy-1));
					b--;
					if(!b)
					break;	
					VX.pb(mp(dx, dy+1));
					b--;
					if(!b)
					break;
				}	
				else
				{
					VX.pb(mp(dx, dy+1));
					b--;
					if(!b)
					break;	
					VX.pb(mp(dx, dy-1));
					b--;
					if(!b)
					break;
				}
			}
		}
		if(w)
		{
			for(int i=2*mx-1;i>0;i-=2)
			{
				int dx = V[i].ff;
				int dy = V[i].ss;
				if(i == 2*mx-1)
				{
					VX.pb(mp(dx+1, dy));
					w--;
					if(!w)
					break;	
					VX.pb(mp(dx, dy-1));
					w--;
					if(!w)
					break;	
					VX.pb(mp(dx, dy+1));
					w--;
					if(!w)
					break;	
				}	
				else
				{
					VX.pb(mp(dx, dy+1));
					w--;
					if(!w)
					break;	
					VX.pb(mp(dx, dy-1));
					w--;
					if(!w)
					break;
				}
			}
		}
		cout<<"YES\n";
		for(auto u : V)
		cout<<u.ff<<" "<<u.ss<<"\n";
		for(auto u : VX)
		cout<<u.ff<<" "<<u.ss<<"\n";	
	}	
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