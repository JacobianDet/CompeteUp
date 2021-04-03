#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
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
std::string s;

bool cmpz1(std::string& A, std::string& B)
{
	bool ok = 0;
	for(int i=0;i<(int)A.size();i++)
	{
		if(A[i] == '0' && B[i] == '1')
		{
			ok = 1;
			break;
		}	
		else if(B[i] == '0' && A[i] == '1')
		{
			ok = 0;
			break;
		}
	}
	return ok;	
}


bool cmpz2(std::string& A, std::string& B)
{
	bool ok = 0;
	for(int i=0;i<(int)A.size();i++)
	{
		if(A[i] == '0' && B[i] == '1')
		{
			ok = 1;
			break;
		}	
		else if(B[i] == '0' && A[i] == '1')
		{
			ok = 0;
			break;
		}
		if(i == (int)A.size()-1)
		ok = 1;	
	}
	return ok;	
}

int bs2(void)
{
	int lo = 0;
	int hi = 100;
	int n = (int)s.size();
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		int x = (mid<<1);
		std::string z, y;
		y = s;
		z += '1';
		for(int i=0;i<x;i++)
		z += '0';
		if(n < x+1)
		{
			std::string t;
			for(int i=0;i<(x+1-n);i++)
			t += '0';
			y = t + y;	
		}
		else 
		{
			std::string t;
			for(int i=0;i<(n-x-1);i++)
			t += '0';
			z = t + z;
		}	
		//std::cout<<lo<<" "<<hi<<" "<<mid<<" "<<z<<" "<<y<<" "<<cmpz(z, y)<<"\n";
		if(cmpz1(z, y))
		lo = mid;
		else hi = mid-1;	
	}
	std::string on;
	for(int i=0;i<n-1;i++)
	on += '0';
	on += '1';	
	if(!lo && cmpz2(s, on))
	lo--;	
	return lo;
}

void solve(int T)
{
	std::cin>>s;
	int ans = bs2();
	std::cout<<ans+1<<"\n";
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