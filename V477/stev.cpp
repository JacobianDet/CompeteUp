#include <bits/stdc++.h>

int lif[100001], elev[100001];

int bs1e(int val, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(elev[mid] < val)
		lo = mid + 1;
		else hi = mid;	
	}
	if((lo > hi) || (elev[lo] < val))
	return -1;	
	else return lo;
}

int bs1s(int val, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(lif[mid] < val)
		lo = mid + 1;
		else hi = mid;	
	}
	if((lo > hi) || (lif[lo] < val))
	return -1;
	else return lo;
}

int bs2e(int val, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(elev[mid] > val)
		hi = mid - 1;
		else lo = mid;	
	}
	if((lo > hi) || (elev[lo] > val))
	return -1;	
	else return lo;
}

int bs2s(int val, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(lif[mid] > val)
		hi = mid - 1;
		else lo = mid;	
	}
	if((lo > hi) || (lif[lo] > val))
	return -1;
	else return lo;
}

int main(void)
{
	int n,m,cl,ce,v;
	std::cin>>n>>m>>cl>>ce>>v;
	for(int i=0;i<cl;i++)
	std::cin>>lif[i];
	for(int i=0;i<ce;i++)
	std::cin>>elev[i];
	int q;
	std::cin>>q;
	while(q--)
	{
		int x1,y1,x2,y2;
		std::cin>>x1>>y1>>x2>>y2;
		if(x1 == x2)
		std::cout<<abs(y2 - y1)<<"\n";
		else
		{
			int sv = abs(x2 - x1);
			int lv = 0;
			if(!(sv % v))
			lv = sv/v;
			else lv = sv/v + 1;	
			int df1 = 1000000000;
			int df2 = 1000000000;
			int mn = 0, mx = 0;
			if(y1 < y2)
			{
				mn = y1;
				mx = y2;
			}	
			else
			{
				mn = y2;
				mx = y1;
			}
			int lx = bs1e(mn, ce);
			int ly = bs2e(mx, ce);
			if(lx != -1 && ly != -1)
			{
				if(ly < lx)
				{
					int tmp = lx;
					lx = ly;
					ly = tmp;
				}	
				if(!((ly - lx + 1) & 1))
				df1 = std::min(abs(mn - elev[lx + (ly - lx + 1)/2 - 1]) + abs(mx - elev[lx + (ly - lx + 1)/2 - 1]), abs(mn - elev[lx + (ly - lx + 1)/2]) + abs(mx - elev[lx + (ly - lx + 1)/2]));
				else df1 = abs(mn - elev[lx + (ly - lx + 1)/2]) + abs(mx - elev[lx + (ly - lx + 1)/2]);
			}
			else if(lx != -1)
			df1 = abs(mn - elev[lx]) + abs(mx - elev[lx]);
			else if(ly != -1) 
			df1 = abs(mn - elev[ly]) + abs(mx - elev[ly]);
			int tx = bs1s(mn, cl);
			int ty = bs2s(mx, cl);
			if(tx != -1 && ty != -1)
			{
				if(ty < tx)
				{
					int tmp = tx;
					tx = ty;
					ty = tmp;
				}	
				if(!((ty - tx + 1) & 1))
				df2 = std::min(abs(mn - lif[tx + (ty - tx + 1)/2 - 1]) + abs(mx - lif[tx + (ty - tx + 1)/2 - 1]), abs(mn - lif[tx + (ty - tx + 1)/2]) + abs(mx - lif[tx + (ty - tx + 1)/2]));
				else df2 = abs(mn - lif[tx + (ty - tx + 1)/2]) + abs(mx - lif[tx + (ty - tx + 1)/2]);
			}
			else if(tx != -1)
			df2 = abs(mn - lif[tx]) + abs(mx - lif[tx]);
			else if(ty != -1)
			df2 = abs(mn - lif[ty]) + abs(mx - lif[ty]);
			std::cout<<std::min(lv + df1, sv + df2)<<"\n";
		}	
	}
	return 0;	
}
