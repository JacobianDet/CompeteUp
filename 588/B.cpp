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

int ar[MV];
ll arr[MV];

void solve(int T)
{
	int n,k;
	std::cin>>n>>k;
	std::string s;
	std::cin>>s;
	if(n == 1)
	{	
		if(!k)
		std::cout<<s<<"\n";	
		else std::cout<<"0\n";
	}	
	else
	{
		for(int i=0,j=0;(i<n && j<k);i++)
		{
			if(!i)
			{
				if(s[i] != '1')
				{
					s[i] = '1';
					j++;
				}	
			}
			else if(s[i] != '0')
			{
				s[i] = '0';
				j++;
			}
		}
		std::cout<<s<<"\n";
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