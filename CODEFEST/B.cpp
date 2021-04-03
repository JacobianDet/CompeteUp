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
MII ctx;
std::set<int> Z;

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>ar[i];
	int mx = 100000;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			ctx[ar[j]]++;
			Z.insert(ar[j]);
		}
		for(int j=i;j<=n;j++)
		{
			ctx[ar[j]]--;
			if(!ctx[ar[j]])
			Z.erase(ar[j]);
			if(Z.sz() == (n-j+i-1))
			mx = std::min(mx, j-i+1);	
		}		
	}
	for(int j=1;j<=n;j++)
	{	
		ctx[ar[j]]++;
		Z.insert(ar[j]);
	}
	if(Z.sz() == n)
	mx = 0;
	cout<<mx<<"\n";	
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