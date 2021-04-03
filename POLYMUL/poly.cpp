#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;
typedef std::complex<long double> base;

int rev(int num, int lv)
{
	int res = 0;
	for(int i=0;i<lv;i++)
	{
		if(num & (1<<i))
		res |= (1<<(lv-1-i));	
	}	
	return res;
}

void fft(std::vector<base> &a, bool invert)
{
	int n = (int)a.size();
	int lv = 0;
	for(lv=0;(1<<lv)<n;lv++);
	for(int i=0;i<n;i++)
	{
		if(i < rev(i, lv))
		std::swap(a[i], a[rev(i, lv)]);		
	}	
	for(int z=2;z<=n;z<<=1)
	{
		long double ang = 2*M_PI/z * (invert ? -1 : 1);
		base wan (cos(ang), sin(ang));
		for(int i=0;i<n;i+=z)
		{
			base w(1);
			for(int j=0;j<z/2;j++)
			{
				base u = a[i+j], v = a[i+j+z/2] * w;
				a[i+j] = u + v;
				a[i+j+z/2] = u - v;
				w *= wan;
			}	
		}
	}
	if(invert)
	{
		for(int i=0;i<n;i++)
		a[i] /= n;	
	}	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int y = n;
		std::vector<base> a,b;
		for(int i=0;i<n+1;i++)
		{
			ll t;
			std::cin>>t;
			a.pb(t);
		}	
		for(int i=0;i<n+1;i++)
		{
			ll t;
			std::cin>>t;
			b.pb(t);
		}
		n = 2*n;
		n++;
		while(n & (n-1))
		n++;
		for(int i=0,j=(int)a.size();i<n-j;i++)
		{
			a.pb(0);
			b.pb(0);
		}	
		fft(a, 0);
		fft(b, 0);
		for(int i=0;i<n;i++)
		a[i] *= b[i];
		fft(a, 1);
		std::vector<ll> res;
		for(int i=0;i<n;i++)
		res.pb(round(a[i].real()));
		for(int i=0;i<2*y+1;i++)
		std::cout<<res[i]<<" ";	
		std::cout<<"\n";
	}
	return 0;
}