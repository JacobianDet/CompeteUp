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

bool memo[6][(1<<2)][2][(1<<10)], vis[6][(1<<2)][2][(1<<10)];
int ar[MV], A[6], B[6];
ll arr[MV];

struct z4
{
	int idx, dm, ld, mask;
}par[6][(1<<2)][2][(1<<10)];

bool xd(int idx, int dm, int lz, int mask)
{
	if(idx == 6)
	return 1;
	if(vis[idx][dm][lz][mask])
	return memo[idx][dm][lz][mask];
	bool ans = 0;
	if(!dm)
	{
		for(int i=A[idx];i<=B[idx];i++)
		{
			if(!(mask & (1<<i)))
			{	
				if((i == A[idx]) && (i == B[idx]))
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, dm, nlz, nm))
					{	
						par[idx][dm][lz][mask] = {idx+1, dm, nlz, nm};	
						ans |= xd(idx+1, dm, nlz, nm);
					}	
				}
				else if(i == A[idx])
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, 1, nlz, nm))
					{
						par[idx][dm][lz][mask] = {idx+1, 1, nlz, nm};
						ans |= xd(idx+1, 1, nlz, nm);
					}	
				}
				else if(i == B[idx])
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, 2, nlz, nm))
					{
						par[idx][dm][lz][mask] = {idx+1, 2, nlz, nm};
						ans |= xd(idx+1, 2, nlz, nm);
					}	
				}
				else
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, 3, nlz, nm))
					{	
						par[idx][dm][lz][mask] = {idx+1, 3, nlz, nm};
						ans |= xd(idx+1, 3, nlz, nm);
					}	
				}
			}		
		}
	}
	else if(dm == 1)
	{
		for(int i=A[idx];i<=9;i++)
		{
			if(!(mask & (1<<i)))
			{	
				if(i == A[idx])
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, 1, nlz, nm))
					{
						par[idx][dm][lz][mask] = {idx+1, 1, nlz, nm};
						ans |= xd(idx+1, 1, nlz, nm);
					}
				}
				else
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, 3, nlz, nm))
					{	
						par[idx][dm][lz][mask] = {idx+1, 3, nlz, nm};
						ans |= xd(idx+1, 3, nlz, nm);
					}	
				}
			}		
		}
	}
	else if(dm == 2)
	{
		for(int i=0;i<=B[idx];i++)
		{
			if(!(mask & (1<<i)))
			{	
				if(i == B[idx])
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, 2, nlz, nm))
					{
						par[idx][dm][lz][mask] = {idx+1, 2, nlz, nm};
						ans |= xd(idx+1, 2, nlz, nm);
					}
				}
				else
				{
					int nlz = ((lz) || (i > 0)) ? 1 : 0;
					int nm = (!nlz) ? mask : (mask | (1<<i));
					if(xd(idx+1, 3, nlz, nm))
					{	
						par[idx][dm][lz][mask] = {idx+1, 3, nlz, nm};
						ans |= xd(idx+1, 3, nlz, nm);
					}	
				}
			}		
		}
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			if(!(mask & (1<<i)))
			{	
				int nlz = ((lz) || (i > 0)) ? 1 : 0;
				int nm = (!nlz) ? mask : (mask | (1<<i));
				if(xd(idx+1, 3, nlz, nm))
				{	
					par[idx][dm][lz][mask] = {idx+1, 3, nlz, nm};
					ans |= xd(idx+1, 3, nlz, nm);
				}	
			}		
		}
	}	
	vis[idx][dm][lz][mask] = 1;
	memo[idx][dm][lz][mask] = ans;
	return ans;
}

void solve(int T)
{
	int l,r;
	cin>>l>>r;
	int ct = 6;
	while(l)
	{
		A[--ct] = l%10;
		l /= 10;
	}	
	ct = 6;
	while(r)
	{
		B[--ct] = r%10;
		r /= 10;
	}
	bool ans = xd(0, 0, 0, 0);
	if(!ans)
	cout<<"-1\n";
	else
	{
		int idx = 0, dm = 0, ld = 0, mask = 0;
		int res = 0;
		while(idx < 6)
		{
			int nidx = par[idx][dm][ld][mask].idx;
			int ndm = par[idx][dm][ld][mask].dm;
			int nld = par[idx][dm][ld][mask].ld;
			int nm = par[idx][dm][ld][mask].mask;
			int tz = mask ^ nm;
			if(!tz)
			res = 10*res + 0;
			else res = 10*res + __builtin_ctz(tz);	
			idx = nidx;
			dm = ndm;
			ld = nld;
			mask = nm;
		}
		cout<<res<<"\n";
	}	
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

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