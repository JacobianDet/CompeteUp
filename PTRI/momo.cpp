#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define sz size

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;

int readInt (void) {
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

#define DO(P,R,I,M,E,S,i0,v0,i1,v1,i2,v2,i3,v3,i4,v4,i5,v5,i6,v6,i7,v7) k=P;\
if (!(sieve[n] & (1<<R))){\
  e = eos - I*n - M;\
  for (m = sieve + (30*n + E) * n + S; m < e; m += i0)\
  { *m        |= (1<<v0); *(m += i1) |= (1<<v1);\
    *(m +=i2) |= (1<<v2); *(m += i3) |= (1<<v3);\
    *(m +=i4) |= (1<<v4); *(m += i5) |= (1<<v5);\
    *(m +=i6) |= (1<<v6); *(m += i7) |= (1<<v7);\
  }\
  if (m < eos) { *m|=(1<<v0);\
    if ((m += i1) < eos) { *m |= (1<<v1);\
      if ((m += i2) < eos) { *m |= (1<<v2);\
        if ((m += i3) < eos) { *m |= (1<<v3);\
          if ((m += i4) < eos) { *m |= (1<<v4);\
            if ((m += i5) < eos) { *m |= (1<<v5);\
              if ((m += i6) < eos)   *m |= (1<<v6);\
} } } } } } }

char bits[]={1,7,11,13,17,19,23,29};

unsigned prime[5761459],nbprimes;
const unsigned bytes=1+100007011/30; //prems < 1e8
char sieve[bytes];

inline void primesieve(){
  unsigned p,q,r,k=0,n,s;
  char *m,*e,*eos;
  if (bytes > 30) for (k=r=(bytes-1)/30; (q=r/k)<k; k>>=1) k+=q;
  eos=sieve+bytes; s=k+1; *sieve=1;
  for (n = p = q = r = 0; n < s; n++)
  { DO(p++,0,28, 0, 2, 0,p,0,r,1,q,2,k,3,q,4,k,5,q,6,r,7); r++;
    DO(q++,1,24, 6,14, 1,r,5,q,4,p,0,k,7,p,3,q,2,r,6,p,1); r++; q++;
    DO(p-1,2,26, 9,22, 4,q,0,k,6,q,1,k,7,q,3,r,5,p,2,r,4); r++;
    DO(q-1,3,28,12,26, 5,p,5,q,2,p,1,k,7,r,4,p,3,r,0,k,6);
    DO(q+1,4,26,15,34, 9,q,5,p,6,k,0,r,3,p,4,r,7,k,1,p,2); r++;
    DO(p+1,5,28,17,38,12,k,0,q,4,r,2,p,5,r,3,q,7,k,1,q,6); r++; q++;
    DO(q++,6,26,20,46,17,k,5,r,1,p,6,r,2,k,3,p,7,q,0,p,4); r++;
    DO(p++,7,24,23,58,28,r,0,k,7,r,6,q,5,p,4,q,3,p,2,q,1);
  }
  prime[0]=2,prime[1]=3,prime[2]=5;
  nbprimes=3;
  for (p=0; p<bytes && nbprimes<=5761459; p++)
    for (k=0; k<8; k++)
      if (!(sieve[p] & (1<<k))) prime[nbprimes++]=30*p+bits[k];
}

int bs2a(int lo, int n)
{
	int hi = 5761458;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(prime[mid] <= n)
		lo = mid;
		else hi = mid-1;	
	}
	return lo;
}

int bs2b(int lo, int ct)
{
	int hi = 15000;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if((mid * (mid + 1))/2 <= ct)
		lo = mid;
		else hi = mid-1;	
	}
	return lo;
}

void solve(int T)
{
	vector<PII> vin(T);
	vector<PII> vout(T, {-1, -1});
	int idx = 0;
	for(auto &&n : vin)
	{
		n.ff = readInt();
		n.ss = idx++;
	}	
	sort(begin(vin), end(vin), [](PII A, PII B){ return (A.ff < B.ff); });
	int l1 = 0, l2 = 1;
	for(auto &&n : vin)
	{
		l1 = bs2a(l1, n.ff);
		if(prime[l1] == n.ff)
		{
			l2 = bs2b(l2, l1+1);
			if((l2 * (l2 + 1))/2 == l1+1)
			vout[n.ss] = {l2, l2};
			else vout[n.ss] = {l2+1, l1 + 1 - (l2 * (l2 + 1))/2};	
		}
	}
	for(auto &&n : vout)
	{
		if(n.ff == -1)
		{
			putchar_unlocked('-');
			putchar_unlocked('1');
		}	
		else
		{
			string hg = (to_string(n.ff) + ' ' + to_string(n.ss));
			for(auto &&u : hg)
			putchar_unlocked(u);
		}	
		putchar_unlocked('\n');
	}	
	return;
}

int main(void)
{
	// FLASH();
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	primesieve();
	T = readInt();
	solve(T);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}