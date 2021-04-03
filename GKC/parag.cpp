#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

ll pval[CHOR], hval[CHOR], xval[CHOR], yval[CHOR];

struct ph
{
	ll p,h;
}sax[CHOR];

bool cmp(ph a, ph b)
{
	return (a.h < b.h);
}

int bs1(ll val, int n)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(sax[mid].h < val)
		lo = mid + 1;
		else hi = mid;	
	}
	if(sax[lo].h < val)
	return -1;
	else return lo;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,k;
		std::cin>>n>>k;
		ll a[5], b[5], c[5], m[5];
		std::cin>>pval[1]>>pval[2]>>a[1]>>b[1]>>c[1]>>m[1];
		std::cin>>hval[1]>>hval[2]>>a[2]>>b[2]>>c[2]>>m[2];
		std::cin>>xval[1]>>xval[2]>>a[3]>>b[3]>>c[3]>>m[3];
		std::cin>>yval[1]>>yval[2]>>a[4]>>b[4]>>c[4]>>m[4];
		sax[1].p = pval[1];
		sax[1].h = hval[1];
		sax[2].p = pval[2];
		sax[2].h = hval[2];
		ll ans = 0;
		for(int i=3;i<=n;i++)
		{	
			pval[i] = ((((((a[1]%m[1]) * (pval[i-1]%m[1]))%m[1]) + (((b[1]%m[1]) * (pval[i-2]%m[1]))%m[1]))%m[1]) + (c[1]%m[1]))%m[1] + 1;	
			hval[i] = ((((((a[2]%m[2]) * (hval[i-1]%m[2]))%m[2]) + (((b[2]%m[2]) * (pval[i-2]%m[2]))%m[2]))%m[2]) + (c[2]%m[2]))%m[2] + 1;	
			sax[i].p = pval[i];
			sax[i].h = hval[i];
		}
		for(int i=3;i<=k;i++)
		{
			xval[i] = ((((((a[3]%m[3]) * (xval[i-1]%m[3]))%m[3]) + (((b[3]%m[3]) * (pval[i-2]%m[3]))%m[3]))%m[3]) + (c[3]%m[3]))%m[3] + 1;	
			yval[i] = ((((((a[4]%m[4]) * (yval[i-1]%m[4]))%m[4]) + (((b[4]%m[4]) * (pval[i-2]%m[4]))%m[4]))%m[4]) + (c[4]%m[4]))%m[4] + 1;	
		}
		std::sort(sax+1, sax+n+1, cmp);
		for(int i=1;i<=k;i++)
		{
			int chk = bs1(yval[i], n);
			if(chk != -1)
			{
				for(int j=chk;j<=n;j++)
				{
					ll t1 = abs(xval[i] - sax[j].p);
					ll t2 = yval[i] + t1;
					if(t2 <= sax[j].h)
					{	
						ans++;
						break;
					}	
				}	
			}		
		}
		std::cout<<"Case #"<<t<<": ";
		std::cout<<ans<<"\n";	
	}
	return 0;
}