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

int ar[MV];
ll arr[MV+5], az[MV];
VL amma[MV];

void solve(int T)
{
	int n,w;
	std::cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		std::cin>>ar[i];
		for(int j=0;j<ar[i];j++)
		{
			ll x;
			std::cin>>x;
			amma[i].pb(x);
		}	
	}	
	for(int i=1;i<=n;i++)
	{
		if(w <= 2*ar[i])
		{
			int gp = w - ar[i];
			int p1 = 0, p2 = 0;
			std::multiset<ll> Z;
			Z.insert(amma[i][p2]);
			while(p2 < ar[i])
			{
				if((gp < p2+1) || (*Z.rbegin() > 0))
				{	
					arr[p2+1] += *Z.rbegin();
					arr[p2+2] -= *Z.rbegin();
				}	
				if(p2 - p1 == gp)
				{
					Z.erase(Z.find(amma[i][p1]));
					p1++;
				}
				p2++;
				if(p2 < ar[i])
				Z.insert(amma[i][p2]);
			}
			p1 = ar[i]-1;
			ll ax = -1000000000000LL;
			while((ar[i] - p1) <= gp)
			{
				ax = max(ax, amma[i][p1]);
				if(ax > 0)
				{	
					arr[w-ar[i]+p1+1] += ax;
					arr[w-ar[i]+p1+2] -= ax;
				}	
				p1--;
			}	
		}
		else
		{
			ll ax1 = -1000000000000LL, ax2 = -1000000000000LL;
			for(int j=0;j<ar[i];j++)
			{
				ax1 = max(ax1, amma[i][j]);
				if(ax1 > 0)
				{	
					arr[j+1] += ax1;
					arr[j+2] -= ax1;
				}	
			}	
			for(int j=ar[i]-1;j>=0;j--)
			{
				ax2 = max(ax2, amma[i][j]);
				if(ax2 > 0)
				{	
					arr[w-ar[i]+j+1] += ax2;
					arr[w-ar[i]+j+2] -= ax2;
				}	
			}
			if(ar[i] <= w-ar[i])
			{
				if(ax1 > 0)
				{	
					arr[ar[i]+1] += ax1;
					arr[w-ar[i]+1] -= ax1;
				}	
			}	
		}	
	}	
	for(int i=1;i<=w;i++)
	{	
		arr[i] += arr[i-1];	
		std::cout<<arr[i]<<" ";
	}	
	std::cout<<"\n";
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