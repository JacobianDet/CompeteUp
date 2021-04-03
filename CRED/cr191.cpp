#include <bits/stdc++.h>

typedef long long ll;

ll memo[20][10][10][2][4][(1<<9)];
ll A[20], B[20];
int dig[10];
int k, m;

ll DC(int ln, int ld, int sl, int ty, int cm, int mask)
{
	if(ln == 20)
	{	
		//std::cout<<ln<<" "<<ld<<" "<<sl<<" "<<ty<<" "<<cm<<" "<<mask<<"\n";
		if(mask == ((1<<m) - 1))
		return 1;
		else return 0;
	}	
	if(memo[ln][ld][sl][ty][cm][mask] != -1)
	return memo[ln][ld][sl][ty][cm][mask];
	ll ans = 0;
	if(!cm)
	{
		for(int i=A[ln];i<=B[ln];i++)
		{
			if(!ld)
			{	
				if((i == A[ln]) && (i == B[ln]))
				ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 0, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				else if(i == A[ln])
				ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 1, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				else if(i == B[ln])
				ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 2, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				else ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));	
			}		
			else
			{
				if(!i || (i == ld) || ((i > ld) && (ty == 0) && (sl + 1 > k)) || ((i < ld) && (ty == 1) && (sl + 1 > k)) || ((((i > ld) && (ty == 1)) || ((i < ld) && (ty == 0))) && (k <= 1)))
				continue;
				else
				{
					if((i == A[ln]) && (i == B[ln]))
					ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 0, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
					else if(i == A[ln])
					ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 1, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
					else if(i == B[ln])
					ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 2, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
					else ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				}	
			}
		}	
	}
	else if(cm == 1)
	{
		for(int i=A[ln];i<=9;i++)
		{
			if(!ld)
			{	
				if(i == A[ln])
				ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 1, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				else ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));	
			}		
			else
			{
				if(!i || (i == ld) || ((i > ld) && (ty == 0) && (sl + 1 > k)) || ((i < ld) && (ty == 1) && (sl + 1 > k)) || ((((i > ld) && (ty == 1)) || ((i < ld) && (ty == 0))) && (k <= 1)))
				continue;
				else
				{
					if(i == A[ln])
					ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 1, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
					else ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				}	
			}
		}	
	}
	else if(cm == 2)
	{
		for(int i=0;i<=B[ln];i++)
		{
			if(!ld)
			{	
				if(i == B[ln])
				ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 2, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				else ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));	
			}		
			else
			{
				if(!i || (i == ld) || ((i > ld) && (ty == 0) && (sl + 1 > k)) || ((i < ld) && (ty == 1) && (sl + 1 > k)) || ((((i > ld) && (ty == 1)) || ((i < ld) && (ty == 0))) && (k <= 1)))
				continue;
				else
				{
					if(i == B[ln])
					ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 2, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
					else ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
				}	
			}
		}	
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			if(!ld)
			ans += DC(ln + 1, i, (sl + (i ? 1 : 0)), ty, 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));		
			else
			{
				if(!i || (i == ld) || ((i > ld) && (ty == 0) && (sl + 1 > k)) || ((i < ld) && (ty == 1) && (sl + 1 > k)) || ((((i > ld) && (ty == 1)) || ((i < ld) && (ty == 0))) && (k <= 1)))
				continue;
				else ans += DC(ln + 1, i, (((i > ld) && (ty == 0)) ? sl+1 : (((i < ld) && (ty == 1)) ? sl+1 : 2)), ((i > ld) ? 0 : 1), 3, ((dig[i] != -1) ? (mask | (1<<dig[i])) : mask));
			}
		}	
	}
	memo[ln][ld][sl][ty][cm][mask] = ans;
	return ans;	
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
		memset(memo, -1, sizeof(memo));
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(dig, -1, sizeof(dig));
		std::cin>>m;
		for(int i=0;i<m;i++)
		{	
			int t;
			std::cin>>t;
			dig[t] = i;
		}	
		std::cin>>k;
		ll a, b;
		std::cin>>a>>b;
		int d = 19;
		while(a)
		{
			A[d] = (a%10);
			d--;
			a /= 10;
		}	
		d = 19;
		while(b)
		{
			B[d] = (b%10);
			d--;
			b /= 10;
		}	
		ll ax = DC(0, 0, 0, 0, 0, 0);
		std::cout<<ax<<"\n";
	}
	return 0;
}