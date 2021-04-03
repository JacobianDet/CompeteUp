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
	std::string s;
	std::cin>>s;
	std::stack<int> S;
	for(int i=0;i<n;i++)
	{
		if(S.empty())
		S.push(i);
		else if(s[i] == ')' && s[S.top()] == '(')
		S.pop();
		else S.push(i);	
	}
	if(S.size() == 0)
	std::cout<<"Yes\n";
	else if(S.size() != 2)
	std::cout<<"No\n";	
	else
	{
		int oc = 0, cc = 0;
		while(!S.empty())
		{
			int x = S.top();
			S.pop();
			if(s[x] == '(')
			oc++;
			else cc++;	
		}	
		if(oc == cc)
		std::cout<<"Yes\n";
		else std::cout<<"No\n";	
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