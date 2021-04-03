#include <bits/stdc++.h>

void NMUL(int B[], int A[], int &s1, int &s2)
{
	int C[2000], sc=0;
	memset(C,0,sizeof(C));
	int temp = 0, cy = 0;
	for(int i=0;i<s1;i++)
	{
		for(int j=0;j<s2;j++)
		{
			int x = B[i]*A[j] + C[i+j] + temp;
			C[i+j] = x%10;
			temp = x/10;
		}
		C[i+s2] = temp;
		temp = 0;
	}
	sc = 2000;
	for(int i=1999;i>=0;i--)
	{
		if(C[i])
		break;
		else sc--;
	}
	s1 = sc;
	for(int i=0;i<s1;i++)
	B[i] = C[i];
	return;	
}

void NSUB(int A[], int B[], int &sz, int &sv)
{
	int brw = 0;
	int C[2000], sc=0;
	memset(C,0,sizeof(C));
	for(int i=0;i<sz;i++)
	{
		C[sc] = A[i] - B[i] - brw;
		brw = 0;
		if(C[sc] < 0)
		{
			C[sc] += 10;
			brw = 1;
		}
		sc++;
	}
	sz = sc;
	for(int i=sc-1;i>=0;i--)
	{
		if(C[i])
		break;
		sz--;
	}
	for(int i=0;i<sc;i++)
	A[i] = C[i];
	if(!sz)
	sz = 1;
	return;	
}

void fexp(int ans[], int &sz, int n)
{
	int res[2000], sr;
	memset(res,0,sizeof(res));
	res[0] = 1;
	sr = 1;
	while(n)
	{
		if(n & 1)
		NMUL(res, ans, sr, sz);
		NMUL(ans, ans, sz, sz);
		n >>= 1;	
	}	
	for(int i=0;i<2000;i++)
	ans[i] = 0;	
	sz = sr;
	for(int i=0;i<sr;i++)
	ans[i] = res[i];
	return;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,m;
		std::cin>>n>>m;
		int ans[2000], sz;
		memset(ans,0,sizeof(ans));
		sz = 1;
		ans[0] = 2;
		fexp(ans, sz, n+1);
		/*for(int i=sz-1;i>=0;i--)
		std::cout<<ans[i];
		std::cout<<"\n"<<(1ll<<57)<<"\n";*/
		int v[2000], sv;
		memset(v,0,sizeof(v));
		sv = 1;
		v[0] = 2;
		fexp(v, sv, m+1);
		/*for(int i=sv-1;i>=0;i--)
		std::cout<<v[i];
		std::cout<<"\n"<<(1ll<<21)<<"\n";*/
		NSUB(ans, v, sz, sv);
		for(int i=sz-1;i>=0;i--)
		std::cout<<ans[i];
		std::cout<<".00\n";	
		//std::cout<<((1ll<<57) - (1ll<<21))<<".00\n"; 
	}	
	return 0;
}