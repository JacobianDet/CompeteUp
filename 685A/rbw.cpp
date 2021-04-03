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

int A[11], B[11], ar[MV];
ll arr[MV];
ll memo[12][12][2][2][2][2][2][2][2][2][2];

ll BALLIA(int i, int j, bool mask1, bool mask2, bool u0, bool u1, bool u2, bool u3, bool u4, bool u5, bool u6)
{
	if((i == 11) && (j == 11))
	return 1;
	if(memo[i][j][mask1][mask2][u0][u1][u2][u3][u4][u5][u6] != -1)
	return memo[i][j][mask1][mask2][u0][u1][u2][u3][u4][u5][u6];
	ll ans = 0;
	bool ux[] = {u0, u1, u2, u3, u4, u5, u6};
	if(i < 11)
	{	
		if(!mask1)
		{
			for(int k=0;k<=A[i];k++)
			{ 
				if((k == A[i]) && !ux[k])
				{	
					ux[k] |= 1;
					ans += BALLIA(i+1, j, mask1, mask2, ux[0], ux[1], ux[2], ux[3], ux[4], ux[5], ux[6]);
					ux[k] ^= 1;
				}
				else if((k < A[i]) && !ux[k])
				{
					ux[k] |= 1;
					ans += BALLIA(i+1, j, mask1 | 1, mask2, ux[0], ux[1], ux[2], ux[3], ux[4], ux[5], ux[6]);
					ux[k] ^= 1;
				}	 	
			}	
		}
		else
		{
			for(int k=0;k<7;k++)
			{
				if(!ux[k])
				{	
					ux[k] |= 1;
					ans += BALLIA(i+1, j, mask1, mask2, ux[0], ux[1], ux[2], ux[3], ux[4], ux[5], ux[6]);
					ux[k] ^= 1;
				}
			}	
		}
	}
	else
	{
		if(!mask2)
		{
			for(int k=0;k<=B[j];k++)
			{ 
				if((k == B[j]) && !ux[k])
				{	
					ux[k] |= 1;
					ans += BALLIA(i, j+1, mask1, mask2, ux[0], ux[1], ux[2], ux[3], ux[4], ux[5], ux[6]);
					ux[k] ^= 1;
				}
				else if((k < B[j]) && !ux[k])
				{
					ux[k] |= 1;
					ans += BALLIA(i, j+1, mask1, mask2 | 1, ux[0], ux[1], ux[2], ux[3], ux[4], ux[5], ux[6]);
					ux[k] ^= 1;
				}	 	
			}	
		}
		else
		{
			for(int k=0;k<7;k++)
			{
				if(!ux[k])
				{	
					ux[k] |= 1;
					ans += BALLIA(i, j+1, mask1, mask2, ux[0], ux[1], ux[2], ux[3], ux[4], ux[5], ux[6]);
					ux[k] ^= 1;
				}
			}	
		}
	}
	memo[i][j][mask1][mask2][u0][u1][u2][u3][u4][u5][u6] = ans;
	return ans;	
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	ll n, m;
	std::cin>>n>>m;
	n--;
	m--;
	ll z1 = n, z2 = m;
	int cx = 10;
	while(z1)
	{
		A[cx--] = (z1%7);
		z1 /= 7; 
	}
	if(cx == 10)
	cx--;	
	int cy = 10;
	while(z2)
	{
		B[cy--] = (z2%7);
		z2 /= 7;
	}
	if(cy == 10)
	cy--;	
	ll ans = BALLIA(cx+1, cy+1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	std::cout<<ans<<"\n";
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