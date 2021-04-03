#include <bits/stdc++.h>

struct block
{
	int x,y,z;
};

int n;
block arr[200];
int memo[200];

bool compare(block a, block b)
{
	if((a.x * a.y) > (b.x * b.y))
	return true;
	else return false;	
}

int babtwr(int i)
{
	if(memo[i] != -1)
	return memo[i];	
	int ans = arr[i].z;
	for(int j=i+1;j<6*n;j++)
	{
		if((arr[j].x < arr[i].x) && (arr[j].y < arr[i].y))
		ans = std::max(ans, arr[i].z + babtwr(j));	
	}	
	memo[i] = ans;
	return ans;
}

int main(void)
{
	std::cin>>n;
	while(n)
	{
		memset(memo, -1, sizeof(memo));
		for(int i=0;i<6*n;i+=6)
		{	
			int x,y,z;
			std::cin>>x>>y>>z;
			block p[6] = {{x, y, z}, {x, z, y}, {y, z, x}, {z, y, x}, {z, x, y}, {y, x, z}};
			for(int j=0;j<6;j++)
			arr[i+j] = p[j];
		}	
		std::sort(arr, arr+6*n, compare);
		int ans = 0;	
		/*for(int i=0;i<6*n;i++)
		std::cout<<arr[i].x<<" "<<arr[i].y<<" "<<arr[i].z<<"\n";*/	
		for(int i=0;i<6*n;i++)
		ans = std::max(ans, babtwr(i));
		std::cout<<ans<<"\n";
		std::cin>>n;
	}
	return 0;	
}