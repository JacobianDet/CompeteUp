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

int bs1(int n)
{
	int lo = 1;
	int hi = *max_element(ar, ar+n);
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		int ct = 0;
		for(int i=0;i<n;i++)
		ct += (ar[i] - mid);
		if(ct <= 0)
		hi = mid;
		else lo = mid + 1;	
	}
	int ct = 0;
	for(int i=0;i<n;i++)
	ct += (ar[i] - lo);
	if(ct < 0)
	return -1;
	else return lo;	
}

void solve(int T)
{
	int n;
	std::cin>>n;
	while(n != -1)
	{
		for(int i=0;i<n;i++)
		std::cin>>ar[i];
		int mxv = bs1(n);
		if(mxv == -1)
		std::cout<<"-1\n";
		else
		{	
			int ct = 0;
			for(int i=0;i<n;i++)
			ct += ((ar[i] > mxv) ? (ar[i] - mxv) : 0);
			std::cout<<ct<<"\n";
		}
		std::cin>>n;		
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