#include <bits/stdc++.h>

int lvl[(1<<17)], par[(1<<17)];
int n,b;

void dfs_visit(int a, int p)
{

}

int main(void)
{
	int a;
	std::cin>>n>>a>>b;
	if(!(__builtin_popcount(a ^ b) & 1))
	std::cout<<"NO\n";
	else
	{
		memset(lvl, -1, sizeof(lvl));
		dfs_visit(a, -1);
	}	
}