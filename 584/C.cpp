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

int ar[MV], col[MV];
ll arr[MV];
char zx[MV];

void solve(int T)
{
	int n;
	string s;
	std::cin>>n>>s;
	for(int i=0;i<n;i++)
	zx[i] = 'A';	
	std::stack<int> S;
	int px = 0;
	char lx = 'A';
	for(int i=0;i<n;i++)
	{
		if(S.empty())
		S.push(i);	
		else
		{
			while(!S.empty() && (s[S.top()] <= s[i]))
			S.pop();
			if(!S.empty())
			{
				if(!px)
				{
					lx = s[S.top()];
					zx[i] = s[i];
					px++;
				}
				else if((px == 1) && (s[S.top()] >= lx))
				zx[i] = s[i];
				else
				{
					px++;
					break;
				}
				S.push(i);
			}
			else S.push(i);	
		}
		col[i] = 1;
	}
	if(px == 2)
	std::cout<<"-\n";
	else 
	{
		char zlx = 'A';
		for(int i=n-1;i>=0;i--)
		{	
			if(i == n-1)
			zlx = zx[i];
			if((zx[i] != 'A') && (zx[i] > zlx))
			{	
				px = 2;
				break;
			}	
			else zlx = min(zlx, zx[i]);
			if((s[i] > zlx) || (s[i] > lx))
			col[i] = 2;	
		}	
		if(px == 2)
		std::cout<<"-\n";	
		else
		{
			for(int i=0;i<n;i++)
			std::cout<<col[i];
			std::cout<<"\n";
		}		
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