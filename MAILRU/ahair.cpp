#include <bits/stdc++.h>

typedef long long ll;

int val[100001], arr[100005], sze[100005], ld[100005];

class dsu
{
	public: int root(int x);
			void find_union(int x, int y); 
};

int dsu::root(int x)
{
	return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(sze[ry] > sze[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
	sze[rx] += sze[ry];
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,l;
	std::cin>>n>>m>>l;
	for(int i=1;i<=n;i++)
	std::cin>>val[i];
	for(int i=1;i<=n+5;i++)
	{
		arr[i] = i;
		ld[i] = i;
		sze[i] = 1;
	}	
	dsu T;
	for(int i=1;i<=n;i++)
	{
		if(val[i] > l)
		{	
			ld[T.root(i)] = i+1;
			T.find_union(i, i+1);
		}	
	}	
	std::set<int> Z;
	for(int i=1;i<=n;i++)
	{
		if(val[i] > l)	
		Z.insert(ld[T.root(i)]);	
	}	
	while(m--)
	{
		int t;
		std::cin>>t;
		if(!t)
		std::cout<<(int)Z.size()<<"\n";
		else
		{
			int id, ch;
			std::cin>>id>>ch;
			if(Z.find(ld[T.root(id)]) == Z.end())
			{	
				val[id] += ch;
				if(val[id] > l)
				{
					ld[T.root(id)] = ld[T.root(id+1)];
					T.find_union(id, id+1);
					Z.insert(ld[T.root(id)]);
				}	
			}	
			else
			{
				Z.erase(ld[T.root(id)]);
				val[id] += ch;
				if(val[id] > l)
				{	
					ld[T.root(id)] = ld[T.root(id+1)];
					T.find_union(id, id+1);
				}	
				Z.insert(ld[T.root(id)]);
			}
		}
	}
	return 0;
}