#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ins insert
#define size sz

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

int ar[MV];
ll arr[MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	ll tc = 0, c1 = 0, cm1 = 0, ceq = 0, etc = 0;
	for(int i=0;i<n;i++)
	{
		int m1 = abs(1 - ar[i]);
		int m2 = abs(-1 - ar[i]);
		if(m1 < m2)
		{	
			tc += m1;
			c1++;	
		}
		else if(m2 < m1)
		{
			tc += m2;
			cm1++;
		}
		else
		{
			etc += m1;
			ceq++;
		}	
	}
	if((cm1 & 1) && !ceq)
	tc += 2;	
	cout<<(tc + etc)<<"\n";
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