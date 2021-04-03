#include <bits/stdc++.h>
#define pb push_back
#define ep emplace_back
#define mp std::make_pair
#define first ff
#define second ss

typedef long long ll;
typedef long double ld;
typedef std::string stx;
typedef std::vector<int> VI;
typedef std::vector<ll> VL;
typedef std::vector<stx> VS;
typedef std::vector<char> VC;
typedef std::pair<int, int> PII;
typedef std::pair<int, ll> PIL;
typedef std::pair<ll, ll> PLL;
typedef std::pair<char, char> PCC;
typedef std::pair<int, char> PIC;
typedef std::pair<stx, int> PSI;
typedef std::set<int> SX;
typedef std::set<ll> SXL;
typedef std::multiset<ll> MSXL;
typedef std::set<double> SXD;
typedef std::set<ld> SXLD;
typedef std::set<stx> SXS;
typedef std::map<int, int> MXII;
typedef std::map<int, ll> MXIL;
typedef std::map<ll, ll> MXLL;
typedef std::map<char, char> MXCC;
typedef std::map<int, char> MXIC;
typedef std::map<stx, int> MXSI;

const int MOD = 1000000007;

PII NE[8] = {{0, -1}, {-1, -1}, {1, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, 0}, {-1, 0}};

void FLASH(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

/*int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

ll readLl (void) {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}*/

int a[100001], b[100001], smx[100001], px[100001];

int main(void)
{
	FLASH();
	//freopen(" ", "r", stdin);
	//freopen(" ", "w", stdout);
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	std::cin>>a[i];
	for(int i=1;i<=n;i++)
	std::cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		if(smx[a[i]] < b[i])
		{	
			smx[a[i]] = b[i];
			px[a[i]] = i;
		}
	}
	MSXL Z;
	int ctr = 0;
	for(int i=1;i<=n;i++)
	{
		if(px[a[i]] != i)
		Z.insert(b[i]);	
		else ctr++;
	}	
	ll tc = 0;	
	while(ctr < k)
	{
		tc += *Z.begin();
		Z.erase(Z.begin());
		ctr++;
	}	
	std::cout<<tc<<"\n";
	return 0;
}