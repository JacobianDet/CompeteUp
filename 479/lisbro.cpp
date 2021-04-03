#include <bits/stdc++.h>
#define pb push_back

typedef std::map<int, int> mii;

int arr[200001];
mii memo;
int n;

int bhai(int i)
{
	int ans = 1;
	if(ans < 1 + memo[arr[i]-1])
	ans = memo[arr[i]-1] + 1;
	memo[arr[i]] = ans;
	return memo[arr[i]];	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin>>n;	
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i];
	}	
	int ans = 0;
	int p = -1;
	for(int i=0;i<n;i++)
	{	
		if(ans < bhai(i))
		{	
			ans = std::max(ans, bhai(i));
			p = i;
		}
	}
	std::cout<<ans<<"\n";
	std::vector<int> res;
	res.pb(p+1);
	for(int i=p-1;i>=0;i--)
	{
		if(arr[i] == arr[p]-1)
		{	
			res.pb(i+1);
			p = i;
		}		
	}	
	for(int i=res.size()-1;i>=0;i--)
	std::cout<<res[i]<<" ";
	std::cout<<"\n";	
	return 0;
}