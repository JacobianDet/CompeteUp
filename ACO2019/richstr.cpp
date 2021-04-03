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
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=2;i<=n;i++)
	{
		if(i > 2)
		{
			if(s[i-1] == s[i-2] || s[i-1] == s[i-3])
			ar[i] = ar[i-1] + 1;
			else ar[i] = ar[i-1];
		}
		else
		{
			if(s[i-1] == s[i-2])
			ar[i] = ar[i-1] + 1;
			else ar[i] = ar[i-1];
		}		
	}	
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int pz = 0;
		if(r-l+1 >= 2)
		{
			pz = ar[r] - ar[l+1];
			if(s[l-1] == s[l])
			pz++;
		}
 		if(((r-l+1) >= 3) && pz)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
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