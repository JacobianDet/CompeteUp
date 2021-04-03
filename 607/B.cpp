#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
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
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];

void solve(int T)
{
	string s,t;
	cin>>s>>t;
	int n1 = (int)s.sz(), n2 = (int)t.sz(), p1 = 0;
	int fc = 0;
	while((p1 < n1) && (p1 < n2))
	{
		if(s[p1] < t[p1])
		{	
			fc = 1;
			break;
		}	
		else if(s[p1 > t[p1]])
		{
			fc = 2;
			break;
		}
	}
	if(fc == 1)
	cout<<s<<"\n";
	else if((fc == 0) && (p1 < n2))
	cout<<s<<"\n";
	else if((fc == 0) && (p1 == n1) && (p1 == n2))
	cout<<"---\n";
	else
	{
		p1 = 0;
		while((p1 < n1) && (p1 < n2))
		{
			if(s[p1] > t[p1])
			break;	
			p1++;
		}
		string res = "";
		bool f = 0;
		int px1 = -1, px2 = -1;
		for(int i=0;i<p1;i++)
		{
			for(int j=p1;j<n1;j++)
			{
				if(s[i] > s[j])
				{
					px1 = i;
					px2 = j;
					f = 1;
					break;
				}
			}	
			if(f)
			break;	
		}
		if(f)
		{
			res = s;
			swap(res[px1], res[px2]);
		}
		else
		{
			for(int i=p1+1;i<n1;i++)
			{
				string k = s.substr(0, p1) + s[i] + s.substr(p1+1, i-p1-1) + s[p1] + s.substr(i+1);
				if(k < t)
				{
					f = 1;
					res = k;
				    break;
				}
			}
			for(int i=0;i<p1;i++)
			{
				string k = s.substr(0, i) + s[p1] + s.substr(i+1, p1-i-1) + s[i] + s.substr(p1+1);
				if(k < t)
				{
					f = 1;
					res = k;
				    break;
				}
			}
		}	
		if(!f)
		cout<<"---\n";
		else cout<<res<<"\n";	
	}	
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