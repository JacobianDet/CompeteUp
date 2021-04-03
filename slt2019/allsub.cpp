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

int ar[MV], ct1[26], ct2[26];
ll arr[MV];

void solve(int T)
{
	string s,r;
	std::cin>>s>>r;
	memset(ct1, 0, sizeof(ct1));
	memset(ct2, 0, sizeof(ct2));
	for(int i=0;i<s.sz();i++)
	ct1[s[i]-'a']++;
	for(int i=0;i<r.sz();i++)
	ct2[r[i]-'a']++;
	bool ok = 1;
	for(int i=0;i<26;i++)
	{
		if(ct2[i] < ct1[i])
		{
			ok = 0;
			break;
		}	
	}	
	if(!ok)
	cout<<"Impossible\n";
	else
	{
		string res;
		for(int i=0;i<26;i++)
		ct2[i] -= ct1[i];
		int idx = 0, pix = 26;
		for(int i=0;i<26;i++)
		{
			int vx = s[idx]-'a';
			if(i < vx)
			{
				for(int j=0;j<ct2[i];j++)
				res += (char)(i+'a');	
			}
			else if(i > vx)
			{
				res += s;
				pix = i;
				break;
			}	
			else
			{
				while((idx < s.sz()) && (s[idx]-'a' == i))
				idx++;
				if((idx == s.sz()) || (s[idx]-'a' < i))
				{
					res += s;
					pix = i;
					break;
				}	
				else
				{
					for(int j=0;j<ct2[i];j++)
					res += (char)(i+'a');
					res += s;
					pix = i+1;
					break;
				}	
			}
		}
		for(int i=pix;i<26;i++)
		{
			for(int j=0;j<ct2[i];j++)
			res += (char)(i+'a');
		}	
		cout<<res<<"\n";
	}	
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