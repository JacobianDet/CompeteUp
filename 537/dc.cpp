#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll ctx[52], factx[100001], invf[100001], inv[100001], memo[52][52], pre[100001], tp1[100001];

void factup(void)
{
	factx[0] = 1;
	factx[1] = 1;
	inv[0] = 0;
	inv[1] = 1;
	for(ll i=2;i<100001;i++)
	{
		factx[i] = (i * factx[i-1])%MOD;
		inv[i] = (MOD - ((MOD/i) * (inv[MOD % i]))%MOD)%MOD;
	}
	invf[0] = 1;
	for(ll i=1;i<100001;i++)
	invf[i] = (inv[i] * invf[i-1])%MOD;	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	factup();
	std::string s;
	std::cin>>s;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		ctx[s[i] - 'a' + 26]++;
		else ctx[s[i] - 'A']++;	
	}
	int n = (int)s.size();
	ll ix = 1;
	for(int i=0;i<52;i++)
	ix = (ix * invf[ctx[i]])%MOD;	
	pre[0] = 1;
	ll wx = (((factx[n/2] * factx[n/2])%MOD) * (ix%MOD))%MOD;
	for(int i=0;i<52;i++)
	{
		if(!ctx[i])
		continue;	
		for(int j=n/2;j>=ctx[i];j--)
		pre[j] = (pre[j] + pre[j-ctx[i]])%MOD;
	}
	for(int i=0;i<52;i++)
	memo[i][i] = (wx * pre[n/2])%MOD;
	for(int i=0;i<52;i++)
	{
		if(!ctx[i])
		continue;	
		for(int j=0;j<=n/2;j++)
		tp1[j] = pre[j];
		for(int j=ctx[i];j<=n/2;j++)
		tp1[j] = (tp1[j] - tp1[j-ctx[i]] + MOD)%MOD;
		for(int j=i+1;j<52;j++)
		{
			if(!ctx[j])
			continue;	
			for(int k=ctx[j];k<=n/2;k++)
			tp1[k] = (tp1[k] - tp1[k-ctx[j]] + MOD)%MOD;
			memo[i][j] = (((2LL * wx)%MOD) * (tp1[n/2]%MOD))%MOD;
			for(int k=n/2;k>=ctx[j];k--)
			tp1[k] = (tp1[k] + tp1[k-ctx[j]])%MOD;	
		}
	}
	int q;
	std::cin>>q;
	while(q--)
	{
		int l,r;
		std::cin>>l>>r;
		l--;
		r--;
		int a = 0, b = 0;
		if(s[l] >= 'a' && s[l] <= 'z')
		a = (s[l] - 'a' + 26);
		else a = (s[l] - 'A');
		if(s[r] >= 'a' && s[r] <= 'z')
		b = (s[r] - 'a' + 26);
		else b = (s[r] - 'A');	
		if(a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		std::cout<<memo[a][b]<<"\n";
	}
	return 0;
}