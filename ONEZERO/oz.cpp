#include <bits/stdc++.h>
#define pb push_back

//typedef long long ll;

int bfs_rem[20001];

void bfs_visit(int n)
{
	int ans = 0, c = -1;
	std::queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		ans = 0;
		int s = Q.front();
		//std::cout<<s<<"\n";
		Q.pop();	
		for(int i=30;i>=0;i--)
		{	
			if((s & (1<<i)))
			ans = ((((10%n) * (ans%n))%n) + (1%n))%n;
			else ans = ((10%n) * (ans%n))%n;
		}
		//std::cout<<ans<<"\n";
		if(!ans)
		{	
			bfs_rem[ans] = s;
			break;
		}	
		else
		{
			if(bfs_rem[ans] == -1)
			{	
				Q.push(2*s);
				Q.push(2*s+1);
				bfs_rem[ans] = s;
			}	
		}	
	}
	//std::cout<<ans<<"\n";	
	return;
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
		memset(bfs_rem, -1, sizeof(bfs_rem));
		int n;
		std::cin>>n;
		bfs_visit(n);
		std::vector<int> res;
		int ans = bfs_rem[0];
		for(int i=30;i>=0;i--)
		{	
			if((ans & (1<<i)))
			res.pb(1);
			else res.pb(0);
		}	
		int p = -1;	
		for(int i=0,j=(int)res.size();i<j;i++)
		{
			if(res[i])
			{
				p = i;
				break;
			}	
		}
		if(p != -1)
		{	
			for(int i=p,j=(int)res.size();i<j;i++)
			std::cout<<res[i];
			std::cout<<"\n";
		}		
	}	
	return 0;
}