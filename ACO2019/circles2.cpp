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
	ld x1, y1, x2, y2, r1, r2;
	std::cin>>x1>>y1>>r1>>x2>>y2>>r2;
	ld rs = r1 + r2, rd = abs(r1 - r2);
	ld sq = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	SETF();
	if(sq >= rs)
	{
		cout<<"YES\n";
		cout<<setprecision(8)<<x1<<" "<<setprecision(8)<<y1<<"\n";
	}	
	else if((r1 <= r2) && (sq <= rd))
	cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		if(x1 != x2)
		{
			ld ang = atan((ld)(y1 - y2)/(ld)(x1 - x2));
			if(ang < asin(1))
			{
				if(x1 - x2 > 0)
				{
					ld xr = x1 + r1 * cos(ang);
					ld yr = y1 + r1 * sin(ang);
					cout<<setprecision(8)<<xr<<" "<<setprecision(8)<<yr<<"\n";
				}	
				else
				{
					ld xr = x1 - r1 * cos(ang);
					ld yr = y1 - r1 * sin(ang);
					cout<<setprecision(8)<<xr<<" "<<setprecision(8)<<yr<<"\n";
				}
			}
			else
			{
				if(x1 - x2 < 0)
				{
					ld xr = x1 + r1 * cos(ang);
					ld yr = y1 + r1 * sin(ang);
					cout<<setprecision(8)<<xr<<" "<<setprecision(8)<<yr<<"\n";
				}	
				else
				{
					ld xr = x1 - r1 * cos(ang);
					ld yr = y1 - r1 * sin(ang);
					cout<<setprecision(8)<<xr<<" "<<setprecision(8)<<yr<<"\n";
				}
			}	
		}
		else
		{
			if(y1 - y2 > 0)
			{
				ld xr = x1;
				ld yr = y1 + r1;
				cout<<setprecision(8)<<xr<<" "<<setprecision(8)<<yr<<"\n";
			}	
			else
			{
				ld xr = x1;
				ld yr = y1 - r1;
				cout<<setprecision(8)<<xr<<" "<<setprecision(8)<<yr<<"\n";
			}
		}
	}
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