#include <bits/stdc++.h>
#define pb push_back
 
typedef unsigned long long ull;
typedef long long ll;
 
std::vector<bool> isP(100000001, 1);
std::map<ull, ull> mx;
std::vector<int> vx;
 
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
 
ull readL (void) {
	bool minus = false;
	ull result = 0;
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
 
void siever(void)
{
	//memset(isP, 1, sizeof(isP));
	isP[0] = 0;
	isP[1] = 0;
	for(ll p=3;p*p<100000001;p+=(1<<1))
	{
		if(isP[p])
		{
			for(ll i=p*p;i<100000001;i+=(p<<1))
			isP[i] = 0;	
		}
	}
	vx.pb(2);
	for(int i=3;i<100000001;i+=(1<<1))
	{
		if(isP[i])
		vx.pb(i);
	}	
	return;
}
 
ull fexp(ull a, ull n)
{
	ull res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}
	return res;
}
 
int main(void)
{
	siever();
	int T;
	T = readInt();
	while(T--)
	{
		ull n;
		n = readL();
		ull ans = 1;
		ull z = n;
		for(int i=0,j=(int)vx.size();i<j;i++)
		{	
			ull p = vx[i];
			if(z == 1 || p*p > z)
			break;	
			ull ctx = 0;
			if(!(z%p))
			{	
				while((z > 1) && !(z%p))
				{
					ctx++;
					z /= p;
				}	
				ans *= ((fexp(p, ctx+1) - 1)/(p - 1));
			}
		}		
		if(z > 1)
		ans *= (z+1);	
		printf("%llu\n", ans-n);		
	}	
	return 0;
} 