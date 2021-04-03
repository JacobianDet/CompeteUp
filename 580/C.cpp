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
	if(!(n & 1))
	cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		ar[0] = 1;
		for(int i=1;i<n;i++)
		{	
			if(i & 1)
			ar[i] = ar[i-1] + 3;
			else ar[i] = ar[i-1] + 1;
		}
		for(int i=n;i<2*n;i++)
		{	
			if(!((i-n) & 1))
			ar[i] = ar[i-n] + 1;
			else ar[i] = ar[i-n] - 1;
		}
		for(int i=0;i<2*n;i++)
		cout<<ar[i]<<" ";
		cout<<"\n";			
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