#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
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
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];
/*int A[65], B[65];
ll memo[65][4];

ll xd(int ix, int mask)
{
	if(ix == 65)
	return 0;
	if(memo[ix][mask] != -1)
	return memo[ix][mask];
	ll res = 0;
	if(!mask)
	{
		for(int i=A[ix];i<=B[ix];i++)
		{	
			if((i == A[ix]) && (i == B[ix]))
			res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 0));
			else if(i == A[ix])
			res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 1));
			else if(i == B[ix])
			res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 2));
			else res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 3));
		}		
	}
	else if(mask == 1)
	{
		for(int i=A[ix];i<=1;i++)
		{
			if(i == A[ix])
			res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 1));
			else res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 3));
		}	
	}
	else if(mask == 2)
	{
		for(int i=0;i<=B[ix];i++)
		{
			if(i == B[ix])
			res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 2));
			else res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 3));
		}
	}
	else
	{
		for(int i=0;i<=1;i++)
		res = max(res, (1LL<<(64-ix)) * i + xd(ix+1, 3));	
	}
	memo[ix][mask] = res;
	return res;
}*/

void solve(int T)
{
	/*memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(memo, -1, sizeof(memo));*/
	ll l,r;
	cin>>l>>r;
	/*int ct = 64;
	while(l)
	{
		A[ct--] = (l & 1);
		l >>= 1;
	}	
	ct = 64;
	while(r)
	{
		B[ct--] = (r & 1);
		r >>= 1;
	}
	ll res = xd(0, 0);*/
	ll x = r;
	ll px = -1;
	for(int i=60;i>=0;i--)
	{
		if((l & (1LL<<i)) != (r & (1LL<<i)))
		{
			px = i;
			break;
		}
	}
	if(px != -1)
	x |= ((1LL<<(px+1))-1);
	cout<<x<<"\n";
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