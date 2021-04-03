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
string rf[3];

void solve(int T)
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(!i)
			{
				if(!(j%3))
				rf[i] += 'R';
				else if((j%3) == 1)
				rf[i] += 'G';
				else rf[i] += 'B';	
			}	
			else if(i == 1)
			{
				if(!(j%3))
				rf[i] += 'G';
				else if((j%3) == 1)
				rf[i] += 'B';
				else rf[i] += 'R';
			}
			else
			{
				if(!(j%3))
				rf[i] += 'B';
				else if((j%3) == 1)
				rf[i] += 'R';
				else rf[i] += 'G';
			}
		}	
	}
	int mndf = 200001;
	for(int i=0;i<3;i++)
	{
		int df = 0;
		for(int j=0;j<k;j++)
		{
			if(s[j] != rf[i][j])
			df++;	
		}	
		int fl = 0;
		mndf = min(mndf, df);
		for(int j=k;j<n;j++)
		{
			if(s[j-k] != rf[(i+fl)%3][0])
			df--;
			fl++;
			fl %= 3;	
			if(s[j] != rf[(i+fl)%3][k-1])
			df++;
			mndf = min(mndf, df);	
		}	
	}
	cout<<mndf<<"\n";
	for(int i=0;i<3;i++)
	rf[i] = "";
	return;	
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	while(T--)
	solve(T);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}