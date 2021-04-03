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
	int n;
	std::cin>>n;
	std::string s,t;
	std::cin>>s>>t;
	std::string z[6] = {"abc", "acb", "bca", "bac", "cab", "cba"};
	int ok = -1;
	int pos = -1;
	for(int i=0;i<6;i++)
	{
		if((z[i].substr(0, 2) != s) && (z[i].substr(0, 2) != t) && (z[i].substr(1, 2) != s) && (z[i].substr(1, 2) != t))
		{
			std::string y = z[i].substr(2, 1) + z[i].substr(0, 1);
			if((y != s) && (y != t))
			{
				ok = 0;
				pos = i;
				break;
			}
			else if(("aa" != s) && ("aa" != t) && ("bb" != s) && ("bb" != t) && ("cc" != s) && ("cc" != t))
			{
				ok = 1;
				pos = i;
				break;
			}	
		}		
	}
	if(ok == -1)
	std::cout<<"NO\n";
	else
	{
		std::cout<<"YES\n";
		if(!ok)
		{
			for(int i=0;i<n;i++)
			std::cout<<z[pos];
			std::cout<<"\n";	
		}	
		else
		{
			for(int i=0;i<n;i++)
			std::cout<<z[pos][0];
			for(int i=0;i<n;i++)
			std::cout<<z[pos][1];
			for(int i=0;i<n;i++)
			std::cout<<z[pos][2];
			std::cout<<"\n";	
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