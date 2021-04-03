#include <bits/stdc++.h>

std::string xd;
int inp[105], A[105], B[105];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(inp, 0, sizeof(inp));
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		std::cin>>xd;
		int ct = 104;
		for(int i=(int)xd.size()-1;i>=0;i--)
		{
			inp[ct] = (xd[i] - '0');
			ct--;
		}
		ct++;
		int ca = -1, cb = -1;
		for(int i=ct;i<=104;i++)
		{
			if(inp[i] == 4)
			{
				if(ca == -1)
				ca = i;	
				A[i] = 3;
				if(cb == -1)
				cb = i;
				B[i] = 1;	
			}	
			else
			{
				if(ca == -1)
				ca = i;
				A[i] = inp[i];	
			}
		}
		if(cb == -1)
		{
			cb = 104;
			A[104]--;
			B[104]++;
		}	
		std::cout<<"Case #"<<t<<": ";
		for(int i=ca;i<=104;i++)
		std::cout<<A[i];
		std::cout<<" ";
		for(int i=cb;i<=104;i++)
		std::cout<<B[i];
		std::cout<<"\n";	
	}
	return 0;
}