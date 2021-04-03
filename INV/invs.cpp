#include <bits/stdc++.h>

int a[70000], b[70000], BIT[70000];

class fentree
{
	public: void build(int n);
			void update(int i, int n);
			int query(int i);
};

void fentree::build(int n)
{
	for(int i=1;i<=n;i++)
	BIT[i] = 0;
	return;	
}

void fentree::update(int i, int n)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i]++;
	return;	
}

int fentree::query(int i)
{
	int sum = 0;
	for( ;i>0;i-=(i & (-i)))
	sum += BIT[i];
	return sum;	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{	
		std::cin>>a[i];
		b[i] = a[i];
	}
	std::sort(b+1, b+n+1);
	for(int i=1;i<=n;i++)
	a[i] = (std::lower_bound(b+1, b+n+1, a[i]) - b);	
	int ct = 0;
	fentree T;
	T.build(n);
	for(int i=n;i>0;i--)
	{
		ct += T.query(a[i]-1);
		T.update(a[i], n);
	}	
	std::cout<<ct<<"\n";
	return 0;
}