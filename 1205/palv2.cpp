#include <bits/stdc++.h>
#define ll long long

ll A[19], B[19], C[19];
//ll memo[19][2][2];

bool checkpal(void)
{
	ll z=0;
	bool t = 1;
	for(z = 0; !C[z]; z++);
	for(ll i=0;i<(18-z+1)/2;i++)
	{
		if(C[z+i] != C[18-i])
		{
			t = 0;
			break;
		}	
	}	
	return t;
}

ll palc(ll i, bool fa, bool fb)
{
	if(i == 18)
	{
		ll ans = 0;
		for(ll j=1;j<=9;j++)
		{
			if(!fa && (j > A[i]))
			fa = 1;
			if(!fb && (j < B[i]))
			fb = 1;
			if((fa && (j == B[i])) || ((j == A[i]) && fb) || (fa & fb) || ((j == A[i]) && (j == B[i])))
			{
				C[i] = j;
				if(checkpal())
				ans += 1;
				C[i] = 0;	
			}	
		}
		return ans;	
	}	
	/*if(memo[i][fa][fb] != -1)
	return memo[i][fa][fb];*/	
	ll ans = 0;
	for(ll j=0;j<=9;j++)
	{
		bool f1a = 0;
		bool f1b = 0;
		if(fa || (!fa && (j > A[i])))
		f1a = 1;
		if(fb || (!fb && (j < B[i])))
		f1b = 1;
		if((f1a && (j == B[i])) || ((j == A[i]) && f1b) || (f1a && f1b) || ((j == A[i]) && (j == B[i])))
		{
			C[i] = j;
			ans += palc(i+1, f1a, f1b);
			C[i] = 0;
		}	
	}	
	//memo[i][fa][fb] = ans;
	return ans;
}

int main(void)
{
	ll T;
	std::cin>>T;
	for(ll y=1;y<=T;y++)
	{
		ll a,b;
		std::cin>>a>>b;
		if(a > b)
		{
			ll temp = b;
			b = a;
			a = temp;
		}	
		if(!a && !b)
		{
			std::cout<<"Case "<<y<<": 0\n";
			continue;
		}	
		//memset(memo, -1, sizeof(memo));
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		ll temp1 = a, temp2 = b;
		ll blim = 0;
		for(ll i=18;i>=0;i--)
		{
			if(!temp2)
			{
				blim = i+1;
				break;
			}	
			A[i] = (temp1%10);
			B[i] = (temp2%10);
			temp1 /= 10;
			temp2 /= 10;
		}	
		ll ans = palc(blim, 0, 0);
		std::cout<<"Case "<<y<<": "<<ans<<"\n";
	}	
	return 0;
}