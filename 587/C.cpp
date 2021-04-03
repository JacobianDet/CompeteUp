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

int ar[MV];
ll arr[MV];

void solve(int T)
{
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	std::cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
	if(x1 >= x3 && x2 <= x4 && y1 >= y3 && y2 <= y4)
	std::cout<<"NO\n";
	else if(x1 >= x5 && x2 <= x6 && y1 >= y5 && y2 <= y6)
	std::cout<<"NO\n";
	else
	{
		int tx1 = max(x3, x5);
		int tx2 = min(x4, x6);
		int ty1 = max(y3, y5);
		int ty2 = min(y4, y6);
		if((tx1 > tx2) || (ty1 > ty2))
		std::cout<<"YES\n";	
		else 
		{
			int zx1 = max(x1, x3);
			int zx2 = min(x2, x4);
			int zy1 = max(y1, y3);
			int zy2 = min(y2, y4);
			ll ar1 = 0, ar2 = 0, ari = 0;
			if((zx1 <= zx2) && (zy1 <= zy2))
			ar1 = (1LL*zx2 - zx1) * (1LL*zy2 - zy1);
			int cx1 = max(x1, x5);
			int cx2 = min(x2, x6);
			int cy1 = max(y1, y5);
			int cy2 = min(y2, y6);
			if((cx1 <= cx2) && (cy1 <= cy2))
			ar2 = (1LL*cx2 - cx1) * (1LL*cy2 - cy1);
			int xx1 = max(x1, tx1);
			int xx2 = min(x2, tx2);
			int xy1 = max(y1, ty1);
			int xy2 = min(y2, ty2);
			if((xx1 <= xx2) && (xy1 <= xy2))
			ari = (1LL*xx2 - xx1) * (1LL*xy2 - xy1);
			ar1 += (ar2 - ari);
			ll ax = (1LL*x2 - x1) * (1LL*y2 - y1);
			if(ar1 == ax)
			std::cout<<"NO\n";
			else std::cout<<"YES\n";	
		}
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