#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::pair<int, int> arr[100001];

int tx[100001];

bool cmpz(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}

int bs1(int val, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(arr[mid].second > val)
		hi = mid;
		else lo = mid + 1;	
	}
	if(arr[lo].second <= val)
	return -1;
	else return lo;	
}

int bs2(int val, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(arr[mid].first <= val)
		lo = mid;
		else hi = mid - 1;	
	}
	if(arr[lo].first > val)
	return -1;
	else return lo;	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,m;
		std::cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			int x,y;
			std::cin>>x>>y;
			arr[i] = mp(x, y);
		}	
		std::sort(arr, arr+n);
		for(int i=0;i<m;i++)
		std::cin>>tx[i];	
		for(int i=0;i<m;i++)
		{
			int p1 = bs1(tx[i], n);
			if(p1 != -1)
			{
				int p2 = bs2(tx[i], n);
				if(p2 != -1)
				{
					if(p1 == p2)
					std::cout<<"0\n";
					else std::cout<<(arr[p1].first - tx[i])<<"\n";	
				}	
				else std::cout<<(arr[p1].first - tx[i])<<"\n";	
			}
			else std::cout<<"-1\n";
		}
	}
	return 0;
}