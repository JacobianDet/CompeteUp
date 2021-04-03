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

int ar[MV], l[MV+1], r[MV+1], ans[MV+1];
ll arr[MV];

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>ar[i];
	for(int i=1;i<=n;i++)
	{
		l[i] = 0;
		r[i] = n+1;
	}	
	std::stack<int> S;
	for(int i=1;i<=n;i++)
	{
		while(!S.empty() && (ar[S.top()] >= ar[i]))
		S.pop();
		if(S.empty())
		l[i] = 0;
		else l[i] = S.top();
		S.push(i);
	}	
	while(!S.empty())
	S.pop();	
	for(int i=n;i>0;i--)
	{
		while(!S.empty() && (ar[S.top()] >= ar[i]))
		S.pop();
		if(S.empty())
		r[i] = n+1;
		else r[i] = S.top();
		S.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		int lx = r[i] - l[i] - 1;
		ans[lx] = std::max(ans[lx], ar[i]);
 	}	
 	for(int i=n;i>0;i--)
 	ans[i] = std::max(ans[i], ans[i+1]);	
 	for(int i=1;i<=n;i++)
 	std::cout<<ans[i]<<" ";
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