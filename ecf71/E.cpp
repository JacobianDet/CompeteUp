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
	ll ans = 0;
	std::cout<<"? ";
	for(int i=0;i<100;i++)
	std::cout<<(((27+i)*1LL)<<7)<<" ";
	std::cout<<endl;
	ll x;
	std::cin>>x;
	for(int i=0;i<7;i++)
	ans += (x & (1LL<<i));
	std::cout<<"? ";
	for(int i=0;i<100;i++)
	std::cout<<(27+i)<<" ";
	std::cout<<endl;
	std::cin>>x;
	for(int i=7;i<14;i++)
	ans += (x & (1LL<<i));	
	std::cout<<"! "<<ans<<endl;
	return;	
}

int main(void)
{
	//FLASH();
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}