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
map<char, int> lx;

void solve(int T)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	int o = 0, _n = 0, e = 0, r = 0, z = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'o')
		o++;
		else if(s[i] == 'n')
		_n++;
		else if(s[i] == 'e')
		e++;
		else if(s[i] == 'r')
		r++;
		else z++;	
	}	
	int onc = min(o, min(_n, e));
	for(int i=0;i<onc;i++)
	std::cout<<"1 ";
	o -= onc;
	_n -= onc;
	e -= onc;
	int znc = min(z, min(e, min(r, o)));
	for(int i=0;i<znc;i++)
	std::cout<<"0 ";
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