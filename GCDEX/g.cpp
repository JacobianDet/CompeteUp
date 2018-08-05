#include <bits/stdc++.h>
#define CHOR 1000001
using namespace std;

vector<long long> phi(CHOR);
vector<long long> gcd(CHOR);

void etf()
{
	for(long long i=1;i<CHOR;i++)
	phi[i] = i;
	for(long long i=2;i<CHOR;i++)
	{
		if(phi[i] == i)
		{
			for(long long j=i;j<CHOR;j+=i)
			phi[j] = phi[j]*(i-1)/i;
		}
	}
}

void gcdex()
{
	for(long long j=1;j<CHOR;j++)
	{
		for(long long i=2*j;i<CHOR;i+=j)
		gcd[i] += j*phi[i/j];
	}
	for(long long i=2;i<CHOR-1;i++)
        gcd[i+1] += gcd[i];
}

int main() {
	etf();
	gcdex();
	long long n;
	cin>>n;
	while(n != 0)
	{
		cout<<gcd[n]<<endl;
		cin>>n;
	}
	return 0;
}
