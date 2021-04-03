#include <bits/stdc++.h>

int arr[100001], cz[100001], BIT[100001];

class fentree
{
	public: int query(int i)
			{
				int ans = 0;
				for( ;i>0;i-=(i & (-i)))
				ans += BIT[i];
				return ans;
			}

			void update(int val, int i, int n)
			{
				for( ;i<=n;i+=(i & (-i)))
				BIT[i] += val;
				return;	
			}
};

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,s;
		std::cin>>n>>s;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		int fz = 0;
		fentree Z;
		for(int i=0;i<n;i++)
		{
			memset(cz, 0, sizeof(cz));
			memset(BIT, 0, sizeof(BIT));
			for(int j=i;j<n;j++)
			{
				if(cz[arr[j]])
				Z.update(-cz[arr[j]], cz[arr[j]], n);
				cz[arr[j]]++;	
				Z.update(cz[arr[j]], cz[arr[j]], n);	
				fz = std::max(fz, Z.query(s));	
			}	
		}
		std::cout<<"Case #"<<t<<": "<<fz<<"\n";	
	}
	return 0;
}