#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 320001
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

int ar[MV], res[MV];
ll arr[MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	for(int i=n;i<3*n;i++)
	ar[i] = ar[i-n];	
	multiset<int, greater<int> > M;
	int pt = 0;	
	for(int i=0;i<n;i++)
	{
		if(pt <= i)
		{
			M.ins(ar[i]);
			pt = i+1;
		}	
		int x = (*M.begin() + 1)/2;
		while((pt < 3*n) && (ar[pt] >= x))
		{
			M.ins(ar[pt]);
			x = (*M.begin() + 1)/2;	
			pt++;
		}
		M.erase(M.find(ar[i]));
		//cout<<pt<<" ";
		if(pt < 3*n)
		res[i] = (pt - i);
		else res[i] = -1;
	}	
	for(int i=0;i<n;i++)
	cout<<res[i]<<" ";
	cout<<"\n";
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