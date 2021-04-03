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

int ar[MV], br[MV];
ll arr[MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	cin>>br[i];
	bool ok = 1;
	PII pz;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ok = 1;
			int x = ar[i] + br[j];
			for(int k=0;k<n;k++)
			{
				if(x == ar[k])
				{
					ok = 0;
					break;
				}
			}
			for(int k=0;k<m;k++)
			{
				if(x == br[k])
				{
					ok = 0;
					break;
				}
			}
			if(ok)
			{
				pz = mp(ar[i], br[j]);
				break;
			}	
		}
		if(ok)
		break;	
	}
	if(ok)
	cout<<pz.ff<<" "<<pz.ss<<"\n";	
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