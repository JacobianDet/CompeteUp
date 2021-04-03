#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 2000001
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

int ar[MV], az[MV], fmv[MV], smv[MV], ST[MV][LMV];
ll arr[MV];

class sparse
{
	public: void build(int n);
			int query(int qs, int qd);
};

void sparse::build(int n)
{
	for(int i=1;i<=n;i++)
	ST[i][0] = az[i];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i + (1<<(j-1)) <= n)
			ST[i][j] = std::max(ST[i][j-1], ST[i + (1<<(j-1))][j-1]);	
		}	
	}	
	return;
}

int sparse::query(int qs, int qd)
{
	int lx = 0;
	for(lx=0;(1<<lx)<=(qd-qs+1);lx++);
	lx--;	
	int mx = std::max(ST[qs][lx], ST[qd-(1<<lx)+1][lx]);
	return mx;
}

void solve(int T)
{
	memset(fmv, -1, sizeof(fmv));
	memset(smv, -1, sizeof(smv));
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		std::cin>>az[i];
		ar[az[i]]++;
		if(i > fmv[az[i]])
		{
			smv[az[i]] = fmv[az[i]];
			fmv[az[i]] = i;
		}	
		else if((i <= fmv[az[i]]) && (i > smv[az[i]]))
		smv[az[i]] = i;	
	}	
	sparse Z;
	Z.build(n);
	for(int i=0;i<LMV;i++)
	{
		for(int mask=MV-1;mask>=0;mask--)
		{
			if(mask & (1<<i))
			{
				ar[mask ^ (1<<i)] += ar[mask];
				int m1 = 0, m2 = 0;
				if(fmv[mask] > fmv[mask ^ (1<<i)])
				{
					m1 = fmv[mask];
					m2 = max(smv[mask], fmv[mask ^ (1<<i)]);
				}
				else if(fmv[mask] < fmv[mask ^ (1<<i)])
				{
					m1 = fmv[mask ^ (1<<i)];
					m2 = max(smv[mask ^ (1<<i)], fmv[mask]);
				}
				else
				{
					m1 = fmv[mask];
					m2 = max(smv[mask], smv[mask ^ (1<<i)]);
				}
				fmv[mask ^ (1<<i)] = m1;
				smv[mask ^ (1<<i)] = m2;
			}	
		}	
	}	
	int vx = 0;
	/*for(int i=0;i<MV;i++)
	{
		if(ar[i] >= 2)
		{
			if(smv[i] > 1)
			vx = std::max(vx, (Z.query(1, smv[i]-1) | i));
		}
	}*/
	for(int i=1;i<=n;i++)
	{
		int w = 0;
		if((ar[w] >= 2) && (smv[w] > i))
		vx = std::max(vx, az[i]);	
		for(int j=LMV-1;j>=0;j--)
		{
			if(!(az[i] & (1<<j)))
			{
				if((ar[w | (1<<j)] >= 2) && (smv[w | (1<<j)] > i))
				{	
					vx = std::max(vx, az[i] | (w | (1<<j)));
					w |= (1<<j);
				}		
			}	
		}
	}
	std::cout<<vx<<"\n";
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